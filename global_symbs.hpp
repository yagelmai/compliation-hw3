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
    int offset;
    bool is_func;
    Symbol(){}
    Symbol(GlobalSymbs* D,string &name, Types &type, bool is_func)
    {
        type = type;
        name = name;
        is_func=is_func;
        offset = D->getOffset();
    }

    string &getName() { return this->name; }
    Types &getTypes() { return this->type; }
    int getOffset() { return this->offset; }
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

class Function
{
    vector<Symbol> symbols;
    public:
    string name;
    Types return_type;
    Function(string name,Types return_type):name(name),return_type(return_type){}
    void add_symbol(Symbol sym)
    {
        symbols.emplace_back(sym);//do we have to check if same name appears twice in formals?
    }
}

class GlobalSymbs
{
    public:
        std::list<InnerSymbs> symbolTables;
        std::stack<int> offset;
        std::list<Function> all_functions;
        static int in_while;
        std::list<
        GlobalSymbs();
        ~GlobalSymbs() = default;
        bool isExist(string id);
        void addSymbol(Types type, string &name);
        void addFunction(Types type);//implement
        void enterWhile();//implement
        void exitWhile();//implement
        void openScope();//implement
        void closeScope();//implement
        void addFormal(Types type, string name);//implemnt
        void clearFormals();//implement
        void currentFunctionType(Types type);//implement
        void checkInWhile();
        void addFormal(Types type, string id);
        void comparesTypesCast(Types first,Types second);
        int getOffset();//implement
};

#endif /*GLOB_SYMBS*/