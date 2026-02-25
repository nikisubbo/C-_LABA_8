#include <iostream>
#include <string>
#include <fstream>
#include "WorkWithFiles.h"	
std::string PromptForFileName() {
	std::cout << "Введите имя файла: ";
	std::string file_name;
	std::cin >> file_name;
	file_name = file_name + ".dat";
	return file_name;
}
void CreateFile() {
	std::string file_name;
	std::cout << "Введите название файла: ";
	std::cin >> file_name;
	file_name = file_name + ".dat";
	int n;
	std::fstream file;
	file.open(file_name, std::ios::out | std::ios::binary);
	std::cout << "Введите количество чисел, которые хотите записать в файл: ";
	std::cin >> n;
	std::cout << "Введите числа для записи через пробел: ";
	for (int i = 0; i < n; i++) {
		double number;
		std::cin >> number;
		file.write((char*)&number,sizeof(double));
	}
	std::cout << "Файл успешно создан" << std::endl;
}

void PrintFile() {
	std::string file_name;
	std::cout << "Введите название файла для вывода: ";
	std::cin >> file_name;
	file_name = file_name + ".dat";
	std::ifstream file;
	file.open(file_name, std::ios::in | std::ios::binary);
	while (!file.is_open()) {
		std::cout << "Ошибка! Такого файла с таким названием не существует.\n";
		std::cout << "Введите другое название файла: ";
		std::cin >> file_name;
		file_name = file_name + ".dat";
		file.clear();
		file.open(file_name, std::ios::in | std::ios::binary);
	}
	double number;
	std::cout << "Содержимое файла " << file_name << ": ";
	while (file.read((char*)&number, sizeof(double))) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
}