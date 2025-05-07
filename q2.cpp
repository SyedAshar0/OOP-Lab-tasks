#include<iostream>
#include<exception>
#include<vector>
using namespace std;
class DimensionMismatchException:public exception
{
    public:
    const char* what() const noexcept override
    {
        return "dimensions dont match";
    }
};
template<typename T>
class Matrix
{
    public:
  int rows,cols;
  vector<vector<T>>dimensions;
  Matrix(int r,int c):rows(r),cols(c),dimensions(r,vector<T>(c)){};
  T& at(int i,int j)
  {
    return dimensions[i][j];//accessing the element
  }
  Matrix operator +(const Matrix&other)const
  {
   if(rows!=other.rows || cols!=other.cols)
   {
    throw DimensionMismatchException();
   }
   Matrix result(rows,cols);
for(int i=0;i<rows;i++)
{
    for(int j=0;j<cols;j++)
    {
        result.dimensions[i][j]=dimensions[i][j]+other.dimensions[i][j];
    }
}
return result;
  }
  Matrix operator*(const Matrix&other)
  {
    if(cols!=other.rows)
   {
    throw DimensionMismatchException();
   }
   Matrix result(rows,other.cols);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<other.cols;j++)
        {
          for(int k=0;k<cols;k++)
          {
            result.dimensions[i][j]+=dimensions[i][k]*other.dimensions[k][j];
          }
        }
    }
    return result;
  }
  void Display()
  {
    for(const auto&row:dimensions)
    {
        for(const auto&item:row)
        {
            cout<<item;
        }
        cout<<endl;
    }
  }
};
int main() {
    try {
        Matrix<int> A(2, 2), B(2, 2);
        A.at(0, 0) = 1; A.at(0, 1) = 2;
        A.at(1, 0) = 3; A.at(1, 1) = 4;
        B.at(0, 0) = 5; B.at(0, 1) = 6;
        B.at(1, 0) = 7; B.at(1, 1) = 8;
        Matrix<int> C = A + B;
        cout << "A + B = \n";
        C.Display();
        Matrix<int> D = A * B;
        cout << "A * B = \n";
        D.Display();
    }
    catch (const DimensionMismatchException& e) {
        cout << "Dimension error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    return 0;
}

