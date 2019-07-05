//∆Ê¿® ∆Æ∏Æ...!!!

#include <stdio.h>

//using namespace std;


int main() {
	int N, Npoint = 1;
	int inputArr[100001] = { 0, };
	int weightArr[100001] = { 0, };

	scanf("%d%*c",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%*c", &inputArr[i]);
	}
	
	while (Npoint <= N) {
		if (inputArr[Npoint1] + weightArr[Npoint] != Npoint) {
			(Npoint%2 != 0)
			for ((Npoint%2 != 0 ? (int j = Npoint; j > 0; j--):) {
				inputArr[j]
			}
		}
	}
	return 0;
}
//int main() {
//	int N = 0, point1 = 1, point2, result_point = 1;
//	int inputArr[100001] = { 0, };
//	int result[100001] = { 0, };
//	char empty;
//	scanf("%d%*c",&N);
//	point2 = N;
//
//	for (int i = 1; i <= N; i++) {
//		scanf("%d%*c", &inputArr[i]);
//		
//	}
//
//	while (point1 <= point2) {
//			if (inputArr[point1] != point1) {
//				for (int i = point1; i <= N; i++) {
//					if (inputArr[i] == point1) {
//	//					cout << "i : " << i << " point1 : " << point1 << endl;
//						result[result_point] = (i - point1);
//						for (int j = i; j > point1; j--) {
//							inputArr[j] = inputArr[j - 1];
//						}
//						inputArr[point1] = point1;
//						break;
//					}
//				}
//			}
//			point1++;
//			result_point++;
//
////			cout << "inputArr : ";
////			for (int i = 1; i <= N; i++) {
////				cout << inputArr[i] << " ";
////			}
////			cout << endl; 
//			if (inputArr[point2] != point2) {
//				for (int i = point1; i <= N; i++) {
//					if (inputArr[i] == point2) {
////						cout << "i : " << i << " point2 : " << point2 << endl;
//						result[result_point] = (point2 - i);
//						for (int j = i; j < point2; j++) {
//							inputArr[j] = inputArr[j+1];
//						}
//						inputArr[point2] = point2;
//						break;
//					}
//				}
//			}
//			point2--;
//			result_point++;
//
////			cout << "inputArr : ";
////			for (int i = 1; i <= N; i++) {
////				cout << inputArr[i] << " ";
////			}
////			cout << endl;
//
//	}
//
//	for (int i = 1; i <= N; i++) {
//		printf("%d \n", result[i]);
//		//cout << result[i] << endl;
//	}
//
//	return 0;
//}