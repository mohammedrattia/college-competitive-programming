#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
	int step, mod;
	while (std::cin >> step >> mod)
	{
		bool good = 1;
		for (int i = 2; i <= std::min(step, mod); i++)
		{
			if (step% i == 0 && mod % i == 0)
			{
				good = 0;
				break;
			}
		}
		if (good == 1)
			std::cout << std::setw(10) << step << std::setw(10) << mod << "    Good Choice\n\n";
		else
			std::cout << std::setw(10) << step << std::setw(10) << mod << "    Bad Choice\n\n";
	}
}