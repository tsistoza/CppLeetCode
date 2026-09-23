// LeetCode 3525
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::min, std::max;

static vector<int> nums { 1, 1, 2, 1, 1 };
static int k = 2;
static vector<vector<int>> queries { { 2, 1, 0, 1 } };

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<int>& results);
            void buildTree(vector<int>& nums, vector<int>& tree, vector<vector<int>>& freq, int k);
            void updateTree(vector<int>& tree, vector<vector<int>>& freq, int n, int k, int index, int value);
            int queryParent(vector<int>& tree, vector<vector<int>>& freq, int curr, int tl, int tr, int l, int r);
            int merge(vector<int>& tree, vector<vector<int>>& freq, int L, int R);
            int queryLR(vector<int>& tree, int n, int k, int leftRange, int rightRange);
            vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries);
    };

    void Program::prettyPrint(vector<int>& results) {
        cout << "{ ";
        for (int i : results) cout << i << " ";
        cout << "}\n" << endl;
        return;
    }

    void Program::buildTree(vector<int>& nums, vector<int>& tree, vector<vector<int>>& freq, int k) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            tree[n+i] = nums[i] % k;
            cout << "tree[" << n+i << "] = " << tree[n+i] << endl;
        }
        for (int i=n-1; i>0; i--) {
            tree[i] = (tree[2*i] * tree[(2*i)+1]) % k;
            for (int j=0; j<k; j++) {
                if (freq[(2*i)+1][j]) {
                    int nr = (tree[2*i] * j) % k;
                    freq[i][nr] += freq[2*i+1][j];
                }
            }
        }

        return;
    }

    void Program::updateTree(vector<int>& tree, vector<vector<int>>& freq, int n, int k, int index, int value) {
        tree[n+index] = value;
        
        int parent = index / 2;
        while (parent > 0) {
            tree[parent] = (tree[2*parent] * tree[2*parent+1]) % k;
            for (int j=0; j<k; j++) {
                if (freq[2*parent+1][j]) {
                    int nr = (tree[2*parent] * j) % k;
                    freq[parent][nr] += freq[(2*parent)+1][j];
                }
            }
            parent = parent / 2;
        }
        return;
    }

    int Program::merge(vector<int>& tree, vector<vector<int>>& freq, int L, int R) {
        int parent = L/2;
        for (int i=0; i<k; i++) {
            if (freq[R][i]) {
                int nr = (tree[L] * i) % k;
                freq[parent][i] += freq[R][i];
            }
        }
        return parent;
    }

    int Program::queryParent(vector<int>& tree, vector<vector<int>>& freq, int curr, int tl, int tr, int l, int r) {
        if (l > r) return -1;
        if (l == tl && r == tr) return tree[curr];

        int mid = l + (r-l) / 2;
        return merge(tree, freq,
                    queryParent(tree, freq, curr*2, tl, mid, l, min(r, mid)),
                    queryParent(tree, freq, curr*2+1, mid+1, tr, max(l, mid+1), r));
    }

    int Program::queryLR(vector<int>& tree, int n, int k, int leftRange, int rightRange) {
        if (leftRange == rightRange) return tree[leftRange];
        if (leftRange > rightRange) return 1;

        int mid = leftRange + (rightRange - leftRange) / 2;
        return (queryLR(tree, n, k, leftRange, mid) % k) * (queryLR(tree, n, k, mid+1, rightRange) % k);
    }

    vector<int> Program::resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        
        vector<int> tree(2*n, 1);
        vector<vector<int>> freq(2*n, vector<int>(5, 0));
        buildTree(nums, tree, freq, k);
        cout << tree[1] << endl;

        vector<int> results(queries.size(), 0);
        for (int i=0; i<queries.size(); i++) {
            int index = queries[i][0], newValue = queries[i][1], start = queries[i][2], x = queries[i][3];
            nums[index] = newValue;
            updateTree(tree, freq, n, k, index, newValue);
            int xValue = 0;
            for (int j=start; j<n; j++) {
                int product = queryLR(tree, n, k, start+n, j+n);
                if (product % k == x) xValue++;
            }
            results[i] = xValue;
        }

        prettyPrint(results);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.resultArray(nums, k, queries);
    return 0;
}