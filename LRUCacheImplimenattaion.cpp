#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
using UNMAP = unordered_map<int,list<int>::const_iterator>;


class LRUCACHE {
public:
   LRUCACHE(int num) : MaxSize(num){

   }

   int getsize() {

   	   return li.size();
   }


   void Insert(int elem) {

   	auto it = map.find(elem);

   	 if(it != map.end()) {
   	 	li.erase(it->second);  
   	 	map[elem] = li.insert(li.begin(),elem); 	 	
   	 }
   	 else if(getsize() < MaxSize) {
   	 	map[elem] = li.insert(li.begin(),elem);
   	 }
   	 else {

   	 	li.pop_back();
   	 	map[elem] = li.insert(li.begin(),elem);
   	 }

   }

   bool erase(int elem) {

   	 auto it = map.find(elem);

   	 if(it != map.end()) {
   	 	li.erase(it->second);  
   	 	map.erase(it); 	
   	 	return true; 	
   	 }

   	 return false ;
   }


   void display() {

	   	for(auto i: li) {

	   		cout<< i << "  " ; 
	   	}
   		cout<< endl;
   }

	private :

	UNMAP map;
	list<int> li;
	const int MaxSize ;
   	

};


int main() {

	cout<< "Enter the number of element " << endl;
	LRUCACHE lc(10);

	lc.Insert(1);
	lc.Insert(2);
	lc.Insert(3);
	lc.Insert(4);
	lc.Insert(5);
	lc.Insert(6);
	lc.Insert(7);
	lc.Insert(8);
	lc.Insert(9);
	lc.Insert(10);

	lc.display();

	lc.Insert(1);

	lc.display();
	lc.Insert(10);
	lc.Insert(10);

	lc.display();
	lc.Insert(2);

	lc.display();
	lc.Insert(22);
	lc.Insert(26);
	lc.display();
	lc.erase(26);
	lc.display();
	lc.Insert(25);
    lc.display();

}
