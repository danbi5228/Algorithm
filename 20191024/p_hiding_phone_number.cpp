/*
프로그래머스 - 핸드폰 번호 가리기
*/

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	string answer = "";
	for (int i = 0; i < phone_number.size() - 4; i++) {
		phone_number[i] = '*';
	}
	return phone_number;
}

//python 
//def solution(phone_number) :
//	length = len(phone_number)
//	answer = '*' * (length - 4)
//	answer += phone_number[length - 4:length]
//	return answer