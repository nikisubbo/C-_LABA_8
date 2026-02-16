#include <iostream>
#include "Header.h"
#include <vector>
#include <fstream>
void BackRec5() {
	std::cout << "Задание: BackRec5" << std::endl;
	CreateMass();
}

void findAns(int a[100][100], int k, int s, std::vector <int> w){
	if (a[k][s] == 0)
		return;
	if (a[k - 1][s] == a[k][s])
		findAns(a, k - 1, s, w);
	else
	{
		std::cout << k << ' ';
		findAns(a, k - 1, s - w[k], w);
	}
}

void CreateMass() {
	std::cout << "Чтение из файла..." << std::endl;
	std::ifstream file("text.txt");
	std::vector <int> matrix;
	int number;
	while (file >> number) {
		matrix.push_back(number);
	}
	file.close();
	int max_weight = matrix[1];
	int n = matrix[0];//кол-во предметов 
	std::vector <int> weight(n + 1);
	std::vector <int> prices(n + 1);
	weight[0] = 0;
	prices[0] = 0;
	for (int i = 0; i < n; i++) {
		weight[i + 1] = matrix[i + 2];
		prices[i + 1] = matrix[i + n + 2];
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
	int a[100][100];
	for (int i = 0; i <= max_weight; i++)
		a[0][i] = 0;
	for (int i = 0; i <= n; i++)
		a[i][0] = 0;
	/*
	std::cout << "Массив a: ";
	for (int i = 0; i < max_weight; i++){
		for (int j = 0; j <= n; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/
	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= max_weight; s++) {
			if (s >= w[k]) {
				a[k][s] = std::max(a[k - 1][s], a[k - 1][s - w[k]] + p[k]);
			}
			else {
				a[k][s] = a[k - 1][s];
			}
		}
	}
	std::cout << "Ответ: " << a[n][max_weight] << " ";
	findAns(a, n, max_weight, w);
}

