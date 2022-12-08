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
    Symbol(){}
    Symbol(GlobalSymbs* D,string &name, Types &type, string &value)
    {
        type = type;
        name = name;
        value = value;
        offset = D->getOffset();
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
        static int in_while;
        GlobalSymbs();
        ~GlobalSymbs() = default;
        bool isExist(string id);
        void addSymbol(Types type, string &value, string &name);
        void enterWhile();//implement
        void exitWhile();//implement
        void openScope();//implement
        void closeScope();//implement
        int getOffset();//implement
};

#endif /*GLOB_SYMBS*/