#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dp(2, vector<int>(1e5 + 1, false));

int solution(vector<int> A)
{
  int n = A.size();
  dp[0][0] = true;
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += A[i-1];
    for (int j = 0; j <= 1e5; j++)
    {
      dp[i%2][j] = dp[(i-1)%2][j];
      if (j >= A[i-1])
      {
        dp[i%2][j] |= dp[(i-1)%2][j - A[i-1]];
      }
    }
  }
  for (int j = sum/2; j >=0; j--)
  {
    if (dp[n%2][j])
    {
      return sum - 2*j;
    }
  }
  return sum;
}

vector<int> toIntVector(string str)
{
  std::vector<int> out;
  std::string i;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, i, ','))
  {
    out.push_back(atoi(i.c_str()));
  }
  return out;
}

int main()
{
  // Read in from stdin, solve the problem, and write answer to stdout.
  string AS;
  cin >> AS;
  cout << solution(toIntVector(AS));
}