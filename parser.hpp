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
    TYPE_UNDEFINED,
    TYPE_VOID,
    TYPE_BYTE,
    TYPE_BOOL,
    TYPE_INT, 
    TYPE_STRING,
};


class Node
{
public:
    string value;
    Types type;

    Node();
    Node(string token_name) : value(token_name) {}
};

class Relop: public Node{};

class Id: public Node{};

class BooleanOperation: public Node{};

class RelationalOperation: public Node{};

class EqualityOperation: public Node{};

class Multiplicative: public Node{};

class Additive: public Node{};

class Number : public Node{};

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