#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100] = { 0, };

int main() {
	int N, L, result = 0, leng = 0;
	int curnt = 0;
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	
	//vertical
	for (int q = 0; q < N; q++) {
		for (int i = 1; i < N; i++) {
			if (curnt == i) continue;
			if (abs(map[i - 1][q] - map[i][q]) <= 1) {
				//감소할 때
				if (map[i][q] == map[i - 1][q]) {
					continue;
				}
				if (map[i - 1][q] - map[i][q] == 1) {
					for (int z = q; z < N; z++) {
						if (map[i][q] == map[z][q]) leng++;
						else break;
					}
					if (leng >= L) {
						curnt = i + L;
						cout << "vertical 감소 curnt : " << i + 1 << " " << q << " " << curnt << endl;
					}
					else {
						i = N;
						result++;
						break;
					}
				}

				//증가할 때
				if (map[i][q] - map[i - 1][q] == 1 ) {
					for (int z = q; z > curnt; z--) {
						if (map[i][q] == map[z][q]) leng++;
						else break;
					}
					if (leng >= L) {
						curnt = i;
						cout << "vertical 증가 curnt : " << i << " " << q << " " << curnt << endl;
					}
					else {
						i = N;
						result++;
						break;
					}
				}
			}
			else {
				i = N;
				result++;
				break;
			}
		}
		curnt = 0;
		leng = 0;
	}

	//horizontal
	for (int h = 0; h < N; h++) {
		for (int j = 1; j < N; j++) {
			if (curnt == j) continue;
			if (abs(map[h][j-1] - map[h][j]) <= 1) {
				//감소할 때
				if (map[h][j] == map[h][j-1]) {
					continue;
				}
				if (map[h][j-1] - map[h][j] == 1) {
					for (int z = h; z < N; z++) {
						if (map[h][j] == map[h][z]) leng++;
						else break;
					}
					if (leng >= L) {
						curnt = j + L;
						cout << "horizontal 감소 curnt : " << j << " " << h << " " << curnt << endl;
					}
					else {
						j = N;
						result++;
						break;
					}
				}

				//증가할 때
				if (map[j][h] - map[j - 1][h] == 1) {
					for (int z = h; z > curnt; z--) {
						if (map[h][j] == map[h][z]) leng++;
						else break;
					}
					if (leng >= L) {
						curnt = j;
						cout << "horizontal 증가 curnt : " << j << " " << h << " " << curnt << endl;
					}
					else {
						j = N;
						result++;
						break;
					}
				}
			}
			else {
				j = N;
				result++;
				break;
			}
		curnt = 0;
		}
	}

	cout << result << endl;

	cout << N*2 - result;
	return 0;
}