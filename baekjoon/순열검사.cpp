#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

bool solution(vector<int> v) {
	int size = v.size();
	for (int i = 1; i <= size; i++) m[i] = 1;

	for (int i = 0; i < size; i++) {
		if (m[v[i]] == 0) return false;
		m[v[i]]--;
	}
	return true;
}