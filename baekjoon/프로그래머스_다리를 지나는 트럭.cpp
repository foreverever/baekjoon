#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 0, w = 0;

	for (int truck : truck_weights) {
		while (1) {
			if (q.empty()) {
				w += truck;
				q.push(truck);
				time++;
				break;
			}
			if (q.size() == bridge_length) {
				w -= q.front();
				q.pop();
			}
			else {
				if (w + truck <= weight) {
					w += truck;
					q.push(truck);
					time++;
					break;
				}
				else {
					q.push(0);	//다리위의 트럭이 앞으로 이동함을 의미
					time++;
				}
			}
		}
	}
	return time + bridge_length;	//마지막 트럭이 탑승할때 시간 + 해당 트럭이 다리를 모두 지나가는 시간(==다리 길이)
}