#include "pch.h"
#include <iostream>
#include "Interpreter.h"
#include "Database.h"

int main()
{
    std::cout << "We are building an interpreter!\n"; 
	//KvInterpreter *interpreter = new KvInterpreter();
	auto db = new Database("C:\\Development");
	delete db;
	/*std::string input;
	std::getline(std::cin, input);
	interpreter->Interpret(input.c_str());
	std::cout << "We are done!\n";*/
}
