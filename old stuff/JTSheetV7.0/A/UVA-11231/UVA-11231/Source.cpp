#include <iostream>

int main()
{
	long n, m;
	bool c;
	while (std::cin >> n >> m >> c && n != 0)
	{
		int num = (n - 7)*(m - 7) / 2;
		if (n % 2 == 0 && m % 2 == 0 && c == 1)
			num++;
		std::cout << num << std::endl;
	}
}