#ifndef _PARSER_H
#define _PARSER_H
#include <vector>
#include "hw3_output.hpp"
extern int yylineno;
using namespace output;
using namespace std;
#include <list>

enum Types
{
    TYPE_UNDEFINED,
    TYPE_VOID,
    TYPE_BOOL,
    TYPE_BYTE,
    TYPE_INT, 
    TYPE_STRING
};


class Node
{
public:
    string value;
    Types type;

    Node(Types type):type(type){};
};

#define YYSTYPE Node*

class Expression: public Node
{
public:
    Expression(Types type):Node(type){};
};
class ExpressionList: public Node
{
public:
    std::list<Expression*> exp_list;
    ExpressionList():Node(TYPE_UNDEFINED){};
    void addExpression(Expression* exp){
        exp_list.emplace_back(exp);
        std::list<Expression*>::iterator<Expression*> ite;
        for (ite = exp_list.begin(); ite != exp_list.end(); ++ite) {
            if((*ite)->value == exp->value){
                //error formal already in function
            }
        }
    }

};
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
};
/*Statement(Type *t, string id_val)
{
    Symbol *symbol = new Symbol();
    symbol->type = ;
    symbol->value = id_val;
    //DS->addSymbol(symbol, id_val);
};*/
#endif //_PARSER_H