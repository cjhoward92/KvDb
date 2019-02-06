#include "pch.h"
#include <iostream>
#include "Interpreter.h"

int main()
{
    std::cout << "We are building an interpreter!\n"; 
	KvInterpreter *interpreter = new KvInterpreter();

	std::string input;
	std::cin >> input;
	interpreter->Parse(input.c_str());
	std::cout << "We are done!\n";
}
