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

//���������� �켱���� ť�� �̿��� �� �հ� �ι�° ���� �����Ͽ� ���ں� ������ ������ش�.
//��� ����� �ٽ� �켱���� ť�� push���ش�.
//�� ������ �ݺ��Ѵ�.
//��� ������ K���� ���ٴ� ���� ���� ������ ������ ����(ť�� �Ǿ�) ������ K���� ���ٴ� ���̹Ƿ�
//q.top()<K�� �������� �ξ� while���� �����ϵ��� �Ѵ�.
//���� ������ ���� 1���� ������ ��(q.size()==1) K���� �۴ٸ�, -1�� �����ϵ��� �Ѵ�.