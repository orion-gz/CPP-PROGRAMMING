#pragma once
#include "CMyString.h"

class CMyStringEx :
    public CMyString
{
public:
    CMyStringEx();
    ~CMyStringEx();

    // 변환 생성자
    explicit CMyStringEx(const char* pszParam);

    int Find(const char* pszParam); 
    int SetString(const char* pszParam);
};

