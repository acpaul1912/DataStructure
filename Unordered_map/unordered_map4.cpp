#include<iostream>
#include<unordered_map>
using namespace std; 

class Employee {
	

 public:
 	size_t operator() (const Employee & e)const {

 		return hash<int>()(e.empid) + hash<string>()(e.name);
 	}

	int empid;
	string name;
 
 	bool operator==(const Employee& e) const {

 		return empid== e.empid && name == e.name;
 	}
};

/*
struct EmpLoyeeHasFunc{

		size_t operator() (const Employee & e)const {

 		return hash<int>()(e.empid) + hash<string>()(e.name);
 	}

};
*/
using UnorderEmployee = unordered_map<Employee,Employee,Employee>;

int main() {
	
		UnorderEmployee  e;
		Employee e2{12,"Achintya"};
		Employee e1{13,"Paul"};

        cout<< e2.empid << e2.name <<endl;

		e.insert({{12,"Achintya"},{12,"Achintya"}});
		e.insert({{13,"Paul"},{13,"Paul"}});
		
		for(auto &e1 : e){
			//cout<<e1.first << "  " <<e1.second <<endl;
		}
}