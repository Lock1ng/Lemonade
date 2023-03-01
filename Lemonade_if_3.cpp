#include <iostream>
#include <cmath>
#include <string>

int main() {
	setlocale(0, "");
	double x, y;
	std::cout << "Введите координату (x; y):" << std::endl;
	std::cin >> x;
	std::cin >> y;
	bool choice1 = (((x == 0) && (y < 0) && (y >= -7)) || ((x == 14) && (y < 0) && (y >= -7))
		|| (y == 0) && (x >= 0) && (x <= 14) || (y == -7) && (x >= 0) && (x <= 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) == pow((3.5), 2));
	bool choice2 = ((y > 0) || (y < -7) || (x < 0) || (x > 14) || (pow((x - 3.5), 2) + pow((y + 3.5), 2)) < pow((3.5), 2));
	bool choice3 = not choice1 && not choice2;
	int choice = stoi(std::to_string(choice1) + std::to_string(choice2) + std::to_string(choice3));
	switch (choice)
	{
	case 100: {
		std::cout << "На границе";
		break; }
	case 10: {
		std::cout << "За границей";
		break; }
	default: {
		std::cout << "В области"; }
		break;
	}
}
