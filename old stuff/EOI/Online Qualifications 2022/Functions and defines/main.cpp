#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define lp(i, v)		for(int i=0;i<sz(v);++i)
#define rep(i, a, b)		for(int i=a; i < (int)(b); ++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)

typedef long long         ll;
const int OO = (int)1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

#define pb					push_back
#define MP					make_pair
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
typedef long double   	  ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

vector<int> BFS(int s, vector<vector<int> > & adjList) {
	vector<int> len(sz(adjList), OO);
	queue< pair<int, int> > q;
	q.push(MP(s, 0)), len[s] = 0;

	int cur, dep;
	while(!q.empty()) {
		pair<int, int> p = q.front();	 q.pop();
		cur = p.first, dep = p.second;

		rep(i, adjList[cur]) if (len[adjList[cur][i]] == OO)
			q.push(MP(adjList[cur][i], dep+1)), len[adjList[cur][i]] = dep+1;
	}

	return len;	//cur is the furthest node from s with depth dep
}

void dfs(int node)
{
	visited[node] = true;

	rep(i, adj[node])
	{
		int child = adj[node][i];
		if (!visited[child])	// To avoid cyclic behavior
			dfs(child);
	}

	topsort.push_back(node);	// DAG // Other way Indegree / Outdegree
}

// start + (end-start)/2 = (start + end) / 2

int BSfindFirst(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					end  = mid;
	}
	return start;
}
int BSfindLast(int start, int end, int val) {
	while(start < end) {
		int mid = start + (end-start)/2;
		if(f(mid) < val)		start= mid+1;
		else if(f(mid) > val)	end  = mid-1;
		else					start= mid;
	}
	return start;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
