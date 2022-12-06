#ifndef _PARSER_H
#define _PARSER_H

#include <vector>
#include "hw3_output.hpp"
extern int yylineno;
using namespace output;
using namespace std;

#define YYSTYPE Node *

enum Types
{
    UNDEFINED,
    VOID,
    BYTE,
    BOOL,
    INT, 
    STRING,
};


class Node
{
public:
    string value;
    Types type;

    Node();
    Node(string token_name) : value(token_name) {}
};

class Relop;

class Id;

class BooleanOperation;

class RelationalOperation;

class EqualityOperation;

class Multiplicative;

class Additive;

class Number;

class Type : public Node
{
public:
explicit Type(Type *t);
explicit Type(Types v_type);
};

class Statement : public Node
{
// Tyte ID;
explicit Statement(Type *t, Node *symbol);
};
#endif //_PARSER_H