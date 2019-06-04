#include <iostream>
#include <ostream>  // for os
#include <string>
#include <utility>  // for pair & make_pair
#include <vector>
using namespace std;

class CodeBuilder {
private:
    string className;
    vector<pair<string, string>> field;
    
public:
    CodeBuilder(const string& class_name) {
        className = class_name;
    }
    
    CodeBuilder& add_field(const string& name, const string& type) {
        field.emplace_back(make_pair(type, name));
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const CodeBuilder& obj) {
        os << "class " << obj.className << "\n{" << endl;
        for (const auto& f : obj.field) {
            os << "  " << f.first << " " << f.second << ";\n";
        }
        os << "};\n";
        return os;
    }
};

int main() {
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
    
    return 0;
}
