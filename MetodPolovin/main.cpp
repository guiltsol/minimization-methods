#include "metods.h"
int main() {
	setlocale(LC_ALL, "rus");
	double eps = 0.01;
	double a = 4;
	double b = 5;
	cout << "����� ���������:\n";
	met_dix(a, b, eps);
	cout << "\n";
	cout << "����� ��������:\n";
	met_perebora(a, b, eps);
	cout << "\n";
	cout << "����� ������������ ������:\n";
	met_poisk(a, b, eps);
	cout << "\n";
	cout << "����� �������� �������:\n";
	met_sechen(a, b, eps);
	cout << "\n";
	cout << "����� ������� �����:\n";
	met_middot(a, b, eps);
	cout << '\n';
	cout << "����� ����:\n";
	met_hord(a, b, eps);
	cout << '\n';
	cout << "����� �������:\n";
	met_nyton(a, b, eps);
	cout << '\n';
	cout << "����� �������-�������:\n";
	met_nyton_rafson(a, b, eps);
	cout << '\n';
	cout << "����� �������-����������:\n";
	met_nyton_mark(a, b, eps);
	cout << '\n';
	return 0;
}