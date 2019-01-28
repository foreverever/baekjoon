#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int tc, N, M;		//테스트케이스, 문서 개수, 찾고자 하는 문서 인덱스

void input(queue<pair<int, int> > &q, vector<int> &v) {
	cin >> N >> M;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push({ x,i });
		v.push_back(x);
	}
}

int findAns() {
	queue <pair<int, int> > q;	//문서의 중요도와 인덱스
	vector<int> v;	//문서의 중요도
	input(q, v);

	sort(v.begin(), v.end());
	while (1) {
		//가장 높은 중요도와 큐 맨앞의 중요도가 같을 때
		if (q.front().first==v.back()) {
			//내가 원하는 문서 찾았을 때
			if (q.front().second == M) {
				q.pop();
				return (N - q.size());
			}
			q.pop();
			v.pop_back();
			continue;
		}
		q.push(q.front());
		q.pop();
	}
}

int main() {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << findAns() <<'\n';
	}
	return 0;
}