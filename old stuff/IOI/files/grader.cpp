#include <bits/stdc++.h>
#include "permutation.h"

using namespace std;

namespace {
	int __n,__x;
	int __qs,__mx;
	vector<int> __p;
	void WA(string s)
	{
		cout << "WA: " << s << endl;
		exit(0);
	}
}

vector<int> use_machine(vector<int> v)
{
	if(v.size()!=__n) WA("size of queried array is not n");
	vector<int> ret;
	__qs++;
	for(int i=0;i<__n;i++)
	{
		ret.push_back(v[__p[i]]^__x);
		__mx=max(__mx,v[i]);
	}
	return ret;
}

int main()
{
	int t,st;
	scanf("%d %d",&t,&st);
	while(t--)
	{
		scanf("%d %d",&__n,&__x);
		__p=vector<int>(__n);
		for(int i=0;i<__n;i++)
			scanf("%d",&__p[i]);
		vector<int> ret=guess_permutation(__n,st);
		if(ret.size()!=__n) WA("size of answer is not n");
		for(int i=0;i<__n;i++)
			if(ret[i]!=__p[i]) WA("Invalid guess");
		printf("OK: %d %d\n",__qs, __mx);
		__mx=0; __qs=0;
	}
}