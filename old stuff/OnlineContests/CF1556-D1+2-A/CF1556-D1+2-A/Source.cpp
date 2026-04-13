#include <iostream>

int main()
{
	long long t;
	std::cin >> t;
	while (t--)
	{
		long long c, d;
		std::cin >> c >> d;
		if (c == 0 && d == 0)
			std::cout << 0 << std::endl;
		else if (abs(c - d) % 2 == 0)
			std::cout << 2 << std::endl;
		else if (abs(c - d) % 2 == 1)
			std::cout << -1 << std::endl;
		else if (c == d)
			std::cout << 1 << std::endl;
	}
}