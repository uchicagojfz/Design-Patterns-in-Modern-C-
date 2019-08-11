#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
    vector<int> combination;
public:
    string status;
    string results;

    CombinationLock(const vector<int> &combination) : combination(combination) {
        for (int digit : combination) {
            results += to_string(digit);
        }
        status = "LOCKED";
    }

    void enter_digit(int digit) {
        if (status == "LOCKED") {
            status = "";
        }
        status +=  to_string(digit);
        if (status.size() == results.size()) {
            if (status == results) {
                status = "OPEN";
            }
            else {
                status = "ERROR";
            }
        }
    }
};
