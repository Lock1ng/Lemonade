#include <iostream>
#include <cmath>

int main() {
	setlocale(0, "");
	double x, y;
	std::cout << "Введите координату (x; y):" << std::endl;
	if (std::cin >> x && std::cin >> y) {
		if (((x == 0) && (y < 0) && (y >= -7)) || ((x == 14) && (y < 0) && (y >= -7))
			|| (y == 0) && (x >= 0) && (x <= 14) || (y == -7) && (x >= 0) && (x <= 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) == pow((3.5), 2)) {
			std::cout << "На границе";
		}
		else {
			if ((y > 0) || (y < -7) || (x < 0) || (x > 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) < pow((3.5), 2)) {
				std::cout << "За границей";
			}
			else {
				std::cout << "В области";
			}
		}
	}
}
