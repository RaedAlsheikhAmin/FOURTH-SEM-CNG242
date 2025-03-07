//
// Created by Hi on 5/5/2023.
//

#ifndef C_RECTANGLE_H
#define C_RECTANGLE_H
class rectangle
{
private:
    float length;
    float width;
public:
    rectangle();
    float perimeter();
    float area();
    void setlength(float);
    void setwidth(float);
    float getlength();
    float getwidth();
    void printer();

};
#endif //C_RECTANGLE_H
