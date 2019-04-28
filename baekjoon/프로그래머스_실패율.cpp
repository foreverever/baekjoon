#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Stage {
	int num, total = 0, fail = 0;
	double avg = 0;
};

bool cmp(Stage &first, Stage &second) {
	if (first.avg == second.avg) {
		return first.num < second.num;
	}
	return first.avg > second.avg;
}

Stage sts[502];

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 1; i <= N; i++) {
		sts[i].num = i;
	}

	for (int i = 0; i < stages.size(); i++) {
		//각 사람마다 1stage부터 그 사람이 현재 있는 stage까지 stage별 도전 횟수, 실패 횟수 갱신
		for (int lev = 1; lev <= stages[i]; lev++) {
			if (lev != stages[i]) sts[lev].total++;
			else {
				sts[lev].total++; sts[lev].fail++;
			}
		}
	}
	
	//실패율 구하기
	for (int i = 1; i <= N; i++) {
		if (sts[i].total == 0) continue;
		sts[i].avg = (double)sts[i].fail / sts[i].total;
	}
	sort(sts + 1, sts + N + 1, cmp);

	for (int i = 1; i <= N; i++) answer.push_back(sts[i].num);

	return answer;
}

int main() {
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(6);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	solution(5, v);
	return 0;
}