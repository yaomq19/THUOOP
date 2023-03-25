#include "Matrix.h"

Matrix::Matrix(){}
Matrix::Matrix(int _row, int _col)
{
    row = _row;
    col = _col;
    elem = new int*[row];
    for(int i = 0; i < row; i++)
    {
        elem[i] = new int[col];
    }
}
Matrix::~Matrix(){}

Matrix Matrix::operator+(const Matrix& other)
{
    Matrix result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.elem[i][j] = elem[i][j] + other.elem[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator-(const Matrix& other)
{
    Matrix result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.elem[i][j] = elem[i][j] - other.elem[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(const int x)
{
    Matrix result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result.elem[i][j] = elem[i][j] * x;
        }
    }
    return result;
}
Matrix Matrix::operator*(const Matrix& other)
{
    Matrix result(this->row, other.col);
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < other.col; j++)
        {
            int sum=0;
            for(int k=0;k<this->col;k++)
            {
                sum+=elem[i][k]*other[k][j];
            }
            result.elem[i][j] = sum;
        }
    }
    return result;
}
Matrix transpose(const Matrix& mat)
{
    Matrix result(mat.col,mat.row);
    for(int i=0;i<result.row;i++)
    {
        for(int j=0;j<result.col;j++)
        {
            result[i][j]=mat[j][i];
        }
    }
    return result;
}
int* Matrix::operator[](int r) const
{
    return elem[r];
}
ostream& operator<<(ostream& ofs, const Matrix& mat)
{
    for(int i=0; i<mat.row; i++)
    {
        for(int j=0; j<mat.col; j++)
        {
            ofs<<mat[i][j]<<" ";
        }
        ofs<<endl;
    }
    return ofs;
}
istream& operator>>(istream& ifs, Matrix& mat)
{
    ifs>>mat.row>>mat.col;
    mat.elem=new int*[mat.row];
    for(int i=0;i<mat.row;i++)
    {
        mat.elem[i]=new int[mat.col];
        for(int j=0;j<mat.col;j++)
        {
            ifs>>mat.elem[i][j];
        }
    }
    return ifs;
}

