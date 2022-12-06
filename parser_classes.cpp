#include "parser.hpp"
#include "global_symbs.hpp"

GlobalSymbs *DS = new GlobalSymbs();

// Tyte ID;
Statement::Statement(Type *t, Node *symbol)
{
    symbol->type = t->type;
    string tmp = "";
    DS->addSymbol(symbol, tmp);
}