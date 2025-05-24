#include <iostream>
using namespace std;
// ����� ��������� � ������� ���������� �����, �� ��������� �����
//Enhanced 08.10.24 3:24 - ������ ������� ��� ������ ������ ����, ���� �� ������������ �������

int CalculateDifference(int ticket) { //�������� ����� ������� �������� � ����� ������� ��������
	return ticket / 100000 + ticket / 10000 % 10 + ticket / 1000 % 10 - (ticket / 100 % 10 + ticket / 10 % 10 + ticket % 10);
}

int Min(int a, int b) { // ���������� �� � � �
	return a <= b ? a : b;
}

//��� ������ ������ �������� ������� �������, ����� �������, ����� �����

int FindLuckyFromRooftop(int ticket, int difference){ // ����������� ����� � 0 �� 9 � ������� �������� �� ��������� ���� ������� � ������� ��������
	int shift = 0;
	int t4 = ticket / 100 % 10, t5 = ticket / 10 % 10, t6 = ticket % 10;

	if (t6 < 9 && difference > 0) {
		shift += Min(difference, 9 - t6);
		difference -= shift;
	}
		if (t5 < 9 && difference > 0) {
			shift += Min(difference, 9 - t5) * 10;
			difference -= shift / 10;
		}
		if (t4 < 9 && difference > 0) {
			shift += Min(difference, 9 - t4) * 100;
		}
		return ticket + shift;
}

int FindLuckyFromBottom(int ticket, int difference) { // ����������� ����� � 9 �� 0 � ������� �������� �� ��������� ���� ������� � ������� ��������
	int shift = 0;
	difference *= -1;
	int t4 = ticket / 100 % 10, t5 = ticket / 10 % 10, t6 = ticket % 10;
	
	if (t6 > 0 && difference > 0) { 
		shift -= Min(difference, t6);
		difference += shift;
	}
	if (t5 > 0 && difference > 0) {
		shift -= Min(difference, t5) * 10;
		difference += shift / 10 % 10;
	}
	if (t4 > 0 && difference > 0) {
		shift -= Min(difference, t4) * 100;
	}
	return ticket + shift;
}

int Next(int luckyTicket) {//������� ��������� ���������� �����
	// 135901
	if ((luckyTicket % 10 != 0) && (luckyTicket / 10 % 10 != 9))
		luckyTicket += 9;
	else if ((luckyTicket / 100 % 10 != 9) && (luckyTicket / 10 % 10 != 0))
		luckyTicket += 90;
	else {
		luckyTicket = (luckyTicket / 1000 + 1) * 1000;
		luckyTicket = FindLuckyFromRooftop(luckyTicket, CalculateDifference(luckyTicket));
	}
	return luckyTicket;
}

int Previous(int luckyTicket) {//������� ���������� ���������� �����
	// 135901
	if ((luckyTicket % 10 != 9) && (luckyTicket / 10 % 10 != 0))
		luckyTicket -= 9;
	else if ((luckyTicket / 100 % 10 != 0) && (luckyTicket / 10 % 10 != 9))
		luckyTicket -= 90;
	else {
		luckyTicket = (luckyTicket / 1000 - 1) * 1000 + 999;
		luckyTicket = FindLuckyFromBottom(luckyTicket, CalculateDifference(luckyTicket));
	}
	return luckyTicket;
}

int main() {
		int ticket;
		cin >> ticket;
		int luckyTicket1 = 0;
		int luckyTicket2 = 0;
		int difference = CalculateDifference(ticket);

		if (difference != 0) {
			if (difference > 0) {
				luckyTicket1 = FindLuckyFromRooftop(ticket, difference);
				luckyTicket2 = Previous(luckyTicket1);
			}
			else {
				luckyTicket1 = FindLuckyFromBottom(ticket, difference);
				luckyTicket2 = Next(luckyTicket1);
			}
			cout << "Nearest lucky ticket is " << (abs(ticket - luckyTicket1) < abs(ticket - luckyTicket2) ? luckyTicket1 : luckyTicket2) << endl;
		}
		else cout << "You just written lucky ticket!" << endl;
	return 0;
}
//04.10.24, � ������� �� ��� ������ ��� ����� � ��� � ����� ������, ������: �� ������, �� �������� �������... 5:55 ���� �� �����