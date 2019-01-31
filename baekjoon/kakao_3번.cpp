#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>&i, const pair<int, int>&j)
{
	return i.first > j.first;
}

vector<int> solution(int N, vector<int> coffee_times) {
	queue<pair<int, int> > q; // �����ð� : ��ȣ
	vector<pair<int, int> > order; //�ֹ� ���� Ŀ��
	vector<int> ans;

	for (int i = 0; i < coffee_times.size(); i++) {
		q.push({ coffee_times[i], i+1 });
	}

	while (1) {
		//�ֹ� ��������� �־���
		if (order.size() < N) {
			if (!q.empty()) {
				order.push_back(q.front());
				q.pop();
				continue;
			}
		}
		//�������� ����
		sort(order.begin(), order.end(), cmp);
		for (int i = 0; i < order.size(); i++) {
			order[i].first -= order.back().first;		//���� ���� �ð��� ��� Ŀ�� �ð��� ����
		}
		//�ֹ��Ϸ� Ŀ�� �־��ֱ�
		for (int i = 0; i < order.size(); i++) {
			if (order[i].first == 0) {
				ans.push_back(order[i].second);
			}
		}
		//�ڿ������� 0�� �ð� Ŀ�Ǵ� �ֹ����� ����
		while (1) {
			if (!order.empty()) {
				if (order.back().first == 0) {
					order.pop_back();
					continue;
				}
				break;
			}
			if (ans.size() == coffee_times.size()) {
				return ans;
			}
			break;
		}
	}
}

int main() {
	vector<int> coff = { 4,2,2,5,3 };
	vector<int> coff2 = { 100,1,50,1,1 };
	vector<int> a = solution(3, coff);
	vector<int> b = solution(1, coff);

	for (int var : a) {
		cout << var;
	}
	for (int var : b) {
		cout << var;
	}
	return 0;
}