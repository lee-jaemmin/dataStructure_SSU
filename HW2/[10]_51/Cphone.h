#pragma once
#include <iostream>
using namespace std;
//20212861 이재민 

class CPhone
{
private:
	string name;
    int birth;
public:
	string getName();
    int getBirth();
    void setName(const string &input);
    void setBirth(const int &n);
};

void CPhone::setName(const string &input)
{
    name = input;
}

void CPhone::setBirth(const int &n)
{
	birth = n;
}

string CPhone::getName()
{
    return name;
}

int CPhone::getBirth()
{
    return birth;
}
