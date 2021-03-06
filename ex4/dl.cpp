﻿#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <list>

#include "exp.cpp"
#include "read.cpp"


int main(){
	std::ifstream inf;
	inf.open("input.txt", std::ios::in);
	
	std::queue<Token*> phrase = getPhrase(inf);
	
	inf.close();
	
	Expression* e;
	try{
		e = makeExpression(phrase);
	}catch (const char* s){
		std::cerr<<s;
		return 0;
	}

	//e->print(std::cout);
	
	std::ofstream of;
	of.open("output.txt", std::ios::out);
	
	try{
		Expression* e_new = e->eval();
		e_new->print(of);
	} catch (const char* s) {
		of<<"ERROR";
		std::cerr<<s;
	}
	
	of.close();
	
	return 0;
}

