#include <string>
#include <vector>

using namespace std;
int number[10001];

void init(int n) {
	for (int i = 1; i <= n; i++) number[i] = i;
}

int solution(int n) {
	int answer = 0;
	init(n);
	int sum = 1, s = 1, e = 1;

	while (e <= n) {
		if (sum == n) {
			answer++;
			sum -= number[s++];
		}
		else if (sum < n) sum += number[++e];
		else sum -= number[s++];
	}
	return answer;
}