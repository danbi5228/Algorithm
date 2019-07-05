#include <iostream>
#include <stack>
using namespace std;

int N = 0, M = 0;
int map[51][51] = { 0, };
int r = 0, c = 0, d = 0; // d ; 0 - 合率, 1 - 悼率, 2 - 巢率, 3 - 辑率

class map_dir {
public:
	int map_x;
	int map_y;
	int dir;

	map_dir(int x, int y, int d) {
		map_x = x;
		map_y = y;
		dir = d;
	}
};

bool isMap(int is_x, int is_y) {
	if (is_x < 0 && is_x >N && is_y < 0 && is_y > M) return false;
	else return true;
}

void bfs(int x, int y, int dir) {
	stack <map_dir> st;

	st.push(map_dir(x, y, dir));

	while (st.empty() == false)
	{
		
	}

}

int main() {
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	bfs(r,c,d);



	return 0;
}