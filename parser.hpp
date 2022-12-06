#ifndef _PARSER_H
#define _PARSER_H

#include <vector>
#include "hw3_output.hpp"
#include "global_symbs.hpp"
extern int yylineno;
using namespace output;
using namespace std;

#define YYSTYPE FanC::Node *

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
namespace FanC
{
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
    explicit Statement(GlobalSymbs* DS, Type *t, Node *symbol)
	{
		symbol->type = t->type;
		DS->addSymbol(symbol, "");
	}
};



}

#endif //_PARSER_H