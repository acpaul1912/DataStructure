#include<iostream>

using namespace std;

int main() {
	
	string s = "Achintya kumar   paul";
	string final = "";
    int i =0 , j = 0;
	for(i = s.size(), j = i+1 ; i >= 0; i--) {
       
		if(s[i] == ' ') {        	
           int k = i + 1 ;
           while(k < j) {
		       final.push_back(s[k]);
		       k++;
		   }	
		   final.push_back(' ');
		   j =  i;		   
		}
	}
    i = 0;
	
		while(i < j){
		       final.push_back(s[i]);
		       i++;
		   }
  
	
    
	cout<< final;
}