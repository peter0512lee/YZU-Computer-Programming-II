#include<iostream>

#include"s1234567_NComplex.h" //Before your test this driver program, please replace it by your own file name.

//ref: https://www.symbolab.com/solver/complex-numbers-calculator/
//you may modified this example to test your program in various condition and input numbers

using namespace std;

int main(int argc, char *argv[]) {
	NComplex n1(1,2), n2(3,7), n3(6,2), n4; //Note, the default complex number is 0+0i
	cout << "Hello, I'm driver program: " << endl;
	cout << "n1 = "; n1.print(); 
	cout << endl << "n2 = "; n2.print();
	cout << endl << "n3 = "; n3.print();
	cout << endl << "n4 = "; n4.print();
	cout << endl;

	cout << "let n2 = 4 + 5i" << endl;
	n2.set(4, 5);
	cout << "new n2 = "; n2.print();
	cout << endl;

	cout << "let n4 = n3" << endl;
	n4.set(n3.getREAL(), n3.getIMAGINARY());
	cout << "new n4 = "; n4.print();
	cout << endl;

	cout << "n1 = n1 + n3 = "; // n1 = 7 + 4i
	n1.add(n3);
	n1.print(); // print out "7 + 4i" 
	cout << endl;

	cout << "n3 = n3 - n2 = "; // n3 = 2 - 3i
	n3.minus(n2);
	n3.print(); // print out "2 - 3i" 
	cout << endl;

	cout << "n2 = n2 * n4 = "; // n2 = (4 + 5i)*(6 + 2i) = 14 + 38i
	n2.multiply(n4);
	n2.print();
	cout << endl;

	cout << "n2 = n2 / n3 = "; // n2 = -(86/13)+(118/13)i
	n2.divide(n3);
	n2.print(); // print out "-6.61 + 9.07i" 
	cout << endl;

	cout << "n3 = conjugate(n3) = "; // n3 = 2 + 3i
	n3.conjugate();
	n3.print();
	cout << endl;

	return 0;
}