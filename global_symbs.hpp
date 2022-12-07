#ifndef GLOB_SYMBS
#define GLOB_SYMBS

#include <vector>
#include <string>
#include <list>
#include <stack>
#include "hw3_output.hpp"
#include "parser.hpp"

class Symbol
{
    public:
    string name;
    Types type;
    string value;
    int offset;
    bool isFunc;
    Symbol();
    Symbol(string &name, Types &type, string &value, int offset, bool isFunc)
    {
        type = type;
        name = name;
        value = value;
        isFunc = isFunc;
        offset = offset;
    }

    string &getName() { return this->name; }
    Types &getTypes() { return this->type; }
    int getOffset() { return this->offset; }
    string &getValue() { return this->value; }
    void setValue(string value) { this->value = value; }
    //void addSymbol
};


class InnerSymbs
{
    vector<Symbol> symbols;

public:
    InnerSymbs()
    {
        symbols = vector<Symbol>();
    }

    vector<Symbol> &getEntries()
    {
        return this->symbols;
    }
};


class GlobalSymbs
{
    public:
        std::list<InnerSymbs> symbolTables;
        std::stack<int> offset;
        static bool in_while;

        
        GlobalSymbs();
        ~GlobalSymbs() = default;
        bool isExist(string id);
        void addSymbol(Node *symbol, string &value);
};

#endif /*GLOB_SYMBS*/