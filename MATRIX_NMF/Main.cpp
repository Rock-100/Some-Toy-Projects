#include "Common.h"
#include "Matrix.h"
#include "Nmf.h"



int main()
{
	Matrix V("file\\m.txt");

	Matrix W, H;
	NMF(V, W, H, 2, 100);
	cout << V << endl;
	cout << W * H << endl;
	cout << W << endl;
	cout << H << endl;
	
	return 0;
}