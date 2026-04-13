#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, odd = 0, even = 0;
		cin >> n;
		vector<bool> a(n);
		a.reserve(n);
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			if (num % 2 == 0)
			{
				a[i] = 1;
				even++;
			}
			else
			{
				a[i] = 0;
				odd++;
			}
		}
		if (odd != n / 2 && even != n / 2)
		{
			cout << "-1\n";
			continue;
		}
		int cnt = 0;
		for (int i = 1; i < n-1; i++)
		{
			while (a[i - 1] != a[i + 1] && a[i] == a[i - 1])
			{
				cnt++;
				swap(a[i], a[i + 1]);
				if (i != 1)
					i--;
			}
		}
		cout << cnt << endl;
	}
}