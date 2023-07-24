// Q2. ���� ������ �� �ܼ� ���� �����ڸ� �ݵ�� �����ؾ� �ϴ� Ŭ������ � Ŭ�������� ���ϼ���.
// ��ü�� �ܼ� ������ �õ��ϴ� Ŭ����
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
	{
		m_pnData = new int;
		*m_pnData = nParam;
	}

	// ���� ������ ���� �� ����
	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;

		// �޸� �Ҵ�
		m_pnData = new int;

		// �����Ͱ� ����Ű�� ��ġ�� ���� �����Ѵ�.
		*m_pnData = *rhs.m_pnData;
	}

	// ��ü�� �Ҹ��ϸ� ���� �Ҵ��� �޸𸮸� �����Ѵ�.
	~CMyData()
	{
		delete m_pnData;
	}

	// �ܼ� ���� ������ �Լ��� �����Ѵ�.
	CMyData& operator=(const CMyData& rhs)
	{
		*m_pnData = *rhs.m_pnData;

		return *this;
	}

	int GetData()
	{
		if (m_pnData != nullptr)
			return *m_pnData;

		return 0;
	}

private:
	// ������ ��� ������
	int* m_pnData = nullptr;
};

int main()
{
	CMyData a(10);
	CMyData b(20);

	// �ܼ� ������ �õ��ϸ� ��� ����� ���� �״�� �����Ѵ�.
	a = b;
	cout << a.GetData() << endl;

	return 0;
}