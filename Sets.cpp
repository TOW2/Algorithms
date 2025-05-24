#include <iostream>
using namespace std;

const int SIZE = 10;
int Universum[SIZE]{ 0,1,2,3,4,5,6,7,8,9 };

void Swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void BubbleSort(int* A) {
	for (int i = SIZE - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (A[j] > A[j + 1])
				Swap(A[j + 1], A[j]);
}

//bool iselement(int x, int* M, int a, int b) {
//	int c = (a + b) / 2;
//	if (a == b) return false;
//	if (x == M[c]) return true;
//	if (x > M[c]) iselement(x, M, c, b);
//	if (x < M[c]) iselement(x, M, a, c);
//}

void SetOut(int* Set, int setSize) {
	for (int i = 0; i < setSize; i++)
		cout << Set[i];
	cout << '\n';
}

int* Intersection(int* A, int* B, int &size) {
	int* intersection = new int[2 * SIZE];
	int index = 0;
	int i = 0, j = 0, k = 0;

	while (i < 10 && j < 10) {
		if (A[i] < B[j]) { i++; }
		else {
			if (A[i] > B[j]) { j++; }
			else {
				intersection[k] = A[i];
				i++;
				j++;
				k++;
			}
		}
	}
	size = k;
	return intersection;
}

int* Subtraction(int* A, int* B, int &size) {
	int* subtracted = new int[10],
		i = 0,
		j = 0,
		k = 0;
	while (i < 10 && j < 10) {
		if (A[i] < B[j]) {
			subtracted[k++] = A[i++];
		}
		else {
			if (A[i] > B[j]) { j++; }
			else { i++; j++; }
		}
	}
	while (i < 10) {
		subtracted[k++] = A[i++];
	}
	size = k;
	return subtracted;
}

int* Union(int* A, int* B, int &size) {
	int* united = new int[SIZE * 2];

	int i = 0, j = 0, k = 0;

	while (i < 10 && j < 10) {
		if (A[i] < B[j]) {
			united[k] = A[i];
			i++;
		}
		else if (A[i] > B[j]) {
			united[k] = B[j];
			j++;
		}
		else {
			united[k] = A[i];
			i++;
			j++;
		}
		k++;
	}

	while (i < 10) {
		united[k] = A[i];
		k++;
		i++;
	}

	while (j < 10) {
		united[k] = B[j];
		k++;
		j++;
	}

	size = k;
	return united;
}

int* unionWithoutIntersection(int* A, int* B, int USize, int interSize, int& size) { //AwB \ AwthoutB
	int* Disjuncted = new int[SIZE * 2];
	Disjuncted = Subtraction(Union(A, B, USize), Intersection(A, B, interSize), size);
	return Disjuncted;
}

int main() {
	int A[SIZE] = {1,2,3,5,5,5,5,5,5,5};
	int B[SIZE] = {4,5,6,7,7,7,7,7,9,8};
	int* C;

	//BubbleSort(Universum);
	BubbleSort(A);
	BubbleSort(B);
	int interSize = 0;
	//C = Intersection(A, B, interSize);
	C = unionWithoutIntersection(A, B, 20, 10, interSize);
	SetOut(C, interSize);

	for(int i = 0; i < SIZE; i++)
	cout << Universum[i];
	delete[] C;
	return 0;
}
//14.10.2024 00:53