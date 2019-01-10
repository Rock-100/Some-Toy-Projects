#include "Common.h"
#include "BigInteger.h"


int main()
{
	BigInteger a("99999999999999999999999"), b(9999);
	cout << a << " " << b << endl;
	cout << a + b << endl;
	cout << a * b << endl;

	return 0;
}