// LeetCode 2349
#include <iostream>
#include <unordered_map>
#include <set>

using std::cout, std::endl, std::unordered_map;
using std::set;

namespace Solution {
    class NumberContainers {
        private:
            unordered_map<int,int> indexes;
            unordered_map<int,set<int>> values;
        public:
            int find(int number);
            void change(int index, int number);
            ~NumberContainers() { indexes.clear(); values.clear(); }
    };

    int NumberContainers::find(int number) {
        if (!values.contains(number)) return -1;
        return *(values[number].begin());
    }

    void NumberContainers::change(int index, int number) {
        if (!indexes.contains(index)) {
            indexes[index] = number;
            values[number].insert(index);
            return;
        }
        
        // Erase old data
        int value = indexes[index];
        values[value].erase(index);

        // Insert new data
        indexes[index] = number;
        values[number].insert(index);
        return;
    }
}

int main() {
    using namespace Solution;
    NumberContainers* nc = new NumberContainers();
    cout << nc->find(10) << endl;
    nc->change(2, 10);
    nc->change(1, 10);
    nc->change(3, 10);
    nc->change(5, 10);
    cout << nc->find(10) << endl;
    nc->change(1, 20);
    cout << nc->find(10) << endl;
    return 0;
}