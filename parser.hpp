#ifndef _PARSER_H
#define _PARSER_H

#include <vector>
#include "hw3_output.hpp"
#include "global_symbs.hpp"
extern int yylineno;
using namespace output;
using namespace std;

#define YYSTYPE FanC::Node *

class Node
{
public:
    string value;
    Var_Type type;

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

class Statement : public Node
{
    // Tyte ID;
    explicit Statement(Type *t, Node *symbol)
	{
		symbol->type = t->type;
		sem->addSymbol(symbol, "");
	}
}

#endif //_PARSER_H