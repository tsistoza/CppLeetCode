// LeetCode 1358
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector, std::min;

static string s = "acbbcac";

namespace Solution {
    class Program {
        private:
            vector<int> containsABC(string& s, int left, int right);
        public:
            int numberOfSubstrings(string s);
    };

    vector<int> containsABC(string& s, int left, int right) {
        vector<int> result(4, -1);
        for (int i=left; i<=right; i++) {
            switch (s[i]) {
                case 'a': result[1] = i;
                    break;
                case 'b': result[2] = i;
                    break;
                case 'c': result[3] = i;
                    break;
                default: break;
            }
        }
        if (result[1] > -1 && result[2] > -1 && result[3] > -1) result[0] = 1;
        return result;
    }

    int Program::numberOfSubstrings(string s) {
        int sum = 0;
        int left = 0, right = 0;
        int indexA=-1, indexB=-1, indexC=-1;
        vector<int> indexCounted;

        while (right < s.size()) {
            switch (s[right]) {
                case 'a': indexA = right;
                    break;
                case 'b': indexB = right;
                    break;
                case 'c': indexC = right;
                    break;
                default: break;
            }

            if (indexA == -1 || indexB == -1 || indexC == -1) {
                right++;
                continue;
            }
            
            left = min(indexA, min(indexB, indexC));
            
            //cout << "indexA=" << indexA << ", indexB=" << indexB << ", indexC=" << indexC << endl;

            // Left = # of new substrings (xxabc)
            if (indexCounted.size() > 0) { 
                // if prevIndex was an a,b,c we can add new substrings up until the prevIndex, which then are duplicates.
                // Ex. (xxaxx[bca]) = 2 new substrings (5[left] - 2[prevIndex] - 1)
                int prevIndex = indexCounted.back();
                sum += left - prevIndex - 1;
            }
            else sum += left;

            // Right = # of new substrings (abcxx)
            sum += s.size() - 1 - right;

            // Both = # of new substrings (xxabcxx)
            if (left > 0 && right < s.size()-1) {
                if (indexCounted.size() > 0) {
                    // Note the left case applies here
                    int prevIndex = indexCounted.back();
                    int leftSum = left - prevIndex - 1; // if leftSum = 0, there are no new duplicates, since this is just the right case
                    int rightSum = s.size() - 1 - right;
                    sum += (leftSum == 0) ? 0 : (leftSum + rightSum - 1);
                }
                else sum += left + s.size() - 2 - right;
            }

            // Reset min index
            if (left == indexA) indexA = -1;
            else if (left == indexB) indexB = -1;
            else indexC = -1;
            indexCounted.push_back(left);
            sum++;
            //cout << "sum = " << sum << endl;

            left++;
        }

        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfSubstrings(s) << endl;
    return 0;
}