#include "Matrix.h"
#include "Nmf.h"


void NMF(const Matrix &V, Matrix &W, Matrix &H, int r, int max_it)
{
	int row = V.get_row(), col = V.get_col();
	W = Matrix(row, r), H = Matrix(r, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < r; j++)
			W.set_val(i, j, douRand());
	for (int i = 0; i < r; i++)
		for (int j = 0; j < col; j++)
			H.set_val(i, j, douRand());

	
	for (int it = 0; it < max_it; it++)
	{
		H = dotDiv(dotMul(H, W.T() * V), W.T() * W * H);
		W = dotDiv(dotMul(W, V * H.T()), W * H * H.T());

		Matrix er = V - W * H;
		er = dotMul(er, er);
		cout << "iter: " << it + 1 << "    error: " << er.get_sum() << endl;
	}
}