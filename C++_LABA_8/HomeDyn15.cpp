#include <iostream>
#include "Header.h"
void HomeDyn15() {
	std::cout << "«адание: HomeDyn15" << std::endl;
	int k, n;
	bool flag = true;
	do {
		std::cout << "¬ведите основание системы счислени€: ";
		std::cin >> k;
		if (k >= 2 && k <= 10) {
			std::cout << "¬ведите разр€д N: ";
			std::cin >> n;
			if ((n > 1 && n < 20) && (n + k < 26)) {
				flag = true;
			}
			else {
				std::cout << "„исло N должно удовлетвро€ть неравенствам: 1 < N < 20 и N + K < 26" << std::endl;
			}
		}
		else {
			std::cout << "K должно удовлетвор€ть неравенству: 2 <= K <= 10" << std::endl;
			flag = false;
		}
	} while (!flag);

	int nz = k - 1; 
	int oz = 1;   
	int tz = 0;  
	for (int i = 2; i <= n; i++) {
		int _nz = nz;
		int _oz = oz;
		int _tz = tz;
		nz = (_nz + _oz + _tz) * (k - 1);
		oz = _nz;
		tz = _oz;
	}
	std::cout << " оличество " << k << "-ых чисел из " << n << " разр€дов, где не содержатс€ 3 и более идущих подр€д 0: " << nz + oz + tz << std::endl;
}// 111 110 11 0 1 100 101 10  