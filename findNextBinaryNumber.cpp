#include<iostream>
using namespace std;


int findNextBinaryNumber(int n) {
	
	int rightBit = n & -n;

	int rightmostbit = n + rightBit;

	int onces = n ^ rightmostbit;

	onces = onces /rightBit ;
	onces >>= 2;

	return onces | rightmostbit;
}

int main() {
	
	int i ;
	cin >> i;
	cout<< findNextBinaryNumber(i) <<endl;
}