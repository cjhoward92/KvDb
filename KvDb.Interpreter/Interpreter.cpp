// KvDb.Interpreter.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Interpreter.h"

// └──
// ├──
// │

// KvToken
KvToken::KvToken(KvTokenKind kind, int start, std::string const& token)
{
	this->_kind = kind;
	this->_start = start;
	this->_length = token.size();
	this->_token = new std::string(token.c_str());
}

KvToken::~KvToken()
{
	this->_start = -1;
	this->_length = -1;
	delete this->_token;
}

KvTokenKind KvToken::Kind() const
{
	return this->_kind;
}

int KvToken::StartPosition() const
{
	return this->_start;
}

int KvToken::Length() const
{
	return this->_length;
}

const std::string * KvToken::Token() const
{
	return this->_token;
}
// End KvToken


KvInterpreter::KvInterpreter()
{
	this->_input = nullptr;
}

KvInterpreter::~KvInterpreter()
{
	if (this->_input)
		delete this->_input;
}

void KvInterpreter::Interpret(const char *input)
{
	this->_input = new std::string(input);
	
	bool lastWasSpace = false;
	for (int i = 0; i < this->_input->size(); i++)
	{
		char c = this->_input->at(i);
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
				std::cout << "Unknown character '" << c << "' at position: " << (i + 1) << std::endl;
				break;
			}
		}
	}
}