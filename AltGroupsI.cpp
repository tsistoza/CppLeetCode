// LeetCode 3206
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> colors { 1, 1, 1 };
static vector<int> colors1 { 0, 1, 0, 0, 1 };

namespace Solution {
    class Program {
        public:
            int numberOfAlternatingGroups(vector<int>& colors);
    };

    int Program::numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        for (int i=0; i<colors.size(); i++) {
            int left, right;
            
            if (i==0) left = colors.size()-1;
            else left = i-1;
            if (i==colors.size()-1) right = 0;
            else right = i+1;

            if (colors[left] != colors[i] && colors[right] != colors[i]) count++;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfAlternatingGroups(colors) << endl;
    cout << obj.numberOfAlternatingGroups(colors1) << endl;
    return 0;
}