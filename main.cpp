#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdexcept>

namespace FanC
{

	void reduceProgram()
	{
	}

	void initProgramHeader()
	{
	}
	void reduceOpenScope()
	{
	}
	
	void addSymbol(Node *symbol, string &value)
{
    if (isExist(symbol->value))
    {
        errorDef(yylineno, symbol->value);
    }

    this->symbolTables.back().getEntries().emplace_back(TableEntry(symbol->value, vector<Var_Type>(1, symbol->type), value, this->offset.top(),false));
    this->offset.top()++;
}

}
