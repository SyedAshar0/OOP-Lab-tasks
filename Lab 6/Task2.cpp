#include<iostream>
#include<string>
using namespace std;
class MediaFile{
    public:
    string filepath;
   double size;
   MediaFile(string filepath,double size):filepath(filepath),size(size){};
   virtual void play()=0;//pure virtual function allowing abstraction thus will prevent object creation of mediafile which fullfilling our requirement since only the derived classes are actual files that should be accessible
   virtual void stop()=0;

    
};
class VisualMedia:virtual public MediaFile{
public:
int Resolution;
VisualMedia(string filepath,double size,int Resolution):MediaFile(filepath,size),Resolution(Resolution){};
 void play()override{
    cout<<"playing media"<<endl;
}
void stop()override{
    cout<<"media stopped"<<endl;
}
};
class AudioMedia:virtual public MediaFile{
public:
int rate;
AudioMedia(string filepath,double size,int rate):MediaFile(filepath,size),rate(rate){};
void play()override{
    cout<<"playing audio"<<endl;
}
 void stop()override{
    cout<<"audio stopped"<<endl;
}

};
class VideoFile:public VisualMedia,public AudioMedia{
public:
VideoFile(string filepath,double size,int Resolution,int rate):MediaFile(filepath,size),VisualMedia(filepath,size,Resolution),AudioMedia(filepath,size,rate){};
 void play()override{
    cout<<"playing video"<<endl;
}
 void stop()override{
    cout<<"video stopped"<<endl;
}
};
int main(){
MediaFile * ptr;
VisualMedia visual("picture.jpg",300,280);
AudioMedia audio("sound.mp3",178,3690);
VideoFile video("movie.mp4",1280,5800,10191);
ptr=&visual;
ptr->play();
ptr->stop();
ptr=&audio;
ptr->play();
ptr->stop();
ptr=&video;
ptr->play();
ptr->stop();


    return 0;
}