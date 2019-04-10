/*Write a program for find element in sorted roted array */

#include<iostream>
#include<vector> 
using namespace std;
int binary_serach(int arr[], int low, int high, int key) {

	if(low > high ) return -1;

	int mid = low + (high - low ) / 2; 
	if(key == arr[mid]) {

		return mid ;
	}
	else if (key > arr[mid]) {

		return binary_serach(arr,mid+1, high, key);
	}
	else {
		return binary_serach(arr,low,mid-1,key);
	}

}

// Find the max element index . 
int findThePivot(int a[], int low, int high) {

	if(high < low) return -1; 

	if(high == low ) return low;

	int mid = low + (high - low ) / 2; 

	if(low < mid && a[mid-1] > a[mid])
		return mid-1 ;
	if(mid < high && a[mid] > a[mid+1])
		return mid;

	if(a[low] >= a[mid])
	return findThePivot(a,low,mid-1);

    return findThePivot(a,mid+1,high);
}


int PivotBinarySearch(int a[], int low, int high,int key) {

     int p = findThePivot(a,low,high);
     cout<< "Pivot: " << p <<endl;
     if(p == -1) {

     	// no pivot element 

     	return	binary_serach(a,low,high, key);
     }

     if(a[p] == key ) return p;

     if(a[0] <= key) {
     	return binary_serach(a,0,p-1,key);
     }

     return binary_serach(a,p+1,high,key);

}


int main() {

	int vec[] = { 7,8,9,1,2,3,4,5,6};

	cout<< PivotBinarySearch(vec, 0,sizeof(vec)/sizeof(vec[0]) -1, 8);
}