#pragma once;
#include "2105175_Symbol_Info.hpp"
static int chainIndex = 0;
static int hashChoice = 1;

struct InsertResult {
    bool found;
    std::string scopeInfo;

    InsertResult() : found(false), scopeInfo("") {}
};

class ScopeTable {
    SymbolInfo** symbols;
    ScopeTable* parentScope;
    int bucketCount;
    string tableId;
    int collisionCount;
    int childCount = 0;
    // std::string generateScopeID() {
    //     if (parentScope == nullptr) {
    //         return "1";
    //     }
    //     size_t lastDot = parentScope->tableId.find_last_of('.');
    //     if (lastDot == std::string::npos) {
    //         return parentScope->tableId + ".1";
    //     }
    //     int parentNum = std::stoi(parentScope->tableId.substr(lastDot + 1));
 
    //    return parentScope->tableId.substr(0, lastDot + 1) + std::to_string(parentNum + 1);
    //    int childCount = 1;
    //     ScopeTable* parent = parentScope;
    //     ScopeTable* child = parent->firstChild;
        
    //     while (child != nullptr && child != this) {
    //         childCount++;
    //         child = child->nextSibling;
    //     }
        
    //     return parent->tableId + "." + std::to_string(childCount);
    // }    
public:
    ScopeTable* firstChild;
    ScopeTable* nextSibling;
    
    ScopeTable(int bucketCount) 
        : bucketCount(bucketCount), parentScope(nullptr), tableId("1"),
          collisionCount(0), firstChild(nullptr), nextSibling(nullptr) {
        symbols = new SymbolInfo*[bucketCount];
        for (int i = 0; i < bucketCount; i++) {
            symbols[i] = nullptr;
        }
    }

    ScopeTable(int bucketCount, const string& id, ScopeTable* parent) 
        : bucketCount(bucketCount), tableId(id), parentScope(parent),
          collisionCount(0), firstChild(nullptr), nextSibling(nullptr) {
        symbols = new SymbolInfo*[bucketCount];
        for (int i = 0; i < bucketCount; i++) {
            symbols[i] = nullptr;
        }
    }

    void addChildScope(ScopeTable* child) {
        childCount++;

        if (firstChild == nullptr) {
            firstChild = child;
        } else {
            ScopeTable* temp = firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }

        cout << "Added child scope " << child->getTableID() << " to parent " << tableId << endl;
    }

    ScopeTable* getParentScope() {
        return parentScope;
    }

    string getTableID() {
        return tableId;
    }

    void setTableID(string tableID) {
        this->tableId = tableID;
    }


    int getChildCount() {
        return childCount;
    }

    unsigned int SDBMHash(string str) {
        unsigned int hash = 0;
        for (char c : str) {
            hash = c + (hash << 6) + (hash << 16) - hash;
        }
        return hash % bucketCount;
    }
    
    // 🔗 Hash Function Overview - GeeksforGeeks

    // 🔗 Wikipedia: List of hash functions

    // 🔗 Dan Bernstein’s site – original djb2 hash

    // 🔗 FNV Hash Specification

    // 🔗 Hash function comparison (StackOverflow)

    unsigned int djb2(string str){
        unsigned long hash = 5381;
        for(char c : str){
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return hash % bucketCount;
    }

    unsigned int BKDRHash(string str){
        unsigned int seed = 131; // or 31, 131, 1313, etc.
        unsigned int hash = 0;
        for(char c : str){
            hash = (hash * seed + c) % bucketCount;
        }
        return hash;
    }
    

    unsigned int FNV1aHash(string str){
        const unsigned int fnv_prime = 0x01000193; //   16777619
        unsigned int hash = 0x811C9DC5; // 2166136261
    
        for(char c : str){
            hash ^= c;
            hash *= fnv_prime;
        }
    
        return hash % bucketCount;
    }
    

    bool insert(SymbolInfo* symbol){
        if (!symbol || !symbols || bucketCount <= 0){
            return false;
        }

        int index;
    
        switch(hashChoice) {
            case 1: index = SDBMHash(symbol->getName()); break;
            case 2: index = BKDRHash(symbol->getName()); break;
            case 3: index = djb2(symbol->getName()); break;
            case 4: index = FNV1aHash(symbol->getName()); break;
            default:
                cout << "Invalid hash choice. Defaulting to SDBMHash\n";
                index = SDBMHash(symbol->getName());
        }
        index %= bucketCount;


    
        chainIndex = 0;
        
        if (symbols[index] == nullptr) {
            symbols[index] = symbol;  
            collisionCount = 0;
            cout << "\tInserted in ScopeTable# " << tableId << " at position " << index << ", " << chainIndex << endl;
            return true;
        }
        
        SymbolInfo* curr = symbols[index];
        collisionCount = 1;
        while (curr != nullptr) {
            if (curr->equal(symbol->getName())) {
                cout << "\t'" << symbol->getName() << "' already exists in the current ScopeTable\n";
                collisionCount = 0;
                //collisionCount = 1;
                return false;  
            }

            chainIndex ++;
            if (curr->getNext() == nullptr) {
                curr->setNext(symbol); 
                cout << "\tInserted in ScopeTable# " << tableId << " at position " << index << ", " << chainIndex << endl;
                //collisionCount = 1;
                return true;
            }
            curr = curr->getNext();  
            //collisionCount = 1;
        }
    
        return false;
    }      

    bool deleteSymbol(string symbol){
        int index;
        switch(hashChoice) {
            case 1: index = SDBMHash(symbol); break;
            case 2: index = BKDRHash(symbol); break;
            case 3: index = djb2(symbol); break;
            case 4: index = FNV1aHash(symbol); break;
            default:
                cout << "Invalid hash choice. Defaulting to SDBMHash\n";
                index = SDBMHash(symbol);
        }
        index %= bucketCount;

        chainIndex = 0;

        SymbolInfo* curr = symbols[index];
        SymbolInfo* prev = nullptr;

        while(curr != nullptr){
            if(curr->equal(symbol)){
                if(prev == nullptr){
                    symbols[index] = curr->getNext();
                }

                else{
                    prev->setNext(curr->getNext());
                }

                cout<<"\tDeleted '"<<curr->getName()<<"' from ScopeTable# "<<tableId<<" at position "<<index<<", "<<chainIndex<<endl;
                delete curr;
                return true;
            }

            prev = curr;
            curr = curr->getNext();
            chainIndex += 1;
        }

        cout<<"\tNot found in the current ScopeTable"<<endl;
        return false;
    }

    SymbolInfo* lookUp(std::ostream& out, string symbol){
        int index;
        switch(hashChoice) {
            case 1: index = SDBMHash(symbol); break;
            case 2: index = BKDRHash(symbol); break;
            case 3: index = djb2(symbol); break;
            case 4: index = FNV1aHash(symbol); break;
            default:
                cout << "Invalid hash choice. Defaulting to SDBMHash\n";
                index = SDBMHash(symbol);
        }
        index %= bucketCount;

        SymbolInfo* curr = symbols[index];
        chainIndex = 0;

        while(curr != nullptr){
            if(curr->equal(symbol)){
                cout<<"\t'"<<curr->getName()<<"' found in ScopeTable# "<<tableId<<" at position "<<index<<", "<<chainIndex<<"\n\n";
                //out<<"ScopeTable# "<<tableId<<" at position "<<index<<", "<<chainIndex<<endl;
                return curr;
            }

            curr = curr->getNext();
            chainIndex += 1;
        }

        return curr;
    }

    SymbolInfo* lookupWithPosition(const string& symbol, int& outIndex, int& outChainIndex) {
        int index;
        switch(hashChoice) {
            case 1: index = SDBMHash(symbol); break;
            case 2: index = BKDRHash(symbol); break;
            case 3: index = djb2(symbol); break;
            case 4: index = FNV1aHash(symbol); break;
            default:
                cout << "Invalid hash choice. Defaulting to SDBMHash\n";
                index = SDBMHash(symbol);
        }
        index %= bucketCount;

        SymbolInfo* curr = symbols[index];
        int chainIdx = 0;
        while (curr != nullptr) {
            if (curr->equal(symbol)) {
                outIndex = index;
                outChainIndex = chainIdx;
                return curr;
            }
            curr = curr->getNext();
            chainIdx++;
        }
        return nullptr;
    }
    
    // Your existing hash functions and insert/delete/lookUp methods unchanged...

    // Recursive print: print all child scopes first, then this scope
    // void printScopeTableHierarchy(std::ostream& out, int indentLevel = 0) {
    //     ScopeTable* child = firstChild;
    //     while (child != nullptr) {
    //         child->printScopeTableHierarchy(out, indentLevel);
    //         child = child->nextSibling;
    //     }
    //     print(out, indentLevel);
    // }

    // // Print the current scope's symbol table (non-empty buckets only)
    // void print(std::ostream& out, int indentLevel = 0) {
    //     //string indent(indentLevel * 4, ' ');
    //     out << "ScopeTable # " << tableId << endl;

    //     for (int i = 0; i < bucketCount; i++) {
    //         SymbolInfo* currSymbol = symbols[i];
    //         if (currSymbol == nullptr) continue;  // skip empty buckets

    //         out << i << " --> ";
    //         while (currSymbol != nullptr) {
    //             out << "< " << currSymbol->getName() << " : " << currSymbol->getType() << " >";
    //             currSymbol = currSymbol->getNext();
    //         }
    //         out << endl;
    //     }
    // }
    void printScopeTableHierarchy(std::ostream& out, int indentLevel = 0) {
        ScopeTable* child = firstChild;
        while (child != nullptr) {
            child->printScopeTableHierarchy(out, indentLevel + 1);  // Increment indent for child
            child = child->nextSibling;
        }
        print(out, indentLevel);
    }
    
    void print(std::ostream& out, int indentLevel = 0) {
        out <<  "ScopeTable # " << tableId << endl;
    
        for (int i = 0; i < bucketCount; i++) {
            SymbolInfo* currSymbol = symbols[i];
            if (currSymbol == nullptr) continue;
    
            out << i << " --> ";
            string printType = currSymbol->getType();
            while (currSymbol != nullptr) {
                if(currSymbol->getType() == "INT" || currSymbol->getType() == "FLOAT" || currSymbol->getType() == "ARRAY" || currSymbol->getType() == "void" || currSymbol->getType() == "FUNCTION") {
                    printType = "ID";
                }
                out << "< " << currSymbol->getName() << " : " << printType << " >";
                currSymbol = currSymbol->getNext();
            }
            out << endl;
        }
    }
    
    

    ~ScopeTable() {
        for (int i = 0; i < bucketCount; i++) {
            SymbolInfo* curr = symbols[i];
            while (curr != nullptr) {
                SymbolInfo* next = curr->getNext();
                delete curr;
                curr = next;
            }
        }
        delete[] symbols;

        ScopeTable* child = firstChild;
        while (child != nullptr) {
            ScopeTable* nextChild = child->nextSibling;
            delete child;
            child = nextChild;
        }
    }
};

