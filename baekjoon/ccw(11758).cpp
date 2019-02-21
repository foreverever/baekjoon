#include <iostream>
#include <vector>
#define FIRST 0
#define SECOND 1
#define THIRD 2
using namespace std;

struct pos
{
	int x, y;
};
vector<pos> v;

int findAns() {
	int val = (v[FIRST].x*v[SECOND].y + v[SECOND].x*v[THIRD].y + v[THIRD].x*v[FIRST].y)
		- (v[FIRST].y*v[SECOND].x + v[SECOND].y*v[THIRD].x + v[THIRD].y*v[FIRST].x);
	if (val > 0) return 1;
	if (val < 0) return -1;
	return 0;
}

int main() {
	pos p;
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &p.x, &p.y);
		v.push_back(p);
	}
	printf("%d", findAns());
	return 0;
}