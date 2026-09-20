#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &chapters, vector<int> &evenings) {
    int M = chapters.size(), N = evenings.size();
    int current_chapter = 0, current_evening = 0;
    while (current_chapter < M) {
        if (current_evening == N)
            return -1;

        while (current_evening < N && chapters[current_chapter] > evenings[current_evening])
            current_evening++;

        if (current_evening == N)
            return -1;

        evenings[current_evening] -= chapters[current_chapter];
        current_chapter++;
    }
    return current_evening + 1;
}