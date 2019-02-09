#include <iostream>
#include <queue>
#include <utility>
#include <set>

using namespace std;

int solution(vector<int> A, vector<int> B, int M, int X, int Y) {
	int personNumber = 0, weight = 0, ans = 0;
	queue<pair<int, int> > q;

	for (int i = 0; i < A.size(); i++) {
		q.push({ A[i],B[i] });
	}

	set<int> s;
	while (!q.empty()) {
		if (personNumber <= X && weight+q.front().first <= Y) {
			personNumber++;
			weight += q.front().first;
			s.insert(q.front().second);
			q.pop();
		}
		else {
			ans += s.size() + 1;
			s.clear();
			personNumber = 0;
			weight = 0;
		}
	}
	return ans+s.size()+1;
}

int main() {
	vector<int> A = { 60, 80, 40, 40 };
	vector<int> B = { 1, 2, 1, 2 };
	cout << solution(A, B, 3, 2, 100);
	return 0;
}