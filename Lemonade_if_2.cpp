#include <iostream>
#include <cmath>

int main() {
	setlocale(0, "");
	double x, y;
	std::cout << "Введите координату (x; y):" << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cout << (((x == 0) && (y < 0) && (y >= -7) || (x == 14) && (y < 0) && (y >= -7)
		|| (y == 0) && (x >= 0) && (x <= 14) || (y == -7) && (x >= 0) && (x <= 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) == pow((3.5), 2)) 
                ? "На границе" : ((y > 0) || (y < -7) || (x < 0) || (x > 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) < pow((3.5), 2) ? "За границей" : "В области"));
}
