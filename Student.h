#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H
#include <sstream>
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int score;
    //重载<运算符，当成绩相等时按名字字典序从小到达排，否则按成绩从小到大排序。
    bool operator<(const Student &otherstudent)
    {
        return score != otherstudent.score ? score < otherstudent.score : name < otherstudent.name;
    }
    //友元函数，重载了<<运算符，在cout的时候可以直接输出Student的信息，节省了代码量。
    //这里重载运算符函数，由于<<是双目运算符，第一个参数是流，第二参数是学生结构体。
    friend ostream &operator<<(ostream &os, const Student &student)
    {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif