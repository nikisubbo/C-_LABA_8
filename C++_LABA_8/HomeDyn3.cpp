#include <iostream>
#include "Header.h"
#include <fstream>
#include <vector>
#include <string>
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
	std::fstream file("KING_INPUT.txt");
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
	std::string moves = "";
	int current_index_r_1 = size_r - 1;
	int current_index_r_2 = size_r - 2;
	int current_index_c_1 = size_c - 2;
	int current_index_c_2 = size_c - 1;
	int summa = field[size_r - 1][size_c - 1];
	bool flag = true;
	while (flag) {
		if ((current_index_r_1 < 0 || current_index_c_1 < 0) && (current_index_r_2 < 0 || current_index_c_2 < 0)) {
			break;
		}
		int left_number;
		int up_number;
		if (current_index_r_1 < 0 || current_index_c_1 < 0) {
			left_number = -1;
			up_number = field[current_index_r_2][current_index_c_2];
		}
		else if (current_index_r_2 < 0 || current_index_c_2 < 0) {
			up_number = -1;
			left_number = field[current_index_r_1][current_index_c_1];
		}
		else {
			left_number = field[current_index_r_1][current_index_c_1];
			up_number = field[current_index_r_2][current_index_c_2];
		}

		if (left_number > up_number) {
			moves += "L ";
			summa += left_number;
			field[current_index_r_1][current_index_c_1] = summa;
			current_index_c_1--;
			current_index_c_2--;
		}
		else if (left_number < up_number) {
			moves += "U ";
			summa += up_number;
			field[current_index_r_2][current_index_c_2] = summa;
			current_index_r_1--;
			current_index_r_2--;
		}
		else {
			if (field[current_index_r_1][current_index_c_1 - 1] > field[current_index_r_2][current_index_c_2 - 1]) {
				moves += "L ";
				summa += left_number;
				field[current_index_r_1][current_index_c_1] = summa;
				current_index_c_1--;
				current_index_c_2--;
			}
			else {
				moves += "U ";
				summa += up_number;
				field[current_index_r_2][current_index_c_2] = summa;
				current_index_r_1--;
				current_index_r_2--;
			}
		}
	}
	std::fstream file_output("KING_OUTPUT.txt");
	file_output << summa << std::endl;
	file_output << moves;
	file_output.close();
}