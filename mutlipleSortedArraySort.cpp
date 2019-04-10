// Sort a arrays of N sorted array
#include<iostream>
#include<queue>
#include<vector>

using namespace std; 

struct ItreatorInput {

	bool operator > (const ItreatorInput & p) const {
		return *current > *p.current;
	}

	vector<int>::const_iterator current;
	vector<int>::const_iterator END;
};

vector<int> MergeSort(vector<vector<int>> & sortArrays) {

	priority_queue<ItreatorInput ,vector<ItreatorInput> , greater<> > min_heap;
    vector<int> res;
	for(auto &array : sortArrays) {
		min_heap.emplace(ItreatorInput{array.begin(), array.end()});

	 }

	 while(!min_heap.empty()) {

	 	auto small = min_heap.top();

	 	min_heap.pop();

	 	if(small.current != small.END) {
	 		res.emplace_back(*small.current);

	 		min_heap.emplace(ItreatorInput{next(small.current), small.END});
	 	}
	 }
	
return res;
}


int main() {
	
	vector<vector<int>> vec = {{1,2,3},{0,2,4,5},{24,29,30}};

    auto rr = MergeSort(vec);

    for(int i : rr) {
    	cout<< i << " ";
    }

}


/*
struct IteratorInput {
	
	bool operator > (IteratorInput &that) const {
		return *current > *that.current ;
	}

	vector<int>::const_iterator current;
	vector<int>::const_iterator End; 
};


vector<int> mergeSort(vector<vector<int>> &sortArrays ){
	
	priority_queue<IteratorInput, vector<IteratorInput> , greater<>> min_heap;

	for(auto & sortarray: sortArrays) {

		min_heap.emplace(IteratorInput{sortarray.begin(),sortarray.end()});

    }

    vector<int> results;

    while(!min_heap.empty()) {

    	auto smallestArray = min_heap.top();

    	min_heap.pop();

    	if(smallestArray.current != smallestArray.End) {
           
            //pushing the current element
    		results.emplace_back(*smallestArray.current);
    		min_heap.emplace(IteratorInput{next(smallestArray.current),smallestArray.End});

    	}
    }

    return results;
}*/
