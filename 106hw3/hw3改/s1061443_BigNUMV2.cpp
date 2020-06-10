#include<iostream>
#include<iomanip>
#include"s1061443_BigNUMV2.h"
using namespace std;

BigNUM::BigNUM(long long int number, long long int index) //number琌┏计, index琌计
{
	negative = false;

	if (number < 0) 
	{
		if (index % 2 != 0)
		{
			negative = true;
			number = 0 - number;
		}
	}

    capacity = size = 1;//capacity籔size常砞﹚Τ计
	ptr = new long long int[capacity]();//承计
	ptr[0] = 1; //单1

	long long int buffer = 0;//秈既丁
	for (long long int i = 0; i < index; i++)
	{
		for (long long int j = 0; j < size; j++)
		{
			ptr[j] = ptr[j] * number + buffer; //计笲衡Α
			buffer = ptr[j] / 1000; //buffer璝0玥惠秈
			ptr[j] = ptr[j] % 1000; //–皚3计
			if (buffer != 0 && j + 1 == size) //耞皚琌惠璶+1
				resize(size + 1); //糤丁
		}
	}

	if (number == 0)
		ptr[0] = 0;
}

//copy constructor
BigNUM::BigNUM(const BigNUM &right):
	size(right.size),
	capacity(right.capacity),
	negative(right.negative)
{
	ptr = new long long int[capacity]();

	for (long long int i = 0; i < size; i++)
		ptr[i] = right.ptr[i];
}

BigNUM::~BigNUM()
{
	delete[] ptr;
}

bool BigNUM::less(const BigNUM &right)
{
	if (size > right.size)
		return false;

	if (size < right.size)
		return true;

	for (long long int i = size - 1; i >= 0; i--)
	{
		if (ptr[i] >= right.ptr[i])
			return false;

		if (ptr[i] < right.ptr[i])
			return true;
	}

	return false;//ㄢ计单
}

void BigNUM::resize(long long int n)//眏n计
{
	if (n > capacity)//n琌и惠璶计
	{		
		long long int *tempPtr = ptr;
		ptr = new long long int[n]();
		for (int i = 0; i < size; i++)
			ptr[i] = tempPtr[i];
		capacity = size = n;
		delete[] tempPtr;
	}
	else
	{
		size = n;
		for (int i = size; i < capacity; i++)
			ptr[i] = 0;
	}
}

BigNUM &BigNUM::operator=(const BigNUM &right)
{
	size = right.size;
	negative = right.negative;
	resize(size);

	for (long long int i = 0; i < size; i++)
		ptr[i] = right.ptr[i];

	return *this;
}

BigNUM BigNUM::operator+(const BigNUM &right)
{
	BigNUM result;//篶result

	if (negative == right.negative) //タタ┪璽璽
	{
		result = *this;//挡狦单砆计
		result.resize(size < right.size ? right.size + 1 : size + 1);//倒﹚result.size

		for (long long int i = 0; i < right.size; i++)//
			result.ptr[i] += right.ptr[i];		

		result.negative = negative;
	}
	else //钵腹
	{
		if (negative == false) //タ璽
		{
			if (less(right))//タ璽
			{
				result = right;//挡狦单计
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = true;
			}
			else
			{
				result = *this;//挡狦单砆计
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = false;
			}
		}
		else //璽タ
		{
			if (less(right))//璽タ
			{
				result = right;//挡狦单计
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = false;
			}
			else
			{
				result = *this;//挡狦单砆计
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = true;
			}
		}
	}

	for (long long int i = 0; i < result.size - 1; i++) //秈
		if (result.ptr[i] / 1000 != 0)
		{
			result.ptr[i] %= 1000;
			result.ptr[i + 1]++;
		}

	for (long long int i = 0; i < result.size; i++) //
		if (result.ptr[i] < 0)
		{
			result.ptr[i] += 1000;
			result.ptr[i + 1]--;
		}

	for (long long int i = result.size - 1; i > 0; i--) //箂
		if (result.ptr[i] == 0)
			result.size--;
		else
			break;

	return result;
}

BigNUM BigNUM::operator-(const BigNUM &right)
{
	/*
	BigNUM result;

	if (negative != right.negative) //ぃ腹碞琌
	{
		result = *this;//挡狦单砆计
		result.resize(size < right.size ? right.size : size);

		for (long long int i = 0; i < right.size; i++)
			result.ptr[i] += right.ptr[i];

	}
	else
	{
		if (negative == false) //タ搭タ
		{
			if (less(right))
			{
				result = right;//挡狦单计
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = true;
			}
			else
			{
				result = *this;//挡狦单砆计
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = false;
			}
		}
		else //璽搭璽
		{
			if (less(right))
			{
				result = right;//挡狦单计
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = false;
			}
			else
			{
				result = *this;//挡狦单砆计
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = true;
			}
		}
	}

	for (long long int i = 0; i < result.size - 1; i++) //秈
		if (result.ptr[i] / 1000 != 0)
		{
			result.ptr[i] %= 1000;
			result.ptr[i + 1]++;
		}

	for (long long int i = 0; i < result.size; i++) //
		if (result.ptr[i] < 0)
		{
			result.ptr[i] += 1000;
			result.ptr[i + 1]--;
		}

	for (long long int i = result.size - 1; i > 0; i--) //箂
		if (result.ptr[i] == 0)
			result.size--;
		else
			break;

	return result;
	*/
	return *this + -right;//э糶Θ硂妓
}

BigNUM BigNUM::operator*(const BigNUM &right)
{
	BigNUM result;
	result.resize(size + right.size + 1);

	if (negative != right.negative)
		result.negative = true;

	long long int i;
	long long int j;
	long long int k;

	for (i = 0; i < right.size; i++)
		for (j = 0, k = i; j < size; j++, k++)
			result.ptr[k] += ptr[j] * right.ptr[i];

	for (long long int l = 0; l < result.size - 1; l++) //秈
		if (result.ptr[l] / 1000 != 0)
		{
			result.ptr[l + 1] += result.ptr[l] / 1000;
			result.ptr[l] %= 1000;
		}

	for (long long int m = result.size - 1; m > 0; m--) //箂
		if (result.ptr[m] == 0)
			result.size--;
		else
			break;

	return result;
}

BigNUM BigNUM::operator-()const//既璽腹计
{
	BigNUM buffer = *this;
	buffer.negative = (buffer.negative == false ? true : false);
	return buffer;
}

ostream &operator<<(ostream &output, const BigNUM &right)
{	
	for (long long int i = right.size - 1; i >= 0; i--) //は块
	{
		if (i != right.size - 1) //程玡皚玡ぃ干0
			output << " " << setfill('0') << setw(3) << right.ptr[i];
		else
			output << (right.negative == true ? "-" : "") << right.ptr[i];
	}

	output << endl;

	return output;
}

istream &operator>>(istream &input, BigNUM &right)//BONUS
{
	long long num;
	input >> num;
	right = BigNUM(num);
	return input;
}

BigNUM operator+(int integer, BigNUM &right)
{
	BigNUM num(integer);
	return num + right;
}

BigNUM operator-(int integer, BigNUM &right)
{
	BigNUM num(integer);
	return num - right;
}

BigNUM operator*(int integer, BigNUM &right)
{
	BigNUM num(integer);
	return num * right;
}

BigNUM operator+(BigNUM &left, int integer)//ぃ糶
{	
	return integer + left;
}

BigNUM operator-(BigNUM &left, int integer)//ぃ糶
{		
	return integer - left;
}

BigNUM operator*(BigNUM &left, int integer)//ぃ糶
{	
	return integer * left;
}

BigNUM &BigNUM::operator++()//++i
{
	*this = *this + 1;
	return *this;
}

BigNUM BigNUM::operator++(int)//i++
{
	BigNUM temp = *this;	
	*this = *this + 1;
	return temp;
}

BigNUM &BigNUM::operator--()//--i
{
	*this = *this - 1;
	return *this;
}

BigNUM BigNUM::operator--(int)//i--
{
	BigNUM temp = *this;
	*this = *this - 1;
	return temp;
}