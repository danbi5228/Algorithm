#include<iostream>
using namespace std;

int main(void) {
	int a, b, c;        //�Է¹��� 3���� ���� 
	int arr[10] = { 0 };    //0���� �ʱ�ȭ 

	cin >> a >> b >> c;    // ���� 3������ �޽��ϴ�. 

	int result = a*b*c;

	//1�� �ڸ��� ��� �ɴϴ�.
	//resutl �� 0 �� �Ǹ� while���� ���������ϴ�. 
	while (result != 0) {
		arr[result % 10] += 1;
		result /= 10;
	}

	//���. 
	for (int i = 0; i<10; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}