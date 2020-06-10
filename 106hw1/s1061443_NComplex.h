#ifndef NCOMPLEX_H
#define NCOMPLEX_H

using namespace std;

class NComplex {

public:
	NComplex(double = 0, double = 0);
	void set(double r, double i);
	double getREAL();
	double getIMAGINARY();
	void print();
	double add(const NComplex &right);
	double minus(const NComplex &right);
	double multiply(const NComplex &right);
	double divide(const NComplex &right);
	double conjugate();

private:
	double real;
	double imaginary;

};

#endif