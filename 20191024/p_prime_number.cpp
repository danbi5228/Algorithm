/*
프로그래머스 - 소수찾기
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector <bool> prime(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (prime[i] == true) {
			answer++;
			for (int j = 2; i*j <= n; j++) {
				prime[i*j] = false;
			}
		}
	}
	return answer;
}