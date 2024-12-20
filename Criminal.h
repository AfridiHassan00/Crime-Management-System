#ifndef CRIMINAL_H_INCLUDE
#define CRIMINAL_H_INCLUDE
#include <iostream>

using namespace std;
class Criminal
{
public:
    int id;
    string name;
    string gender;
    int age;
    string offense;
    string offenseDate;
    string penalty;

    void setID(int);
    void setAge(int);
    void setName(string);
    void setGender(string);
    void setOffense(string);
    void setOffenseDate(string);
    void setPenalty(string);
};

#endif // CRIMINAL_H_INCLUDE
