#include <iostream>
#include <string>

int dir_i[8] = { 1, 0, 1, -1, 0, -1, 1, -1 };
int dir_j[8] = { 0, 1, 1, -1, -1, 0, -1, 1 };
int p[25][25];
bool visited[25][25] = { 0 };

bool valid(int r, int c, int n)
{
	return r < n && c < n && r >= 0 && c >= 0;
}

void dfs(int n, int r, int c)
{
	if (visited[r][c])
		return;
	visited[r][c] = 1;

	for (int i = 0; i < 8; i++)
	{
		int x = c + dir_j[i];
		int y = r + dir_i[i];
		if (valid(y, x, n) && !visited[y][x] && p[y][x] == 1)
		{
			dfs(n, y, x);
		}
	}
}

int main()
{
	int n,k = 1;
	while (std::cin >> n)
	{
		std::string str;
		for (int i = 0; i < n; i++)
		{
			std::cin >> str;
			for (int j = 0; j < n; j++)
			{
				p[i][j] = str[j] - '0';
				visited[i][j] = 0;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && p[i][j] == 1)
				{
					dfs(n, i, j);
					cnt++;
				}
			}
		}
		std::cout << "Image number " << k << " contains " << cnt << " war eagles.\n";
		k++;
	}
}