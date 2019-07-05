#include <iostream>
using namespace std;

int v = 0;
int arr[100][100] = { 0, };  // 입력 받을 배열
int result[100][100] = { 0, }; // 결과 나타낼 배열


int now_ptr = 0; // result 배열 중 한 행 가리킴..
int visit_ary[10000] = { 0, }; // visit 확인 배열
int queue[10000] = { 0, }; // 갈 곳 저장
int front = 0, rear = 1;
int dup = 0;

//void bfs(int a) {
//
//	if (a != now_ptr && front != 0) { // 처음 0,0 에서 x 값 0에 대해 방문 처리를 하지 않기 위해!
									 // 그래야 예제 입력 2에서 5번째 행에 대해 방문이 가능!
//		visit_ary[a] = 1;
//	}
//
//	while (front != rear) {
//		for (int i = 0; i < v; i++) {
//			if (arr[a][i] == 1 && visit_ary[i] != 1) {
//				result[now_ptr][i] = 1;
//				queue[rear] = i;
//				rear++;
//			}
//		}
//
//		front++;
//		bfs(queue[front]);
//		
//	}
//}

void dfs(int a) {
	if (dup != 0) {
		visit_ary[a] = 1;
	}
	dup++;
	for (int i = 0; i < v; i++) {
		if (arr[a][i] == 1 && visit_ary[i] != 1) {
			result[now_ptr][i] = 1;
			dfs(i);
		}
	}

}
int main() {
	cin >> v;

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> arr[i][j];
		}
	}

	//for (int i = 0; i < v; i++) {
	//	dfs_now_ptr = i;
	//	bfs(i);

	//	for (int j = 0; j < v+1; j++) {
	//			bfs_visit_ary[j]= 0;
	//			queue[j] = 0;
	//	}
	//	front = 0;
	//	rear = 1;
	//}

	for (int i = 0; i < v; i++) {
		now_ptr = i;
		dfs(i);
		dup = 0;
		for (int j = 0; j < v; j++) {
			visit_ary[j] = 0;
		}
	}
	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cout << result[i][j]<<" ";
		}
		cout << endl;
	}

	return 0;
}