
#include<iostream>
#include<unordered_map>
#include<vector>
#include <algorithm>
using namespace std;
unordered_map <string,vector<string>> FindAnaGram(vector<string> & dict) {

	unordered_map<string,vector<string>> UNSTR;

	for(auto &str: dict) {

			string temp =  str;
	    	std::sort(temp.begin(),temp.end()); 
	    	UNSTR[temp].emplace_back(str);
	}

   unordered_map<string,vector<string>> res;
	for(auto & it: UNSTR) {

		if(it.second.size() >= 2) {

			res[it.first].assign(it.second.begin(),it.second.end());
		}
	}
	return res;
}

int main() {

	vector<string> ana;
	ana.push_back("achintya");
	ana.push_back("ayhintca");
	ana.push_back("ayhintca1");
	
	
	ana.push_back("Moumita");
	ana.push_back("Moumati");
	ana.push_back("paul");
	
	auto ref = FindAnaGram(ana);

	for(auto &it: ref) {

		cout<<" anagram of  are : ";

		for(auto & it1: it.second){
			cout<< it1 << "   " ;
		}		
		cout<<endl;
	 }

}