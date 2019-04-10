// Minimum distance between same word in the String.
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 


int findtheNearestNumber(vector<string> & vec) {
	
	unordered_map<string,int> unName;

	int min_distance_ = INT_MAX;

	for(int i = 0; i < vec.size(); i++) {
		auto it= unName.find(vec[i]);
		if( it != unName.end()) {

			int num = i- it->second ;

			min_distance_ = min(min_distance_, num);
		}
		unName[vec[i]] = i;

	}
	
return min_distance_ -1;
}

int main()
{
	vector<string> vec {"achintya","kumar","paul","achintya","moumita","kuhndu","moumita"};

	cout<<findtheNearestNumber(vec);

}