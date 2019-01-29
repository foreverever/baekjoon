#include <iostream>
using namespace std;
int A, B, V;

int findAns() {
	int move = A - B;	//하루 이동거리 (낮,밤 모두)
	V -= A;	//마지막은 무조건 낮, 해당 일 수 빼줌
	if (V%move) {
		return V / move + 2;	//나머지가 있을 경우, 나머지로 인해 하루 더 걸리므로 이틀치 추가
	}
	return V / move + 1;	//아니면 하루치 추가
}

int main() {
	cin >> A >> B >> V;
	cout << findAns();
	return 0;
}