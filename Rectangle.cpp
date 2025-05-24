#include <iostream>
using namespace std;

struct Point {
	double x;
	double y;

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

double Length(Point A, Point B) {
	return sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

const double EPS = 0.00001;

int main() {
	double x1, x2, y1, y2, x3, y3, AB, BC, AC;
	bool isRightTriangle = 0;
	cout << "Input three coordinate pairs of points on plane" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point A(x1, y1);
	Point B(x2, y2);
	Point C(x3, y3);
	Point D(0,0);
	AB = Length(A, B);
	BC = Length(B, C);
	AC = Length(A, C);
	double maxx = max(max(AB, BC), AC);
	double minn = min(min(AB, BC), AC);
	double avrg = AB + BC + AC - (maxx + minn);
	isRightTriangle = (maxx * maxx - minn * minn - avrg * avrg < EPS);

	if (isRightTriangle) {
		if (AB == maxx) {
			D.x = A.x + B.x - C.x;
			D.y = A.y + B.y - C.y;
		}
		if (BC == maxx) {
			D.x = B.x + C.x - A.x;
			D.y = B.y + C.y - A.y;
		}
		if (AC == maxx) {
			D.x = C.x + A.x - B.x;
			D.y = C.y + A.y - B.y;
		}
		cout << "Triangle is right, points of coordinate: " << D.x << ' ' << D.y << endl;
	}
	else cout << "Not a right triangle" << endl;
	return 0;
}