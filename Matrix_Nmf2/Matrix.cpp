#include "Matrix.h"

istream& operator >> (istream& in, Matrix& ma)
{
	if (ma.use != NULL)
	{
		(*ma.use)--;
		if (*ma.use == 0)
		{
			delete ma.use;
			delete[] ma.data;
			ma.use = NULL;
			ma.data = NULL;
		}
	}

	cout << "input your row and col:" << endl;
	in >> ma.row >> ma.col;
	if (ma.row <= 0 || ma.col <= 0)
		throw runtime_error("row and col must be positive");
	ma.data = new double[ma.row * ma.col];
	ma.use = new int(1);
	cout << "input your data:" << endl;
	for (int i = 0; i < ma.row; i++)
	{
		for (int j = 0; j < ma.col; j++)
		{
			in >> ma.data[i * ma.col + j];
		}
	}
	return in;
}


ostream& operator << (ostream& out, const Matrix &ma)
{
	out << "row: " << ma.row << " col: " << ma.col << endl;

	for (int i = 0; i < ma.row; i++)
	{
		for (int j = 0; j < ma.col; j++)
			out << ma.data[i * ma.col + j] << " ";
		out << endl;
	}
	return out;
}

Matrix::Matrix(int r, int c, double va) : row(r), col(c)
{
	if (row <= 0 || col <= 0)
		throw runtime_error("row and col must be positive");

	data = new double[row * col];

	fill(data, data + row * col, va);
	use = new int(1);
}

Matrix::Matrix(string s)
{
	ifstream infile;
	infile.open(s);
	if (!infile)
		throw runtime_error("unable to open file!");

	string line;
	row = 0;
	vector<string> line_txt;
	while (getline(infile, line))
	{
		row++;
		line_txt.push_back(line);
		istringstream stream(line);
		string num;
		col = 0;
		while (stream >> num)
		{
			col++;
		}
	}

	use = new int(1);
	data = new double[row * col];
	for (int i = 0; i < row; i++)
	{
		istringstream stream(line_txt[i]);
		for (int j = 0; j < col; j++)
			stream >> data[i * col + j];
	}
}

Matrix::Matrix(const Matrix &ma)
{
	row = ma.row, col = ma.col;
	data = ma.data;
	use = ma.use;
	if (use != NULL)
	{
		(*use)++;
	}
}


Matrix& Matrix::operator = (Matrix &ma)
{
	if (ma.data != NULL)
		++(*ma.use);
	if (data != NULL)
	{
		(*use)--;
		if (*use == 0)
		{
			delete use;
			delete[] data;
			use = NULL;
			data = NULL;
		}
	}
	row = ma.row, col = ma.col;
	data = ma.data;
	use = ma.use;
	return *this;
}


Matrix::~Matrix()
{
	if (use != NULL)
	{
		(*use)--;
		if (*use == 0)
		{
			delete use;
			delete[] data;
			use = NULL;
			data = NULL;
		}
	}
}

Matrix& Matrix::operator += (const Matrix &rhs)
{
	if (row != rhs.row || col != rhs.col)
		throw runtime_error("matrix's size not compatible");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			data[i * col + j] += rhs.data[i * col + j];
	}
	return *this;
}

Matrix& Matrix::operator -= (const Matrix &rhs)
{
	if (row != rhs.row || col != rhs.col)
		throw runtime_error("matrix's size not compatible");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			data[i * col + j] -= rhs.data[i * col + j];
	}
	return *this;
}

Matrix Matrix::T() const
{
	Matrix res;

	if (data != NULL)
	{
		res.row = col;
		res.col = row;
		res.use = new int(1);
		res.data = new double[row * col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				res.data[j * row + i] = data[i * col + j];
		}
	}
	return res;
}


void Matrix::copyTo(Matrix &ma) const
{
	if (ma.data != NULL)
	{
		(*ma.use)--;
		if (*ma.use == 0)
		{
			delete ma.use;
			delete[] ma.data;
			ma.use = NULL;
			ma.data = NULL;
		}
	}

	ma.row = row, ma.col = col;
	if (data == NULL)
	{
		ma.use = NULL;
		ma.data = NULL;
	}
	else
	{
		ma.use = new int(1);
		ma.data = new double[row * col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				ma.data[i * col + j] = data[i * col + j];
		}
	}
}

double Matrix::get_val(int r, int c) const
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		throw runtime_error("wrong index");
	return data[r * col + c];
}

void Matrix::set_val(int r, int c, double va)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		throw runtime_error("wrong index");
	data[r * col + c] = va;
}

double Matrix::get_sum() const
{
	double res = 0;
	for (int i = 0; i < row * col; i++)
		res += data[i];
	return res;
}


Matrix dotMul(const Matrix &x, const Matrix &y)
{
	if (x.row != y.row || x.col != y.col)
		throw runtime_error("matrix's size not compatible");
	Matrix z;
	if (x.data != NULL)
	{
		z.row = x.row, z.col = x.col;
		z.use = new int(1);
		z.data = new double[x.row * x.col];
		for (int i = 0; i < z.row; i++)
		{
			for (int j = 0; j < z.col; j++)
				z.data[i * z.col + j] = x.data[i * z.col + j] * y.data[i * z.col + j];
		}
	}
	return z;
}

Matrix dotDiv(const Matrix &x, const Matrix &y)
{
	if (x.row != y.row || x.col != y.col)
		throw runtime_error("matrix's size not compatible");
	Matrix z;
	if (x.data != NULL)
	{
		z.row = x.row, z.col = x.col;
		z.use = new int(1);
		z.data = new double[x.row * x.col];
		for (int i = 0; i < z.row; i++)
		{
			for (int j = 0; j < z.col; j++)
				z.data[i * z.col + j] = x.data[i * z.col + j] / y.data[i * z.col + j];
		}
	}
	return z;
}

Matrix operator + (const Matrix &x, const Matrix &y)
{
	if (x.row != y.row || x.col != y.col)
		throw runtime_error("matrix's size not compatible");
	Matrix z;
	if (x.data != NULL)
	{
		z.row = x.row, z.col = x.col;
		z.use = new int(1);
		z.data = new double[x.row * x.col];
		for (int i = 0; i < z.row; i++)
		{
			for (int j = 0; j < z.col; j++)
				z.data[i * z.col + j] = x.data[i * z.col + j] + y.data[i * z.col + j];
		}
	}
	return z;
}

Matrix operator - (const Matrix &x, const Matrix &y)
{
	if (x.row != y.row || x.col != y.col)
		throw runtime_error("matrix's size not compatible");
	Matrix z;
	if (x.data != NULL)
	{
		z.row = x.row, z.col = x.col;
		z.use = new int(1);
		z.data = new double[x.row * x.col];
		for (int i = 0; i < z.row; i++)
		{
			for (int j = 0; j < z.col; j++)
				z.data[i * z.col + j] = x.data[i * z.col + j] - y.data[i * z.col + j];
		}
	}
	return z;
}


Matrix operator * (const Matrix &x, const Matrix &y)
{
	if (x.col != y.row)
		throw runtime_error("matrix's size not compatible");
	Matrix z;
	if (x.data != NULL)
	{
		z.row = x.row, z.col = y.col;
		z.use = new int(1);
		z.data = new double[z.row * z.col];
		fill(z.data, z.data + z.row * z.col, 0);
		for (int i = 0; i < x.row; i++)
		{
			for (int j = 0; j < x.col; j++)
			{
				if (!isZero(x.data[i * x.col + j]))
				{
					for (int k = 0; k < y.col; k++)
						z.data[i * z.col + k] += x.data[i * x.col + j] * y.data[j * y.col + k];
				}

			}
		}
	}
	return z;
}