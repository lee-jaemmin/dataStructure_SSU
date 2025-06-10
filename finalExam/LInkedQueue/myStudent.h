#pragma once
#include <iostream>
using namespace std;
//20212861 이재민 

class CStudent
{
private:
	int m_nID;
public:
	int GetID();
    void SetID(int n);
};

void CStudent::SetID(int n)
{
	m_nID = n;
}

int CStudent::GetID()
{
	return m_nID;
}
