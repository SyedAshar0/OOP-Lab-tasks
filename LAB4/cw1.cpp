#include<iostream>

using namespace std;
class Matrix{
    public:
    int rows;
    int cols;
    int **array;
    Matrix(){
       rows=0;
       cols=0;
    }
    Matrix(int rows,int cols){
       this->rows=rows;
       this->cols=cols;
       array=new int*[rows];
       for(int i=0;i<rows;i++){
        array[i]=new int[cols];
       }
    }
    Matrix(const Matrix& other){
        rows=other.rows;
        cols=other.cols;
        array=new int*[rows];
        for(int i=0;i<rows;i++){
            array[i]=new int[cols];
            for(int j=0;j<cols;j++){
                array[i][j]=other.array[i][j];
            }
        }
    }
    Matrix(Matrix&& other) noexcept{
       rows=other.rows;
       cols=other.cols;
       array=other.array;
       other.array=nullptr;
       other.rows=0;
       other.cols=0;
    }
    ~Matrix(){
        if(array){
       for(int i=0;i<rows;i++){
        delete[] array[i];
       }
       delete[] array;
    }
}
    int getrows(){
        return rows;
    }
    int getCols(){
        return cols;
    }
    void fill(double value){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                 array[i][j]=value;
            }
        }
    }
    int& at(int r,int c){
        return array[r][c];
    }
    Matrix transpose()const{
        Matrix result(cols,rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                result.array[j][i]=array[i][j];
            }
        }
        return result;
    }
    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<array[i][j];
            }
            cout<<endl;
        }
    }
};
int main(){
    Matrix obj1(5,3);
    obj1.fill(3);
    cout<<"object1 has rows:"<<obj1.getrows()<<endl;
    cout<<"object1 has columns:"<<obj1.getCols()<<endl;
    cout<<"<-----displaying initial matrix---->"<<endl;
    obj1.display();
    Matrix obj2= obj1;
    cout<<"object2 has rows:"<<obj2.getrows()<<endl;;
    cout<<"object2 has columns:"<<obj2.getCols()<<endl;;
    cout<<"copied obj1 to obj2"<<endl;
    obj2.display();
    Matrix obj3= move(obj1);
    cout<<"have moved obj1 to obj3 thus obj1 is redundant and obj3 has data of obj1"<<endl;
    cout<<"object3 has rows:"<<obj3.getrows()<<endl;;
    cout<<"object3 has columns:"<<obj3.getCols()<<endl;;
    obj3.display();
    Matrix result=obj3.transpose();
    cout<<"result matrix has rows:"<<result.getrows()<<endl;;
    cout<<"result matrix has columns:"<<result.getCols()<<endl;;
    cout<<"<-----transposed matrix----->"<<endl;
    result.display();
    
    return 0;
    }