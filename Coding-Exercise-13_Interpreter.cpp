#include <string>
#include <unordered_map>
using namespace std;

struct ExpressionProcessor
{
  unordered_map<char,int> variables;

  int calculate(const string& expression)
  {
    int sum = 0;
    bool sum_flag = true;
    bool prev_is_alpha = false;
    int tmp = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            tmp = tmp * 10 + stoi(string{expression[i]});
            prev_is_alpha = false;
        }
        else {
            if (expression[i] == '+' or expression[i] == '-') {
                sum += sum_flag ? tmp : -tmp;
                sum_flag = expression[i] == '+' ? true : false;
                tmp = 0;
                prev_is_alpha = false;
            }
            else {
                if (prev_is_alpha) {
                    return 0;
                }
                auto it = variables.find(expression[i]);
                if (it == variables.end()) {
                    return 0;
                }
                tmp += it->second;
                prev_is_alpha = true;
            }
        }
        if (i == expression.size() - 1) {
            sum += tmp;
        }
    }
    return sum;
  }
};
