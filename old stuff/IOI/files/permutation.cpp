#include <bits/stdc++.h>
#include "permutation.h"

// You don't need to change anything in includes,
// you can submit your code as it is.

#ifndef ONLINE_JUDGE
#include "grader.cpp"
#endif

using namespace std;

vector<int> guess_permutation(int n,int st)
{
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
	vector<int> ret=use_machine(a);
	for (int i = 0; i < n; i++)
        cout << ret[i];

	for (int i = 0; i < n; i++)
	{
	    a[i] =
	}
	int x = ret[0] + 1 - 2*(ret[0] & 1);
	cout << x;
	return vector<int>();
}
