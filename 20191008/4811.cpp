//////////////////// 30 �� �� �����ư�. �ФФ�  13���� ���� ����� ���ư� �ФФФ�
// long long vector -> �ȵ�
// string hash �� Ǯ� �ߺ��� �Ǿ ���� ������ ������ �ȵǵ���~! -> �ȵ� ��
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

vector <vector <long long>> pill_dp(31, vector<long long> (31, -1)) ;
long long pill(int half, int one) {
	if (pill_dp[half][one] == -1) {
		long long sum = 0;
		if (half > 0) {
			sum += pill(half - 1, one);
		}
		if (one > 0) {
			sum += pill(half + 1, one - 1);
		}
		pill_dp[half][one] = sum;
		return pill_dp[half][one];
	}
	else return pill_dp[half][one];
}
int main(void) {
	// �����ڸ� 0��, �Ѱ�¥�� 0������ ����� �� : 0
	pill_dp[0][0] = 0;

	// �����ڸ� n��, �Ѱ�¥�� 0������ ����� �� : 1 
	// ���� �ϳ��� �Դ� ����ۿ� ����. 11, 111, 1111 ~~
	for (int i = 1; i < 31; i++) {
		pill_dp[i][0] = 1;
	}

	while (1) {
		int caseNum;
		cin >> caseNum;
		if (caseNum == 0) break;
		cout<<pill(0, caseNum)<<endl;
	}
}








//
//#include"pch.h"
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//using namespace std;
//long long dp[1001][1001] = { 0, };
////long long result = 0;
//// 'W' : 1, 'H': 0
//void pill(int one, int half, string str, unordered_map <string, int> string_hash, long long result) {
//	if (one == 0 && half == 0) {
//		//for (int i = 0; i < v.size(); i++) {
//		//	cout << v[i];
//		//}
//		//cout << endl;
//		string_hash.insert(pair<string, int>(str, 1));
//
//	}
//	if (one > 0) {
//		str.push_back(0);
//		pill(one - 1, half + 1, str, string_hash, result+1);
//		str.pop_back();
//	}
//	if (half > 0) {
//		str.push_back(1);
//		pill(one, half - 1, str, string_hash, result+1);
//		str.pop_back();
//	}
//	dp[one][half] = result;
//	cout << one <<" "<<half<<" "<<dp[one][half] << endl;
//}
//int main(void) {
//	while (1) {
//		int caseNum;
//		cin >> caseNum;
//		if (caseNum == 0) break;
//		unordered_map <string, int> string_hash;
//		string s;
//		long long result = 0;
//		pill(caseNum, 0,s, string_hash, result);
//		cout << dp[caseNum][caseNum]<< endl;
//		result = 0;
//	}
//}