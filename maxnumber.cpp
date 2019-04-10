#include<iostream>
#include<deque>
#include<vector>



using namespace std ;

int findMaxNumber(int number, int k) {
	
	deque<int> vec; 
	int ntemp = number;
	while(number) {

		vec.push_front(number%10);
		number = number /10 ;
	}

    if(k > vec.size()) {
    	return ntemp;
    }

	vector<int> li;
    
	int index = 0;
	int max = vec[0];
	
	for(int j = k-1 ; j >=0 ; j--) {
	for(int i = index ; i < vec.size()-j ; i++) {

		if(max < vec[i]) {
			max = vec[i];
			index = i;			
		}
	}
  	li.push_back(max);
  	max = vec[++index];
  }
	
	long int temp = 0;
 	 for(auto i : li) { 	 	
 	 	temp = temp * 10 + i;
 	 }

 	 return temp;
}

int main() {
	
	int i;
    
    int k;
 
    cout<<"enter the number " <<" kth string  " << endl;

    cin>> i >> k;

	cout<< findMaxNumber(i,k);
}