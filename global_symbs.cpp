#include "global_symbs.hpp"

GlobalSymbs::GlobalSymbs()
{
    symbolTables = std::list<InnerSymbs>();
    offset = stack<int>();
    offset.push(0);
    in_while = 0;
}

bool GlobalSymbs::isExist(string id)
{
    for (InnerSymbs iner_symb : symbolTables)
    {
        for (Symbol symb : iner_symb.getEntries())
        {
            if (symb.getName().compare(id) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void GlobalSymbs::addSymbol(Types type, string &value,string& name)//check if symbol is function, if so add accordingly
{
    if (isExist(symbol->value))
    {
        errorDef(yylineno, symbol->value);
    }
    this->symbolTables.back().getEntries().emplace_back(Symbol(symbol->value, symbol->type, value, this->offset.top(),false));
    this->offset.top()++;
}
// add a function for "while" counter