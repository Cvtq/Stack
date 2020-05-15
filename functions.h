#pragma once
#include <iostream>
#include <string>
#include "stack.h"
#include "Calculator.h"

using namespace std;

void calculator() {
	string expression;
	bool expressionIsCorrect = false;

	do {
		system("cls");
		expressionIsCorrect = false;

		cout << "Введите выражение (обратная польская нотация): ";
		std::cin.clear();		
		fflush(stdin);
		getline(cin, expression);		
		getline(cin, expression);
		system("cls");
		cout << "Вы ввели: " << expression << " Это корректное выражение?" << endl;
		cout << "Введите ответ (1 или 0): ";
		cin >> expressionIsCorrect;
	} while (!expressionIsCorrect);

	system("cls");

	cout << expression << " = " << Calculator::Calculate(expression) << endl;
	system("pause");
}


void numbers() {
	
	long num; // десятичное число
	int base; // основание
	cout << "Введите неотрицательное десятичное число и основание " << "(2 <= основание <= 9): ";
	cin >> num >> base;
	cout << num << " основание " << base << " = ";

	Stack<long> S;
	
	do
	{
		S.Push(int(num % base));
		num /= base;
	} while (num != 0);

	while (!S.stackEmpty())
		cout << S.Pop();

	system("pause");
}

void palindroms() {

	std::cin.clear();
	fflush(stdin);

	Stack<char> stack;
	cout << "Введите слово: " << endl;
	string word;
	getline(cin, word);
	getline(cin, word);
	
	for (char c : word) {
		stack.Push(c);
	}

	size_t i = 0;
	while (stack.Pop() == word[i]) {
		if (i != word.size() - 1) {
			i++;
		}
		else {
			break;
		}		
	}

	if (i == word.size() - 1) {
		cout << "Вы ввели палиндром" << endl;
	}
	else {
		cout << "Вы ввели НЕ палиндром" << endl;
	}

	system("pause");
}