#include<iostream>
#include<unordered_map> 
#include<memory>

using namespace std; 


struct Trie {

	bool isLeafNode = false ;
	unordered_map<char,Trie*> map;

};

Trie* getTrieNode() {

	Trie* node = new Trie();
	return node ;
}

void insert(Trie *& root, string str) {

	 if(root == nullptr) {

	 	root= getTrieNode();
	 }

	 Trie * head = root ;
     int i =0;
	 while(i < str.length()) {

	 	if(head->map.find(str[i]) == head->map.end()) {

     		head->map[str[i]] = new Trie();
	 	}

	 	head = head->map[str[i]];
	 	i++;
	 }
	 head->isLeafNode = true;
}

bool haveChildren(Trie *const root) {

	for(auto i: root->map){

		if(i.second != nullptr) {
			return true ;
		}
	}
	return false;
}


bool search(Trie * const root, string str) {

	if(root == nullptr) {

		return false ;
	}

	Trie * head = root;
    
    int i = 0;
	while(i < str.length()) {

		head = head->map[str[i]]; 

		if(head == nullptr) {
			return false ;
		}
		i++;
	}

   return head->isLeafNode;
}


bool deletion(Trie * &root, string str, int start = 0) {

	if(root == nullptr) return false;

	if(start < str.length()) {

		if(root != nullptr && root->map.find(str[start]) != root->map.end() &&
			deletion(root->map[str[start]] ,str,start+1) && root->isLeafNode == false) {

			if(!haveChildren(root)) {
				delete root;
				root= nullptr;
				return true;
			}
			else {

				return false ;
			}
		}
	}
	if(start == str.length() && root->isLeafNode) {

		if(!haveChildren(root)) {

			delete root;
				root= nullptr;
				return true;
		}
		else {

			root->isLeafNode = false ;
			return false ;
		}
	}

	return false ;
}


/*
void insert(Trie * &root, string str) {

	if(root == nullptr) {
		root = getTrieNode();
	}

	Trie * head = root ;
    int i = 0;
	while(i < str.length()) {

		if(head->map.find(str[i]) == head->map.end()) {
			head->map[str[i]] = getTrieNode();
		}
		head = head->map[str[i]];
		i++;
	}

	head->isLeafNode = true;
}

bool haveChildren(Trie * const node) {

	for(auto it : node->map) {
		if(it.second != nullptr){
			return true;
		}
	}
	return false ;
}

bool search(Trie * root, string str) {

	if(root == nullptr) {
		return false ;
	}

	Trie * head = root;
    int i = 0;
	while(i < str.length()) {
		head = head->map[str[i]];

		if(head == nullptr) {
			return false ;
		}
		i++;
	}

	return head->isLeafNode;
}

bool deletion(Trie * &root, char* str) {

	if(root == nullptr) {
		return false ;
	}
        
	if(*str) {

		if(root != nullptr && root->map.find(*str) != root->map.end() 
			&& deletion(root->map[*str], str+1) && root->isLeafNode == false){

			if(!haveChildren(root)) {
				delete root;
				root= nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}
   
    if(*str =='\0' && root->isLeafNode){

    	if(!haveChildren(root)) {
				delete root;
				root= nullptr;
				return true;
			}
			else {

				root->isLeafNode = false ;
				return false;
			}
    }

    return false ;
}


*/
int main()
{
	Trie* head = nullptr;

	insert(head, "hello");
	cout << search(head, "hello") << " ";   	// print 1

	insert(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 1

	cout << search(head, "helll") << " ";   	// print 0 (Not present)

	insert(head, "hell");
	cout << search(head, "hell") << " ";		// print 1

	insert(head, "h");
	cout << search(head, "h") << endl;  		// print 1 + newline

	deletion(head, "hello");
	cout << search(head, "hello") << " ";   	// print 0 (hello deleted)
	cout << search(head, "helloworld") << " ";  // print 1
	cout << search(head, "hell") << endl;   	// print 1 + newline

	deletion(head, "h");
	cout << search(head, "h") << " ";   		// print 0 (h deleted)
	cout << search(head, "hell") << " ";		// print 1
	cout << search(head, "helloworld") << endl; // print 1 + newline

	deletion(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 0
	cout << search(head, "hell") << " ";		// print 1

	deletion(head, "hell");
	cout << search(head, "hell") << endl;   	// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";   			// Trie is empty now

	cout << search(head, "hell");   			// print 0

	return 0;
}