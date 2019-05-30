#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int findAns() {
	vector<int> xPos, yPos;
	int x = 0, y = 0;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		xPos.push_back(x);
		yPos.push_back(y);
	}
	sort(xPos.begin(), xPos.end());
	sort(yPos.begin(), yPos.end());

	x = xPos.back() - xPos.front();
	y = yPos.back() - yPos.front();

	int longestLen = y > x ? y : x;
	return longestLen * longestLen;
}

int main() {
	cin >> N;
	cout << findAns();
	return 0;
}