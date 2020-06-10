#ifndef BIGNUM_H
#define BIGNUM_H
#include<iostream>
using namespace std;

#include"s1061443_BigNum.h"

class BigNUM
{
	friend ostream &operator<<(ostream &output, const BigNUM &right);//��X
	friend istream &operator>>(istream &input, BigNUM &right);//BONUS
	friend BigNUM operator-(int integer, BigNUM &right);//��� - �j��
	friend BigNUM operator+(int integer, BigNUM &right);//��� + �j��
	friend BigNUM operator*(int integer, BigNUM &right);//��� * �j��
	friend BigNUM operator-(BigNUM &left, int integer);//�j�� - ���
	friend BigNUM operator+(BigNUM &left, int integer);//�j�� + ���
	friend BigNUM operator*(BigNUM &left, int integer);//�j�� * ���

public:

	BigNUM(long long int = 0, long long int = 1);//constructor
	BigNUM(const BigNUM &right);//copy constructor
	~BigNUM();//destructor
	bool less(const BigNUM &right);//�P�_���ӼƦr�p
	void resize(long long int);//���ܪŶ�
	BigNUM &operator=(const BigNUM &right);//assign operator
	BigNUM operator-(const BigNUM &right);
	BigNUM operator+(const BigNUM &right);
	BigNUM operator*(const BigNUM &right);
	BigNUM operator-()const;//�t��

private:
	long long int *ptr;
	bool negative;//�s�t��
	long long int size;//�ثe�Ψ쪺���
	long long int capacity;//�̦h�i�H�Ψ쪺���
};

#endif // !BIGNUM_H


