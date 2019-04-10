/* User define Hasfunction with unordered_map :

	template<class Key , class T, class HASH=hash<Key>, class Pred=equal_to<Key>, class Alloc=allocator<pair<Key,T>> > unordered_map;

	There two thing we need write for our own type key
	1. Write Hash function 
	2. Write == operator of the key .

	and you can define your own hash function of you overload has<key> from the std namespace .

	namespace std {
		
		template<> 
		struct hash<Key>  {
			
			size_t operator()(const key& k) {
				
					hash<member1 type>(k1.first1) + hash(member2 type ) (k2.type)
			}
	
		};

	}

    struct HashFunction {
	
	size_t operator () (const Key& k) {
		
		 hash<member1 type>(k1.first1) + hash(member2 type ) (k2.type)		

	}
    };

    in this case you need tell hasher function in unordered_map definition .


*/


#include<iostream>
#include<unordered_map>

using namespace std;

struct Employee {

 Employee(int Id, int ProjectId): Id(Id),ProjectId(ProjectId){}
 bool operator== (const Employee& emp1 )const{

		return (emp1.Id == Id && emp1.ProjectId == ProjectId);

	}

  friend ostream& operator<<(ostream &ot, Employee& emp);

  int Id; 
  int ProjectId; 

};

 ostream& operator<<(ostream &ot, const Employee& emp) {

   	ot<< emp.Id << "   " << emp.ProjectId <<endl;
  	return ot;
  }

struct EqualhasherFunction {

	bool operator()(const Employee& emp1,const Employee& emp2 )const{

		return (emp1.Id == emp2.Id && emp1.ProjectId == emp2.ProjectId);

	}
};


struct HaserFunctionEmployee {

	size_t operator() (const Employee& emp) const{
		return std::hash<int>()(emp.Id) + std::hash<int>()(emp.ProjectId);
	}
};

namespace std {


	template<>
	struct hash<Employee> {

		size_t operator()(const Employee & emp)const {

			return std::hash<int>()(emp.Id) + std::hash<int>()(emp.ProjectId);
		}
	};
}

int main() {

	unordered_map<Employee, int ,HaserFunctionEmployee> emp1 ;
	unordered_map<Employee, int ,HaserFunctionEmployee,EqualhasherFunction> emp2 ;
	unordered_map<Employee, int> emp3 ;
    emp1.emplace(Employee(1,123), 10000);
    emp1.emplace(Employee(2,125), 100033);
    emp1.emplace(Employee(3,127), 100066);

    emp2.emplace(Employee(1,129), 10000);
    emp2.emplace(Employee(2,131), 100033);
    emp2.emplace(Employee(3,135), 100066);


     emp3.emplace(Employee(1,135), 10000);
    emp3.emplace(Employee(2,134), 100033);
    emp3.emplace(Employee(3,138), 100066);

    for(auto e:emp1) {

    	cout << e.first << "  " <<e.second <<endl;
    }

     for(auto e:emp2) {

    	cout << e.first << "  " <<e.second <<endl;
    }
    for(auto e:emp3) {

    	cout << e.first << "  " <<e.second <<endl;
    }
}