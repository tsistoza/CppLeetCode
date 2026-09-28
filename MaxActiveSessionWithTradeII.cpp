// LeetCode 3501
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::string, std::max, std::min;

static string s = "0101110001101";
static vector<vector<int>> queries { { 0, 7 }, { 0, 12 } };

namespace Solution {
    class Program {
        private:
            void prettyPrint(vector<int>& ans);
        public:
            void buildTree(vector<int>& tree, vector<int>& blockSums, int curr, int l, int r);
            int query(vector<int>& tree, int curr, int ql, int qr, int l, int r);
            int findLowestBlock(vector<int>& blockRight, int ql);
            int findHighestBlock(vector<int>& blockLeft, int qr);
            vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries);
    };

    void Program::prettyPrint(vector<int>& ans) {
        cout << "{ ";
        for (int i : ans) cout << i << " ";
        cout << "}" << endl;
        return;
    }

    void Program::buildTree(vector<int>& tree, vector<int>& blockSums, int curr, int l, int r) {
        if (l == r) {
            tree[curr] = blockSums[l];
            return;
        }

        int mid = (l + r) / 2;
        int leftChild = curr*2, rightChild = curr*2+1;
        buildTree(tree, blockSums, leftChild, l, mid);
        buildTree(tree, blockSums, rightChild, mid+1, r);
        tree[curr] = max(tree[leftChild], tree[rightChild]);
    }

    int Program::query(vector<int>& tree, int curr, int ql, int qr, int l, int r) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[curr];

        int mid = (l + r) / 2;
        return max(query(tree, curr*2, ql, qr, l, mid), query(tree, curr*2+1, ql, qr, mid+1, r));
    }

    int Program::findLowestBlock(vector<int>& blockRight, int ql) {
        int low = 0, high = blockRight.size()-1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (blockRight[mid] >= ql)
                high = mid - 1;
            if (blockRight[mid] < ql)
                low = mid + 1;
        }

        return (blockRight[low] < ql) ? low+1 : low;
    }

    int Program::findHighestBlock(vector<int>& blockLeft, int qr) {
        int low = 0, high = blockLeft.size()-1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (blockLeft[mid] <= qr)
                low = mid + 1;
            if (blockLeft[mid] > qr)
                high = mid - 1;
        }

        return (blockLeft[low] > qr) ? low-1 : low;
    }

    vector<int> Program::maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> segments;
        vector<int> blockLeft;
        vector<int> blockRight;
        int numOnes = 0;
        for (int i=0; i<s.size(); ) {
            if (s[i] == '1') {
                numOnes++;
                i++;
                continue;
            }

            int start = i;
            while (s[i] == '0' && i<s.size()) i++;
            segments.push_back(i - start);
            blockLeft.push_back(start);
            blockRight.push_back(i - 1);
        }

        int n = segments.size();
        if (n < 2) return vector<int>(queries.size(), numOnes);

        vector<int> blockSums(n-1, 0);
        for (int i=0; i<n-1; i++)
            blockSums[i] = segments[i] + segments[i+1];
        

        vector<int> tree(4*n, 0);
        buildTree(tree, blockSums, 1, 0, blockSums.size()-1);
        
        prettyPrint(segments);
        prettyPrint(blockLeft);
        prettyPrint(blockRight);

        vector<int> ans(queries.size(), -1);
        for (int i=0; i<queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            int L = findLowestBlock(blockRight, l);
            int R = findHighestBlock(blockLeft, r);
            
            cout << "l = " << l << ", r = " << r << ", L = " << L << ", R = " << R << endl;

            if (L > n - 1 || R < 0 || L >= R) {
                ans[i] = numOnes;
                continue;
            }

            int blockOneZeros = blockRight[L] - max(blockLeft[L], l) + 1; 
            int blockTwoZeros = min(blockRight[R], r) - blockLeft[R] + 1;

            if (L + 1 == R) {
                ans[i] = (blockOneZeros + blockTwoZeros + numOnes);
                continue;
            }
            int case1 = blockOneZeros + segments[L + 1]; // LEFT END
            int case2 = segments[R - 1] + blockTwoZeros; // RIGHT END
            int case3 = query(tree, 1, L+1, R-2, 0, blockSums.size()-1); // CENTER
            
            cout << case1 << case2 << case3 << endl;
            int currAns = max({ case1, case2, case3 });
            ans[i] = currAns + numOnes;
        }

        prettyPrint(ans);
        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.maxActiveSectionsAfterTrade(s, queries);
    return 0;
}