//
// Created by Hi on 5/5/2023.
//
#include<iostream>
#include "rectangle.h"
using namespace std;

rectangle::rectangle(){
    length=1;
    width=1;
}
float rectangle::getlength()
{
    return length;
}
float rectangle::getwidth() {
    return width;
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
