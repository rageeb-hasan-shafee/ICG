#pragma once;
#include "2105175_Scope_Table.hpp"

class SymbolTable {
    ScopeTable* currTable;
    int currTableID;
    int bucketCount;
    int numOfTables;

public:
    SymbolTable(int bucketCount)
        : currTable(new ScopeTable(bucketCount, "1", nullptr)),
          currTableID(1),
          bucketCount(bucketCount),
          numOfTables(1) {
        cout << "\tScopeTable# 1 created\n";
    }

    ScopeTable* getCurrentScope() { return currTable; }
    int getCurrentScopeID() { return currTableID; }

    void enterScope() {
        if (!currTable) return;
    
        int childIndex = currTable->getChildCount() + 1;
        string newId = currTable->getTableID() + "." + to_string(childIndex);
    
        ScopeTable* newTable = new ScopeTable(bucketCount, newId, currTable);
    
        currTable->addChildScope(newTable);
    
        currTable = newTable;
    
        cout << "\tScopeTable# " << newId << " created\n";
    }

    void unlinkCurrentScopeFromParent() {
        ScopeTable* parent = currTable->getParentScope();
        if (!parent) return;
    
        ScopeTable* prev = nullptr;
        ScopeTable* currChild = parent->firstChild;
    
        while (currChild && currChild != currTable) {
            prev = currChild;
            currChild = currChild->nextSibling;
        }
    
        if (!currChild) return;  
    
        if (prev == nullptr) {
            parent->firstChild = currTable->nextSibling;
        } else {
            prev->nextSibling = currTable->nextSibling;
        }
        currTable->nextSibling = nullptr;
    }

    void exitScope() {
        if (!currTable) return;
    
        if (currTable->getParentScope() == nullptr) {
            cout << "\tRoot scope cannot be removed\n";
            return;
        }
    
        cout << "\tScopeTable# " << currTable->getTableID() << " removed\n";
    
        unlinkCurrentScopeFromParent();
    
        ScopeTable* temp = currTable;
        currTable = currTable->getParentScope();
    
        delete temp;
    }
 

    bool insert(SymbolInfo* symbol) {
        if (currTable != nullptr) {
            return currTable->insert(symbol);
        }
        return false;
    }

    

    bool remove(const string& symbol) {
        return currTable ? currTable->deleteSymbol(symbol) : false;
    }

    SymbolInfo* lookup(std::ostream& out, const string& symbol) {
        if (!currTable) return nullptr;

        SymbolInfo* temp = currTable->lookUp(out, symbol);
        ScopeTable* tempTable = currTable->getParentScope();

        while (temp == nullptr && tempTable != nullptr) {
            temp = tempTable->lookUp(out, symbol);
            tempTable = tempTable->getParentScope();
        }

        if (temp == nullptr) {
            cout << "\t'" << symbol << "' not found in any ScopeTable\n";
            out << "\t'" << symbol << "' not found in any ScopeTable\n";
        }
        return temp;
    }

    InsertResult lookupWithPosition(const std::string& symbol) {
        InsertResult result;
        ScopeTable* scope = currTable;
    
        while (scope != nullptr) {
            int idx = -1, chainIdx = -1;
            SymbolInfo* found = scope->lookupWithPosition(symbol, idx, chainIdx);
    
            if (found != nullptr) {
                result.found = true;
                result.scopeInfo = scope->getTableID() + " at position " + to_string(idx) + ", " + to_string(chainIdx);
                return result;
            }
    
            scope = scope->getParentScope();
        }
        return result;
    }
    

    void printAllScopes(std::ostream& out) {
        if (currTable) {
            ScopeTable* root = currTable;
            while (root->getParentScope() != nullptr) {
                root = root->getParentScope();
            }
            root->printScopeTableHierarchy(out);
        }
    }

    ~SymbolTable() {
        if (currTable) {
            ScopeTable* root = currTable;
            while (root->getParentScope() != nullptr) {
                root = root->getParentScope();
            }
            cout << "\tScopeTable# " << root->getTableID() << " removed\n";
            delete root;
            currTable = nullptr;
        }
    }
};
