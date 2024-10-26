#include <iostream>
#include <string>
#include <unordered_map>

using std::cout, std::cin, std::endl;
using std::string, std::to_string, std::unordered_map;

namespace Solution {
    class Program {
        public:
            unordered_map<string, int> hashtable;
            int romanToInt(string s);
            void initMap();
    };

    int Program::romanToInt(string s) {
        this->initMap();
        if (s.size() == 1) return this->hashtable[s];
        int sum=0;
        string specialCases;
        for(string::iterator it=s.begin(); it!=s.end(); it++) {
            specialCases.push_back(*it);
            if (specialCases.size() == 2 && this->hashtable.contains(specialCases)) {
                sum+=this->hashtable[specialCases];
                specialCases.clear();
            } else if (specialCases.size() == 2 && !this->hashtable.contains(specialCases)) {
                string ch(1, specialCases.front());
                sum+=this->hashtable[ch];
                specialCases.clear();
                specialCases.push_back(*it);
            }
            if (it==s.end()-1 && specialCases.size() == 1) sum+=this->hashtable[specialCases]; // catch end
        }
        return sum;
    }

    void Program::initMap() {
        this->hashtable["I"] = 1;
        this->hashtable["IV"] = 4;
        this->hashtable["V"] = 5;
        this->hashtable["IX"] = 9;
        this->hashtable["X"] = 10;
        this->hashtable["XL"] = 40;
        this->hashtable["L"] = 50;
        this->hashtable["XC"] = 90;
        this->hashtable["C"] = 100;
        this->hashtable["CD"] = 400;
        this->hashtable["D"] = 500;
        this->hashtable["CM"] = 900;
        this->hashtable["M"] = 1000;
        return;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.romanToInt("MCMXCIV");
    return 0;
}