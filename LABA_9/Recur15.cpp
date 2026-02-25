#include <iostream>
#include <string>
#include "Recur15.h"
void Recur15() {
	std::cout << "Задание Recur15" << std::endl;
	std::string s;
	std::cin.ignore();
	std::cout << "Введите ваше выражение: ";
	std::getline(std::cin, s);
	std::cout << "Ваше выражение: " << s << std::endl;
	int position = 0;
	int number = s[position] - '0';
	position++;
}
int Recursive() {

}