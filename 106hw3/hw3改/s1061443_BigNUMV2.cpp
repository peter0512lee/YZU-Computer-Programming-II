#include<iostream>
#include<iomanip>
#include"s1061443_BigNUMV2.h"
using namespace std;

BigNUM::BigNUM(long long int number, long long int index) //number�O����, index�O����
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

    capacity = size = 1;//capacity�Psize���]�@��A�]���@�w���@���
	ptr = new long long int[capacity]();//�ЫؼƦC
	ptr[0] = 1; //����ȵ���1

	long long int buffer = 0;//�i��Ȧs�Ŷ�
	for (long long int i = 0; i < index; i++)
	{
		for (long long int j = 0; j < size; j++)
		{
			ptr[j] = ptr[j] * number + buffer; //�U�Ӧ�ƹB�⦡
			buffer = ptr[j] / 1000; //buffer�Y�j��0�A�h�ݶi��
			ptr[j] = ptr[j] % 1000; //�C��}�C�s3���
			if (buffer != 0 && j + 1 == size) //�P�_�}�C�O�_�ݭn+1
				resize(size + 1); //�W�[�Ŷ�
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

	return false;//��j�Ƶ����
}

void BigNUM::resize(long long int n)//�j���n��ƪ���
{
	if (n > capacity)//n�O�ڻݭn�����
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
	BigNUM result;//�غcresult�l

	if (negative == right.negative) //���[���έt�[�t
	{
		result = *this;//���G����Q�[��
		result.resize(size < right.size ? right.size + 1 : size + 1);//���wresult.size

		for (long long int i = 0; i < right.size; i++)//
			result.ptr[i] += right.ptr[i];		

		result.negative = negative;
	}
	else //������
	{
		if (negative == false) //���[�t
		{
			if (less(right))//�p���[�j�t
			{
				result = right;//���G����[��
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = true;
			}
			else
			{
				result = *this;//���G����Q�[��
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = false;
			}
		}
		else //�t�[��
		{
			if (less(right))//�p�t�[�j��
			{
				result = right;//���G����[��
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = false;
			}
			else
			{
				result = *this;//���G����Q�[��
				result.resize(size < right.size ? right.size + 1 : size + 1);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = true;
			}
		}
	}

	for (long long int i = 0; i < result.size - 1; i++) //�i��
		if (result.ptr[i] / 1000 != 0)
		{
			result.ptr[i] %= 1000;
			result.ptr[i + 1]++;
		}

	for (long long int i = 0; i < result.size; i++) //�ɦ�
		if (result.ptr[i] < 0)
		{
			result.ptr[i] += 1000;
			result.ptr[i + 1]--;
		}

	for (long long int i = result.size - 1; i > 0; i--) //�h�s
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

	if (negative != right.negative) //���P���N�O�ۥ[
	{
		result = *this;//���G����Q�[��
		result.resize(size < right.size ? right.size : size);

		for (long long int i = 0; i < right.size; i++)
			result.ptr[i] += right.ptr[i];

	}
	else
	{
		if (negative == false) //���
		{
			if (less(right))
			{
				result = right;//���G����[��
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = true;
			}
			else
			{
				result = *this;//���G����Q�[��
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = false;
			}
		}
		else //�t��t
		{
			if (less(right))
			{
				result = right;//���G����[��
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < size; i++)
					result.ptr[i] -= ptr[i];

				result.negative = false;
			}
			else
			{
				result = *this;//���G����Q�[��
				result.resize(size < right.size ? right.size : size);

				for (long long int i = 0; i < right.size; i++)
					result.ptr[i] -= right.ptr[i];

				result.negative = true;
			}
		}
	}

	for (long long int i = 0; i < result.size - 1; i++) //�i��
		if (result.ptr[i] / 1000 != 0)
		{
			result.ptr[i] %= 1000;
			result.ptr[i + 1]++;
		}

	for (long long int i = 0; i < result.size; i++) //�ɦ�
		if (result.ptr[i] < 0)
		{
			result.ptr[i] += 1000;
			result.ptr[i + 1]--;
		}

	for (long long int i = result.size - 1; i > 0; i--) //�h�s
		if (result.ptr[i] == 0)
			result.size--;
		else
			break;

	return result;
	*/
	return *this + -right;//�i�H��g���o��
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

	for (long long int l = 0; l < result.size - 1; l++) //�i��
		if (result.ptr[l] / 1000 != 0)
		{
			result.ptr[l + 1] += result.ptr[l] / 1000;
			result.ptr[l] %= 1000;
		}

	for (long long int m = result.size - 1; m > 0; m--) //�h�s
		if (result.ptr[m] == 0)
			result.size--;
		else
			break;

	return result;
}

BigNUM BigNUM::operator-()const//�Ȧs�@�ӥ[�t�����j��
{
	BigNUM buffer = *this;
	buffer.negative = (buffer.negative == false ? true : false);
	return buffer;
}

ostream &operator<<(ostream &output, const BigNUM &right)
{	
	for (long long int i = right.size - 1; i >= 0; i--) //�ϦV��X
	{
		if (i != right.size - 1) //�̫e�����}�C�e�������0
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

BigNUM operator+(BigNUM &left, int integer)//�i���g
{	
	return integer + left;
}

BigNUM operator-(BigNUM &left, int integer)//�i���g
{		
	return integer - left;
}

BigNUM operator*(BigNUM &left, int integer)//�i���g
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