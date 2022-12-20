#ifndef _PARSER_H
#define _PARSER_H
#include <vector>
#include <string>
#include <list>
extern int yylineno;
using namespace std;
#define YYSTYPE Node*

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
    std::string value;
    Types type;

    Node(Types type):type(type){};
    std::string getValue(){
        return value;
    }
};


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
        for(Expression* curr_exp : exp_list)
        {
            if(curr_exp->value == exp->value){
                //error formal already in function
            }
        }
    }

};
class Number : public Node
{
    public:
    int num;
    Number(Types type, string num_s):Node(type) {
        num=std::stoi(num_s);
    };
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