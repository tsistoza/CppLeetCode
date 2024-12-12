// LeetCode 2558
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using std::cout, std::endl;
using std::priority_queue, std::vector;
using std::floor;

static vector<int> gifts { 25, 64, 9, 4, 100 };
static int k = 4;
static vector<int> gifts1 { 1, 1, 1, 1 };
static int k1 = 4;

namespace Solution {
    class Program {
        public:
            long long pickGifts(vector<int>& gifts, int k);
    };
    
    long long Program::pickGifts(vector<int>& gifts, int k) {
        long long numGifts = 0;
        priority_queue<int> heap;
        for (int i : gifts) {
            heap.push(i);
            numGifts += i;
        }

        for (int i=0; i<k; i++) {
            int giftsLeft = floor(sqrt(heap.top()));
            numGifts-= (heap.top()-giftsLeft);
            heap.pop();
            heap.push(giftsLeft);
        }
        return numGifts;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.pickGifts(gifts, k) << endl;
    cout << obj.pickGifts(gifts1, k1) << endl;
    return 0;
}