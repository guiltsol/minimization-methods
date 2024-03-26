#include "metods.h"
int main() {
	setlocale(LC_ALL, "rus");
	double eps = 0.01;
	double a = 4;
	double b = 5;
	cout << "Метод дихотомии:\n";
	met_dix(a, b, eps);
	cout << "\n";
	cout << "Метод перебора:\n";
	met_perebora(a, b, eps);
	cout << "\n";
	cout << "Метод поразрядного поиска:\n";
	met_poisk(a, b, eps);
	cout << "\n";
	cout << "Метод золотого сечения:\n";
	met_sechen(a, b, eps);
	cout << "\n";
	cout << "Метод средней точки:\n";
	met_middot(a, b, eps);
	cout << '\n';
	cout << "Метод хорд:\n";
	met_hord(a, b, eps);
	cout << '\n';
	cout << "Метод Ньютона:\n";
	met_nyton(a, b, eps);
	cout << '\n';
	cout << "Метод Ньютона-Рафсона:\n";
	met_nyton_rafson(a, b, eps);
	cout << '\n';
	cout << "Метод Ньютона-Марквардта:\n";
	met_nyton_mark(a, b, eps);
	cout << '\n';
	return 0;
}