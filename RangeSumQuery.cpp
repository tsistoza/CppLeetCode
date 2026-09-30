// LeetCode 303
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::vector, std::endl, std::log2;

static vector<int> nums { -8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703 };

namespace Solution {
    class NumArray {
        private:
            vector<int> nums;
            vector<vector<int>> table;

            void build(int n);
            void prettyPrint();
        public:
            NumArray(vector<int>& _nums);
            int sumRange(int left, int right);
    };

    void NumArray::build(int n) {
        int row = n, col = log2(n) + 1;
        table.resize(row, vector<int>(col));
        for (int i=0; i<n; i++)
            table[i][0] = nums[i];
        
        // for each table[i][j] = this is the sum from arr[i] to arr[i + 2^j - 1]
        for (int j=1; j<col; j++) {
            for (int i=0; i + (1 << j) <= n; i++) {
                int index = i + (1 << (j - 1));
                //cout << "i = " << i << ", j = " << j << ", ";
                //cout << "table[i][j-1] = " << table[i][j-1]  << ", table[" << index << "][j-1] = " << table[index][j-1] << endl;
                table[i][j] = table[i][j - 1] + table[index][j - 1];
                //cout << "table[i][j] = " << table[i][j] << endl;
            }
        }
        //prettyPrint();
        return;
    }

    void NumArray::prettyPrint() {
        for (const vector<int>& v : table) {
            cout << "{ ";
            for (int i : v) cout << i << " ";
            cout << "} " << endl;
        }
        return;
    }

    NumArray::NumArray(vector<int>& _nums) {
        nums = std::move(_nums);
        build(nums.size());
    }

    int NumArray::sumRange(int left, int right) {
        int sum = 0;

        // table[left][k] is the sum of arr[i]...arr[i + 2^k - 1], or the sum of arr[leftBound]..arr[rightBound]
        // since k is only of size logn, we can only sum up to a set amount, so we have to get each block, we know where the next block is by the rightBound

        // table[leftBound][k] is the first block
        int k = log2(right - left + 1);
        int leftBound = left;
        int rightBound = leftBound + (1 << k) - 1;
        while(rightBound <= right) { // Check if this block satisifies the query range, else get next block
            //cout << "table[" << leftBound << "][" << k << "] = " << table[leftBound][k] << endl;
            sum += table[leftBound][k];
            leftBound = rightBound + 1;
            if (leftBound > right) break;
            k = log2(right - leftBound + 1);
            rightBound = leftBound + (1 << k) - 1;
        }
        return sum;
    }

    /*

    This is old debug variant which helped me understand how sparse tables work, note it works for a small array size, anything greater > 10 no good.

    int NumArray::sumRange(int left, int right) {
        int indexLeftk = log2(right - left + 1);
        
        // check if the indexLeftK already satisfies the range(left, right);
        if ((left + (1 << indexLeftk) - 1) == right) return table[left][indexLeftk];

        // If it doesnt we want to get the range it doesnt cover [indexRight, rightK] 
        // since we know table[left][indexLeftK] covers the sum of arr[left] to arr[(left + (1 << indexLeftK) - 1))] or arr[left + 2^indexLeftK - 1]
        // we want to cover for table[indexLeftK+1][rightK], where rightK = (right - indexLeftK+1 + 1), where this sums up the rest
        int indexRange = (left + (1 << indexLeftk) - 1) + 1;
        int indexRightK = log2(right - indexRange + 1);
        cout << "left = " << left << ", right = " << right << ", indexLeftk = " << indexLeftk << ",indexRightk = " << indexRightK << endl;
        cout << "table[" << left << "][" << indexLeftk << "] = " << table[left][indexLeftk];
        cout << ", table[" << indexRange << "][" << indexRightK << "] = " << table[indexRange][indexRightK] << endl;
        return table[left][indexLeftk] + table[indexRange][indexRightK];
    }

    */
}

int main() {
    using namespace Solution;
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    cout << numArray.sumRange(0, 12) << endl;
    return 0;
}