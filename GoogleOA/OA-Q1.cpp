#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> A) {
  vector<int> answer(3, 0);
  for (int i = 0; i < (int)A.size(); i++)
  {
     if (A[i] < 50) answer[0]++;
     else if (A[i] > 80) answer[2]++;
     else answer[1]++;
  }
  return answer;
}
