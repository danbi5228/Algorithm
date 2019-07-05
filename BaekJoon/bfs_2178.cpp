//#include <iostream>
////#include <vector>
////#include <algorithm>
//using namespace std;
//
//int N, M;
//char ** str;
//int front = 0;
//int rear = 0;
//int cnt = 0;
//
////vector <int> result;
//
//int result[1000000] = { 0, };
//int result_idx = 0;
//
//bool inRange(int y, int x) {
//	return (y >= 0 && y < N && x >= 0 && x < M);
//}
//
//struct struct_1 {
//	int y;
//	int x;
//	int cnt;
//};
//struct_1 queue[1000000] = { 0, };
//
//void bfs(int y, int x) {
//	
//	queue[rear++] = { y,x,++cnt};
//
//	while (front != rear) {
//		if (queue[front].y == N - 1 && queue[front].x == M - 1) {
//			result[result_idx]=queue[front].cnt; // 결과저장
//			result_idx++;
//			return;
//		}
//
//		int i = queue[front].y; int j = queue[front].x; int z = queue[front].cnt;
//		front++;
//
//		if (str[i][j] == '0') continue;
//
//		if (inRange(i, j + 1) && str[i][j + 1] == '1') { // 오른쪽 확인
//			queue[rear] = { i,j + 1, z+1 };
//			rear++;
//		}
//		if (inRange(i + 1, j) && str[i + 1][j] == '1') { // 아래 확인
//			queue[rear] = { i + 1, j, z + 1 };
//			rear++; 
//		}
//
//		if (inRange(i, j - 1) && str[i][j - 1] == '1') { // 왼쪽 확인
//			queue[rear] = { i , j - 1,z+1 };
//			rear++;
//		}
//
//		if (inRange(i - 1, j) && str[i - 1][j] == '1') { // 위 확인
//			queue[rear] = { i - 1, j ,z+1 };
//			rear++;
//		}
//		str[i][j] = '0'; // 방문한 위치 체크
//	}
//
//}
//
//void quickSort(int arr[], int left, int right) {
//	int i = left, j = right;
//	int pivot = arr[(left + right) / 2];
//	int temp;
//	do {
//		while (arr[i] < pivot)
//			i++;
//		while (arr[j] > pivot)
//			j--;
//		if (i <= j) {
//			temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//			i++;
//			j--;
//		}
//	} while (i <= j);
//
//	if (left < j)
//		quickSort(arr, left, j);
//
//	if (i < right)
//		quickSort(arr, i, right);
//}
//
//int main() {
//	cin >> N >> M;
//
//	str = new char*[N+1];
//	for (int i = 0; i < N+1; i++) {
//		str[i] = new char[M+1];
//	}
//	for (int i = 0; i < N; i++) {
//		cin >> str[i];
//	}
//
//	bfs(0, 0);
//
//	quickSort(result, 0, result_idx-1);
//	cout << result[0];
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char ** str;
int front = 0;
int rear = 0;
int cnt = 0;

vector <int> result;

bool inRange(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

struct struct_1 {
	int y;
	int x;
	int cnt;
};
struct_1 queue[1000000] = { 0, };

void bfs(int y, int x) {

	queue[rear++] = { y,x,++cnt };

	while (front != rear) {
		if (queue[front].y == N - 1 && queue[front].x == M - 1) {
			result.push_back(queue[front].cnt); // 결과를 벡터에 넣음
			return;
		}

		int i = queue[front].y; int j = queue[front].x; int z = queue[front].cnt;
		front++;

		if (str[i][j] == '0') continue;

		if (inRange(i, j + 1) && str[i][j + 1] == '1') { // 오른쪽 확인
			queue[rear] = { i,j + 1, z + 1 };
			rear++;
		}
		if (inRange(i + 1, j) && str[i + 1][j] == '1') { // 아래 확인
			queue[rear] = { i + 1, j, z + 1 };
			rear++;
		}

		if (inRange(i, j - 1) && str[i][j - 1] == '1') { // 왼쪽 확인
			queue[rear] = { i , j - 1,z + 1 };
			rear++;
		}

		if (inRange(i - 1, j) && str[i - 1][j] == '1') { // 위 확인
			queue[rear] = { i - 1, j ,z + 1 };
			rear++;
		}
		str[i][j] = '0';
	}

}

int main() {
	cin >> N >> M;

	str = new char*[N+1];
	for (int i = 0; i < N+1; i++) {
		str[i] = new char[M+1];
	}
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	bfs(0, 0);

	sort(result.begin(), result.end());
	cout << result[0];
	return 0;
}




// 하늘코드
// 얘랑 비슷하게 가려면, 큐에 넣을때 0으로 바꿔줘야함

//str[i + 1][j] = 0
//str[i][j + 1] = 0
//str[i - 1][j] = 0
//str[i][j - 1] = 0

//위와같은식으로 바꿔줘야함! 그리고 컨티뉴 필요없어짐..후
//static void bfs(Point vertex) {
//	//		if(map[0][0]==0){
//	//			return;
//	//		}
//	queue.add(vertex);
//	isVisited[vertex.i][vertex.j] = 1;
//	while (!queue.isEmpty()) {
//		vertex = queue.poll();
//		if (vertex.i == n && vertex.j == m) {
//			break;
//		}
//
//		for (int dir = 0; dir < 4; dir++) {
//			// 0: 상 , 1: 하, 2: 좌, 3 : 우
//			Point next_vertex = new Point(vertex.i + direction.get(dir).i, vertex.j + direction.get(dir).j);
//			if ((next_vertex.i) >= n || (next_vertex.i) < 0 || (next_vertex.j) >= m || (next_vertex.j) < 0) {
//				continue;
//			}
//			if (map[next_vertex.i][next_vertex.j] == 1 && isVisited[next_vertex.i][next_vertex.j] == 0) {
//				//					System.out.println(next_vertex.j + ", " + next_vertex.i);
//				queue.add(next_vertex);
//				isVisited[next_vertex.i][next_vertex.j] = isVisited[vertex.i][vertex.j] + 1;
//			}
//
//		}
//
//	}
//
//}