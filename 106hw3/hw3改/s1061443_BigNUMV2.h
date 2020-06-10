#ifndef BIGNUM_H
#define BIGNUM_H
#include<iostream>
using namespace std;

class BigNUM
{
	friend ostream &operator<<(ostream &output, const BigNUM &right);//块
	friend istream &operator>>(istream &input, BigNUM &right);//BONUS
	friend BigNUM operator-(int integer, BigNUM &right);//俱计 - 计
	friend BigNUM operator+(int integer, BigNUM &right);//俱计 + 计
	friend BigNUM operator*(int integer, BigNUM &right);//俱计 * 计
	friend BigNUM operator-(BigNUM &left, int integer);//计 - 俱计//ぃ糶
	friend BigNUM operator+(BigNUM &left, int integer);//计 + 俱计//ぃ糶
	friend BigNUM operator*(BigNUM &left, int integer);//计 * 俱计//ぃ糶

public:

	BigNUM(long long int = 0, long long int = 1);//constructor
	BigNUM(const BigNUM &right);//copy constructor
	~BigNUM();//destructor
	bool less(const BigNUM &right);//耞计
	void resize(long long int);//э跑丁
	BigNUM &operator=(const BigNUM &right);//assign operator
	BigNUM operator-(const BigNUM &right);
	BigNUM operator+(const BigNUM &right);
	BigNUM operator*(const BigNUM &right);
	BigNUM operator-()const;//璽腹
	BigNUM &operator++();
	BigNUM operator++(int);
	BigNUM &operator--();
	BigNUM operator--(int);

private:
	long long int *ptr;
	bool negative;//璽腹
	long long int size;//ヘ玡ノ计
	long long int capacity;//程ノ计
};

#endif // !BIGNUM_H


