/*
프로그래머스 - 문자열 내 p와 y의 개수
*/
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int num_p = 0, num_y = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P' or s[i] == 'p') {
			num_p++;
			continue;
		}
		if (s[i] == 'Y' or s[i] == 'y') {
			num_y++;
		}
	}
	return (num_p == num_y ? true : false);
}

//python
//def solution(s) :
//	s = s.lower()
//	num_p = 0
//	num_y = 0
//
//	for alpha in s :
//if alpha == 'p' :
//	num_p += 1
//	continue
//	if alpha == 'y' :
//		num_y += 1
//		return True if num_p == num_y else False