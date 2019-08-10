#include <iostream>
#include <string>
using namespace std;

class Person
{
  friend class ResponsiblePerson;
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age=age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
    ResponsiblePerson(const Person &person) : person(person) {}
    // get age
    int get_age() const {
        return person.get_age();
    }
    // set age
    void set_age(int age) {
        person.set_age(age);
    }
    // drink
    string drink() const {
        if (person.get_age() < 18)
            return "too young";
        else
            return person.drink();
    }
    // drive
    string drive() const {
        if (person.get_age() < 16)
            return "too young";
        else
            return person.drive();
    }
    // drink and drive
    string drink_and_drive() const {
        return "dead";
    }
    
private:
    Person person;
};
