#include <iostream>

int main()
{
	int s[4], cnt = 0;
	bool visit[4] = { 0 };
	for (int i = 0; i < 4; i++)
		std::cin >> s[i];
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (s[i] == s[j] && visit[j] != 1)
			{
				cnt++;
				visit[j] = 1;
			}
		}
	}
	std::cout << cnt;
}