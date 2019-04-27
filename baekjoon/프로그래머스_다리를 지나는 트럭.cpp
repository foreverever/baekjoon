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
					q.push(0);	//�ٸ����� Ʈ���� ������ �̵����� �ǹ�
					time++;
				}
			}
		}
	}
	return time + bridge_length;	//������ Ʈ���� ž���Ҷ� �ð� + �ش� Ʈ���� �ٸ��� ��� �������� �ð�(==�ٸ� ����)
}