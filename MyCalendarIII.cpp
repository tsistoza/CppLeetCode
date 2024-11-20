// LeetCode 732
// Line Sweep
#include <iostream>
#include <map>

using std::cout, std::endl;
using std::map;

namespace Solution {
    class MyCalendarThree {
        public:
            map<int, int> line;
            int book(int startTime, int endTime);

        ~MyCalendarThree() {
        }
    };

    int MyCalendarThree::book(int startTime, int endTime) {
        int max = 1;
        for (int i=startTime; i<=endTime; i++) {
            if (i < endTime) this->line[i]++;
            max = (max < this->line[i]) ? this->line[i] : max;
        }
        return max;
    }
}

int main() {
    using namespace Solution;
    MyCalendarThree* obj = new MyCalendarThree();
    cout << obj->book(10, 20) << endl;
    cout << obj->book(50, 60) << endl;
    cout << obj->book(10, 40) << endl;
    cout << obj->book(5, 15) << endl;
    cout << obj->book(5, 10) << endl;
    cout << obj->book(25, 55) << endl;
    delete(obj);
    return 0;
}