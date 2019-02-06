// KvDb.Interpreter.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Interpreter.h"

// └──
// ├──
// │

// TODO: Move this to its own file
// KvToken
KvToken::KvToken(KvTokenKind kind, int start, std::string const& token)
{
	_kind = kind;
	_start = start;
	_length = static_cast<int>(token.size());
	_token = new std::string(token.c_str());
}

KvToken::~KvToken()
{
	_start = -1;
	_length = -1;
	delete _token;
}

KvTokenKind KvToken::Kind() const
{
	return _kind;
}

int KvToken::StartPosition() const
{
	return _start;
}

int KvToken::Length() const
{
	return _length;
}

const std::string * KvToken::Token() const
{
	return _token;
}
// End KvToken

// TODO: Move this to its own file
// KvLexer
KvLexer::KvLexer(std::string const& source)
{
	_source = new std::string(source.c_str());
}

KvLexer::~KvLexer()
{
	delete _source;
}

char KvLexer::Peek(int offset)
{
	auto position = _position + offset;

	if (position >= _source->size())
		return '\0';

	return _source->at(position);
}

char KvLexer::Current()
{
	return Peek(0);
}

char KvLexer::Lookahead()
{
	return Peek(1);
}

KvToken * KvLexer::Lex()
{
	// Should this be a nullptr or an EOF?
	if (_position >= _source->size())
		return new KvToken(KvTokenKind::EndOfFile, _position, std::string('\0'));

	switch (_source->at(_position))
	{
	default:
		break;
	}

	return nullptr;
}
// End KvLexer


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