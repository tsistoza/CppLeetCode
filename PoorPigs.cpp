// LeetCode 458
#include <iostream>

using std::cout, std::endl;

static int buckets = 4;
static int minutesToDie = 15;
static int minutesToTest = 30;

namespace Solution {
    class Program {
        public:
            int poorPigs(int buckets, int minutesToDie, int minutesToTest);
    };

    int Program::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int numPigs = 0;
        int tests = (minutesToTest / minutesToDie + 1);
        while ((tests * numPigs) < buckets) numPigs++;
        return numPigs;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.poorPigs(buckets, minutesToDie, minutesToDie) << endl;
    return 0;
}