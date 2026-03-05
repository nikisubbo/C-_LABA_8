#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "WorkWithFiles.h"	
std::string PromptForFileName() {
	std::cout << "Введите имя файла с расширением (.dat или .txt): ";
	std::string file_name;
	std::cin >> file_name;
	file_name = file_name;
	return file_name;
}
void CreateFile() {
	std::string file_name = PromptForFileName();
	std::fstream file;
	file.open(file_name, std::ios::out | std::ios::binary);
	int choice;
	std::cout << "Как вы хотите заполнить ваш ьинарный файл?\n1)Ввод с клавиатуры\n2)Рандомно\n3)Из TXT файла\nВыбор: ";
	std::cin >> choice;
	if (choice == 1) {
		int n;
		std::cout << "Введите количество чисел, которые хотите записать в файл: ";
		std::cin >> n;
		std::cout << "Введите числа для записи через пробел: ";
		for (int i = 0; i < n; i++) {
			double number;
			std::cin >> number;
			file.write((char*)&number, sizeof(double));
		}
	}
	else if (choice == 2) {
		srand(time(0));
		double number = rand() % 10;
		int n;
		std::cout << "Введите количество чисел, которые хотите записать в файл: ";
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			number = rand() % 10;
			file.write((char*)&number, sizeof(double));
		}
	}
	else if (choice == 3) {
		std::cout << "Введите название файла, c указанием расширения txt: ";
		std::string txt_file_name;
		std::cin >> txt_file_name;
		std::ifstream txt_file(txt_file_name);
		if (!txt_file.is_open()) {
			std::cout << "Ошибка. Такого файла не существует." << std::endl;
			return;
		}
		else {
			char number;
			while (txt_file.get(number)) {
				file.write((char*)&number, sizeof(char));
			}
		}
	}
	else {
		std::cout << "Неправильный ввод" << std::endl;
		return;
	}
	file.close();
	std::cout << "Файл успешно создан" << std::endl;
}

void PrintFile() {
	std::string file_name = PromptForFileName();
	std::ifstream file;
	file.open(file_name, std::ios::in | std::ios::binary);
	while (!file.is_open()) {
		std::cout << "Ошибка! Такого файла с таким названием не существует.\n";
		file_name = PromptForFileName();
		file.clear();
		file.open(file_name, std::ios::in | std::ios::binary);
	}
	double number;
	std::cout << "Содержимое файла " << file_name << ": ";
	while (file.read((char*)&number, sizeof(double))) {
		std::cout << number << " ";
	}
	file.close();
	std::cout << std::endl;
}