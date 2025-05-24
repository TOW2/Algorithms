#include <iostream>
using namespace std;

//����� ���������� �� O(log(n)) � ������� ������

void PrintMatrix(int (*Matrix)[2]) { // ������� �������, ��������������� �����
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cout << Matrix[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}

void MultiplyMatrices(int (*MatrixA)[2], int (*MatrixB)[2]) { //�������� ������� � ��������� ��������� � MatrixA
	int tempMatrix[2][2] = {};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int z = 0; z < 2; z++)
				tempMatrix[i][j] += MatrixA[i][z] * MatrixB[z][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			MatrixA[i][j] = tempMatrix[i][j];
}

//void MatrixToBinaryPower(int (*Matrix)[2], int power) { //�������� ������� � ����� �������, ������� ��� power = 2^k, k - �����������
//	if (power == 0) { Matrix[0][0] = 1; Matrix[1][0] = 0; Matrix[0][1] = 0; Matrix[1][1] = 1; }
//	else
//	for (int i = power; i > 0; i--)
//		MultiplyMatrices(Matrix, Matrix);
//}
//
//void Refresh(int (*Matrix)[2]) {
//	Matrix[0][0] = 1;
//	Matrix[0][1] = 1;
//	Matrix[1][0] = 1;
//	Matrix[1][1] = 0;
//}


int main() {
	unsigned int number;
	int index = 0;
	int temp = 0;
	bool binaryRepresentation[100] = {};
	int powerHolder[2][2] = { {1,1},{1,0} };
	int inverseMatrix[2][2] = { {0,1},{1,-1} };
	int result[2][2] = { {1,0},{0,1} };

	cout << "Insert number: ";
	cin >> number;
	temp = number;
	number--;

	while (number > 0) { //���������� ������ -> �������� ������
		binaryRepresentation[index] = number % 2;
		number /= 2;
		index++;
	}

	for (int i = 0; i <= index; i++) { //������� ���������� � ������� + ��������
		if (binaryRepresentation[i]) {
			MultiplyMatrices(result, powerHolder);
		}
		MultiplyMatrices(powerHolder, powerHolder);
		//PrintMatrix(result);
	}
	if (number % 2) {cout << result[0][1]; }
	else cout << result[0][0];
	return 0;
}