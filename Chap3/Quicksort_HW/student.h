
#pragma once
#include <iostream>

using namespace std;

class Student
{
private:
   int m_nScore;
   string m_strName;
public:
   Student(int score = 0, string Name = "") : m_nScore(score), m_strName(Name)
   {
   }
   void SetScore(int n);
   void SetName(const string N);
   int GetScore();
   string GetName();
   friend bool operator <=(Student& s1, Student& s2);
   friend bool operator >=(Student& s1, Student& s2);
};
