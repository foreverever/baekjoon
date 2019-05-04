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
//입력받은 숫자 n부터 1씩 증가한 숫자의 이진수를 구한 후, 
//해당 이진수의 1의 개수가 n의 이진수의 1의 개수와 같은 최초의 숫자가 n 다음 큰 숫자가 된다.