#include<iostream>
using namespace std;

int minimunDistanceBetweenTwoNumber(int a[], int n , int x , int y) {

   int min1 = INT_MAX;
   int match = 0;
   int i = 0;
   int end = n-1;
   while(i < n ) {

   		if(a[i] == x || a[i] == y) {

   			match = i;    			
   			i++;         
   			break;
   		}
   		i++;
   	}
  while(i < n ) {

        if(a[i] == x || a[i] == y) {

        	if(a[match] == a[i])
               match = i;
            else {
        	end = i;

        	min1 = std::min(min1, (end-match));
        }
	}
     i++; 
   }

return min1  == INT_MAX ? -1: min1;
}

int main() {

	int a[] = { 1,2,3,4,5,6,7,1,7,1,2,3,4,5,5,5,5};

	cout<<minimunDistanceBetweenTwoNumber(a,sizeof(a)/sizeof(a[0]), 5,5);
}