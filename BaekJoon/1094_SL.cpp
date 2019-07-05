#include <iostream>
using namespace std;

int main() {

	int num = 0, sum = 0, stick = 0; // input , input 값의 합, 막대기 수
	int arr[7] = { 1,2,4,8,16,32,64 };
	cin >> num;

	for (int i = 6; i >= 0; i--) {
		if (sum == num) break;
		if (arr[i] + sum <= num) {
			sum += arr[i];
			stick++;
		}
	}

	cout << stick;
	return 0;
}

//length 나누기 전에 인풋 값보다 큰지 보면서 '/2',continue하면서 while문 내 if문 반복.
//이후 length보다 인풋이 크면 스틱개수 더해주고, 위에 한 것처럼 /2하고, 원래값에서 - length
//이러고 다시 while문 맨 처음으로. 마지막에 stick 개수 출력

//내 코드에서 저 arr ㅋㅋㅋㅋ 차라리 64부터 저장했으면 더 편했을 듯!