#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

struct Board {
	int score = 0;
	char sq;

	Board(int score, char sq) {
		this->score = score;
		this->sq = sq;
	}

	Board() {}
};

map<char, bool> info;
vector<Board> board;
int ans[5];

void initMap() {
	string s = "0123456789";
	for (char c : s) info[c] = true;
}

int solution(string dartResult) {
	initMap();
	int i = 0;
	for (i = 0; i < dartResult.size(); i++) {
		if (info.count(dartResult[i])) {
			//10 체크
			if (dartResult[i + 1] == '0') {
				board.push_back(Board(10, dartResult[i+2]));
				i += 2;
				continue;
			}
			board.push_back(Board((int)(dartResult[i]-'0'), dartResult[i + 1]));
			i += 1;
			continue;
		}
		//옵션인 경우
		board.push_back(Board(-1, dartResult[i]));
	}

	//점수 먼저 계산
	for (int i = 0; i < board.size(); i++) {
		if (board[i].score == -1) continue;
		if (board[i].sq == 'S') {
			ans[i] = board[i].score;
		}
		else if (board[i].sq == 'D') {
			ans[i] = pow(board[i].score, 2);
		}
		else if (board[i].sq == 'T') {
			ans[i] = pow(board[i].score, 3);
		}
	}

	//옵션 계산
	for (int i = 0; i < board.size(); i++) {
		//옵션이면
		if (board[i].score == -1) {
			char option = board[i].sq;
			if (option == '*') {
				ans[i - 1] *= 2;
				if (board[i - 2].score != -1) {
					ans[i - 2] *= 2;
				}
				else {
					if (i - 3 >= 0) ans[i - 3] *= 2;
				}
			}
			else if (option == '#') {
				ans[i - 1] *= -1;
			}
		}
	}

	int answer = 0;

	for (int val : ans) answer += val;
	return answer;
}

int main() {
	char a = '1';
	cout << solution("1D2S#10S");
	
	return 0;
}