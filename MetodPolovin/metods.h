#pragma once
#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

double fun(double x) {
	double res = pow(4 - x, 3) / (9 * (2 - x));
	return res;
}
double fun_pr1(double x) {
	double res = (3*pow(x,3) - 30*pow(x,2)+96*x+pow((4-x),3)-96)/(9*pow(x,2)-36*x+36);
	return res;
}
double fun_pr2(double x) {
	double res = (2*pow(x,3)-12*pow(x,2)+24*x-32)/(9*pow(x,3)-54*pow(x,2)+108*x-72);
	return res;
}

void met_dix(double a, double b, double eps) {
	double x1;
	double x2;
	double del = eps / 2;
	double mid = (b - a) / 2;
	double min = 0;
	while (abs(mid) > eps) {
		x1 = (b + a - del) / 2;
		x2 = (b + a + del) / 2;
		if (fun(x1) <= fun(x2)) {
			b = x2;
		}
		else {
			a = x1;
		}
		mid = (b - a) / 2;
		min = (b + a) / 2;
	}
	cout << min << "   " << fun(min)<<"\n";

}

void met_perebora(double a, double b, double eps) {
	double n = (b - a) / eps;
	double h = (b - a) / n;
	double result = 0;
	double min = 9999;
	double arg;
	for (double i = a; i <= b; i += h)
	{
		result = (pow((4 - i), 3) / (9 * (2 - i)));
		if (result < min)
		{
			arg = i;
			min = result;
		}
		cout << "�������� X: " << setw(5) << i << " �������� ������� : " << result << "\n";
	}

	cout << "\n��� �_min = " << arg << "  �������� ������� = " << min<<"\n";

}

void met_poisk(double a, double b, double eps) {
	double h = (b - a) / 4;
	double x1 = a;
	double x2 = x1 + h;
	int i = 0;
	while (abs(h) > eps) {
		if (fun(x1) > fun(x2)) {
			x1 = x2;
			if (x1 > a && x1 < b) {
				x2 += h;
			}
			i++;
		}
		else {
			x1 = x2;
			h /= -4;
			x2 += h;
			i++;
		}
	}
	cout << "Xmin = " << x2 << " F(Xmin) = " << fun(x2)<<"\n";
	cout << "i = " << i << "\n";
}

void met_sechen(double a, double b, double eps) {
	double tao = (sqrt(5) - 1) / 2;
	double x1 = a + (1 - tao) * (b - a);
	double x2 = a + tao * (b - a);
	while (abs(b - a) > eps) {
		if (fun(x1) > fun(x2)) {
			a = x1;
			x1 = x2;
			x2 = a + tao * (b - a);
		}
		else {
			b = x2;
			x2 = x1;
			x1 = a + (1 - tao) * (b - a);

		}
	}
	double min = (b + a )/ 2;
	cout << "Xmin = " << min << " F(Xmin) = " << fun(min)<<"\n";

}

void met_middot(double a, double b, double eps) {
	double first = a;
	double sec = b;
	double x = (first+sec) / 2;
	while (abs(sec - first) > eps) {
		if (fun_pr1(x) > 0) {
			sec = x;
			x = (first + sec) / 2;
		}
		else {
			first = x;
			x = (first + sec) / 2;
		}
	}
	cout << "Xmin = " << x << " F(Xmin) = " << fun(x) << "\n";


}

void met_hord(double a, double b, double eps) {
	double first = a;
	double sec = b;
	double x_min = 0;
	if (fun_pr1(first) * fun_pr1(sec) < 0) {
		x_min = first - (fun_pr1(first)) / (fun_pr1(sec) - fun_pr1(first)) * (sec - first);
		while (fun_pr1(x_min) > eps) {
			if (fun_pr1(x_min) > 0) { 
				sec = x_min; 
				x_min = first - (fun_pr1(first)) / (fun_pr1(sec) - fun_pr1(first)) * (sec - first);
			}
			else { 
				first = x_min;
				x_min = first - (fun_pr1(first)) / (fun_pr1(sec) - fun_pr1(first)) * (sec - first);
			}
		}
	
	}
	else {
		if ((fun_pr1(first) > 0 && fun_pr1(sec) > 0) || (fun_pr1(first) == 0)) { x_min = first; }
		if ((fun_pr1(first) < 0 && fun_pr1(sec) < 0) || (fun_pr1(sec) == 0)) { x_min = sec; }
	}
	cout << "Xmin = " << x_min << " F(Xmin) = " << fun(x_min) << "\n";


}

void met_nyton(double a, double b, double eps) {
	double x0 = -12;
	double x1 = x0 - (fun_pr1(x0)) / (fun_pr2(x0));
	while (fun_pr1(x1) > eps) {
		x0 = x1;
		x1 = x0 - (fun_pr1(x0)) / (fun_pr2(x0));
	}
	cout << "Xmin = " << x1 << " F(Xmin) = " << fun(x1) << "\n";


}
