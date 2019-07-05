#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int L, A, B, C, D;
	int i = 1;
	int max_day = 0;

	cin >> L >> A >> B >> C >> D;
	
	while ((C * i) < A) {
		i++;
	}

	max_day = i;
	i = 1;
	
	while ((D * i) < B) {
		i++;
	}
	max_day = max(max_day, i);

	cout << L - max_day;


	return 0;
}


//int main() {
//	int L, A, B, C, D = 0;
//	int i = 0, sum = 0;
//	int max_day = 0, max_day2 = 0;
//	cin >> L >> A >> B >> C >> D;
//
//	for (i = 1; sum <= A; i++) {
//		sum = C * i;
//		max_day++;
//		cout << sum << " " << C << " " << i << " " << endl;
//	}
//	
//	sum = 0;
//	i = 0;
//
//	for (i = 1; sum <= B; i++) {
//		sum = D * i;
//		max_day2++;
//
//		cout << sum << " " << D << " " << i << " " << endl;
//	}
//
//	//cout << max_day << " " << max_day2 << endl;
//	max_day = max(max_day, max_day2);
//
//	cout << L - max_day;
//
//	return 0;
//}

// 몫을 더해주고 나머지가 0이 아니면 +1


/*while (i++) {
if (B >= sum) {
sum = D * i;
}
}
*/