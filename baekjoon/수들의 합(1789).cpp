#include <iostream>
typedef long long ll;
using namespace std;

ll N;

ll findAns() {
	ll cnt = 0, num = 1;

	while(N>=num){
		N -= num;
		cnt++; num++;
	}
	return cnt;
}

int main() {
	cin >> N;
	cout << findAns();
	return 0;
}
//입력받은 N을 자연수 1부터 1씩 증가시키며 빼준다. (N이 0이 될 때 까지)
//빼고 남은 N의 값보다 다음에 빼줄 값이 더 큰 경우
//그 이전에 남은 N에 만족하는 값을 더해줘야 하는 의미이므로(이미 해당 개수는 더해줬으므로) 그때의 count값 리턴
//예) 200에 대해 1~18까지 합은 171이므로 남은 N은 29이며,
//29 - 19 = 10으로, 10(남은 N)은 다음에 빼줄 값 20보다 작으므로, 이전의 N인 29일때 29를 뺌으로써 최대 개수가 결정된다.
//이때 이미 19에서 count를 증가시켜줬기 때문에, 해당 count는 이미 계산한것으로 보고 바로 count를 리턴하면 정답이 된다.