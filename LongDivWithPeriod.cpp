#include <iostream>
using namespace std;
// ����� ������ �����, ���� ��� �������������
// a b �����������, ������� �������

const int arrsize = 150;

int main() {
	int decimalRepresentation[arrsize] = {};
	int divisible = 0;
	int divisor = 0;
	int index = 0;
	bool flag = 0;

	cin >> divisible >> divisor;

	int remainders[arrsize] = {};// ������ ��������, ������� = i, � [i] ������������ ������� ������� ���������
	cout << divisible / divisor; // ����� ����� �����
	divisible %= divisor;
	if (divisible != 0) cout << ','; // ���� ����� ������ �� �������, �������� �������

	for (index = 1; (index < arrsize - 1) && (divisible != 0);) { //������� � ������� 
		remainders[divisible] = index;
		divisible *= 10;
		decimalRepresentation[index] = divisible / divisor;
		divisible %= divisor;
		index++;
		if (remainders[divisible] != 0) {
			flag = 1;
			for (int i = 1; i < remainders[divisible]; i++)
				cout << decimalRepresentation[i];
			cout << '(';
			for (int i = remainders[divisible]; i < index; i++)
				cout << decimalRepresentation[i];
			cout << ')';
			return 0;
		}
	}

	if (!flag) {
		for (int i = 0; i < index; i++) {
			cout << decimalRepresentation[i];
		}
	}
	return 0;
}
//05.10.2024 20:15 