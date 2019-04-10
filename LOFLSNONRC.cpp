#include<iostream>
#include<unordered_map>

using namespace std ;


int findLengthOfSubstring(string& str) {
	
	if(str.size() == 0) return 0 ;

	int max_length = 0;
	int currentlength = 0; 
	unordered_map<char,int> map; 

	for(int i= 0; i < str.length() ; i++) {

	if(map.find(str[i]) == map.end()) {
		map[str[i]] = i;
		currentlength++; 
	}
	else {				
		auto in = map[str[i]]; 
        if(max_length < currentlength){
			max_length = currentlength;
	    }
	    currentlength = i - in;
        map[str[i]] = i; 
	}

	if(max_length < currentlength){
			max_length = currentlength;
	}

	}

	return max_length;

}

int main() {
	
	string str ="abcdabd"; //

	cout<< findLengthOfSubstring(str);
	return 0;
}