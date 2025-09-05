#include<iostream>
using namespace std;

class Human{
   string name;
    int age, wt;

};

class Student:public Human{
 int roll_number, fees;
};

int main(){
    Student Mansi;
    Mansi.name="Mansi";
}