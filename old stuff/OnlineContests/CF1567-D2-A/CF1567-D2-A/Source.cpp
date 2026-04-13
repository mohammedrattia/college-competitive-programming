#include <iostream>
#include <string>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		std::string str;
		std::cin >> str;
		for (auto &e : str)
		{
			if (e == 'L')
				std::cout << "LR";
			else if (e == 'U')
				std::cout << "D";
			else if (e == 'D')
				std::cout << "U";
		}
		std::cout << std::endl;
	}
}