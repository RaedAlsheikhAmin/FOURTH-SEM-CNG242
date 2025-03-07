
#include<iostream>

class rectangle
{
private:
    float length;
    float width;
    char boarder;
    char inside;
public:
    rectangle();
    float perimeter();
    float area();
    void setlength(float);
    void setwidth(float);
    float getlength();
    float getwidth();
    char setFillCharacter();//for the body
    char setPerimeterCharacter();//for the border
    void draw();
    void printer();

};
using namespace std;

rectangle::rectangle(){
    length=1;
    width=1;
}
float rectangle::getlength()
{
    cout<<"please give me the length of your rectangle: ";
    cin>>this->length;
    return this->length;
}
float rectangle::getwidth(){
    cout<<"please give me the width of your rectangle: ";
    cin>>this->width;
    return this->width;
}
void rectangle::setlength(float length) {
    this->length=length;
}
void rectangle::setwidth(float width) {
    this->width=width;
}
void rectangle::printer(){
    cout <<"this is your data\n"<<"the length is"<<length<<"\n the width is"<<width;
}
void rectangle::draw(){

}
int main(int argc,char **argv)
{
    rectangle R;
    R.setlength(2.1);
    R.setwidth(8.9);
    R.getwidth();
    R.printer();


    return 0;



}