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

void GlobalSymbs::addSymbol(Types type,string& name)
{
    if (isExist(name))
    {
        errorDef(yylineno, name);
    }
    this->symbolTables.back().getEntries().emplace_back(Symbol(symbol->value, symbol->type, value, this->offset.top(),false));//needs fix
    this->offset.top()++;
}

bool GlobalSymbs::checkInWhile()
{
    return in_while>0;
}

void GlobalSymbs::addFunction(string name, Types type)
{
    //create new Function with current_function_parameters
    //add to all_functions
    Function new_f(name, type);
    while(!current_function_parameters.empty())
    {
        new_f.add_symbol(current_function_parameters.pop_front());
    }
}
void GlobalSymbs::enterWhile()
{
    in_while++;
}
void GlobalSymbs::exitWhile()
{
    in_while--;
}
void GlobalSymbs::openScope()
{
    //add InnerSymbol entry to symbolTables
    //add int to offset stack(value should be equal to last value)
    InnerSymbs new_is();
    symbolTables.emplace_back(new_is);
    offset.emplace(offset.top());]
}
void GlobalSymbs::compareTypesAssignment(Types assigned_to, Types assigned_from){
    
}
void GlobalSymbs::closeScope()
{
    //remove last InnerSymbol entry
    //remove last in from offset stack
    symbolTables.pop_back().printAllSymbs();
    offset.pop();
}
void GlobalSymbs::addFormal(Types type, string name)
{
    //add Formal to current_function_parameters
    current_function_parameters.emplace_back(Symbol(this,name,type,false));

}
void GlobalSymbs::clearFormals()
{
    //empty current_function_parameters
    current_function_parameters.clear();
}
void GlobalSymbs::currentFunctionType(Types type)
{
    current_function_type=type;
}

void GlobalSymbs::comparesTypesCast(Types first,Types second)
{
    //check if second type can be cast into first type
    if(first==second) return;
    if(second==TYPE_BYTE && first==TYPE_INT) return;
    if(second==TYPE_INT && first==TYPE_BYTE) return;
    errorMismatch(yylineno);
    exit(0);
}
int GlobalSymbs::getOffset()
{
    return offset.top();
}
// add a function for "while" counter