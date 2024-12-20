// LeetCode 2231
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::cout, std::endl;
using std::vector, std::string;
using std::to_string, std::stoi;
using std::pair;

namespace Solution {
    class Program {
        private:
            bool vecContains(vector<int>& indexes, int index);
        public:
            int largestInteger(int num);
    };
    int Program::largestInteger(int num) {
        string number = to_string(num);
        vector<int> indexes;
        for (int i=0; i<number.size(); i++) {
            pair<char, int> index(number[i], i);
            for (int j=i+1; j<number.size(); j++) {
                int number1 = number[i]-48;
                int number2 = number[j]-48;
                if ((number1%2 == number2%2) && index.first < number[j]) {
                    index.first = number[j];
                    index.second = j;
                }
            }
            if (index.second == i) continue;
            char tmp = number[i];
            number[i] = number[index.second];
            number[index.second] = tmp;
        }
        return stoi(number);
    }

    bool Program::vecContains(vector<int>& indexes, int index) {
        for (int i : indexes)
            if (i == index) return true;
        return false;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.largestInteger(1234) << endl;
    cout << obj.largestInteger(65875) << endl;
    return 0;
}