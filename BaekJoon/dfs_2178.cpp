// dfs 로 풀어보고
// 구조체 형식의 배열로 bfs 로 풀어보기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N , M;
char ** str;
int cnt = 0;
vector <int> result;

bool inRange(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}
void bfs(int y, int x) {
	if(y== N-1 && x== M-1){
		result.push_back(++cnt);
		return;
	}
	int i = y; int j = x;

	if (inRange(i, j + 1) && str[i][j] == '1' && str[i][j + 1] == '1') { // 오른쪽 확인
		cnt++;
		str[i][j] = '0';
		bfs(i, j + 1);
		str[i][j] = '1';
	}

	if (inRange(i + 1, j) && str[i][j] == '1' && str[i + 1][j] == '1') { // 아래 확인
		cnt++;
		str[i][j] = '0';
		bfs(i + 1, j);
		str[i][j] = '1';
	}

	if (inRange(i - 1, j) && str[i][j] == '1' && str[i - 1][j] == '1') { // 위 확인
		cnt++;
		str[i][j] = '0';
		bfs(i - 1, j);
		str[i][j] = '1';
	}

	if (inRange(i, j - 1) && str[i][j] == '1' && str[i][j - 1] == '1') { // 왼쪽 확인
		cnt++;
		str[i][j] = '0';
		bfs(i, j - 1);
		str[i][j] = '1';
	}
	cnt--;
}

int main() {
	cin >> N >> M;
	
	str = new char* [N];
	for (int i = 0; i < M; i++) {
		str[i] = new char [M];
	}
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	bfs(0, 0);

	sort(result.begin(), result.end());
	cout << result[0];
	return 0;
}