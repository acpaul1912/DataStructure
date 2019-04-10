/* Analysisng the Bucket related things in unordered_map  */ 

#include<iostream>
#include<unordered_map>
using namespace std; 


int main() {

	unordered_map<int ,string> UnInStr; 

	UnInStr[1] = "Achintya";
	UnInStr[2] = "Paul";
	UnInStr[3] = "Kumar";

	UnInStr[4] = "Moumita";
	UnInStr[5] = "kundu";


	cout<<" Number of bucket Count :" << UnInStr.bucket_count() <<endl;

	for(int i = 0; i < UnInStr.bucket_count(); i++) {
        
        cout<<"Total number of element in " << i <<" Bucket: " << UnInStr.bucket_size(i) <<endl;
		cout<<" Element in Bucket#" << i << "  : ";
		for(auto it = UnInStr.begin(i) ; it != UnInStr.end(i) ; it++){
				cout<< it->first << "   " << it->second ;
		}
		cout<<endl;
	}
    //bucket input is key
	cout<< " bucket Numbet "  << UnInStr.bucket(1) <<endl;

}