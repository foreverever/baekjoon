#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int parent[102];

bool cmp(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

void init(int &n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
}

int findParent(int &node) {
	if (parent[node] == node) return node;
	return parent[node] = findParent(parent[node]);
}

void unionSet(int &a, int &b) {
	int pA = findParent(a);
	int pB = findParent(b);

	if (pA > pB) parent[pA] = pB;
	else parent[pB] = pA;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	init(n);
	sort(costs.begin(), costs.end(), cmp);

	for (int i = 0; i < costs.size(); i++) {
		int a = costs[i][0];
		int b = costs[i][1];
		int cost = costs[i][2];

		if (findParent(a) != findParent(b)) {
			unionSet(a, b);
			answer += cost;
		}
	}
	return answer;
}