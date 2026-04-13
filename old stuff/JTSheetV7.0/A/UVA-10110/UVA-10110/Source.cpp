#include <iostream>
#include <cmath>

int main()
{
	while (true)
	{
		long long n, cnt = 0;
		std::cin >> n;
		if (n == 0)
			return 0;
		
		long sqr = (int)sqrt(n);

		std::cout << (sqr * sqr == n ? "yes" : "no") << std::endl;
	}
}