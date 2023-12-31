#include "stdafx.h"
#include "CMyString.h"

CMyString::CMyString()
	: m_pszData(nullptr), m_nLength(0)
{

}

// 변환 생성자
CMyString::CMyString(const char* pszParam)
	: m_pszData(nullptr), m_nLength(0)
{
	SetString(pszParam);
}

// 복사 생성자
CMyString::CMyString(const CMyString& rhs)
	: m_pszData(nullptr), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

// 이동 생성자
CMyString::CMyString(CMyString&& rhs)
	: m_pszData(nullptr), m_nLength(0)
{
	cout << "CMyString 이동 생성자 호출" << endl;

	// 얕은 복사 수행. 원본이 곧 소멸되기 때문
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들은 초기화 된다. 절대로 해제하면 안됨.
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString::~CMyString()
{
	// 객체가 소멸하기 전에 메모리를 해제한다.
	Release();
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	// 자기 자신에 대한 대입이면 아무것도 하지 않는다.
	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

// 허용되는 변환
CMyString::operator char* (void) const
{
	return m_pszData;
}

int CMyString::SetString(const char* pszParam)
{
	// 새로운 문자열 할당에 앞서 기존 정보를 해제한다.
	Release();
	
	// Null을 인수로 함수를 호출했다는 것은 메모리를 해제하고
	// Null로 초기화 하는 것으로 볼 수 있다.
	if (pszParam == nullptr)
		return 0;

	// 길이가 0인 문자열도 초기화로 인식하고 처리한다.
	int nLength = strlen(pszParam);

	if (nLength == 0)
		return 0;

	// 문자열의 끝인 Null 문자를 고려해 메모리를 할당한다.
	m_pszData = new char[nLength + 1];

	// 새로 할당한 메모리에 문자열을 저장한다.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	// 문자열의 길이를 반환한다.
	return nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

void CMyString::Release()
{
	// 이 함수가 여러번 호출될 경우를 고려해 주요 멤버를 초기화 한다.
	if (m_pszData != nullptr)
		delete[] m_pszData;

	m_pszData = nullptr;
	m_nLength = 0;
}
