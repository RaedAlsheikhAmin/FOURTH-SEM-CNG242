#include<iostream>
using namespace std;
class Course;//important for class student to take type course. and then we define course.
class Student
{
private:
	char* name;
	int ST_ID;
public:
	Student(char*, int);
	Student(Student&);
	~Student();
	char* getname() { return name; }
	int getid() { return ST_ID; }
	void enrol(Course&);
	void enrol2(Course&);
};

class Course
{
private:
	Student* container[50];
	char* code;
	int numberofstudents;
public:
	Course(char*);
	Course(Course&);
	~Course();
	void regeisterer(Student&);
	friend ostream& operator << (ostream&, Course);
	friend void Student::enrol2(Course&);


};