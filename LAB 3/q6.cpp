#include<iostream>
using namespace std;
class Matrix{
    public:
    int row;
    int column;
    int elements[50][50];
    Matrix(){
              //default values
               row=0;
               column=0;
    }
    Matrix(int row,int column){
        this->row=row;
        this->column=column;
    }
    void getrows(){
        cout<<"rows:"<<row<<endl;
    }
    void getcol(){
        cout<<"columns:"<<column<<endl;
    }
    void setelement(){
        cout<<"<-----enter elements----->"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                 cin>>elements[i][j];
            }
        }
    }
    void addition(Matrix metrix1,Matrix metrix2,int result[50][50]){//for addition since both dimensions need to be same so i chose metrix 1's dimension
          if(metrix1.row==metrix2.row && metrix1.column==metrix2.column){
            for(int i=0;i<metrix1.row;i++){
                for(int j=0;j<metrix1.column;j++){
                    result[i][j]=metrix1.elements[i][j]+metrix2.elements[i][j];
                }
            }
          }else{
        cout<<"Matrices cannot be added"<<endl;
    }
    }
    void multiplication(Matrix metrix1,Matrix metrix2,int result[50][50]){
        if(metrix1.column==metrix2.row){
            for(int i=0;i<metrix1.row;i++){
                for(int j=0;j<metrix2.column;j++){
                    result[i][j]=0;//inner loop to calculate dot product
                    for(int k=0;k<metrix1.column;k++){
                        result[i][j]+=metrix1.elements[i][j]*metrix2.elements[i][j];
                    }
                }
            }
        }else{
            cout<<"dimensions dont adhere to multiplication property"<<endl;
        }

    }           
    void display(){
        cout<<"<--displaying-->"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<elements[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    void displayy(int result[50][50],int row,int column){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }         
};
int main(){
int row1,col1;
int row2,col2;
cout<<"enter rows for 1st matrix and column for first matrix"<<endl;
cin>>row1>>col1;
Matrix metrix1=Matrix(row1,col1);
cout<<"enter rows for 2nd matrix and column for 2nd matrix"<<endl;
cin>>row2>>col2;
Matrix metrix2=Matrix(row2,col2);
Matrix metrix3;
int result1[50][50];
int result2[50][50];
metrix1.getrows();
metrix1.getcol();
metrix2.getrows();
metrix2.getcol();
metrix1.setelement();
metrix1.display();
metrix2.setelement();
metrix2.display();
metrix3.addition(metrix1,metrix2,result1);
cout<<"<----addition result---->"<<endl;
metrix3.displayy(result1,row1,col1);
metrix3.multiplication(metrix1,metrix2,result2);
cout<<"<----multiplication result---->"<<endl;
metrix3.displayy(result2,row2,col1);
    return 0;
}