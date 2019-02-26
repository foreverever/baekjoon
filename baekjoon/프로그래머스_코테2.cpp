#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;

bool cmp(const int &a, const int &b) {
	return a > b;
}

void insertQueue(vector<int> tshirts) {
	for (int val : tshirts) {
		q.push(val);
	}
}

void initQueue() {
	while (!q.empty()) {
		q.pop();
	}
}

void solution(vector<int> people, vector<int> tshirts) {
	int ans = 0;
	sort(people.begin(), people.end(), cmp);
	insertQueue(tshirts);
	for (int pSize : people) {
		if (q.empty()) break;
		if (pSize > q.top()) continue;
		ans++;
		q.pop();
	}
	printf("%d\n", ans);
	initQueue();
}

int main() {
	vector<int> p1 = { 2,3 };
	vector<int> t1 = { 1,2,3 };
	solution(p1, t1);

	vector<int> p2 = { 1,2,3 };
	vector<int> t2 = { 1,1 };
	solution(p2, t2);

	vector<int> p3 = { 4,2,2,3 };
	vector<int> t3 = { 2,4,1 };
	solution(p3, t3);
	return 0;
}