#include <iostream>

int main()
{
	int k, r;
	std::cin >> k >> r;
	int num = 0;
	while (true)
	{
		num++;
		if ((k * num - r) % 10 == 0 || (k * num) % 10 == 0)
			break;
	}
	std::cout << num;
	std::cin.get();
}