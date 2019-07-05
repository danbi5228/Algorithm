#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, KIM, LM, roundNum = 1;
	int i = 0;
	cin >> N >> KIM >> LM;

	
	while (1) {
		(KIM % 2 == 0 ? KIM /= 2 : KIM = (KIM / 2) + 1);
		(LM % 2 == 0 ? LM /= 2 : LM = (LM / 2) + 1);
		if (KIM == LM) {
			cout << roundNum;
			break;
		}
		roundNum++;
	}
	return 0;
}

//int main() {
//	vector <int> people;
//
//	int roundNum = 1, N, KIM, LM;
//	int a, b, flag = 0;
//	cin >> N >> KIM >> LM;
//
//	for (int i = 0; i < N; i++) {
//		people.push_back(i + 1);
//	}
//	
//	if (N % 2 == 0) {
//		while (1) {
//			for (int i = 0; i < N / 2; i++) {
//				a = people[0];
//				b = people[1];
//
//				//cout << "a : " << a << " b : " << b << " num : " << roundNum << endl;
//
//				if ((a == KIM && b == LM) || (a == LM && b == KIM)) {
//					cout << roundNum;
//					return 0;
//				}
//
//				if (a == KIM || a == LM) {
//					people.push_back(a);
//				}
//				else {
//					people.push_back(b);
//				}
//				people.erase(people.begin());
//				people.erase(people.begin());
//			}
//			N /= 2;
//			roundNum++;
//		}
//	}
//	else {
//		while (1) {
//			a = people[0];
//			b = people[1];
//
//			if (a > b) {
//				people.push_back(a);
//				people.erase(people.begin());
//				roundNum++;
//				continue;
//			}
//
//			//cout << "a : " << a << " b : " << b << " num : " << roundNum << endl;
//
//			if ((a == KIM && b == LM) || (a == LM && b == KIM)) {
//				cout << roundNum;
//				return 0;
//			}
//
//
//
//
//			if (a == KIM || a == LM) {
//				people.push_back(a);
//			}
//			else {
//				people.push_back(b);
//			}
//			people.erase(people.begin());
//			people.erase(people.begin());
//
//		}
//	}
//	return 0;
//}
//int main() {
//	
//	queue <int> people;
//
//	int roundNum = 1, N, Kim,Im;
//	int a = 0, b = 0, tmp = 0;
//	cin >> N >> Kim >> Im;
//
//
//	for (int j = 0; j < N; j++) {
//		people.push(j + 1);
//	}
//
//	
//
//	while (1) {
//
//		a = people.front();
//		people.pop();
//		b = people.front();
//		people.pop();
//
//		cout << "a : " << a << " b : " << b << " num : " << roundNum << endl;
//
//		if ((a == Kim && b == Im) || (a == Im && b == Kim)) {
//			cout << roundNum;
//			break;
//		}
//
//		// b 다음 꺼가 b보다 크면 연산 수행
//			// 자기보다 크면 push, pop, push 수행
//		// b 다음 꺼가 b보다 작으면
//
//		if (a < b) {
//			if (a == Kim || a == Im) {
//				people.push(a);
//			}
//			else people.push(b);
//		}
//
//		else {
//			people.push(a);
//			people.pop();
//			roundNum++;
//			continue;
//		}
//
//		tmp = people.front();
//
//		if (b > tmp) roundNum++;
//
//		/*if (a == N && flag == 0) {
//			flag = 1;
//			people.push(a);
//			roundNum++;
//			continue;
//		}
//
//		if (people.front() > a) {
//			b = people.front();
//			people.pop();
//		}
//		else {
//			people.push(a);
//		}
//
//		int tmp = people.front();
//		if (tmp < a) roundNum++;
//	}*/
//
//	}
//	return 0;
//}