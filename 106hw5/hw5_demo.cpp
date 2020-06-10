#include <iostream>
#include "s1061443_MyString.h"

using namespace std;
int main()
{
	cout << "作業批改!!" << endl << endl;
	cout << "1.可以正常建構(預設大小為10的鎮列) 和 3.getSize, getCapacity:" << endl;
	MyString A;
	cout << " [size=" << A.getSize() << ", capacity=" << A.getCapacity() << "]" << endl << endl;

	cout << "2.可以用push_back / pop_back 放與丟東西" << endl;
	const char *str1= "to be ";
	MyString B(str1);
	cout << "' " << B << " '" << " push_back(a) = ";
	B.push_back('a'); cout << B << endl;
	cout << "' " << B << " '" << " pop_back() = ";
	B.pop_back(); cout << B << endl << endl;

	cout << "4. resize, reserve, shrink_to_fit" << endl;
	MyString C = "aaa";
	cout << "C = " << C << " [size=" << C.getSize() << ", capacity=" << C.getCapacity() << "]" << endl;
	cout << "resize(6, 'b') = ";
	C.resize(6, 'b');
	cout << C << " [size=" << C.getSize() << ", capacity=" << C.getCapacity() << "]" << endl;
	cout << "reserve(20)    = ";
	C.reserve(20);
	cout << C << " [size=" << C.getSize() << ", capacity=" << C.getCapacity() << "]" << endl;
	cout << "shrink_to_fit  = ";
	C.shrink_to_fit();
	cout << C << " [size=" << C.getSize() << ", capacity=" << C.getCapacity() << " ]" << endl << endl;

	cout << "7. ==與!= " << endl;
	MyString D = "aaa", E = "bbb", F = "aaa";
	cout << "D = " << D << endl << "E = " << E << endl << "F = " << F << endl;
	cout << "D == E ? " << (D == E) << endl;
	cout << "D != F ? " << (D != F) << endl << endl;

	cout << "8.clear, empty, front, back" << endl;
	MyString G = "demo";
	cout << "G = " << G << endl;
	cout << "G.front() = " << G.front() << endl;
	cout << "G.back() = " << G.back() << endl;
	cout << "G is empty ? " << G.empty() << endl;
	cout << "G.clear()" << endl;
	G.clear();
	cout << "G is empty ? " << G.empty() << endl << endl;

	cout << "11.MyString先直接使用公開測資, 繼承正常5分" << endl;
	const char *str2 = "the ";
	const char *str3 = "or not to be";
	const char *str_tester = "Ha";
	MyString t0(str1);
	MyString X(str2);
	MyString t1 = X;
	MyString t2 = "or not to be";
	cout << "t0 = str1: " << t0 << endl;
	cout << "t1 = X = str2: " << t1 << " = " << X << endl;
	cout << "t2 = str3: " << t2 << " = " << str3 << endl << endl;

	cout << "13.六大功能" << endl;
	A = "I love ", B = "coding", C = "very ", D = "love", E = "running", F = "xx";
	cout << "[append] : " << A.append(B) << endl;
	cout << "[insert] : " << A.insert(2,C) << endl;
	cout << "[substr] : " << A.substr(7,11) << endl;
	cout << "[erase ] : " << A.erase(2, 5) << endl;
	cout << "[find有] : " << A.find(D) << endl;
	cout << "[find無] : " << A.find(E) << endl;
	cout << "[find_first_of有] : " << A.find_first_of(E) << endl;
	cout << "[find_first_of無] : " << A.find_first_of(F) << endl << endl;

	cout << "三種+都可用" << endl;
	A = "A ", C = "C ";
	str1 = "B ";
	cout << "MyString + MyString = " << (A + C) << endl;
	cout << "MyString + char* = " << (A + str1) << endl;
	cout << "char* + MyString = " << (str1 + C) << endl;

	/*///To be or not to be, that is the question;
	char *str1 = "to be "; //This char string ended with '\0' automatically
	char *str2 = "the ";
	char *str3 = "or not to be";
	char *str_tester = "Ha";
	MyString A(str1);
	MyString X(str2);
	MyString B = X;
	MyString C = "or not to be";
	cout << "A = str1: " << A << endl;
	cout << "B = X = str2: " << B << " = " << X << endl;
	cout << "C = str3: " << C << " = " << str3 << endl;

	MyString D = A + C;
	cout << "D = A + C: " << D << endl;
	D = A + str3;
	cout << "D = A + str3: " << D << endl;
	D = str1 + C;
	cout << "D = str1 + C: " << D << endl;

	cout << "-------------------------------" << endl;

	cout << "D push ',': ";
	D.push_back(',');
	cout << D << endl;
	cout << "D pop_back: ";
	D.pop_back();
	cout << D << endl;

	cout << "-------------------------------" << endl;

	MyString STR = D;
	MyString E = ", that is cool question";
	MyString F = ", that is (the )question";
	MyString G = "the ";

	cout << "STR = D append F: " << STR.append(F) << endl;

	cout << "STR erase 28-34: " << STR.erase(28, 6) << endl;

	cout << "STR insert G: " << STR.insert(28, G) << endl;

	cout << "STR erase 28-31: " << STR.erase(28, 4) << endl;

	cout << "STR insert E (10-14): " << STR.insert(28, E, 10, 5) << endl;

	cout << "STR substr(3,len=15): " << STR.substr(3, 15) << endl;

	cout << "STR: " << STR << endl;

	cout << "-------------------------------" << endl;

	MyString STR2(E, 10, 4);
	cout << "find \"cool\" in the STR: " << STR.find(STR2) << endl;

	STR2 = "cXXL";
	cout << "Let STR2 = cXXL: " << STR2 << endl;

	cout << "find \"cXXL\" in the STR: " << STR.find(STR2) << endl;

	cout << "find first \"cXXL\" in the STR: " << STR.find_first_of(STR2) << endl;

	cout << "print the first and last char of STR: " << STR.front() << " & " << STR.back() << endl;

	//cout << "replace the first and last char of STR: " << STR.front() << " & " << STR.back() << endl;

	cout << "-------------------------------" << endl;

	cout << "Rebuild STR2 word by word (x2): ";
	MyString STR3 = "";
	for (int i = 0; i < STR2.getSize(); i++)
		STR3.push_back(STR2[i]);
	//cout << STR3;
	//STR3.clear();
	//STR3 = STR3 + STR2[0] + STR2[1] + STR2[2] + STR2[3];
	cout << STR3 << endl;

	cout << STR3 << " is equal to " << STR2 << "? " << (STR3 == STR2) << endl;
	STR3 = STR3 + "-ZZZ";
	cout << STR3 << " is equal to " << STR2 << "? " << (STR3 == STR2) << endl;

	STR3.pop_back();
	STR3.pop_back();
	cout << "STR3 pop 2 char = " << STR3 << endl;

	STR3.clear();
	cout << "STR3 clear all char = " << STR3 << endl;

	cout << "-------------------------------" << endl;

	cout << "Current STR3 [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	cout << "STR3 append STR2 = " << STR3.append(STR2);
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	STR3.reserve(20);
	cout << "STR3 reserve to 20 = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	STR3.shrink_to_fit();
	cout << "STR3 shrink_to_fit = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;

	STR3.resize(25, 'c');
	cout << "STR3 resize to 25 = " << STR3 << endl;
	cout << " [size=" << STR3.getSize() << ", capacity=" << STR3.getCapacity() << "]" << endl;
	cout << "STR3_123 = " << STR3[1] << STR3[2] << STR3[3] << endl;*/

	system("pause");
	return 0;
}