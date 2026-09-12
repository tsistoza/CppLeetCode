// LeetCode 846
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl, std::vector, std::priority_queue;

static vector<int> hand { 8, 10, 12 };
static int groupSize = 3;

namespace Solution {
    class Program {
        public:
            bool isNStraightHand(vector<int>& hand, int groupSize);
    };

    bool Program::isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1) return true;
        if (hand.size() % groupSize > 0) return false;
        
        priority_queue<int, vector<int>, std::greater<int>> queue(hand.begin(), hand.end());
        vector<int> requeue;
        
        int sizeOfHand = 0, lastCard = -1;
        while (!queue.empty()) {
            int currCard = queue.top();
            queue.pop();

            if (sizeOfHand == 0) {
                lastCard = currCard;
                sizeOfHand++;
                continue;
            }
            
            if (lastCard + 1 < currCard || lastCard + 1 > currCard) requeue.push_back(currCard);
            else if (lastCard + 1 == currCard) {
                lastCard = currCard;
                sizeOfHand++;
            } 

            if (sizeOfHand == groupSize) {
                sizeOfHand = 0;
                lastCard = -1;

                for (int i : requeue) queue.push(i);
                requeue.clear();
                lastCard = -1;
            }
        }

        if (requeue.size() > 0 || sizeOfHand > 1) return false;

        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj; 
    cout << std::boolalpha << obj.isNStraightHand(hand, groupSize) << endl;
    return 0;
}