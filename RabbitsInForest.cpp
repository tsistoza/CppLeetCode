// LeetCode 781
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector, std::unordered_map;

static vector<int> answers { 10, 10, 10 };

namespace Solution {
    class Program {
        public:
            int numRabbits(vector<int>& answers);
    };

    int Program::numRabbits(vector<int>& answers) {
        unordered_map<int,int> count;
        for (int i=0; i<answers.size(); i++)
            count[answers[i]]++;
        
        int minRabbits=0;
        for (auto it=count.begin(); it!=count.end(); it++) {
            if (it->first+1 >= it->second) minRabbits += it->first+1;
            else {
                int groupRabbits = (it->second / (it->first+1)) + (it->second % (it->first+1));
                minRabbits += (it->first+1) * groupRabbits;
            }
        }
        return minRabbits;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numRabbits(answers) << endl;
}