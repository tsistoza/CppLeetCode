// LeetCode 2751
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>

using std::cout, std::endl, std::vector, std::string, std::unordered_map, std::sort, std::stack;

static vector<int> positions { 3, 5, 2, 6 };
static vector<int> healths { 10, 10, 15, 12 };
static string directions = "RLRL";

namespace Solution {
    class SortByPosition {
        public:
            bool operator()(const vector<int>& v1, const vector<int>& v2) const {
                return v1[0] < v2[0];
            }
    };
    class Program {
        private: 
            static void prettyPrint(vector<int> answers);
        public:
            vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions);
    };

    void Program::prettyPrint(vector<int> answers) {
        cout << "Robots Remaining Health: { ";
        for (int i : answers) cout << i << " ";
        cout << "}\n\n" << endl;
        return;
    }

    vector<int> Program::survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> sortedRobots;
        for (int i=0; i<positions.size(); i++) {
            sortedRobots.push_back(vector<int> { positions[i], i });
        }
    
        SortByPosition cmp;
        sort(sortedRobots.begin(), sortedRobots.end(), cmp);

        stack<vector<int>> collisions; // each robot --> position, index, directions
        collisions.push(sortedRobots[0]);
        
        for (int i=1; i<positions.size(); i++) {
            vector<int> elementToPush = sortedRobots[i];
            int index1 = elementToPush[1];

            if (collisions.empty()) {
                collisions.push(elementToPush);
                continue;
            }

            vector<int> top = collisions.top();
            int index = top[1];

            if (directions[index] == 'R' && directions[index1] == 'L') {
                int interaction = 0;
                if (healths[index] > healths[index1]) interaction = 1;
                if (healths[index] == healths[index1]) interaction = 2;

                #ifdef DEBUG
                cout << "Robot" << index+1 << " @ " << top[0] << " with direction " << directions[index] << endl;
                cout << "Robot" << index1+1 << " @ " << elementToPush[0] << " with direction " << directions[index1] << endl;
                cout << "currInteraction: " << interaction << endl;
                #endif

                switch(interaction) {
                    case 0: healths[index] = 0;
                            healths[index1]--;
                            collisions.pop();
                            collisions.push(elementToPush);
                        break;
                    case 1: healths[index]--;
                            healths[index1] = 0;
                        break;
                    default: healths[index] = 0;
                             healths[index1] = 0;
                             collisions.pop();
                        break;
                }
            }

            if (directions[index1] == 'R') collisions.push(elementToPush);
        }

        vector<int> answer;
        for (int i : healths) if (i > 0) answer.push_back(i);
        prettyPrint(answer);
        return answer;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.survivedRobotsHealths(positions, healths, directions);
    return 0;
}