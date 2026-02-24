#include <iostream>
#include <vector>
#include <fstream>
#include "Backrec5.h"
void BackRec5() {
	std::cout << "Задание: BackRec5" << std::endl;
	CreateMass();
}
void CreateMass() {
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
	int max_weight, n;//размер рюкзака и количество предметов 
	file >> n >> max_weight;
	std::vector <int> weight(n + 1);
	std::vector <int> prices(n + 1);
	weight[0] = 0; 
	prices[0] = 0;
	for (int i = 1; i <= n; i++) {
		file >> weight[i];
	}
	for (int i = 1; i <= n; i++) {
		file >> prices[i];
	}
	std::cout << "Размер рюкзака: " << max_weight << std::endl;
	std::cout << "Кол-во предметов: " << n << std::endl;
	std::cout << "Веса: ";
	for (int i = 1; i < n + 1; i++) {
		std::cout << weight[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Цены: ";
	for (int i = 1; i < n + 1; i++) {
		std::cout << prices[i] << " ";
	}	
	std::cout << std::endl;
	Algorithm(weight, prices, max_weight, n);
}
void Algorithm(std::vector <int> w, std::vector <int> p, int max_weight, int n) {
	std::cout << "Запуск алгоритма..." << std::endl;
	std::vector <std::vector <int>> a(n + 1, std::vector<int>(max_weight + 1, 0));//создаем таблицу динам. прог.
	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= max_weight; s++) {//проходим по таблице динам. прог.
			if (s >= w[k]) {
				a[k][s] = std::max(a[k - 1][s], a[k - 1][s - w[k]] + p[k]);//взять или нет предмет
			}
			else {
				a[k][s] = a[k - 1][s];//пропускаем предмет
			}
		}
	}
	int current_weight = max_weight;
	std::vector <int> selected_items;
	for (int k = n; k >= 1; k--) {
		if (current_weight >= w[k] && a[k][current_weight] == a[k - 1][current_weight - w[k]] + p[k]) {//предмет помещается и был взят
			selected_items.push_back(k);
			current_weight -= w[k];
		}
	}
	std::cout << "Общая ценность: " << a[n][max_weight] << std::endl;
	std::cout << "Итоговая масса: " << max_weight - current_weight << std::endl;
	std::cout << "Номера выбранных предметов: ";
	for (int i = 0; i < selected_items.size(); i++) {
		std::cout << selected_items[i] << " ";
	}
	std::cout << std::endl;

}

