#include <iostream>
#define MAX 10000000
using namespace std;
int input, temp;
int up, down;		//����,�и�

int main() {
	cin >> input;
	for (int i = 1; i <= MAX; i++) {
		temp = input - i;
		if (temp <= 0) {
			//¦��
			if (i % 2 == 0) {
				up = input;				//temp�� ���� ������ input�� ã���� �ϴ� ���ڰ� ���Ե� ���ο���, �� ��°�� ��ġ�ϴ����� �ǹ�
				down = i + 1 - up;	//i�� �� ��° ���������� �ǹ�
				break;
			}
			//Ȧ��
			else {
				down = input;
				up = i + 1 - down;
				break;
			}
		}
		else {
			input = temp;
		}
	}
	cout << up << '/' << down;
	return 0;
}