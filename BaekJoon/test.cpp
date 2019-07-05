// 2583 영역 구하기 문제
#include <iostream> 
//#include <cstdio> 
#include <algorithm> 
//#include <cstdlib> 
#include <vector> 

using namespace std;

int a[200][200];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m, k;

bool inRange(int y, int x) {
	return (y >= 0 && y < n && x >= 0 && x < m);
}

void place(int ystart, int xstart, int height, int width) {
	for (int y = ystart; y < ystart + height; y++) {
		for (int x = xstart; x < xstart + width; x++) {
			a[y][x] = 1;
		}
	}
}

void dfs(int y, int x, int &cnt) {
	if (a[y][x] == 0) ++cnt;
	a[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (inRange(ny, nx) && a[ny][nx] == 0) dfs(ny, nx, cnt);
	}
	return;
}

int main() {
	cin >> n >> m >> k;
	//scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		place(y1, x1, y2 - y1, x2 - x1);
	}
	int res = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				int cnt = 0;
				dfs(i, j, cnt);
				v.push_back(cnt);
				res++;
			}
		}
	}
	printf("%d\n", res);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}