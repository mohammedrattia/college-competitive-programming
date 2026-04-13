#include <iostream>
#include <cstring>

int main()
{
	std::string x, y;
	while (std::cin >> x >> y)
	{
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());

		int result[600];
		std::memset(result, 0, sizeof(result));

		for (int i = 0; i < x.length(); i++)
		{
			for (int j = 0; j < y.length(); j++)
			{
				result[i + j] += (x[i] - '0') * (y[j] - '0');
			}
		}

		for (int i = 0; i < 600; i++)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}

		int i = 599;
		while (i > 0 && result[i] == 0) 
			i--;
		for (; i >= 0; i--)
			std::cout << result[i];
		std::cout << std::endl;
	}
}