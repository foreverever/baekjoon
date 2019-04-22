#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Food {
	int idx, amout;

	Food(int idx, int amount) {
		this->idx = idx;
		this->amout = amount;
	}

	Food() {};
};

queue<Food> q;

int solution(vector<int> food_times, long long k) {

	//모두 다 먹을 수 있는 경우 -1리턴
	long long sum = 0;

	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
		q.push(Food(i + 1, food_times[i]));
	}
	if (sum <= k) return -1;

	long long mok = 0, rm = 0;
	int qSize = 0;

	while (1) {
		qSize = q.size();
		mok = k / qSize;
		rm = k % qSize;

		if (mok == 0) {
			if (rm == 0) return q.front().idx;

			while (rm != 0) {
				q.pop();
				rm--;
			}
			return q.front().idx;
		}

		for (int i = 0; i < qSize; i++) {
			if (q.front().amout - mok < 0) {
				rm += mok - q.front().amout;
				q.pop();
			}
			else if (q.front().amout - mok == 0) {
				q.pop();
			}
			else {
				q.front().amout -= mok;
				q.push(q.front());
				q.pop();
			}
		}
		k = rm;
	}
}

int main() {
	vector<int> food = { 3,1,2 };
	cout << solution(food, 5);
	return 0;
}