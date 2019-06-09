#include <iostream>
using namespace std;

int fm, m, k;

int findAns() {
	int cnt = 0;

	while (fm >= 2 && m >= 1) {
		fm -= 2;
		m--;
		if (fm + m < k || fm < 0 || m < 0) break;
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> fm >> m >> k;
	cout << findAns();
	return 0;
}

//여자 2명, 남자 1명 이상인 경우에 대해
//하나의 팀을 구성(여자 -=2, 남자 -=1)
//구성 후 다음 조건을 만족하면 팀을 구성 못한다는 의미
// 1) 여자,남자의 합이 인턴 수 보다 작은 경우
// 2) 여자의 수가 0보다 작은 경우
// 3) 남자의 수가 0보다 작은 경우
//위 조건을 만족하지 않는 경우, 앞서 하나의 팀을 구성한 것이 유효하므로 팀 개수 1 증가