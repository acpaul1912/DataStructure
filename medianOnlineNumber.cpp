//Running Median or Median of online number .
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void  RunningMedian(vector<int>& vec) {
	
	int med = vec[0];

	cout<< med << "---> Medain is " << med <<endl;

	priority_queue<int> first;
	priority_queue<int,vector<int>, greater<int>> second;

	first.emplace(med);


	for(int i = 1; i < vec.size() ; i++) {

		int x= vec[i];

		if(first.size() > second.size() ) {

			if(x > med ) {

				second.emplace(x);
			}
			else {
				second.emplace(first.top());
				first.pop();
				first.emplace(x);
			}

			med = (first.top() + second.top() ) /2 ; 
		}

	   else if(second.size() > first.size()) {


			if(x < med ) {

				first.emplace(x);
			}
			else {
				first.emplace(second.top());
				second.pop();
				second.emplace(x);
			}
			med = (first.top() + second.top() ) /2 ; 

	   }
	   else {

	   		if(x > med){

	   			second.emplace(x);
	   			med = second.top();

	   		}
	   		else {
	   			first.emplace(x);
	   			med = first.top();
	   		}

	   }

	   for (int j = 0; j <= i; j++) cout<< vec[j] << " " ;
	   	cout << " -----> median element : " <<med <<endl; 
	   
	}

	return  ;
	
}

int main() {
	
	vector<int> vec {5, 15, 10, 20, 3};

	RunningMedian(vec);

}