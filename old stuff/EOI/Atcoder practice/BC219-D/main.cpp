#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n, x, y;
	std::cin >> n >> x >> y;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i] >> b[i];

	const int inf = 1000000000;

	std::vector<std::vector<int> > dp(x + 1, std::vector<int>(y + 1, inf));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = x; j >= 0; --j)
			for (int k = y; k >= 0; --k)
				dp[j][k] = std::min(dp[j][k], dp[std::max(j - a[i], 0)][std::max(k - b[i], 0)] + 1);

	std::cout << (dp[x][y] != inf ? dp[x][y] : -1) << std::endl;
	return 0;
}
