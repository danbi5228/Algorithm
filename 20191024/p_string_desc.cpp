/*
프로그래머스 - 문자열 내림차순으로 배치하기
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	sort(s.begin(), s.end(), greater<char>());
	return s;
}

//python
//def solution(s) :
//	s = sorted(s, reverse = True)
//	s = ''.join(s)
//	return s