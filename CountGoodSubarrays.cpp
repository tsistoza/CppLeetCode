// LeetCode 2537
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <iterator>

using std::cout, std::endl, std::vector, std::ceil;
using std::unordered_map, std::next, std::distance, std::pair;
using ll = long long;

static vector<int> nums { 3, 1, 4, 3, 2, 2, 4 };
static int k = 2;

namespace Solution {
    class Program {
        private:
            bool isGoodSubarray(vector<int> subarray, int k);
        public:
            ll countGood(vector<int>& nums, int k);
    };

    bool Program::isGoodSubarray(vector<int> subarray, int k) {
        unordered_map<int,pair<int,int>> dict;
        ll count = 0;
        for (int i : subarray) {
            if (dict.contains(i)) {
                dict[i].first++;
                dict[i].second+=dict[i].first-1;
            } else
                dict.insert({i, {1, 0}});

            count += dict[i].second;
            if (count >= k) return true;
        }
        return false;
    }

    ll Program::countGood(vector<int>& nums, int k) {
        ll count = 0;
        if (nums.size() == 1) return count;

        int windowSize = 0;
        for (int i=1, j=1, pairs=0; i<nums.size(); i++, j++) {
            pairs+=j;
            if (pairs < k) continue;
            windowSize = i;
            break;
        }

        auto end = nums.end();
        for (auto it=nums.begin(); it!=next(end, -1-windowSize+1); it++) {
            int num = windowSize;
            vector<int> subarray;

            while((next(it, num) != nums.end())) {
                subarray.clear();
                subarray.insert(subarray.begin(), it, next(it, num));
                subarray.push_back(*(next(it,num)));
                if (isGoodSubarray(vector<int> (subarray), k)) {
                    count++;
                    break;
                }
                num++;
            }
            if (count == 0) return count;
            ll extraSubarrays = (ll) distance(it+num, nums.end()) - 1;
            if (extraSubarrays == -1) continue;
            count += extraSubarrays;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countGood(nums, k) << endl;
}