#include <iostream>
#define MAX 10000000
using namespace std;
int input, temp;
int up, down;		//분자,분모

int main() {
	cin >> input;
	for (int i = 1; i <= MAX; i++) {
		temp = input - i;
		if (temp <= 0) {
			//짝수
			if (i % 2 == 0) {
				up = input;				//temp에 의해 가공된 input은 찾고자 하는 숫자가 포함된 라인에서, 몇 번째에 위치하는지를 의미
				down = i + 1 - up;	//i는 몇 번째 라인인지를 의미
				break;
			}
			//홀수
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