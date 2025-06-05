// LeetCode 1061
#include <iostream>
#include <string>
#include <set>
#include <vector>

using std::cout, std::endl, std::string;
using std::set, std::vector;

static string s1 = "hello";
static string s2 = "world";
static string baseStr = "hold";

namespace Solution {
    class Program{
        public:
            string smallestEquivalentString(string s1, string s2, string baseStr);
    };

    string Program::smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> groups;
        for (int i=0; i<s1.size(); i++) {
            if (groups.size() == 0) {
                set<char> order { s1[i] };
                if (s1[i] != s2[i]) order.insert(s2[i]);
                groups.push_back(order);
                continue;
            }

            bool newGroup = true;
            bool same = (s1[i] == s2[i]);
            for (set<char>& group : groups) {
                if (!group.contains(s1[i]) && !group.contains(s2[i])) continue;
                group.insert(s1[i]);
                if (!same) group.insert(s2[i]);
                newGroup = false;
            }

            if (!newGroup) continue;
            set<char> group;
            group.insert(s1[i]);
            if (!same) group.insert(s2[i]);
            groups.push_back(group);
        }

        string ans = "";
        for (char c : baseStr) {
            bool isGrouped = false;
            for (set<char>& group : groups) {
                if (!group.contains(c)) continue;
                ans += *(group.begin());
                isGrouped = true;
            }
            if (!isGrouped) ans += c;
        }

        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}