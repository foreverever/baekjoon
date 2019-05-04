#include <vector>
#define MAX 1000000
using namespace std;

int getCount(int n) {
	vector<int> binary;
	while (n) {
		binary.push_back(n % 2);
		n /= 2;
	}

	int cnt = 0;
	for (int v : binary) {
		if (v) cnt++;
	}
	return cnt;
}

int solution(int n) {
	int answer = 0;
	int origin = getCount(n);

	for (int i = n + 1; i <= MAX; i++) {
		if (getCount(i) == origin) {
			answer = i;
			break;
		}
	}
	return answer;
}