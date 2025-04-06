#pragma once
#include <iostream>
using namespace std;

class myCStudent
{
private:
	int m_nID;
	string m_strName;
	double gpa;
public:
	
	void setID(int n) {m_nID = n;}
	void setName(const string &name) {m_strName;}
	void setGPA(double g) {gpa = g;}

	int getID() {return m_nID;}
	string getName() {return m_strName;}
	double getGPA() {return gpa;}


	bool operator > (const myCStudent &other) const{
		return gpa > other.gpa;
	}
	bool operator < (const myCStudent &other) const{
		return gpa < other.gpa;
	}

	
};