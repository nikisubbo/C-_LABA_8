#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "HomeDyn3.h"
void HomeDyn3() {
	std::cout << "Задание HomeDyn3" << std::endl;
	/*
	int size_r = 3; //строки
	int size_c = 4; //столбцы
	int matrix[100] = { 2, 5, 8, 9, 3, 4,  7, 1, 2, 3, 4, 5 };
	std::vector <std::vector < int >> field(size_r, std::vector <int>(size_c));// = { 2, 5, 8, 9, 3, 4,  7, 1, 2, 3, 4, 5 }
	for (int i = 0; i < size_r; i++) {
		for (int j = 0; j < size_c; j++) {
			field[i][j] = matrix[i * size_c + j];
		}
	}
	*/
	std::cout << "Введите название файла с входными данными: ";
	std::string file_name;
	std::cin >> file_name;
	file_name = file_name + ".txt";
	std::cout << file_name << " ";
	std::ifstream file(file_name);
	while (!file.is_open()) {
		std::cout << "Такого файла не существует или невозможно открыть" << std::endl;
		std::cout << "Введите название файла с входными данными: ";
		std::cin >> file_name;
		file_name = file_name + ".txt";
		file.open(file_name);
	}
	std::vector <int> vec;
	int number;
	while (file >> number) {
		vec.push_back(number);
	}
	int size_r, size_c;
	size_r = size_c = vec[0];
	vec.erase(vec.begin());
	std::vector <std::vector < int >> field(size_r, std::vector <int>(size_c));// = { 2, 5, 8, 9, 3, 4,  7, 1, 2, 3, 4, 5 }
	for (int i = 0; i < size_r; i++) {
		for (int j = 0; j < size_c; j++) {
			field[i][j] = vec[i * size_c + j];
		}
	}
	file.close();
	std::cout << "Поле: " << std::endl;
	for (int i = 0; i < size_r; i++) 
	{
		for (int j = 0; j < size_c; j++) 
			std::cout << field[i][j] << ' '; 
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::vector<std::vector<int>> d_field(size_r, std::vector<int>(size_c));
	for (int i = 0; i < size_r; i++) {
		for (int j = 0; j < size_c; j++) {
			if (i == 0 && j == 0) {
				d_field[i][j] = field[i][j];//частный случай конец
			}
			else if (i == 0) {
				d_field[i][j] = d_field[i][j - 1] + field[i][j];//частный случай последний столбец
			}
			else if (j == 0) {
				d_field[i][j] = d_field[i - 1][j] + field[i][j];//частный случай последняя строка
			}
			else {
				d_field[i][j] = std::max(d_field[i - 1][j], d_field[i][j - 1]) + field[i][j];//проверка на лучший выбор 
			}
		}
	}
	std::string moves = "";
	int current_index_r = size_r - 1;  
	int current_index_c = size_c - 1;
	int summa = d_field[current_index_r][current_index_c];//начало 
	while (current_index_r > 0 || current_index_c > 0) {
		if (current_index_r == 0) {//граниченое условие
			moves += "L ";
			current_index_c--;
		}
		else if (current_index_c == 0) {//граничное условие
			moves += "U ";
			current_index_r--;
		}
		else {
			if (d_field[current_index_r - 1][current_index_c] > d_field[current_index_r][current_index_c - 1]) {
				moves += "U ";
				current_index_r--;
			}
			else {
				moves += "L ";
				current_index_c--;
			}
		}
	}
	std::cout << "Введите название файла для вывода: ";
	std::string file_name_output;
	std::cin >> file_name_output;
	file_name_output = file_name_output + ".txt";
	std::cout << file_name_output << " ";
	std::ofstream file_output(file_name_output);
	file_output << summa << std::endl;
	file_output << moves;
	file_output.close();
}