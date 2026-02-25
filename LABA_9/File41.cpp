#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "File41.h"
#include "WorkWithFiles.h"
void File41() {
	std::cout << "Задание File41" << std::endl;
	std::string file_name = PromptForFileName();
	std::ifstream file_in;
	file_in.open(file_name, std::ios::in | std::ios::binary);
	double number;
	std::vector <double> numbers_file;
	while (file_in.read((char*)&number, sizeof(double))) {
		numbers_file.push_back(number);
	}
	file_in.close();
	for (int i = 0; i < numbers_file.size(); i++) {
		if (numbers_file[i] >= 0) {
			numbers_file[i] = 0;
		}
	}
	std::ofstream file_out;
	file_out.open(file_name, std::ios::out | std::ios::binary);
	for (int i = 0; i < numbers_file.size(); i++) {
		file_out.write((char*)&numbers_file[i], sizeof(double));
	}
	std::cout << "Программа выполнена, можете проверить содержимое файла через пункт 6 в меню" << std::endl;
}