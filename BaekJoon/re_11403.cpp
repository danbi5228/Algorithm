#include <iostream>
using namespace std;

int **arr;
int **newarr;
int num;
int visitarr[100] = { 0, };
int now_point_num = 0;

void dfs(int x) {
	for (int i = 0; i < num; i++) {
		if (arr[x][i] == 1 && visitarr[i] != 1) {
			newarr[now_point_num][i] = 1;
			visitarr[i] = 1;
			dfs(i);
		}
	}
	
}

int main() {
	cin >> num;
	arr = new int* [num];
	
	for (int i = 0; i < num; i++) {
		arr[i] = new int [num];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}

	newarr = new int*[num];

	for (int i = 0; i < num; i++) {
		newarr[i] = new int[num];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			newarr[i][j] = 0;
		}
	}

	for (int i = 0; i < num; i++) {
		now_point_num = i;
		dfs(now_point_num);
		for (int j = 0; j < num; j++) {
			visitarr[j] = 0;
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << newarr[i][j]<<" ";
		}
		cout << endl;
	}
	
	////메모리 해제
	//for (int i = 0; i < num; i++) {
	//	delete[] arr;
	//} 
	//delete arr;

}