#include "pch.h"
#include <iostream>
using namespace std;

int main(void) {
	int testNum=10, idx = 0, tmp;
	while (testNum--) {
		cin >> tmp;
		int result = 0;
		int arr[100][100] = { 0 };
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		//1은 아래로, 2는 위로 
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (arr[j][i] == 1) {
					for (int k = j+1; k < 100; k++) {
						if (arr[k][i] == 2) {
							result++;
							break;
						}
						else if (arr[k][i] == 1) {
							break;
						}
					}
				}
				else if (arr[j][i] == 2) {
					for (int k = j-1; k >= 0; k--) {
						if (arr[k][i] == 1) {
							result++;
							break;
						}
						else if (arr[k][i] == 2) {
							break;
						}
					}
				}
			}
			
		}

		idx++;
		cout << "#" << idx <<" "<<result/2<<endl;
	}
}