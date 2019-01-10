#ifndef __MATRIX__
#define __MATRIX__

#include "Common.h"

class Matrix
{
	friend istream& operator >> (istream&, Matrix&);        //重载输入
	friend ostream& operator << (ostream&, const Matrix&);  //重载输出
	friend Matrix dotMul(const Matrix &, const Matrix &);
	friend Matrix dotDiv(const Matrix &, const Matrix &);
	friend Matrix operator + (const Matrix &, const Matrix &); 
	friend Matrix operator - (const Matrix &, const Matrix &);
	friend Matrix operator * (const Matrix &, const Matrix &);

public:
	//构造函数
	Matrix() : data(NULL), use(NULL), row(0), col(0)  //默认构造函数
	{
	}
	Matrix(int r, int c, double va = 0);
	Matrix(string s);

	//复制控制
	Matrix(const Matrix &);   //复制构造函数
	Matrix& operator = (Matrix &);   //重载赋值
	~Matrix();   //析构函数

	//重载复合赋值
	Matrix& operator += (const Matrix &);
	Matrix& operator -= (const Matrix &);

	//普通成员函数
	Matrix T() const;
	void copyTo(Matrix &) const;
	int get_row() const
	{
		return row;
	}
	int get_col() const
	{
		return col;
	}
	double get_val(int r, int c) const;
	void set_val(int r, int c, double va);
	double get_sum() const;

private:
	int row, col;
	double *data;
	int *use;

};


Matrix dotMul(const Matrix &, const Matrix &);
Matrix dotDiv(const Matrix &, const Matrix &);
Matrix operator + (const Matrix &, const Matrix &);
Matrix operator - (const Matrix &, const Matrix &);
Matrix operator * (const Matrix &, const Matrix &);


#endif 
