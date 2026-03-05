#include <iostream>
#include <string>
#include <climits>
#include "Recur15.h"
std::string s;
int pos = 0;
int Reading() { // ф-я для чтения 1 символа (числа)
	return s[pos++] - '0'; 
}
int Term() {
	int number = Reading();
	if (pos < s.size() && s[pos] == '*') {
		pos++;
		return number * Term();
	}
	return number;
}

int Expression(int number = INT_MIN) {
	if (number == INT_MIN) {
		number = Term();
	}
	if (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) {
		char operand = s[pos++];
		int new_term = Term();
		int new_number = number;
		if (operand == '+') {
			new_number += new_term;
		}
		else {
			new_number -= new_term;
		}
		return Expression(new_number);
	}
	return number;
}
void Recur15() {
	std::cout << "Задание Recur15" << std::endl;
	std::cout << "Введите ваше выражение: ";
	std::cin >> s;
	pos = 0;
	std::cout << "Результат: " << Expression() << std::endl;
}