// LeetCode 66
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using std::cout, std::endl, std::vector, std::string, std::stack;

static vector<int> digits { 9, 9, 9, 9 };

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<int> temp);
        public:
            vector<int> plusOne(vector<int>& digits);
    };

    void Program::prettyPrint(vector<int> temp) {
        cout << "{ ";
        for (int i=0; i<temp.size(); i++) {
            if (i == temp.size()-1)
                cout << temp[i] << " ";
            else
                cout << temp[i] << ", ";
        }
        cout << "}" << endl;
        return;
    }

    vector<int> Program::plusOne(vector<int>& digits) {
        stack<int> lifo;
        
        vector<int>::reverse_iterator itr = digits.rbegin();
        int digit = *itr + 1;
        bool carry = (digit > 9);
        lifo.push((digit > 9) ? 0 : digit);
        itr++;

        for (; itr != digits.rend(); itr++) {
            digit = (carry) ? *itr + 1 : *itr;
            lifo.push((digit > 9) ? 0 : digit);
            carry = (digit > 9);
        }
        
        if (carry) lifo.push(1);

        vector<int> results;
        while (!lifo.empty()) {
            int digit = lifo.top();
            results.push_back(digit);
            lifo.pop();
        }
        prettyPrint(results);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.plusOne(digits);
    return 0;
}