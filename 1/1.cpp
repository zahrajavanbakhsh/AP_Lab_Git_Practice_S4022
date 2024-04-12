
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	Person():name("") , age(0){}
	Person(int _age):name("") , age(_age){}
	Person(string& _name):name(_name) , age(0){}
	Person(const string& name) {
		this->name = name;

	}
	Person(const string& _name , int _age): name(_name) , age(_age){}
	Person(Person& _person){
		name=_person.name;
		age=_person.age;
	}
	~Person(){}
	string& getName()  { return name; }
	string getName()const{
		return name;
	}
	friend void deletePerson(string name){}
	friend ostream& operator<<(ostream& out, const Person& p){}
	friend class Group;
private:
	string name;
	int age;

};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}

ostream& operator<<(ostream& out , const Group& g){
	cout<<g;
	return out; 
}


class Group {
public:

	Group(){}
	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void add(Person p , int s){
		if(s== this->cap){
			return;
		}
		else{
			this->members[s] = p;
			this->size++;
		}
	}
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if(members[i].name == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}

	~Group() {
		delete[] members;
	}

	Group operator+(Group& g){
		Group nahaee(cap + g.cap); 
        for(int i = 0; i < size; ++i) {
            nahaee.members[i] = members[i];
            nahaee.size++;
        }
        for(int i = 0; i < g.size; ++i) {
            nahaee.members[nahaee.size++] = g.members[i];
        }
        return nahaee;
		
	}
	Group& operator+=(const Group& g) {
        for(int i = 0; i < g.size; ++i) {
            if(size == cap) {
                break; 
            }
            members[size++] = g.members[i];
        }
        return *this;
    }

	friend bool isGroupFull(Group g){}
	friend ostream& operator<<(ostream& out , const Group& g){}

private:
	int size;
	int cap;
	Person* members;

};

bool isGroupFull(Group g) {
	return (g.size == g.cap);
}

int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
	
	
	Group g1(5);
	g1.add({ "Erfan",20 });
	g1.add({ "Saba",20 });
	g1.add({ "Mahrokh",20 });
	g1.add({ "Yasin",21 });
	cout<<isGroupFull(g1)<<endl;
	
	
	Group g2(g1);
	Group g3(10);
	g2.deletePerson("Erfan");
	cout << g1<<endl;//should cout every person in it with a \t as the separator
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	
	Person persons[10];
	Person Erfan("Erfan",20);
	persons[1]=Erfan;
	for(int i=0;i<10;i++){
		persons[i].getName()=to_string(rand()%100);
	}
	sort(persons,persons+10);//what operator should be overloaded for sort? :)

	for(int i=0;i<10;i++){
		cout<<persons[i].getName()<<' ';
	}
	
	cout<<*find(persons,persons+10,Erfan);
	
	








}

