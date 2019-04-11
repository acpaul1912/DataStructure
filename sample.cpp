// Question on Dutch national flag sorting problem.
//Sort an array of 0s, 1s and 2s
#include<iostream>
#include<vector>
using namespace std;
int main() 
{ 
   
    vector<int> ve = {0,0,0,1,1,1,2,2,2,1,0};
    int low = 0;
    int pivot = 1;
    int mid = low;
    int high = ve.size()-1;

    while(mid < high) {

    	if(ve[mid] < pivot) {

    		swap(ve[low], ve[mid]);
    		low ++ ;
    		mid++;
    	}
    	else if(ve[mid] > pivot) {
    		swap(ve[mid],ve[high]);
    		--high;
    	}
        else {
        	++mid;
        }
   }

   for(int &vec: ve){
   	   cout<<vec;
   }
    return 0; 
} 
