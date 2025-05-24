#include <string>
#include <iostream>
using namespace std;
//Найти корень многочлена на [а,b], если он находится методом Ньютона

const double EPS = pow(0.1, 15); // Точность рассчета

int Max(int a, int b) {
	return a >= b ? a : b;
}

double Evaluate(int degree, double* polinom, double point) {// Вычисляет значение многочлена в точке
	double result = 0;

	for (int i = degree; i >= 0; i--) {
		result += polinom[i] * pow(point, i);
	}
	return result;
}

bool isnumber(char symbol) { return (symbol - '0' >= 0) && (symbol - '0' < 10); } //Проверяет символ, является ли он цифрой (0-9)

void Initialize(double* arr, int size){ //initialize array of double
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

//void Differentiate(double* dough, double* polinom, int degree) { //Находит производную(функцию)
//	for (int i = degree; i > 0; i--)
//		dough[i - 1] = polinom[i] * i;
//}

//term of a polinom represented as: (+,-)A_kx^k
void ParsePolinom(string polinom, double* arrepresentation) {//Нехитрыми манипуляциями переводит многочлен-строку в многочлен-массив
	short sign = 1;
	short degree = 0;
	string coefficient = "";

	for (int index = 0; polinom[index] != '\0';) {
		if ((polinom[index] == '+') || (polinom[index] == '-')) {
			sign = polinom[index] == '+' ? 1 : -1;
			index++;
		}
		while (polinom[index] != '_') {
			coefficient += polinom[index];
			index++;
		}
		while (polinom[index - 1] != '^') index++;
		while (isnumber(polinom[index])) { degree = degree * 10 + (polinom[index] - '0'); index++; }
		arrepresentation[degree] = stod(coefficient) * sign;
		coefficient = "";
		degree = 0;
	}
}

int FindDegree(string polinom) {//Находит степень многочлена-строки
	int index = 0;
	int degree = 0;
	int temp = 0;

	while (polinom[index] != '\0') {
		if (polinom[index] == '^') {
			index++;
			while (isnumber(polinom[index])) {
				temp = temp * 10 + (polinom[index] - '0');
				index++;
			}
			degree = Max(degree, temp);
			temp = 0;
			index--;
		}
		index++;
	}
	return degree;
}

double NewtonsMethod(double a, double b, double* polinom, int degree) {
	double c = (a + b) / 2;
	if ((b - a) < EPS || Evaluate(degree, polinom, c) == 0) {
		//delete[] polinom;
		return c;
	}
	if (Evaluate(degree, polinom, c) * Evaluate(degree, polinom, a) > 0)
		return NewtonsMethod(c, b, polinom, degree);
	return NewtonsMethod(a, c, polinom, degree);
}

//double NewtonSqueeze(double* polinom, double* derivative, int degree, double x) {// функция, осуществляющая сжатие вблизи окрестности корня искомой функции
//	return x - Evaluate(degree, polinom, x) / Evaluate(degree - 1, derivative, x);
//}

int main() {
	string input = "1_2x^2-7_0x^0";
	double a, b;
	//bool flag = 0;
	int degree = 0;
	double result = 0;
	cout << "Input polinom represented as A_kx^k+B_ix^i-... , then a,b from needed segment [a,b], sign of polinom must differ on the ends" << endl;
	//getline(cin, input);
	cin >> a >> b;

	degree = FindDegree(input); // Блок инициализации и создания массивов для производной и самого многочлена
	double* polinom = new double[degree + 1];
	Initialize(polinom, degree + 1);
	ParsePolinom(input, polinom);
	result = NewtonsMethod(a, b, polinom, degree);
	cout << NewtonsMethod(a, b, polinom, degree) << endl;

	if (result < EPS)
		cout << "Root is " << result;
	else
		cout << "Unable to find a root or there is no root at all, try another segment";
	//double* derivative = new double[degree];

	//ParsePolinom(input, polinom); //Блок заполнения массивов производной и многочлена
	//Differentiate(derivative, polinom, degree);
	//
	//x_n = NewtonSqueeze(polinom, derivative, degree, x_prev); // Блок собственно с методом Ньютона
	//x_next = NewtonSqueeze(polinom, derivative, degree, x_n);
	//int haltFactor = 0; //Вероятно, можно придумать условие получше
	//for (;;) {
	//	if (haltFactor > 100) { flag = 1; break; }
	//	if (abs((x_next - x_n) / (1 - (x_next - x_n) / (x_n - x_prev))) < eps) { break; }
	//	x_prev = x_n;
	//	x_n = x_next;
	//	x_next = NewtonSqueeze(polinom, derivative, degree, x_n);
	//	haltFactor++;
	//	cout << x_next << endl;
	//}
	//if (flag || (x_next < a) || (x_next > b)) cout << "Impossible to find a root in this segment, try another segment";
	//else cout << "Root found: " << x_next;
	return 0;
}
//07.10.2024 3:19