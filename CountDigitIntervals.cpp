// LeetCode 2276
#include <iostream>
#include <utility>
#include <unordered_set>

using std::cout, std::endl;
using std::unordered_set;

namespace Solution {
    class CountIntervals {
        private:
            unordered_set<int> vis;
        public:
            void add(int left, int right);
            int count();
    };

    void CountIntervals::add(int left, int right) {
        for (int i=left; i<=right; i++) {
            if (vis.contains(i)) continue;
            vis.insert(i);
        }
        return;
    }

    int CountIntervals::count() {
        return this->vis.size();
    }
}

int main() {
    using namespace Solution;
    CountIntervals obj;
    obj.add(2,3);
    obj.add(7,10);
    cout << obj.count() << endl;
    obj.add(5,8);
    cout << obj.count() << endl;
    return 0;
}