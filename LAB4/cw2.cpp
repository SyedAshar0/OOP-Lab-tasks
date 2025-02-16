#include<iostream>

using namespace std;

class Polynomial{
    public:
    double *array;
    int degree;
    Polynomial(){
        degree=0;
        array=new double[1];
        for(int i=0;i<1;i++){
            array[i]=0;
        }
    }
    Polynomial(int deg,const double *coefficient){
           degree=deg;
           array=new double[degree+1];
           for(int i=0;i<=degree;i++){
            array[i]=coefficient[i];
           }
    }
    Polynomial(const Polynomial&other){
        degree=other.degree;
        array=new double[degree+1];
        for(int i=0;i<=degree;i++){
            array[i]=other.array[i];
        }
    }
    Polynomial(Polynomial&&other) noexcept{
        degree=other.degree;
        array=other.array;
        other.array=nullptr;
        other.degree=0;

    }
    ~Polynomial(){
    delete[] array;
    }
    void fill(){
        cout<<"enter for:"<<degree+1<<"coefficients"<<endl;
        for(int i=0;i<=degree;i++){
            cin>>array[i];
        }
    }
    int getdegree(){
         return degree;
    }
    double evaluate(double x){
        double result=0;
        double power=1;
        for(int i=0;i<=degree;i++){
            result=result+(array[i]*power);
            power=power*x;
    }
    return result;
}
    Polynomial add(const Polynomial&other) const{
         int newdegree=max(degree,other.degree);
         double *newcoefficient=new double[newdegree+1];
         for(int i=0;i<=newdegree;i++){
            newcoefficient[i]=0;
            newcoefficient[i]+=array[i];
         }
         for(int i=0;i<=newdegree;i++){
            newcoefficient[i]+=other.array[i];
         }
         Polynomial result(newdegree,newcoefficient);
         delete[] newcoefficient;
         return result;
    }
    Polynomial multiply(const Polynomial& other) const{
        int newdegree=degree+other.degree;
        double *newcoefficient=new double[newdegree+1];
        for(int i=0;i<=degree;i++){
            newcoefficient[i]=0;
            for(int j=0;j<=other.degree;j++){
                newcoefficient[i+j]=newcoefficient[i+j]+(array[i]*other.array[j]);
            }
        }
        Polynomial result(newdegree,newcoefficient);
        delete[] newcoefficient;
        return result;
    }
};
int main(){
    double coefficent1[]={2,4,6};
    double coefficent2[]={1,3,5};
    Polynomial poly1(2,coefficent1);
    Polynomial poly2(2,coefficent2);
    cout<<"degree of first polynomial:"<<poly1.getdegree()<<endl;
    cout<<"degree of second polynomial:"<<poly2.getdegree()<<endl;
    cout<<"for function at p(3)="<<poly1.evaluate(3)<<endl;
    Polynomial addition=poly1.add(poly2);
    cout<<"addition at x=3 results in:"<<addition.evaluate(3)<<endl;
    Polynomial multiplicatiom=poly1.multiply(poly2);
    cout<<"product at x=3 results in:"<<multiplicatiom.evaluate(3)<<endl;
    Polynomial poly3=poly1;
    cout<<" copy of polynomial1 at x=3 is "<<poly3.evaluate(3)<<endl;
    Polynomial poly4=move(poly2);
    cout<<"moved polynomial->poly4 evaluated at x=3 is"<<" "<<poly4.evaluate(3)<<endl;
} 