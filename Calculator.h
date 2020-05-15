#pragma once
#include <string>

using namespace std;

class Calculator
{

public:
	static bool IsDelimeter(char c);
	static  double Calculate(string input);

private:
	static bool IsOperator(char ñ);
	static size_t GetPriority(char s);
	static string GetExpression(string input);
	static double Counting(string input);
};