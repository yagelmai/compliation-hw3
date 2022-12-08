#ifndef _PARSER_H
#define _PARSER_H
#include <vector>
#include "hw3_output.hpp"
#include "global_symbs.hpp"
extern int yylineno;
using namespace output;
using namespace std;


enum Types
{
    TYPE_UNDEFINED,
    TYPE_VOID,
    TYPE_BYTE,
    TYPE_BOOL,
    TYPE_INT, 
    TYPE_STRING,
    TYPE_FUNCTION
};


class Node
{
public:
    string value;
    Types type;

    Node(Types type):type(type){};
};

class Relop: public Node{};

class Id: public Node{};

class BooleanOperation: public Node{};

class RelationalOperation: public Node{};

class EqualityOperation: public Node{};

class Multiplicative: public Node{};

class Additive: public Node{};

class Number : public Node
{
    Number(Types type):Node(type) {};
};

class Type : public Node
{
public:
Type(Types v_type):Node(v_type){};
};

class Statement : public Node
{
// Tyte ID;
public:
Statement(Type *t, string id_val)
{
    Symbol *symbol = new Symbol();
    symbol->type = t->type;
    symbol->value = id_val;
    //DS->addSymbol(symbol, id_val);
}
};
#endif //_PARSER_H