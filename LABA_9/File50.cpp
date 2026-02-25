#include <iostream>
#include <fstream>
#include <string>
#include "File50.h"
#include "WorkWithFiles.h"
void File50() {
	std::cout << "Задание File50" << std::endl;
	std::string file_name_one = PromptForFileName();
	std::string file_name_two = PromptForFileName();
	std::string file_name_three = PromptForFileName();
	std::ifstream file_one;
	file_one.open(file_name_one, std::ios::in | std::ios::binary);
	std::ifstream file_two;
	file_two.open(file_name_two, std::ios::in | std::ios::binary);
	std::ofstream file_three;
	file_three.open(file_name_three, std::ios::out | std::ios::binary);
	double number_one;
	while (file_one.read((char*)&number_one, sizeof(double))) {
		file_three.write((char*)&number_one, sizeof(double));
	}
	file_one.close();
	double number_two;
	while (file_two.read((char*)&number_two, sizeof(double))) {
		file_three.write((char*)&number_two, sizeof(double));
	}
	file_two.close();
	file_three.close();
	std::cout << "Программа выполнена, можете проверить содержимое файла через пункт 6 в меню" << std::endl;
}
