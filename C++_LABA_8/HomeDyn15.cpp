#include <iostream>
#include "Header.h"
void HomeDyn15() {
	std::cout << "Задание: HomeDyn15" << std::endl;
	int k, n;
	bool flag = true;
	do {
		std::cout << "Введите основание системы счисления: ";
		std::cin >> k;
		if (k >= 2 && k <= 10) {
			std::cout << "Введите разряд N: ";
			std::cin >> n;
			if ((n > 1 && n < 20) && (n + k < 26)) {
				flag = true;
			}
			else {
				std::cout << "Число N должно удовлетвроять неравенствам: 1 < N < 20 и N + K < 26" << std::endl;
			}
		}
		else {
			std::cout << "K должно удовлетворять неравенству: 2 <= K <= 10" << std::endl;
			flag = false;
		}
	} while (!flag);

	int nz = k - 1; 
	int oz1 = 1;    
	int oz2 = 0;    
	int oz3 = 0;  
	int oz4 = 0;    
	int total = nz + oz1 + oz2 + oz3;
	for (int i = 2; i <= n; i++) {
		int _nz = nz;
		int _oz1 = oz1;
		int _oz2 = oz2;
		int _oz3 = oz3;
		nz = (_nz + _oz1 + _oz2 + _oz3) * (k - 1);
		oz1 = _nz;
		oz2 = _oz1;
		oz3 = _oz2;
		total = nz + oz1 + oz2 + oz3;
	}
	std::cout << "Количество чисел из " << n << " разрядов: " << total << std::endl;
}