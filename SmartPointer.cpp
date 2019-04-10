#include<iostream>
using namespace std;

class Reference {
	int count {};
public:
	void addRef() {
		count++;
	}
	int removeRef(){
		return --count;
	}
};


template<typename T>

class SmartPointer {

	T * pData;
	Reference *ref;

 public:
 	SmartPointer(): pData(0),ref(0){
 		ref = new Reference();
 		ref->addRef();
 	}
 	SmartPointer(T * p): pData(p),ref(0){
 		ref = new Reference();
 		ref->addRef();
 	}

    SmartPointer(const SmartPointer<T> & p){
    	pData = p.pData;
    	ref= p.ref;
 		ref->addRef();
 	}

 SmartPointer<T>& operator=(const SmartPointer<T> & p) {

 	if(&p == this ) return *this;

    if(ref->removeRef() == 0){

    	delete pData;
    	delete ref;
    }

 	pData = p.pData;
    ref= p.ref;
 	ref->addRef();

 	return *this;
 }
 
 T* operator->() {
 	return pData;
 }

 T& operator*() {

 	return *pData;
 }


 ~SmartPointer() {

 	if(ref->removeRef() ==0 ){

 		delete pData;
 		delete ref;
 	}
 	cout<< "Destructor called "<< this <<endl;
 }
};

class Person
{
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }

        void Display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void Shout()
        {
            printf("Ooooooooooooooooo");
      }
};

int main()
{
    SmartPointer<Person> p(new Person("Scott", 25));
    p->Display();
    {
        SmartPointer<Person> q = p;
        q->Display();
        // Destructor of q will be called here..

        SmartPointer<Person> r;
        r = p;
        r->Display();
        // Destructor of r will be called here..
    }
    p->Display();
    // Destructor of p will be called here 
    // and person pointer will be deleted
}