// LeetCode 3208
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> colors { 0, 1, 0, 1, 0 };
static int k = 3;
static vector<int> colors1 { 0, 1, 0, 0, 1, 0, 1 };
static int k1 = 6;
static vector<int> colors2 { 1, 1, 0, 1 };
static int k2 = 4;


namespace Solution {
    class Program {
        public:
            int numberOfAlternatingGroups(vector<int>& colors, int k);
    };

    int Program::numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        for (int i=0; i<colors.size()-1; i++) {
            int tiles = 1;
            for (int j=i; tiles<k; tiles++) {
                if (j==colors.size()) j=0;
                int left, right;
            
                if (j==0) left = colors.size()-1;
                else left = j-1;
                if (j==colors.size()-1) right = 0;
                else right = j+1;

                if ((tiles != 1 && tiles != k) && (colors[left] == colors[j] || colors[right] == colors[j])) break;
                j++;
            }

            if (tiles == k)
                count++;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfAlternatingGroups(colors, k) << endl;
    cout << obj.numberOfAlternatingGroups(colors1, k1) << endl;
    cout << obj.numberOfAlternatingGroups(colors2, k2) << endl;
}