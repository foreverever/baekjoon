#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;

bool cmp(string &first, string &second) {
	return first[idx] == second[idx] ? first < second : first[idx] < second[idx];
}

vector<string> solution(vector<string> strings, int n) {
	idx = n;
	sort(strings.begin(), strings.end(), cmp);
	return strings;
}