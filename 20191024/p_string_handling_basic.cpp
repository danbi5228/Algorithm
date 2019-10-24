/*
프로그래머스 - 문자열 다루기 기본
*/
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	if (s.size() == 4 or s.size() == 6) {
		for (int i = 0; i < s.size(); i++) {
			if (int(s[i]) > 57) {
				return false;
			}
		}
		return true;
	}
	return false;
}

// python
//def solution(s) :
//	if len(s) == 6 or len(s) == 4 :
//		if s.isnumeric() :
//			return True
//			return False