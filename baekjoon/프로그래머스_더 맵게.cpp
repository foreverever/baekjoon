#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int first, second;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (int val : scoville) q.push(val);

	while (q.top() < K) {
		if (q.size() == 1) {
			answer = -1;
			break;
		}

		first = q.top(); q.pop();
		second = q.top(); q.pop();
		answer++;
		q.push(first + (second * 2));
	}
	return answer;
}

//오름차순인 우선순위 큐를 이용해 맨 앞과 두번째 앞을 추출하여 스코빌 지수를 계산해준다.
//계산 결과를 다시 우선순위 큐에 push해준다.
//위 과정을 반복한다.
//모든 음식이 K보다 높다는 뜻은 가장 스코필 지수가 낮은(큐의 맨앞) 음식이 K보다 높다는 것이므로
//q.top()<K를 조건으로 두어 while문을 종료하도록 한다.
//만약 마지막 음식 1개가 남았을 때(q.size()==1) K보다 작다면, -1를 리턴하도록 한다.