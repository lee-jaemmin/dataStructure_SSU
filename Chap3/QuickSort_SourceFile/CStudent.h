// 클래스 CStudent 선언부

#pragma once
#include <iostream>
using namespace std;

class CStudent
{
private:
	int m_nID;
	string m_strName;
public:
	CStudent(int ID = 0, string Name = "") : m_nID(ID), m_strName(Name)
	{}
	void SetID(int n);
	void SetName(const string N);
	int GetID();
	string GetName();
	friend bool operator <=(CStudent& stu1, CStudent& stu2);
};