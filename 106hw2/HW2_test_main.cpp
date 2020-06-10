#include<iostream>
#include "s1061443_BigNUM.h"

//ref: https://defuse.ca/big-number-calculator.htm
//you may modified this example to test your program in various condition and input numbers
//(updated at 0324)

using namespace std;


int main(int argc, char *argv[]) {
	cout << "無傳入值測試:\n";
	BigNUM t1;
	cout << "t1 : "; t1.print();

	cout << "\nM^N測試:\n";
	BigNUM t2(12, 52), t3(-33, 39);
	cout << "t2 : "; t2.print();
	cout << "t3 : "; t3.print();

	cout << "\n加法測試(正+正、負+負、正+負、負+正):\n";
	BigNUM t4(12, 51), t5(33, 51);
	//t4: 10 920 525 780 002 579 727 993 102 330 411 079 589 912 583 123 907 903 488
	//t5: 278 106 368 284 019 834 975 553 700 094 962 919 414 183 375 617 767 113 232 413 626 310 384 666 309 217
	t4.add(t5);
	t4.print();
	// 278 106 368 284 019 834 975 564 620 620 742 921 993 911 368 720 097 524 312 003 538 893 508 574 212 705
	BigNUM t6(-12, 51), t7(-33, 51);
	t7.add(t6);
	t7.print();
	// -278 106 368 284 019 834 975 564 620 620 742 921 993 911 368 720 097 524 312 003 538 893 508 574 212 705
	t4.add(t6);
	t4.print();
	// 278 106 368 284 019 834 975 553 700 094 962 919 414 183 375 617 767 113 232 413 626 310 384 666 309 217
	t7.add(t5);
	t7.print();
	// -10 920 525 780 002 579 727 993 102 330 411 079 589 912 583 123 907 903 488



	cout << "\n減法測試(正-正、負-負、正-負、負-正):\n";
	BigNUM t8(12, 51), t9(33, 51), t10(-12, 51), t11(-33, 51);
	t8.minus(t9);
	t8.print();
	// -278 106 368 284 019 834 975 542 779 569 182 916 834 455 382 515 436 702 152 823 713 727 260 758 405 729
	t10.minus(t11);
	t10.print();
	// 278 106 368 284 019 834 975 542 779 569 182 916 834 455 382 515 436 702 152 823 713 727 260 758 405 729
	t9.minus(t8);
	t9.print();
	// 556 212 736 568 039 669 951 096 479 664 145 836 248 638 758 133 203 815 385 237 340 037 645 424 714 946
	t11.minus(t10);
	t11.print();
	// - 556 212 736 568 039 669 951 096 479 664 145 836 248 638 758 133 203 815 385 237 340 037 645 424 714 946

	cout << "\n乘法測試(正x正、負x負、正x負、負x正):\n";
	BigNUM t12(12, 51), t13(33, 51), t14(-12, 51), t15(-33, 51);
	t12.multiply(t13);
	t12.print();
	// 3 037 067 764 428 530 408 665 202 163 743 275 041 533 447 489 469 800 829 540 088 403 626 208 333 837 246 200 818 957 217 608 702 987 035 390 163 369 517 942 708 545 200 848 896
	t14.multiply(t15);
	t14.print();
	//3 037 067 764 428 530 408 665 202 163 743 275 041 533 447 489 469 800 829 540 088 403 626 208 333 837 246 200 818 957 217 608 702 987 035 390 163 369 517 942 708 545 200 848 896
	t13.multiply(t15);
	t13.print();
	//-77 343 152 080 126 873 570 688 483 304 283 542 095 729 779 543 390 270 242 493 118 064 108 955 564 144 781 852 952 037 268 871 309 230 886 002 078 517 029 480 119 830 360 830 961 461 567 986 628 659 153 089
	BigNUM t16(12, 51), t17(-12, 51);
	t17.multiply(t16);
	t17.print();
	// -119 257 883 311 700 952 372 108 129 977 861 063 714 321 684 906 960 798 706 845 068 430 868 708 383 537 456 117 438 920 794 747 554 791 522 566 144

	system("pause");
	return 0;
}/*#include<iostream>
#include"s1041523_BigNUM.h" //Before your test this driver program, please replace it by your own file name.

//ref: https://defuse.ca/big-number-calculator.htm
//you may modified this example to test your program in various condition and input numbers
//(updated at 0324)

using namespace std;

int main(int argc, char *argv[]) {
BigNUM n1(12, 52), n2(23, 34), n3(4, 45), n4(-14, 17), n5, n6, n7(12, 52), n8(-21, 55); //Note, the default complex number is 0+0i
cout << "Hello, I'm driver program: " << endl;
cout << "n1: ";
n1.print();
cout << "n2: ";
n2.print();
cout << "n3: ";
n3.print();
cout << "n4: ";
n4.print();
cout << "n5: ";
n5.print();
cout << "n6: ";
n6.print();
cout << "n7: ";
n7.print();
cout << "n8: ";
n8.print();

n1.minus(n7);
cout << "n1 - n7 : ";
n1.print();

n7.add(n2);
cout << "n7 + n2 : ";
n7.print();

n1.minus(n3);
cout << "n1 - n3 : ";
n1.print();

n4.minus(n8);
cout << "n4 - n8 : ";
n4.print();

n8.multiply(n4);
cout << "n8 * n4 : ";
n8.print();

n4.multiply(n2);
cout << "n4 * n2 : ";
n4.print();

n2.minus(n3);
cout << "n2 - n3 : ";
n2.print();

n4.minus(n2);
cout << "n4 - n2 : ";
n4.print();

n6.random();
cout << "random generate n6: ";
n6.print();
//random數字

system("pause");
return 0;
}*/


/*      official release HW2 below      */

/*
#include<iostream>
//#include"s1041523_BigNUM.h" //Before your test this driver program, please replace it by your own file name.

//ref: https://defuse.ca/big-number-calculator.htm
//you may modified this example to test your program in various condition and input numbers
//(updated at 0324)

using namespace std;

int main(int argc, char *argv[]) {
	BigNUM n1(12, 52), n2(30, 34), n3(4, 45), n4(-14, 17), n5; //Note, the default complex number is 0+0i
	cout << "Hello, I'm driver program: " << endl;
	n1.print(); //131 046 309 360 030 956 735 917 227 964 932 955 078 950 997 486 894 841 856
	n2.print(); //166 771 816 996 665 690 000 000 000 000 000 000 000 000 000 000 000
	n3.print(); //1 237 940 039 285 380 274 899 124 224
	n4.print(); //-30 491 346 729 331 195 904
	n5.print(); //0

	n1.add(n2);
	n1.print();
	//131 046 476 131 847 953 401 607 227 964 932 955 078 950 997 486 894 841 856

	n3.minus(n2);
	n3.print();
	//- 166 771 816 996 665 689 999 998 762 059 960 714 619 725 100 875 776

	n1.multiply(n2);
	n1.print();
	//21 854 858 935 518 465 180 686 186 178 538 568 205 420 280 703 402 589 363 822 244 011 851 120 640 000 000 000 000 000 000 000 000 000 000 000

	n3.multiply(n4);
	n3.print();
	//5 085 097 296 725 903 133 379 923 521 726 365 787 587 987 024 550 753 443 952 747 824 021 504
	n2.minus(n3);
	n2.print();
	//-5 085 097 296 725 903 133 213 151 704 729 700 097 587 987 024 550 753 443 952 747 824 021 504

	n4.minus(n2);
	n4.print();
	//5 085 097 296 725 903 133 213 151 704 729 700 097 587 987 024 550 722 952 606 018 492 825 600
	system("pause");
	return 0;
}
//n1 131046309360030956735917227964932955078950997486894841856
//n2 166771816996665690000000000000000000000000000000000
//n3 1237940039285380274899124224
//n4 -30491346729331195904
//n5 0

//n1 131046476131847953401607227964932955078950997486894841856
//n3 -166771816996665689999998762059960714619725100875776
//n1 21854858935518465180686186178538568205420280703402589363822244011851120640000000000000000000000000000000000
//n3 5085097296725903133379923521726365787587987024550753443952747824021504
//n2 -5085097296725903133213151704729700097587987024550753443952747824021504
//n4 5085097296725903133213151704729700097587987024550722952606018492825600*/