// LeetCode 2553
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector;

static vector<int> nums { 7, 1, 3, 9 };

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<int>& ans);
            int findNumDigits(int number);
        public:
            vector<int> separateDigits(vector<int>& nums);
    };

    void Program::prettyPrint(vector<int>& ans) {
        cout << "{ ";
        for (int i : ans) cout << i << " ";
        cout << "}\n\n";
        return;
    }

    int Program::findNumDigits(int number) {
        int i=10, times=1;
        while (i<number) {
            i*=10;
            times++;
        }
        return times-1;
    }

    vector<int> Program::separateDigits(vector<int>& nums) {
        vector<int> answer;

        for (int i=0; i<nums.size(); i++) {
            int remains = nums[i], temp = nums[i];
            //cout << "CurrNumber: " << nums[i] << endl;
            while (remains > 0) {
                int multipleOfTen = std::pow(10, findNumDigits(remains));
                if (multipleOfTen == 1) {
                    answer.push_back(remains);
                    remains -= remains;
                    continue;
                }

                remains %= multipleOfTen;
                //cout << "MultipleOfTen = " << multipleOfTen << " Remaining = " << remains << endl;
                temp -= remains;
                temp /= multipleOfTen;
                answer.push_back(temp);
                temp = remains;
            }
        }

        prettyPrint(answer);
        return answer;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.separateDigits(nums);
    return 0;
}