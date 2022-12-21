#include "global_symbs.hpp"

GlobalSymbs::GlobalSymbs()
{
    symbolTables = std::list<InnerSymbs>();
    offset = stack<int>();
    offset.push(0);
    in_while = 0;
}

bool GlobalSymbs::isExist(std::string id)
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
void GlobalSymbs::checkVariables(std::string id, ExpressionList* El)
{
    
}
void GlobalSymbs::checkFunctionType(Types type)
{
    
}
void GlobalSymbs::checkIfBool(Types type)
{
    
}
void GlobalSymbs::addSymbol(Types type,std::string name)
{
    if (isExist(name))
    {
        output::errorDef(yylineno, name);
        exit(0);
    }
    this->symbolTables.back().getEntries().emplace_back(Symbol(name, type, false,this->getOffset()));//needs fix
    this->offset.top()++;
    std::cout<<"symbol " << name << "added"<< std::endl;
}

bool GlobalSymbs::checkInWhile()
{
    return in_while>0;
}

Types GlobalSymbs::getVarType(std::string id){
    for (InnerSymbs iner_symb : symbolTables)
    {
        for (Symbol symb : iner_symb.getEntries())
        {
            if (symb.getName().compare(id) == 0)
            {
                return symb.type;
            }
        }
    }
    return TYPE_UNDEFINED;
}

Types GlobalSymbs::getFunctionType(std::string id){
    for(Function fun: this->all_functions)
    {
        if(fun.name==id)
        {
            return fun.return_type;
        }
    }
    return TYPE_UNDEFINED;
}

void GlobalSymbs::addFunction(std::string name, Types type)
{
    //create new Function with current_function_parameters
    //add to all_functions
    Function new_f(name, type);
    while(!current_function_parameters.empty())
    {
        new_f.add_symbol(current_function_parameters.front());
        current_function_parameters.pop_front();
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
    InnerSymbs new_is;
    symbolTables.emplace_back(new_is);
    offset.emplace(offset.top());
}
void GlobalSymbs::compareTypesAssignment(Types assigned_to, Types assigned_from){

}
void GlobalSymbs::closeScope()
{
    //remove last InnerSymbol entry
    //remove last in from offset stack
    symbolTables.back().printAllSymbs();
    symbolTables.pop_back();
    offset.pop();
}
void GlobalSymbs::addFormal(Types type, std::string name)
{
    //add Formal to current_function_parameters
    Symbol new_s(name, type, false,this->symbolTables.back().getEntries().back().getOffset()-1);
    this->symbolTables.back().getEntries().emplace_back(new_s);
    current_function_parameters.emplace_back(new_s);

}
void GlobalSymbs::clearFormals()
{
    //empty current_function_parameters
    /*current_function_parameters.clear();
    while(this->symbolTables.back().getEntries().empty() && this->symbolTables.back().getEntries().back().getOffset()<0)
    {
        this->symbolTables.back().getEntries().pop_back();
    }*/
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
    output::errorMismatch(yylineno);
    exit(0);
}
int GlobalSymbs::getOffset()
{
    return offset.top();
}
void GlobalSymbs::printFunctions()
{
    /*for(Function fun: this->all_functions)
    {
        vector<std::string> argtypes;
        for(Symbol sym: fun.symbols){
            argtypes.emplace_back(this->typeToString(sym.type));
        }
        output::printID(fun.name,0,output::makeFunctionType(this->typeToString(fun.return_type),argtypes));
    }*/
}
string GlobalSymbs::typeToString(Types type){
    switch(type){
            case TYPE_BOOL: return "BOOL";
            case TYPE_BYTE: return "BYTE";
            case TYPE_INT: return "INT";
            case TYPE_STRING: return "STRING";
            default: return "ERROR";
        }
}
// add a function for "while" counter