#include <bits/stdc++.h>
#include "guessx.h"

using namespace std;

namespace {
	int __qs;
	int __n,__x;
	void WA(string s)
	{
		cout << "WA: " << s << endl;
		exit(0);
	}
}

bool isLessThanX(int y)
{
    __qs++;
	if(y<1||y>__n)
		WA("Invalid query");
	return y<__x;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&__n,&__x);
		int res=guess_number(__n);
		if(res!=__x)
			WA("Wrong guess");
		printf("OK: %d\n",__qs);
		__qs=0;
		// otherwise complete the program normally
	}
}
