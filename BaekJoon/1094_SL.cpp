#include <iostream>
using namespace std;

int main() {

	int num = 0, sum = 0, stick = 0; // input , input ���� ��, ����� ��
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

//length ������ ���� ��ǲ ������ ū�� ���鼭 '/2',continue�ϸ鼭 while�� �� if�� �ݺ�.
//���� length���� ��ǲ�� ũ�� ��ƽ���� �����ְ�, ���� �� ��ó�� /2�ϰ�, ���������� - length
//�̷��� �ٽ� while�� �� ó������. �������� stick ���� ���

//�� �ڵ忡�� �� arr �������� ���� 64���� ���������� �� ������ ��!