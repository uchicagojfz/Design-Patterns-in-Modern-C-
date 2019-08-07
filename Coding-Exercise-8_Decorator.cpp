#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Flower {
  virtual string str() = 0;
};

struct Rose : Flower {
  string str() override {
    ostringstream oss;
    oss << "A rose";
    return oss.str();
  }
};

struct RedFlower : Flower {
    Flower& flower;
    // Assignment constructor
    RedFlower(Flower& _flower) : flower(_flower) {}
    // Operator overloading
    string str() override {
        ostringstream oss;
        oss << flower.str();
        if (flower.str() == "A rose") {
            oss << " that is red";
        }
        else if (flower.str() == "A rose that is blue") {
            oss << " and red";
        }
        return oss.str();
    }
};

struct BlueFlower : Flower {
    Flower& flower;
    // Assignment constructor
    BlueFlower(Flower& _flower) : flower(_flower) {}
    // Operator overloading
    string str() override {
        ostringstream oss;
        oss << flower.str();
        if (flower.str() == "A rose") {
            oss << " that is blue";
        }
        else if (flower.str() == "A rose that is red") {
            oss << " and blue";
        }
        return oss.str();
    }
};
