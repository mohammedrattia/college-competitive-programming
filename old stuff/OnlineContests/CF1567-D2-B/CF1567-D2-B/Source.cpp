#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int a, b, mex = 0;
		std::cin >> a >> b;
		for (int i = 1; i < a; i++)
			mex ^= i;
		if (mex == b)
		{
			std::cout << a << std::endl;
			continue;
		}
		if ((mex ^ b) != a)
			std::cout << a + 1 << std::endl;
		else
			std::cout << a + 2 << std::endl;
	}
}