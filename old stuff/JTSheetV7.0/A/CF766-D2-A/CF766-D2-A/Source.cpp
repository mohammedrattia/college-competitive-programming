#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string a, b;
	std::cin >> a >> b;

	if (a == b)
		std::cout << -1;
	else if (a.size() != b.size())
		std::cout << std::max(a.size(), b.size());
	else
		std::cout << a.size();
}