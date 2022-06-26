#include "Date.h"

int main()
{
	Date first(01, 10, 2021);
	Date second(15, 10, 2022);
	std::cout << first - second;
	std::cout <<std::endl;

	Date Three = first + 365;
	Three.PrintDate();

	if (first < second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first > second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first == second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	if (first != second)
		std::cout << "ok!\n";
	else
		std::cout << "no\n";

	Date today;
	today.PrintDate();

	Date birthday;
	std::cin >> birthday;
	birthday.PrintDate();
	std::cout << birthday;
}
