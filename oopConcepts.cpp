#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
// Abstract Base Class (ABC) - defines an interface for Person objects

class Person {
public:
    virtual void InputData() = 0;
    virtual void OutputData() = 0;
    virtual void CalculateNumbers()=0;
    virtual void CheckName()=0;
        virtual void Think() = 0;
    virtual ~Person(){} // Virtual destructor for proper cleanup
};
// Inheritance - Student is a subclass of Person

class Student:public Person{
    int age;
    string name;
    char gender;
    string major;
    double gpa;
public:
    Student() : age(15), name("nun"), gender('M'), major("dd"), gpa(0.0) {}
    Student(int a, string n, char g,string m, double gp) : age(a), name(n), gender(g), major(m),gpa(gp) {}
    void InputData() {
        cout << "enter age: "; cin >> age;
        cout << "enter name: "; cin >> name;
        cout << "enter gender: "; cin >> gender;
        cout << "enter major: ";cin>>major;    }
        void CalculateNumbers() {
        double a,b,c;
        cout<<"Enter 1st numbers: ";
        cin >> a;
    if (a > 50) {
        cout << "Number must be 50 or less. Please enter again: ";
        cin >> a;
    }
        cout<<"Enter 2nd numbers: ";

    cin >> b;
    if (b > 50) {
        cout << "Number must be 50 or less. Please enter again: ";
        cin >> b;
    }
        cout<<"Enter 3rd numbers: ";

    cin >> c;
    if (c > 50) {
        cout << "Number must be 50 or less. Please enter again: ";
        cin >> c;
    }
        gpa=(a+b+c)/50;
        cout<<gpa<<endl;
    }
    void OutputData() {
        cout << "age is: " << age << endl;
        cout << "name is: " << name << endl;
        cout << "gender is: " << gender << endl;
        cout<<"major is: "<<major<<endl;
        cout<<"gpa is: "<<gpa<<endl;
        
    }
    
    void CheckName() {
        if (name.length() > 10) {
            cout << "bro has a fuck fake ass name." << endl;
            }
            else
            cout << "name checks out let him in." << endl;
            }
            ~Student() {}
            void Think() {
        cout << "I'm thinking about my homework..." << endl;
    }
};
// Inheritance - Someone is a subclass of Person

class Someone : public Person {
    int a, b, c;
    string name;
public:
    Someone() : a(4), b(6), c(4), name("nun") {}
    Someone(int a2, int b2, int c2, string nm) : a(a2), b(b2), c(c2), name(nm) {}
    void InputData() {
        cout << "Enter the value of a, b, c: " << endl;
        cin >> a;
        cin >> b;
        cin >> c;
        cout<<"Enter name: ";
        cin >> name;
    }
    void OutputData() {
        cout << "value of a is: " << a << endl;
        cout << "value of b is: " << b << endl;
        cout << "value of c is: " << c << endl;
        cout << "name is: " << name << endl;
    }
    void CalculateNumbers(){
        cout << "a + b + c = " << a + b + c << endl;
    }
    void CheckName(){
        int length;
        length=name.size();

        if (length<34&& length>2){
        cout << "name checks out he's legit!" << endl;
        }
        else {
            cout<<"he's a fake ass shit";
        }
    }
    void Think() {
        cout << "I'm thinking about my failure..." << endl;
    }
};
// Inheritance - Someone2 is a subclass of Person

class Someone2 : public Person {
    int age;
    string name;
    char gender;
public:
    Someone2() : age(15), name("nun"), gender('M') {}
    Someone2(int a, string n, char g) : age(a), name(n), gender(g) {}
    void InputData() {
        cout << "enter age: "; cin >> age;
        cout << "enter name: "; cin >> name;
        cout << "enter gender: "; cin >> gender;
    }
    void OutputData() {
        cout << "age is: " << age << endl;
        cout << "name is: " << name << endl;
        cout << "gender is: " << gender << endl;
    }
    
    void CalculateNumbers(){}
    void CheckName(){
        int length;
        length=name.size();

        if (length<34&& length>2) {
        cout << "name checks out he's legit!" << endl;
        }
        else {
            cout<<"he's a fake ass shit.";
        }
    }
    void Think() {
        cout << "I'm thinking about my future wife." << endl;
    }
};

int main() {
    vector<Person*> persons;
system("clear");
    int n;
    cout << "Enter the number of Someone objects: ";
    cin >> n;
    for(int i=0;i<n;i++){
        persons.push_back(new Someone());
        persons[i]->InputData();
    }
cout<<"Enter number of Student objects: ";
    cin>>n;
    for(int i=0;i<n;i++){
        persons.push_back(new Student());
        persons[persons.size()-1]->InputData();
    }
    cout<<"Enter number of Someone2 objects: ";
    cin>>n;
    for(int i=0;i<n;i++){
        persons.push_back(new Someone2());
        persons[persons.size()-1]->InputData();
    }
  cout<<"Outputting data: "<<endl;
  for(Person* p: persons){
    
    p->CalculateNumbers();
    p->CheckName();
    p->OutputData();

    cout<<endl;
  }

   for(Person* p: persons){
    delete p;
   }

    return 0;
}
