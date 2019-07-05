#include <iostream>
#include <queue>
using namespace std;
int vtx = 0, edge = 0, start_num = 0, cnt=1; // 정점,간선,시작번호, 방문순서저장
int front = 0, rear = 0; // bfs
int queue_bfs[10000] = { 0, };
int *visit_p,*visit_pp;
int *arr_dfs, *arr_bfs;
int **arr;

void dfs(int v) {
	visit_p[v] = 1;
	for (int i = v; i < vtx + 1; i++) {
		for (int j = 1; j < vtx + 1; j++) {
			if (arr[i][j] == 1 && visit_p[j] != 1) {
				cnt++;
				arr_dfs[cnt] = j;
				dfs(j);
			}
		}
	}
}

void bfs(int v) {
	queue_bfs[rear] = v;
	rear++;
	while (front != rear) {
		int i = queue_bfs[front];
		front++;
		visit_pp[i] = 1;
		arr_bfs[cnt] = i;
		cnt++;
		for (int j = 1; j < vtx + 1; j++) {
			if (arr[i][j] == 1 && visit_pp[j] != 1) {
				queue_bfs[rear] = j;
				rear++;
			}
		}
	}
}

int main() {

	cin >> vtx >> edge >> start_num;

	//방문정점 확인
	visit_p = new int [vtx+1];
	visit_pp = new int[vtx + 1];

	arr_dfs = new int[vtx + 1];
	arr_bfs = new int[vtx + 1];

	//2차원 배열 동적할당
	arr = new int*[vtx+1]; 
	for (int i = 1; i < vtx+1; ++i) {
		arr[i] = new int[vtx+1]; 
	} 

	//입력값 배열에 넣기
	for (int i = 0; i < edge; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	visit_p[start_num] = 1; 
	arr_dfs[cnt] = start_num;
	arr_bfs[cnt] = start_num;
	dfs(start_num);
	cnt = 1;
	bfs(start_num);

	for (int i = 1; i < vtx + 1; i++) {
		cout << arr_dfs[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < vtx + 1; i++) {
		cout << arr_bfs[i] << " ";
	}

	/* 메모리 해제 */
	for (int i = 1; i < vtx+1; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

