#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int tc, N, M;		//�׽�Ʈ���̽�, ���� ����, ã���� �ϴ� ���� �ε���

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
	queue <pair<int, int> > q;	//������ �߿䵵�� �ε���
	vector<int> v;	//������ �߿䵵
	input(q, v);

	sort(v.begin(), v.end());
	while (1) {
		//���� ���� �߿䵵�� ť �Ǿ��� �߿䵵�� ���� ��
		if (q.front().first==v.back()) {
			//���� ���ϴ� ���� ã���� ��
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