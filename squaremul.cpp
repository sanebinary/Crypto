//Based on the provided description of the square- and-multiply algorithm, write a program
//to calculate exponentiations xe mod m

#include <iostream>
using namespace std;

int Exp(int a, int b, int c)
{
	int result = b & 1 ? a : 1;
	while (b) {
		b >>= 1;
		a = (a * a) % c;
		if (b & 1)
			result = (result * a) % c;
	}
	return result;
}

int main()
{
	int a = 2, b = 3, c = 3;

	cout << "Computing " << a << " to the power " << b << " modulo " << c << "\n";
	int r = Exp(a, b, c);
	cout << a << " to the power " << b << " ≡ " << r << " (modulo " << c << ")\n";

	return 0;
}
