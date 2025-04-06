#include "Student.h"

void Student::SetScore(int n)
{
   m_nScore = n;
}
void Student::SetName(const string N)
{
   m_strName = N;
}
int Student::GetScore()
{
   return m_nScore;
}
string Student::GetName()
{
   return m_strName;
}
