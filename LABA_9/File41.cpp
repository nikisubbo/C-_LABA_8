#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "File41.h"
#include "WorkWithFiles.h"
void File41() {
	std::cout << "Задание File41" << std::endl;
	std::string file_name = PromptForFileName();
	std::fstream file;
	file.open(file_name, std::ios::in | std::ios::binary);
	std::vector <double> numbers_from_file;
	std::vector <double> numbers_for_file;
	double number;
	while (file.read((char*)&number, sizeof(double))) {
		numbers_from_file.push_back(number);
	}
	file.close();
	for (int i = 0; i < numbers_from_file.size(); i++) {
		if (numbers_from_file[i] > 0) {
			numbers_for_file.push_back(0);
			numbers_for_file.push_back(0);
			numbers_for_file.push_back(0);
		}
		else {
			numbers_for_file.push_back(numbers_from_file[i]);	
		}
	}
	file.open(file_name, std::ios::out | std::ios::binary);
	for (int i = 0; i < numbers_for_file.size(); i++) {
		file.write((char*)&numbers_for_file[i], sizeof(double));
	}

	std::cout << "Программа выполнена, можете проверить содержимое файла через пункт 6 в меню" << std::endl;
}
