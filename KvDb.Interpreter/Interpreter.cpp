// KvDb.Interpreter.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Interpreter.h"

KvInterpreter::KvInterpreter()
{
}

KvInterpreter::~KvInterpreter()
{	
}

void KvInterpreter::Parse(std::string const& input)
{
	// Copy the input to keep for later... I think.
	this->_input = std::string(input.c_str());
	
	bool lastWasSpace = false;
	for (int i = 0; i < this->_input.size(); i++)
	{
		char c = this->_input[i];
		if (isdigit(c))
		{

		}
		else if (isspace(c) && !lastWasSpace)
		{

		}
		else
		{
			switch (c)
			{
			case '+':
				break;
			case '-':
				break;
			case '*':
				break;
			case '/':
				break;
			default:
				std::cout << "Unknown character '" << c << "'" << std::endl;
				break;
			}
		}
	}
}