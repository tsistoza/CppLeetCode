// LeetCode 69
#include <iostream>

using std::cout, std::endl;

static int x = 70;

namespace Solution {
    class Program {
        public:
            int mySqrt(int x);
    };

    int Program::mySqrt(int x) {
        int low = 0;
        int high = x;
        while (low <= high) {
            int middle = low + (high-low)/2;
            if (middle*middle == x) return middle;
            if (middle*middle < x)
                low = middle + 1;
            if (middle*middle > x)
                high = middle - 1;
        }
        if (low*low < x) return low;
        return low-1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.mySqrt(x) << endl;
}