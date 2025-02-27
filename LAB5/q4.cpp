#include<iostream>
#include<windows.h>
using namespace std;
class Blend{
    public:
    void blendJuice(){
      cout<<"<-----blending juice----->"<<endl;
      for(int i=0;i<4;i++){
        cout<<"blending:"<<i+1<<endl;
        Sleep(2000);
      }
      cout<<"<-blended->"<<endl;
} 
};
class Grind{
public:
void Grindjuice(){
  cout<<"<-----grinding----->"<<endl;
  Sleep(5000);
  cout<<"grinded"<<endl;
}
};
class JuiceMaker{
  public:
  Blend blender;
  Grind grinder;
  void blendJuice(){
         blender.blendJuice();
  } 
  void Grindjuice(){
    grinder.Grindjuice();
  }
};
int main(){
    JuiceMaker juiceMaker;
    juiceMaker.blendJuice();
    juiceMaker.Grindjuice();
}