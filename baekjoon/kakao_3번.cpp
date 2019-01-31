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
	queue<pair<int, int> > q; // 남은시간 : 번호
	vector<pair<int, int> > order; //주문 중인 커피
	vector<int> ans;

	for (int i = 0; i < coffee_times.size(); i++) {
		q.push({ coffee_times[i], i+1 });
	}

	while (1) {
		//주문 비어있으면 넣어줌
		if (order.size() < N) {
			if (!q.empty()) {
				order.push_back(q.front());
				q.pop();
				continue;
			}
		}
		//내림차순 정렬
		sort(order.begin(), order.end(), cmp);
		for (int i = 0; i < order.size(); i++) {
			order[i].first -= order.back().first;		//제일 적은 시간을 모든 커피 시간에 빼줌
		}
		//주문완료 커피 넣어주기
		for (int i = 0; i < order.size(); i++) {
			if (order[i].first == 0) {
				ans.push_back(order[i].second);
			}
		}
		//뒤에서부터 0인 시간 커피는 주문에서 빼줌
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