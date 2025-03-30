// LeetCode 2818
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <utility>

using std::cout, std::endl, std::vector;
using std::unordered_set, std::unordered_map;
using std::sort, std::pair;

static vector<int> nums { 19, 12, 14, 6, 10, 18 };
static int k = 3;

namespace Solution {
    class Sort {
        public:
            bool operator()(pair<int,int> p1, pair<int,int> p2) const  { return p1.first < p2.first; }
    };
    class Program {
        private:
            bool isPrime(int num);
            int primeScore(int num);
        public:
            int maximumScore(vector<int>& nums, int k);
    };

    bool Program::isPrime(int num) {
        if (num <= 1) return false; 
        if (num <= 3) return true; 
      
        if (num % 2 == 0 || num % 3 == 0) return false;

        for (int i = 5; i * i <= num; i += 6)
          if (num % i == 0 || num % (i + 2) == 0) return false;
        
        return true;
    }

    int Program::primeScore(int num) {
        if (num == 1) return 0;
        if (isPrime(num)) return 1;
        unordered_set<int> count;
        int temp = num;
        for (int i=2; i<num && temp > 1; ) {
            if ((temp % i) > 0) i++;
            temp /= i;
            if (count.contains(i)) continue;
            count.insert(i);
        }

        return count.size();
    }

    int Program::maximumScore(vector<int>& nums, int k) {
        vector<int> scores;
        vector<pair<int,int>> sorted;
        for (int i=0; i<nums.size(); i++) {
            scores.push_back(primeScore(nums[i]));
            sorted.push_back({nums[i], i});
        }

        unordered_map<int, vector<int>> dict;
        for (int i=0; i<scores.size(); i++) {
            int left = -1;
            int right = nums.size();

            // find left index
            int j = i-1;
            while (j >= 0) {
                if (scores[i] < scores[j]) {
                    j--;
                    continue;
                }
                left = j;
                break;
            }

            // find right index
            j = i+1;
            while (j < nums.size()) {
                if (scores[j] <= scores[i]) {
                    j++;
                    continue;
                }
                right = j;
                break;
            }
            dict[i] = vector<int> { left, right };
        }
        
        Sort cmp;
        sort(sorted.begin(), sorted.end(), cmp);

        int score = 1;
        for (int i=sorted.size()-1, ops=0; i>=0 && ops<k;) {
            int index = sorted[i].second;
            int left = dict[index][0];
            int right = dict[index][1];
            int numTimes = (index - left) * (right - index);
            while (numTimes > 0 && ops < k) {
                score *= sorted[i].first;
                ops++;
                numTimes--;
            }
            i--;
        }

        return score;
    }
}

int main(){
    using namespace Solution;
    Program obj;
    cout << obj.maximumScore(nums, k) << endl;
}