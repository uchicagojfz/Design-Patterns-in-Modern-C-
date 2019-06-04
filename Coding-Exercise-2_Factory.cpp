#include <iostream>
#include <string>
using namespace std;

struct Person {
    int id;
    string name;
};

class PersonFactory {
private:
    int id = 0;
public:
    Person create_person(const string& name) {
        Person p;
        p.id = id;
        p.name = name;
        id++;
        return p;
    }
};

int main() {
    PersonFactory pf;
    Person p = pf.create_person("John Doe");
    cout << "(" << p.id << ", " << p.name << ")\n";
    
    return 0;
}
