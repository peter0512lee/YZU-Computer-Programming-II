#include<iostream>
#include "s1061443_BigNUMV2.h" //Before your test this driver program, please replace it by your own file name.

//ref: https://defuse.ca/big-number-calculator.htm
//you may modified this example to test your program in various condition and input numbers

using namespace std;

int main(int argc, char *argv[]) {
    BigNUM n1(12, 52), n2(23, 34), n3(4, 45), n4(-14, 17), n5, n6, n7(12, 52), n8(-21, 55), n9(922337203685477580), n10(-9898989), n11(100);
    
    cout << "Hello, I'm driver program: " << endl;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;
    cout << "n5 = " << n5 << endl;
    cout << "n6 = " << n6 << endl;
    cout << "n7 = " << n7 << endl;
    cout << "n8 = " << n8 << endl;
    cout << "n9 = " << n9 << endl;
    cout << "n10 = " << n10 << endl;
    
    cout << "n1 = n1 - n7 : " << (n1 = n1 - n7) << endl;
    
    cout << "n7 = n7 + n2 : " << (n7 = n7 + n2) << endl;
    
    cout << "n1 = " << n1 << endl;
    cout << "n3 = " << n3 << endl;
    cout << "n1 - n3 = " << (n1 - n3) << endl;
    cout << "n1 - n3 = " << (n1 - n3) << endl;
    cout << "n1 - n3 = " << (n1 - n3) << endl;
    cout << "n1 = " << n1 << endl;
    cout << "n3 = " << n3 << endl;
    
    cout << "n1 = n1 - n3 : " << (n1 = n1 - n3) << endl;
    cout << "n1 = " << n1 << endl;
    cout << "n3 = " << n3 << endl;

    
    cout << "n4 = " << n4 << endl;
    cout << "n8 = " << n8 << endl;
    cout << "n4 = n4 - n8 : " << (n4 = n4 - n8) << endl;
    cout << "n8 * n4 : " << (n8 * n4) << endl;
    cout << "n8 * n4 : " << (n8 * n4) << endl;
    cout << "n8 * n4 : " << (n8 * n4) << endl;
    cout << "n4 = " << n4 << endl;
    cout << "n8 = " << n8 << endl;
    cout << "n8 = n8 * n4 : " << (n8 = n8 * n4) << endl;    
    cout << "n8 + n4 * n2 : " << (n8 + n4 * n2) << endl;
    cout << "n8 + n4 * n2 : " << (n4 * n2 + n8) << endl;
    
    cout << "n6 - n8 + n9: " << (n6 - n8 + n9) << endl;
    cout << "n6 - n8 + n9: " << ((n6 - n8) + n9) << endl;
    cout << "n6 - n8 + n9: " << (n6 - (n8 - n9)) << endl;
    cout << "n1 = n6 - n8 + n9: " << (n1 = n6 - (n8 - n9)) << endl;
	
    cout << "32 * n1: " << (32 * n1) << endl;
    cout << "n1 = n1 * 32: " << (n1 = n1 * 32) << endl;
    
    cout << "9999 + n1: " << (9999 + n1) << endl;
    cout << "n1 + 9999: " << (n1 + 9999) << endl;
    
    cout << "-9999 - n1: " << (-9999 - n1) << endl;
    cout << "-n1 - 9999: " << (-n1 - 9999) << endl;

	++n10;
	cout << "++n10 = " << n10 << endl;
	n10++;
	cout << "n10++ = " << n10 << endl;
	--n11;
	cout << "--n11 = " << n11 << endl;
	n11--;
	cout << "n11-- = " << n11 << endl;

	system("pause");
	return 0;
}
