#include<iostream>

using namespace std;

int **arr, visit_ary[1000000] = { 0, }, visit_ary[100000] = { 0, }, **dfs_able_ary, *bfs_able_ary;
int v = 0, e = 0, v_1st = 0; // 정점, 간선, 첫 탐색 정점
int a, b; // 연결 간선

int front = 0, rear = 0;


void dfs(int** arr, int v_1st) { 
	visit_ary[v_1st] = 1;
	cout << v_1st << " ";
	
	// 방문 가능한 정점 표시
	for (int i = 0; i < v; i++) {
		if (arr[v_1st][i + 1] == 1) {
			dfs_able_ary[v_1st][i + 1] = 1;
		}
	}

	// 방문 가능한 정점 중 작은 정점부터 방문
	for (int i = 0; i < v; i++) {
		if ( (dfs_able_ary[v_1st][i + 1] == 1) && (visit_ary[i + 1] != 1) ) {
			dfs(arr, i + 1);
		}
	}
	
}

void bfs() {
	visit_ary[rear] = v_1st; // queue
	rear++;

	while (front != rear) {
		bfs_able_ary[v_1st] = 1; // 방문 여부 저장
		for (int i = 0; i < v; i++) {
			if (arr[v_1st][i + 1] == 1 && bfs_able_ary[i + 1] != 1) {
				visit_ary[rear] = i + 1;
				bfs_able_ary[i + 1] = 1;
				rear++;
			}
		}
		cout << visit_ary[front] << " ";
		front++;
		v_1st = visit_ary[front];
	}
}
int main() {

	cin >> v >> e >> v_1st;

	arr = new int *[v+1];
	for (int i = 0; i < v; i++) {
		arr[i+1] = new int[v+1];
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	///////////////////////////////

	dfs_able_ary = new int *[v + 1];
	for (int i = 0; i < v; i++) {
		dfs_able_ary[i + 1] = new int[v + 1];
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			dfs_able_ary[i + 1][j + 1] = 0;
		}
	}

	dfs(arr, v_1st);
	cout << endl;

	bfs_able_ary = new int [v + 1];
	for (int i = 0; i < v; i++) {
		bfs_able_ary[i+1] = 0;
	}

	bfs();

	/* 메모리 해제 */
	for (int i = 1; i < v+ 1; ++i) {
		delete[] arr[i];
		delete[] dfs_able_ary[i];
	}
	delete[] arr;
	delete[] bfs_able_ary;
	return 0;
}