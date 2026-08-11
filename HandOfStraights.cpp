// LeetCode 846
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl, std::vector, std::priority_queue;

static vector<int> hand { 1, 2, 3, 4, 5, 6, 7, 8 };
static int groupSize = 4;

namespace Solution {
    class Program {
        public:
            bool isNStraightHand(vector<int>& hand, int groupSize);
    };

    bool Program::isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize > 0) return false;
        
        priority_queue<int, vector<int>, std::greater<int>> queue(hand.begin(), hand.end());
        vector<int> requeue;
        
        int size = 0, lastCard = -1;
        while (!queue.empty()) {
            int currCard = queue.top();

            if (size == 0) {
                for (int i : requeue) queue.push(i);
                requeue.clear();
                lastCard = currCard;
                queue.pop();
                continue;
            }
            
            if (lastCard + 1 < currCard) return false;
            else if (lastCard + 1 == currCard) {
                lastCard =  currCard;
                size++;
            }
            else requeue.push_back(currCard);

            queue.pop();

            if (size == groupSize) {
                size = 0;
                lastCard = -1;
            }
        }

        if (requeue.size() > 0 || size > 0) return false;

        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj; 
    cout << std::boolalpha << obj.isNStraightHand(hand, groupSize) << endl;
    return 0;
}