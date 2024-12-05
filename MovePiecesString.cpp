// LeetCode 2337
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::string, std::unordered_map;
using std::vector;

static string start = "_L__R__R_";
static string target = "L______RR";
static string start1 = "R_L_";
static string target1 = "__LR";
static string start2 = "_R";
static string target2 = "R_";

namespace Solution {
    class Program {
        public:
            bool canChange(string start, string target);
    };
    bool Program::canChange(string start, string target) {
        unordered_map<char, vector<int>> startPos; // Store the pieces positions into a map, key=piece (L,R,_), value={vector of indexes}
        unordered_map<int, char> targetPos;        // Store the target positions, key=index, value=piece
        for (int i=0; i<start.size(); i++) {
            if (start[i] != '_')
                startPos[start[i]].push_back(i);
            if (target[i] != '_')
                targetPos[i] = target[i];
        }

        // The idea is that for each target piece, we want to find its closest piece from the start string
        // Then, you want the closest piece index, and then start increment/decrementing towards the target position.
        // If you encounter a piece opposite of the current piece, then return false, if you reach target position, go on to the next target piece, and repeat.
        for (unordered_map<int, char>::iterator it=targetPos.begin(); it!=targetPos.end(); it++) {
            vector<int> temp(startPos[it->second]);
            int closestIndex = 0;
            int index = temp[0];
            for(int i=0; i<temp.size(); i++)
                if (abs(it->first-temp[i]) < abs(it->first-index)) {
                    index = temp[i]; 
                    closestIndex = i;
                }
            //cout << "index: " << index << " : (" << it->first << "," <<it->second<<")" << endl;
            for (;index<it->first; index++) // YOU CAN ONLY MOVE Right
                if (start[index] == 'L') return false;
            for (;index>it->first; index--) // YOU CAN ONLY MOVE Left
                if (start[index] == 'R') return false;
            temp[closestIndex] = INT_MAX; // Set this index max so that we dont pick this index again.
            startPos[it->second] = temp;
        }
        return true;
    }
}


int main() {
    using namespace Solution;
    Program obj;
    cout << obj.canChange(start, target) << endl;
    cout << obj.canChange(start1, target1) << endl;
    cout << obj.canChange(start2, target2) << endl;
    return 0;
}