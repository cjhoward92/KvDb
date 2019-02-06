#pragma once

#include <string>

#ifdef KVDBINTERPRETER_EXPORTS
#define KVDBEXPORT __declspec(dllexport)
#else
#define KVDBEXPORT __declspec(dllimport)
#endif

enum KvTokenKind
{
	EOL,
	Number,
	Plus,
	Minus,
	Multiply,
	Divide
};

class KvToken {
public:
	KvToken(KvTokenKind kind, int start, std::string const& token);
	~KvToken();

	KvTokenKind Kind() const;
	int StartPosition() const;
	int Length() const;
	const std::string * Token() const;

private:
	KvTokenKind _kind;
	int _start;
	int _length;
	std::string *_token;
};

class KvLexer {
public:
	KvLexer(std::string const& source);
	~KvLexer();

	KvToken * Lex();

	char Current();
	char Lookahead();

private:
	std::string *_source;
	int _position;

	char Peek(int offset);
};

class KVDBEXPORT KvInterpreter
{
public:
	KvInterpreter();
	~KvInterpreter();

	void Interpret(const char *input);

private:
	std::string *_input;
};