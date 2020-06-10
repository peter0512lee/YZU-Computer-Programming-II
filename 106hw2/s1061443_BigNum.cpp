#include<iostream>
#include<iomanip>
#include<cmath>
#include"s1061443_BigNum.h"

using namespace std;

BigNUM::BigNUM(long long int number, long long int index)//number琌┏, index琌计
{
	negative = false;

	if (number < 0)
	{
		if (index % 2 != 0)
			negative = true;

		number = 0 - number;
	}

	ptr = new long long int[100000]();
	ptr[0] = 1; //琵程Ν璶硂皚单1

	digits = 1; //ぃ恨或妓digitsゲ穦单1俱计﹚Τ计
	long long int buffer = 0;

	for (int i = 0; i < index; i++)
	{
		for (long long int j = 0; j < digits; j++)
		{
			ptr[j] = ptr[j] * number + buffer; //计笲衡Αbuffer琌Τ秈璶
			buffer = ptr[j] / 1000; //buffer璝0玥惠秈
			ptr[j] = ptr[j] % 1000; //–皚3计
			if (buffer != 0 && j + 1 == digits) //耞皚琌+1
				digits++; //癘魁皚计
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

	for (long long int i = digits - 1; i >= 0; i--) //は块
	{
		if (i != digits - 1) //程玡皚玡ぃ干0
			cout << " " << setfill('0') << setw(3) << ptr[i];
		else //程玡皚块
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
		if (negative == false)//砆计タ
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

		for (long long int i = 0; i < digits; i++)//
			if (ptr[i] < 0)
			{
				ptr[i] += 1000;
				ptr[i + 1]--;
			}

		for (long long int i = digits - 1; i > 0; i--)//箂
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
		if (negative == false)//砆搭计タ
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

	for (long long int i = 0; i < digits; i++)//
		if (ptr[i] < 0)
		{
			ptr[i] += 1000;
			ptr[i + 1]--;
		}

	for (long long int i = digits - 1; i > 0; i--)//箂
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

	for (long long int i = digits - 1; i > 0; i--)//箂
		if (ptr[i] == 0)
			digits--;
		else
			break;
}