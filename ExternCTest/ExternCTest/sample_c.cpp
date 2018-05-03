#include <math.h>

#define EXPORT extern "C" __declspec(dllexport)

EXPORT int gcd(int x, int y);
EXPORT double* BSOption1(short TypeFlag, double S0, double *t);
EXPORT short BSOption0(short TypeFlag, double S0);
EXPORT double BSOption_Delta(
	short TypeFlag,		// Option Type: 1이면 콜, 2이면 풋
	double S0,		// 기초자산 현재가
	double *t,		// 무위험이자율 기간구조 시점	
	double *rf, 		// 무위험이자율 기간구조
	short nt,		// 무위험이자율 개수
	double *td,		// 할인이자율 기간구조 시점
	double *rd, 		// 할인이자율 기간구조
	short ntd,		// 기간 구조 데이터 개수
	double *t_vol,		// 변동성 만기 시점
	double *vol,		// 기초자산 변동성 
	short n_vol,		// 각 변동성 데이터 개수
	double dvd,		// 배당율
	double X,		// 행사가격
	short MaturityDate,	// 만기(최종) 평가일까지의 일수
	short PaymentDate,	// 지급일까지 일수
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
    short TypeFlag,		// Option Type: 1이면 콜, 2이면 풋
    double S0		// 기초자산 현재가
)
{
    return TypeFlag;
}

double* BSOption1(
    short TypeFlag,		// Option Type: 1이면 콜, 2이면 풋
    double S0,		// 기초자산 현재가
    double *t		// 무위험이자율 기간구조 시점
)
{
    return t;
}

double BSOption_Delta(
	short TypeFlag,		// Option Type: 1이면 콜, 2이면 풋
	double S0,		// 기초자산 현재가
	double *t,		// 무위험이자율 기간구조 시점	
	double *rf, 		// 무위험이자율 기간구조
	short nt,		// 무위험이자율 개수
	double *td,		// 할인이자율 기간구조 시점
	double *rd, 		// 할인이자율 기간구조
	short ntd,		// 기간 구조 데이터 개수
	double *t_vol,		// 변동성 만기 시점
	double *vol,		// 기초자산 변동성 
	short n_vol,		// 각 변동성 데이터 개수
	double dvd,		// 배당율
	double X,		// 행사가격
	short MaturityDate,	// 만기(최종) 평가일까지의 일수
	short PaymentDate,	// 지급일까지 일수
	short TextFlag		// TextDump
)
{
    return X;
}