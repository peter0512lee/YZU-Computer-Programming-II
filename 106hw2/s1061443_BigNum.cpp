#include<iostream>
#include<iomanip>
#include<cmath>
#include"s1061443_BigNum.h"

using namespace std;

BigNUM::BigNUM(long long int number, long long int index)//number�O��, index�O����
{
	negative = false;

	if (number < 0)
	{
		if (index % 2 != 0)
			negative = true;

		number = 0 - number;
	}

	ptr = new long long int[100000]();
	ptr[0] = 1; //�����̦��n�����o��}�C�ȵ���1

	digits = 1; //���ޫ��ˡAdigits���|�j�󵥩�1�A�]����Ƥ@�w�����
	long long int buffer = 0;

	for (int i = 0; i < index; i++)
	{
		for (long long int j = 0; j < digits; j++)
		{
			ptr[j] = ptr[j] * number + buffer; //�U�Ӧ�ƹB�⦡�Abuffer�O���i��ɭn�[�W�h��
			buffer = ptr[j] / 1000; //buffer�Y�j��0�A�h�ݶi��
			ptr[j] = ptr[j] % 1000; //�C��}�C�s3���
			if (buffer != 0 && j + 1 == digits) //�P�_�}�C�O�_+1
				digits++; //�O���}�C���
		}
	}

	if (number == 0)
		ptr[0] = 0;
}

BigNUM::~BigNUM()
{
	delete[] ptr;
}

void BigNUM::print() const
{
	if (negative == true)
		cout << "-";

	for (long long int i = digits - 1; i >= 0; i--) //�ϦV��X
	{
		if (i != digits - 1) //�̫e�����}�C�e�������0
			cout << " " << setfill('0') << setw(3) << ptr[i];
		else //�̫e�����}�C��X
			cout << ptr[i];
	}

	cout << endl;
}

bool BigNUM::less(const BigNUM &right)
{
	if (digits > right.digits)
		return false;

	if (digits < right.digits)
		return true;

	if (ptr[digits - 1] >= right.ptr[digits - 1])
		return false;

	if (ptr[digits - 1] < right.ptr[digits - 1])
		return true;
}

void BigNUM::add(const BigNUM &right)
{
	if (negative == right.negative)
	{
		digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

		for (long long int i = 0; i < digits; i++)
			ptr[i] += right.ptr[i];

		for (long long int i = 0; i < digits - 1; i++)
			if (ptr[i] / 1000 != 0)
			{
				ptr[i] %= 1000;
				ptr[i + 1]++;
			}

		if (ptr[digits - 1] == 0) digits--;
	}
	else
	{
		if (negative == false)//�Q�[�Ƭ���
		{
			if (less(right))
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] = right.ptr[i] - ptr[i];

				negative = true;
			}
			else
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] -= right.ptr[i];
			}
		}
		else
		{
			if (less(right))
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] = right.ptr[i] - ptr[i];

				negative = false;
			}
			else
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] -= right.ptr[i];
			}
		}

		for (long long int i = 0; i < digits; i++)//�ɦ�
			if (ptr[i] < 0)
			{
				ptr[i] += 1000;
				ptr[i + 1]--;
			}

		for (long long int i = digits - 1; i > 0; i--)//�h�s
			if (ptr[i] == 0)
				digits--;
			else
				break;
	}
}

void BigNUM::minus(const BigNUM &right)
{
	if (negative != right.negative)
	{
		digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

		for (long long int i = 0; i < digits; i++)
			ptr[i] += right.ptr[i];

		for (long long int i = 0; i < digits - 1; i++)
			if (ptr[i] / 1000 != 0)
			{
				ptr[i] %= 1000;
				ptr[i + 1]++;
			}

		if (ptr[digits - 1] == 0) digits--;
	}
	else
	{
		if (negative == false)//�Q��Ƭ���
		{
			if (less(right))
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] = right.ptr[i] - ptr[i];

				negative = true;
			}
			else
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] -= right.ptr[i];
			}
		}
		else
		{
			if (less(right))
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] = right.ptr[i] - ptr[i];

				negative = false;
			}
			else
			{
				digits = (digits < right.digits) ? right.digits + 1 : digits + 1;

				for (long long int i = 0; i < digits; i++)
					ptr[i] -= right.ptr[i];
			}
		}
	}

	for (long long int i = 0; i < digits; i++)//�ɦ�
		if (ptr[i] < 0)
		{
			ptr[i] += 1000;
			ptr[i + 1]--;
		}

	for (long long int i = digits - 1; i > 0; i--)//�h�s
		if (ptr[i] == 0)
			digits--;
		else
			break;
}

void BigNUM::multiply(const BigNUM &right)
{
	if (negative == right.negative)
		negative = false;
	else
		negative = true;

	digits = digits + right.digits + 1;

	BigNUM buffer;
	buffer.digits = digits;

	long long int i;
	long long int j;
	long long int k;

	for (i = 0; i < right.digits; ++i)
	{
		for (j = 0, k = i; j < digits; ++j, ++k)
		{
			buffer.ptr[k] += ptr[j] * right.ptr[i];

			for (long long int l = 0; l < digits - 1; l++)
				if (buffer.ptr[l] / 1000 != 0)
				{
					buffer.ptr[l + 1] += buffer.ptr[l] / 1000;
					buffer.ptr[l] %= 1000;
				}
		}
	}

	for (long long int i = 0; i < digits; i++)
		ptr[i] = buffer.ptr[i];

	for (long long int i = digits - 1; i > 0; i--)//�h�s
		if (ptr[i] == 0)
			digits--;
		else
			break;
}