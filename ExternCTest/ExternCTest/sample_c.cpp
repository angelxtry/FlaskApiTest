#include <math.h>

#define EXPORT extern "C" __declspec(dllexport)

EXPORT int gcd(int x, int y);
EXPORT double* BSOption1(short TypeFlag, double S0, double *t);
EXPORT short BSOption0(short TypeFlag, double S0);
EXPORT double BSOption_Delta(
	short TypeFlag,		// Option Type: 1�̸� ��, 2�̸� ǲ
	double S0,		// �����ڻ� ���簡
	double *t,		// ������������ �Ⱓ���� ����	
	double *rf, 		// ������������ �Ⱓ����
	short nt,		// ������������ ����
	double *td,		// ���������� �Ⱓ���� ����
	double *rd, 		// ���������� �Ⱓ����
	short ntd,		// �Ⱓ ���� ������ ����
	double *t_vol,		// ������ ���� ����
	double *vol,		// �����ڻ� ������ 
	short n_vol,		// �� ������ ������ ����
	double dvd,		// �����
	double X,		// ��簡��
	short MaturityDate,	// ����(����) ���ϱ����� �ϼ�
	short PaymentDate,	// �����ϱ��� �ϼ�
	short TextFlag		// TextDump
);

int gcd(int x, int y) {
    int g = y;
    while ( x > 0 ) {
        g = x;
        x = y % x;
        y = g;
    }
    return g;
}

short BSOption0(
    short TypeFlag,		// Option Type: 1�̸� ��, 2�̸� ǲ
    double S0		// �����ڻ� ���簡
)
{
    return TypeFlag;
}

double* BSOption1(
    short TypeFlag,		// Option Type: 1�̸� ��, 2�̸� ǲ
    double S0,		// �����ڻ� ���簡
    double *t		// ������������ �Ⱓ���� ����
)
{
    return t;
}

double BSOption_Delta(
	short TypeFlag,		// Option Type: 1�̸� ��, 2�̸� ǲ
	double S0,		// �����ڻ� ���簡
	double *t,		// ������������ �Ⱓ���� ����	
	double *rf, 		// ������������ �Ⱓ����
	short nt,		// ������������ ����
	double *td,		// ���������� �Ⱓ���� ����
	double *rd, 		// ���������� �Ⱓ����
	short ntd,		// �Ⱓ ���� ������ ����
	double *t_vol,		// ������ ���� ����
	double *vol,		// �����ڻ� ������ 
	short n_vol,		// �� ������ ������ ����
	double dvd,		// �����
	double X,		// ��簡��
	short MaturityDate,	// ����(����) ���ϱ����� �ϼ�
	short PaymentDate,	// �����ϱ��� �ϼ�
	short TextFlag		// TextDump
)
{
    return X;
}