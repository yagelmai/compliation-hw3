#include "parser.hpp"
#include "global_symbs.hpp"

GlobalSymbs *DS = new GlobalSymbs();

// Tyte ID;
Statement::Statement(Type *t, string id_val)
{
    symbol->type = t->type;
    symbol->value = id_val;
    DS->addSymbol(symbol, id_val);
}

Type::Type(Types v_type){
    type = v_type;
}


Number::Number(string value) : value(value)
{

}