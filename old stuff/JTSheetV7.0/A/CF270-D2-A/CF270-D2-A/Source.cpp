#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int a;
		std::cin >> a;
		if (a < 60)
		{
			std::cout << "NO\n";
			continue;
		}
		int i = 3;
		while (true)
		{
			if ((i - 2) * 180 / i == a)
			{
				std::cout << "YES\n";
				break;
			}
			else if ((i - 2) * 180 / i > a)
			{
				std::cout << "NO\n";
				break;
			}
			i++;
		}
	}
}