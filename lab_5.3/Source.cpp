#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double rp, rk, z;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;
	double rg = (rk - rp) / n;
	double r = rp;
	cout << "|" << setw(5) << "r" << "|" << setw(8) << "z" << "|" << right << endl;
	while (r <= rk)
	{
		z = h(r + 1) + h(r * r + 1) * h(r * r + 1) + 1;
		cout << "|" << setw(5) << r << "|" << " " << setw(5) << z << "|" << right << endl;
		r += rg;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 0)
		return (cos(x) + 1) / (cos(x)* cos(x)+1);
	else
	{
		double S = 0;
		int n = 0;
		double a = (x * x) / 1;
		S = a;
		do
		{
			n++;
			double R = 2 * x * n + x;
			a *= R;
			S += a;
		} while (n < 6);
		return S;
	}
}