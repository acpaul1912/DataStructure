/*
unordered_map : 
	
	template<class Key, class T, class HASH= hash<Key>, class Pred= equal_to<Key> , class Alloc=allocator< pair<Key,T> > >unordered_map;

	1.	Unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows
	 for fast retrieval of individual elements based on their keys.

	2. In an unordered_map, the key value is generally used to uniquely identify the element, while the mapped value is an object with the content associated 
	to this key. Types of key and mapped value may differ.
    
    3. unordered_map containers are faster than map containers to access individual elements by their key, 
    although they are generally less efficient for range iteration through a subset of their elements.

    4. Iterators in the container are at least forward iterators.

    template < class Key,                                // unordered_map::key_type
           class T,                                      // unordered_map::mapped_type
           class Hash = hash<Key>,                       // unordered_map::hasher
           class Pred = equal_to<Key>,                   // unordered_map::key_equal
           class Alloc = allocator< pair<const Key,T> >  // unordered_map::allocator_type
           > class unordered_map;


Container properties:
	Associative
	    Elements in associative containers are referenced by their key and not by their absolute position in the container.
	Unordered
	    Unordered containers organize their elements using hash tables that allow for fast access to elements by their key.
	Map
	    Each element associates a key to a mapped value: Keys are meant to identify the elements whose main content is the mapped value.
	Unique keys
	    No two elements in the container can have equivalent keys.
	Allocator-aware
	    The container uses an allocator object to dynamically handle its storage needs.


Iterators to elements of unordered_map containers access to both the key and the mapped value. 
For this, the class defines what is called its value_type, which is a pair class with its first value corresponding
to the const version of the key type (template parameter Key) and its second value corresponding to the mapped value (template parameter T):  typedef pair<const Key, T> value_type;

Iterators of a unordered_map container point to elements of this value_type. Thus, for an iterator called it that points to an element of a map, its key and mapped value can be accessed respectively with:
	unordered_map<Key,T>::iterator it;
	(*it).first;             // the key value (of type Key)
	(*it).second;            // the mapped value (of type T)
	(*it);                   // the "element value" (of type pair<const Key,T>) 


	
	
*/

#include<iostream> 
#include<unordered_map>

using namespace std; 

using StringUnMap= unordered_map<string,string>;

StringUnMap Merge_map(StringUnMap fi, StringUnMap se) {

	StringUnMap t(fi);
    t.insert(se.begin(), se.end());
    return t;
}


void Print_Umap(StringUnMap & ump) {

	for(auto i: ump) {

		cout<<i.first << "   " << i.second << " " << endl;
	}
}

int main() 
{
	//unordered_map < , > : Constructor 

	StringUnMap first;
	StringUnMap second = {{"Achintya","paul"},{"Moumita","kundu"}};

	StringUnMap third = second;

	StringUnMap fourth = Merge_map(third,second);

	StringUnMap fifth (third.begin(),third.end());

	Print_Umap(fourth);
}