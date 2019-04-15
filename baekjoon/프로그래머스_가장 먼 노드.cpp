#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> arr[20001];
int dist[20001];
bool visit[20001];

void findAns(int n) {
	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : arr[cur]) {
			if (visit[next] == false) {
				visit[next] = true;
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	sort(dist + 1, dist + n + 1);
}

int solution(int n, vector<vector<int>> edge) {

	int answer = 0;

	for (int i = 0; i < edge.size(); i++) {
		arr[edge[i][0]].push_back(edge[i][1]);
		arr[edge[i][1]].push_back(edge[i][0]);
	}

	findAns(n);

	for (int i = n; i >= 1; i--) {
		if (dist[i] == dist[n]) answer++;
		else break;
	}
	
	return answer;
}