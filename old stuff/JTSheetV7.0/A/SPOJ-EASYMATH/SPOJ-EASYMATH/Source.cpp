#include <iostream>

int gcd(int a, int b) {
	if (a == 0) return b;
	gcd(b  %a, a);
}

int inc_exc(int num[], int n, int idx = 0, int div = 1, int sign = 1)
{
	if (idx == 5)
		return sign * n / div;
	return inc_exc(num, n, idx + 1, div, sign) + inc_exc(num, n, idx + 1, (div * num[idx]) / gcd(div, num[idx]), sign * -1);
}

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, m, a, d;
		std::cin >> n >> m >> a >> d;

		int num[5];
		for (int i = 0; i < 5; i++)
		{
			num[i] = a + i * d;
		}

		std::cout << inc_exc(num, m) - inc_exc(num, n - 1) << std::endl;
	}
}