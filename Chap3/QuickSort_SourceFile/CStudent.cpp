// 클래스 CStudent Member Function 정의부 (Accessor, Mutator)

#include "CStudent.h"

void CStudent::SetID(int n)
{
	m_nID = n;
}
void CStudent::SetName(const string N)
{
	m_strName = N;
}
int CStudent::GetID()
{
	return m_nID;
}
string CStudent::GetName()
{
	return m_strName;
}