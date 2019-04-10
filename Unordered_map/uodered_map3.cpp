/*
template<class Key, class T, class HASH=hash<Key>, class Pred=equal_to<Key>, class Allocation = allocation<pair<Key,T>> > unordered_map;

container iterator (1)	
      iterator begin() noexcept;
	  const_iterator begin() const noexcept;

bucket iterator (2)	

      local_iterator begin ( size_type n );
	  const_local_iterator begin ( size_type n ) const;


*/

#include<iostream>
#include<unordered_map>

using namespace std;


using StringMap = unordered_map<string,string> ;


int main() {

	StringMap sump {{ "Achintya" , "Paul"} , {"Mounita", "kundu"} , {"Jharkhand","KalaPathar"}, {"Banglore","Marathahali"}};

	for(auto it = sump.begin() ; it != sump.end(); it++) {

		cout<<" "  << it->first << "  " << it->second <<endl;
	}
    for(auto i = 0; i < sump.bucket_count() ; i++) {

    	cout<< "bucket number :" << i << endl;
    	for(auto local_it = sump.begin(i) ; local_it != sump.end(i); local_it++) {

    		cout<<local_it->first << "    " <<local_it->second <<endl;
    	}
    }

}