#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>
#include <iomanip>
using namespace std;

class BigNUM
{
	friend ostream &operator<<(ostream &, BigNUM &);
	friend istream &operator >> (istream &, BigNUM &);

	friend BigNUM operator-(int , BigNUM &);
	friend BigNUM operator-(BigNUM &, int);

	friend BigNUM operator+(int , BigNUM &);
	friend BigNUM operator+(BigNUM &, int);

	friend BigNUM operator*(int , BigNUM &);
	friend BigNUM operator*(BigNUM &, int);

	friend BigNUM operator/(int, BigNUM &);
	friend BigNUM operator/(BigNUM &, int);

	friend BigNUM operator%(int, BigNUM &);
	friend BigNUM operator%(BigNUM &, int);

public:
	//default constructor
	BigNUM(long long = 0, long long = 1);

	//copy constructor
	BigNUM(BigNUM &right);

	//destructor
	~BigNUM();

	BigNUM &resize(long long);

	bool numLess(BigNUM &right);
	bool operator<(BigNUM &right);
	bool operator>(BigNUM &right);
	bool operator==(BigNUM &right);
	bool operator==(int right);
	BigNUM &operator=(BigNUM &right);
	BigNUM operator-(BigNUM &right);
	BigNUM operator+(BigNUM &right);
	BigNUM operator*(BigNUM &right);
	BigNUM operator/(BigNUM &right);
	BigNUM operator%(BigNUM &right);
	BigNUM operator+();
	BigNUM operator-();

private:
	bool negative;
	long long *ptr;
	long long size;
	long long capacity;
};

//default constructor
BigNUM::BigNUM(long long number, long long index):
	negative(false),
	size(1),
	capacity(1)
{
	if (number < 0)if (index % 2 != 0) { negative = true; number = 0 - number; }

	ptr = new long long[capacity]();
	ptr[0] = number == 0 ? 0 : 1;

	long long buffer = 0;
	for (long long i = 0; i < index; i++)
		for (long long j = 0; j < size; j++)
		{
			ptr[j] = ptr[j] * number + buffer;
			buffer = ptr[j] / 1000;
			ptr[j] = ptr[j] % 1000;
			if (buffer != 0 && j + 1 == size)resize(size + 1);
		}
}

//copy constructor
BigNUM::BigNUM(BigNUM &right):
	negative(right.negative),
	size(right.size),
	capacity(right.capacity)
{
	ptr = new long long[capacity]();
	for (long long i = 0; i < size; i++)ptr[i] = right.ptr[i];
}

//destructor
BigNUM::~BigNUM()
{
	delete[] ptr;
}

BigNUM &BigNUM::resize(long long n)
{
	if (n > capacity)
	{
		long long *tempPtr = ptr;
		ptr = new long long[n]();
		for (int i = 0; i < size; i++)ptr[i] = tempPtr[i];
		capacity = size = n;
		delete[] tempPtr;
	}
	else
	{
		size = n;
		for (int i = size; i < capacity; i++)ptr[i] = 0;
	}

	return *this;
}

bool BigNUM::numLess(BigNUM &right)
{
	if (size > right.size)return false;

	if (size < right.size)return true;

	for (long long i = size - 1; i >= 0; i--)
	{
		if (ptr[i] > right.ptr[i])return false;
		if (ptr[i] < right.ptr[i])return true;
	}

	return false;
}

bool BigNUM::operator<(BigNUM &right)
{
	if (negative == true && right.negative == false) return true;
	if (negative == false && right.negative == true) return false;
	if (negative == right.negative == false) return numLess(right);
	if (negative == right.negative == true) return right.numLess(*this);
}

bool BigNUM::operator>(BigNUM &right)
{
	return right < *this;
}

bool BigNUM::operator==(BigNUM &right)
{
	if (size != right.size)return false;

	if (negative != right.negative)return false;

	for (long long i = size - 1; i >= 0; i--)
	{
		if (ptr[i] > right.ptr[i])return false;
		if (ptr[i] < right.ptr[i])return false;
	}

	return true;
}

bool BigNUM::operator==(int right)
{
	BigNUM num(right);
	return *this == num;
}

BigNUM &BigNUM::operator=(BigNUM &right)
{
	size = right.size;
	negative = right.negative;
	resize(size);
	for (long long i = 0; i < size; i++)ptr[i] = right.ptr[i];

	return *this;
}

BigNUM BigNUM::operator+(BigNUM &right)
{
	BigNUM result;

	if (*this == -right) return 0;

	if (negative == right.negative) //正加正或負加負
	{
		result.negative = negative;
		result = *this;
		result.resize(size < right.size ? right.size + 1 : size + 1);
		for (long long i = 0; i < right.size; i++)result.ptr[i] += right.ptr[i];
	}
	else
	{
		if (negative == false) //正加負
		{
			if (numLess(right)) //小正加大負
			{
				result = right;
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = true;
			}
			else //大正加小負
				return -(-right + -*this);
		}
		else //負加正
			return -(-*this + -right);
	}

	for (long long i = 0; i < result.size - 1; i++) //進位
		if (result.ptr[i] / 1000 != 0)
		{
			result.ptr[i] %= 1000;
			result.ptr[i + 1]++;
		}

	for (long long i = 0; i < result.size - 1; i++) //借位
		if (result.ptr[i] < 0)
		{
			result.ptr[i] += 1000;
			result.ptr[i + 1]--;
		}

	for (long long i = result.size - 1; i > 0; i--) //去零
		if (result.ptr[i] == 0)
			result.size--;
		else
			break;

	return result;
}

BigNUM BigNUM::operator-(BigNUM &right)
{
	return *this + -right;
}

BigNUM BigNUM::operator*(BigNUM &right)
{
	BigNUM result;
	result.resize(size + right.size + 1);

	if (negative != right.negative)result.negative = true;

	long long i;
	long long j;
	long long k;

	for (i = 0; i < right.size; i++)
		for (j = 0, k = i; j < size; j++, k++)
			result.ptr[k] += ptr[j] * right.ptr[i];

	for (long long l = 0; l < result.size - 1; l++)
		if (result.ptr[l] / 1000 != 0)
		{
			result.ptr[l + 1] += result.ptr[l] / 1000;
			result.ptr[l] %= 1000;
		}

	for (long long m = result.size - 1; m > 0; m--)
		if (result.ptr[m] == 0)
			result.size--;
		else
			break;

	return result;
}

BigNUM BigNUM::operator/(BigNUM &right)
{
	BigNUM result;

	if (right == 0) return result.resize(0);
	if (*this == 0 || numLess(right)) return 0;

	BigNUM remainder = *this;
	BigNUM buffer;
	

	result.resize(size - right.size + 1);
	buffer = right * BigNUM(1000, size - right.size);
	remainder.negative = buffer.negative = false;

	for (int i = result.size - 1; i >= 0; i--)
	{
		while (!remainder.numLess(buffer))
		{
			remainder = remainder - buffer;
			result.ptr[i]++;
		}

		for (int j = 0; j < buffer.size - 1; j++)
			buffer.ptr[j] = buffer.ptr[j + 1];
		
		buffer.size--;
	}
	
	for (long long m = result.size - 1; m > 0; m--)
		if (result.ptr[m] == 0)
			result.size--;
		else
			break;

	if (negative != right.negative) result.negative = true;

	return result;
}

BigNUM BigNUM::operator%(BigNUM &right)
{
	BigNUM result = +*this - +*this / +right * +right;
	if (negative != right.negative) result.negative = true;
	return result;
}

BigNUM BigNUM::operator+() //絕對值
{
	BigNUM buffer = *this;
	buffer.negative = false;
	return buffer;
}

BigNUM BigNUM::operator-()
{
	BigNUM buffer = *this;
	buffer.negative = !buffer.negative;
	return buffer;
}

ostream &operator<<(ostream &output, BigNUM &right)
{
	for (long long i = right.size - 1; i >= 0; i--)
		if (i == right.size - 1)
			output << (right.negative == true ? 0 - right.ptr[i] : right.ptr[i]);
		else
			output << " " << setfill('0') << setw(3) << right.ptr[i];

	output << endl;
	return output;
}

istream &operator >> (istream &input, BigNUM &right)
{
	long long num;
	input >> num;
	right = BigNUM(num);
	return input;
}

BigNUM operator+(int number, BigNUM &right)
{
	BigNUM num(number);
	return num + right;
}

BigNUM operator+(BigNUM &left, int number)
{
	return number + left;
}

BigNUM operator-(int number, BigNUM &right)
{
	BigNUM num(number);
	return num - right;
}

BigNUM operator-(BigNUM &left, int number)
{
	return -(number - left);
}

BigNUM operator*(int number, BigNUM &right)
{
	BigNUM num(number);
	return num * right;
}

BigNUM operator*(BigNUM &left, int number)
{
	return number * left;
}

BigNUM operator/(int number, BigNUM &right)
{
	BigNUM num(number);
	return num / right;
}

BigNUM operator/(BigNUM &left, int number)
{
	return number / left;
}

BigNUM operator%(int number, BigNUM &right)
{
	BigNUM num(number);
	return num % right;
}

BigNUM operator%(BigNUM &left, int number)
{
	return number % left;
}

#endif //BIGNUM_H
