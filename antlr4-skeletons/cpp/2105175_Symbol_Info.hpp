#pragma once;
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//ofstream output("Myoutput.txt");

class SymbolInfo{
    string name;
    string type;
    SymbolInfo* next;

public:
    SymbolInfo(string name, string type) : name(name), type(type), next(nullptr){}

    void setName(string name){
        this -> name = name;
    }

    void setType(string type){
        this -> type = type;
    }

    void setNext(SymbolInfo* next){
        this -> next = next;
    }

    string getName(){
        return name;
    }

    string getType(){
        return type;
    }

    SymbolInfo* getNext(){
        return next;
    }

    bool equal(string symbol){
        if(this->name == symbol) return true;
        else return false;
    }


    ~SymbolInfo(){
        this -> next = nullptr;
    }
};