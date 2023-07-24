#include "stdafx.h"
#include "CMyStringEx.h"

CMyStringEx::CMyStringEx()
{

}

CMyStringEx::~CMyStringEx()
{

}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == nullptr || GetString() == nullptr )
		return -1;

	const char* pszResult = strstr(GetString(), pszParam);

	if (pszResult != nullptr)
		// �����Ϳ� �����͸� ���� ������ �� �ּ� ���̿� ����� � �ִ����� ����ϴ� ��.
		return pszResult - GetString();

	return -1;
}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "������") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "���Ѹ�");
}