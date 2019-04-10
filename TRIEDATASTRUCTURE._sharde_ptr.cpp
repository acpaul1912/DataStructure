#include<iostream>
#include<unordered_map> 
#include<memory>
#include<vector>
using namespace std; 


struct Trie {

	bool isLeafNode = false ;
	unordered_map<char,shared_ptr<Trie>> map;

};

shared_ptr<Trie> getTrieNode() {

	shared_ptr<Trie> node (new Trie());
	return node ;
}

void insert(shared_ptr<Trie> & root, string str) {

	 if(root == nullptr) {

	 	root= getTrieNode();
	 }

	 shared_ptr<Trie> head = root ;
     int i =0;
	 while(i < str.length()) {

	 	if(head->map.find(str[i]) == head->map.end()) {
	 		shared_ptr<Trie> node (new Trie());
     		head->map[str[i]] = node;
	 	}

	 	head = head->map[str[i]];
	 	i++;
	 }
	 head->isLeafNode = true;
}

bool haveChildren(const shared_ptr<Trie> root) {

	for(auto i: root->map){

		if(i.second != nullptr) {
			return true ;
		}
	}
	return false;
}


bool search(const shared_ptr<Trie>  root, string str) {

	if(root == nullptr) {

		return false ;
	}

	shared_ptr<Trie>  head = root;
    
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


bool deletion(shared_ptr<Trie> &root, string str, int start = 0) {

	if(root == nullptr) return false;

	if(start < str.length()) {

		if(root != nullptr && root->map.find(str[start]) != root->map.end() &&
			deletion(root->map[str[start]] ,str,start+1) && root->isLeafNode == false) {

			if(!haveChildren(root)) {
				root.reset();
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

			 root.reset();
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
void recusrivePrint(shared_ptr<Trie> root, string fstr, vector<string> &vstr, string& nnn) {
	
	if(root == nullptr) {

		return ;
	} 
	else {
		if(root->isLeafNode) {
			string ft= nnn+fstr;
		vstr.push_back(ft);		
	}
       
	    for(auto i: root->map){	    
	        fstr.push_back(i.first);
			recusrivePrint(i.second,fstr,vstr,nnn);
		}

	}
}

vector<string> display(shared_ptr<Trie> &root, string str) {

	string fianlStr;  
	vector<string> vstr; 
	int i  = 0;
	shared_ptr<Trie> head = root;
	while(i < str.length()) {

		if(head->map.find(str[i]) != head->map.end()) {

			head = head->map[str[i]];
			fianlStr.push_back(str[i]);
			i++;
		}else {

				insert(root,str);
				vstr.push_back(str);
			return vstr;
		}
	}

	if(head !=nullptr &&  haveChildren(head)) {

		fianlStr = str;
		for(auto i: root->map) {
			string fstr;
			fstr.push_back(i.first);
			recusrivePrint(i.second,fstr,vstr,fianlStr);
		}

	}

	else {

		vstr.push_back(str);
	}


	return	vstr;
}



int main()
{
	shared_ptr<Trie> head = nullptr;

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

	cout << search(head, "hell")<<endl;   			// print 0

    //vector<string> vstr = display(head,"hell");

    //cout<<vstr[0] <<  "  " << vstr[1] << "  " <<vstr[2] << endl;;
	return 0;
}