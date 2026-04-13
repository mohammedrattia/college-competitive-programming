#include <iostream>

int main()
{
	int n, x, y, a;
	std::cin >> n;
	bool win[120] = { 0 };
	std::cin >> x;
	for (int i = 0; i < x; i++)
	{
		std::cin >> a;
		win[a] = 1;
	}
	std::cin >> y;
	for (int i = 0; i < y; i++)
	{
		std::cin >> a;
		win[a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!win[i])
		{
			std::cout << "Oh, my keyboard!";
			return 0;
		}
	}
	std::cout << "I become the guy.";
}