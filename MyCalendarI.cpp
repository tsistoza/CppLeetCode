// LeetCode 729
#include <iostream>
#include <vector>
#include <utility>
#include <ios>

using std::cout, std::endl, std::vector;
using std::pair, std::boolalpha;

namespace Solution {
    class MyCalendar {
        private:
            vector<pair<int,int>> ST;

            int STTraversal(int node, int startTime, int endTime);
        public:
            bool book(int startTime, int endTime);
            MyCalendar() { }
    };

    int MyCalendar::STTraversal(int node, int startTime, int endTime) {
        int currStart = ST[node].first;
        int currEnd = ST[node].second;

        if (startTime >= currStart && endTime <= currEnd) return -1;
        if (startTime >= currStart && startTime < currEnd) return -1;
        if (startTime < currStart && endTime > currStart) return -1;

        
        int newNode = (startTime < currStart) ? 2*node : 2*node+1;
        if (newNode >= ST.size()) {
            while (ST.size()-1 == node-1) ST.push_back({ -1, -1 });
            ST.push_back( {startTime, endTime });
            return newNode;
        }
        if (ST[newNode].first == -1) {
            ST[newNode] = { startTime, endTime };
            return newNode;
        }
        return STTraversal(newNode, startTime, endTime);
    }

    bool MyCalendar::book(int startTime, int endTime) {
        if (ST.size() == 0) {
            ST.push_back({ startTime, endTime });
            return true;
        }

        return (STTraversal(0, startTime, endTime) == -1) ? false : true;
    }
}

int main() {
    using namespace Solution;
    MyCalendar* myCalendar = new MyCalendar();
    cout << boolalpha << myCalendar->book(10, 20) << endl;
    cout << boolalpha << myCalendar->book(15, 25) << endl;
    cout << boolalpha << myCalendar->book(20, 30) << endl;
    return 0;
}