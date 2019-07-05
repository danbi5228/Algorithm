#include <iostream>
using namespace std;

int main() {
	int M = 0, x = 0, y = 0, tmp = 0, flag = 0;
	int map[3] = { 1,2,3 };
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		flag = 0;

		for (int t = 0; t < 3; t++) {
			if (map[t] == x) {
				for (int t2 = 0; t2 < 3; t2++) {
					if (map[t2] == y && t2 != t) {
						map[t] = y;
						map[t2] = x;
						flag = 1;
					}
				}
			}

			if (flag == 1) break;
		}
	}

	cout << map[0];
	return 0;
}

// 그냥 공 위치만 저장해두고 그 위치인지 아닌지만 확인...
// ball == x || ball == y 보고... ball 위치가 x면 ball 을 y로 바꿔주고... 반대면 x로 바꿔주고..
// 둘다 아니면 무시... 변하든말든 노상관...흑