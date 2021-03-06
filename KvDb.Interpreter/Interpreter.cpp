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
		return new KvToken(KvTokenKind::EndOfFile, _position, "\0");

	auto c = _source->at(_position);
	if (isspace(c))
	{
		auto start = _position++;
		while (_position < _source->size() && isspace(_source->at(_position)))
			_position++;
		return new KvToken(KvTokenKind::Space, start, _source->substr(start, _position - start));
	}
	else if (isdigit(c))
	{
		auto start = _position++;
		while (_position < _source->size() && isdigit(_source->at(_position)))
			_position++;
		return new KvToken(KvTokenKind::Number, start, _source->substr(start, _position - start));
	}
	else if (c == '+')
	{
		return new KvToken(KvTokenKind::Plus, _position++, "+");
	}
	else if (c == '-')
	{
		return new KvToken(KvTokenKind::Minus, _position++, "-");
	}
	else if (c == '*')
	{
		return new KvToken(KvTokenKind::Multiply, _position++, "*");
	}
	else if (c == '/')
	{
		return new KvToken(KvTokenKind::Divide, _position++, "/");
	}
	else if (c == '(')
	{
		return new KvToken(KvTokenKind::OpenParen, _position++, "(");
	}
	else if (c == ')')
	{
		return new KvToken(KvTokenKind::CloseParen, _position++, ")");
	}
	else
	{
		std::cout << "Unknown character '" << c << "' at position: " << (_position + 1) << std::endl;
		return new KvToken(KvTokenKind::Invalid, _position++, _source->substr(_position - 1, 1));
	}
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
	if (!input)
		return;

	auto istr = std::string(input);
	if (istr.size() == 0)
		return;

	auto tokens = std::vector<std::unique_ptr<KvToken>>();
	auto lexer = new KvLexer(istr);

	KvToken *lastToken = nullptr;
	do
	{
		lastToken = lexer->Lex();
		if (!lastToken)
			throw std::string("There was a major issue");

		tokens.push_back(std::unique_ptr<KvToken>(lastToken));
	} while (lastToken->Kind() != KvTokenKind::EndOfFile);

	for (std::vector<std::unique_ptr<KvToken>>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		auto token = it->get();
		std::cout << "Token Kind: " << token->Kind()
			<< "; Length: " << token->Length()
			<< "; Start: " << token->StartPosition()
			<< std::endl;
	}

	delete lexer;
}