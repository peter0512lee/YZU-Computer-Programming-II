#include<iostream>
#include<iomanip>
#include"s1061443_NComplex.h"

using namespace std;

NComplex::NComplex(double r, double i) {

	set(r, i);

}

void NComplex::set(double r, double i) {

	real = r;
	imaginary = i;
}

double NComplex::getREAL() {

	return real;
}

double NComplex::getIMAGINARY() {

	return imaginary;
}

void NComplex::print() {

	if (imaginary < 0)
		cout << setprecision(3) << real << " - " << setprecision(3) << -1 * imaginary << "i";
	else
		cout << setprecision(3) << real << " + " << setprecision(3) << imaginary << "i";
}

double NComplex::add(const NComplex &right) {

	real += right.real;
	imaginary += right.imaginary;

	return real, imaginary;
}

double NComplex::minus(const NComplex &right) {

	real -= right.real;
	imaginary -= right.imaginary;

	return real, imaginary;
	
}

double NComplex::multiply(const NComplex &right) {

	double realBuffer;

	realBuffer = real;

	real = real * right.real - imaginary * right.imaginary;
	
	imaginary = realBuffer * right.imaginary + imaginary * right.real;
		
	return real, imaginary;
	
}

double NComplex::divide(const NComplex &right) {

	double dividendR, dividendI, divisor, conjugateR, conjugateI;
	

	conjugateR = right.real;
	conjugateI = right.imaginary * -1;

	dividendR = real * conjugateR - imaginary * conjugateI;	
	dividendI = real * conjugateI + imaginary * conjugateR;
	
	divisor = right.real * right.real + right.imaginary * right.imaginary;

	real = dividendR / divisor;
	imaginary = dividendI / divisor;

	return real, imaginary;
	
}

double NComplex::conjugate() {
		
	imaginary = imaginary * -1;

	return real, imaginary;

}