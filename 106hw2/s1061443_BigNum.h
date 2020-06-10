#ifndef BIGNUM_H
#define BIGNUM_H

using namespace std;


class BigNUM
{
public:
	BigNUM(long long int = 0, long long int = 0);
	~BigNUM();
	void print()const;
	bool less(const BigNUM &right);
	void add(const BigNUM &right);
	void minus(const BigNUM &right);
	void multiply(const BigNUM &right);

private:

	long long int *ptr;
	bool negative;
	long long int digits;
};

#endif // !BIGNUM_H


