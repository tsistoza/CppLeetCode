// LeetCode 3280
#include <iostream>
#include <string>
#include <cmath>

using std::cout, std::endl;
using std::string, std::stoi;
using std::log2;

static string date = "2080-02-29";
static string date1 = "1900-01-01";
static string date2 = "2025-01-17";

namespace Solution {
    class Program {
        private:
            string toBinary(int num);
        public:
            string convertDateToBinary(string date);
    };

    string Program::toBinary(int num) {
        string ans = "";
        int numBits = (int) log2(num) + 1;
        for (int i=numBits-1; i>=0; i--) {
            char bit = ((num >> i) & 1) + 48;
            ans.push_back(bit);
        }
        return ans;
    }

    string Program::convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string dateInBinary = "";
        dateInBinary += toBinary(year);
        dateInBinary.push_back('-');
        dateInBinary += toBinary(month);
        dateInBinary.push_back('-');
        dateInBinary += toBinary(day);
        return dateInBinary;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.convertDateToBinary(date) << endl;
    cout << obj.convertDateToBinary(date1) << endl;
    cout << obj.convertDateToBinary(date2) << endl;
    return 0;
}