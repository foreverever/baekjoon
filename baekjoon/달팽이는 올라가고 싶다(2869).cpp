#include <iostream>
using namespace std;
int A, B, V;

int findAns() {
	int move = A - B;	//�Ϸ� �̵��Ÿ� (��,�� ���)
	V -= A;	//�������� ������ ��, �ش� �� �� ����
	if (V%move) {
		return V / move + 2;	//�������� ���� ���, �������� ���� �Ϸ� �� �ɸ��Ƿ� ��Ʋġ �߰�
	}
	return V / move + 1;	//�ƴϸ� �Ϸ�ġ �߰�
}

int main() {
	cin >> A >> B >> V;
	cout << findAns();
	return 0;
}