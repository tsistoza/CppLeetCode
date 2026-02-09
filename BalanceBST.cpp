// LeetCode 1382
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::cout, std::endl, std::vector, std::queue;
using std::sort;

static vector<int> ref { 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, 4 };
static vector<int> ref2 { 2, 1, 3 };

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(NULL), right(NULL) {}
        TreeNode(int x): val(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode* _left, TreeNode* _right): val(x), left(_left), right(_right) {}
};

int leftChild(int index) { return 2*index + 1; }
int rightChild(int index) { return 2*index + 2; }
int parent(int index) { return (index-1)/2; }

namespace Solution {
    class Compare {
        public:
            bool operator()(TreeNode* a, TreeNode* b) const { return a->val < b->val; }
    };

    class Program {
        private:
            void setChildren(TreeNode* parent, vector<int>& ref, int index);
            void dfs(vector<TreeNode*>& list, TreeNode* ptr);
            TreeNode* split(int start, int end, vector<TreeNode*>& list);
        public:
            TreeNode* root;

            TreeNode* balanceBST(TreeNode* root);
            void prettyPrintTree();
            void initRoot(vector<int>& ref);
            void freeTree();
    };

    TreeNode* Program::balanceBST(TreeNode* root) {
        vector<TreeNode*> list;
        dfs(list, root);

        Compare cmp;
        sort(list.begin(), list.end(), cmp);

        this->root = split(0, list.size()-1, list);
        return this->root;
    }

    void Program::dfs(vector<TreeNode*>& list, TreeNode* ptr) {
        if (ptr != NULL)
            list.push_back(ptr);
        
        if (ptr->left != NULL)
            dfs(list, ptr->left);
        if (ptr->right != NULL)
            dfs(list, ptr->right);
        return;
    }

    TreeNode* Program::split(int start, int end, vector<TreeNode*>& list) {
        if (start == end) {
            list[start]->left = NULL;
            list[start]->right = NULL;
            return list[start];
        }
        if (start > end) return NULL;

        int mid = start + ((end-start)/2);
        TreeNode* root = list[mid];

        root->left = split(start, mid-1, list);
        root->right = split(mid+1, end, list);
        return root;
    }

    void Program::initRoot(vector<int>& ref) {
        this->root = new TreeNode(ref[0]);
        setChildren(this->root, ref, 0);
        return;
    }

    void Program::setChildren(TreeNode* parent, vector<int>& ref, int index) {
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if (leftIndex < ref.size())
            parent->left = (ref[leftIndex] != -1) ? new TreeNode(ref[leftIndex]) : NULL;
        if (rightIndex < ref.size())
            parent->right = (ref[rightIndex] != -1) ? new TreeNode(ref[rightIndex]) : NULL;
        
        if (parent->left != NULL) 
            setChildren(parent->left, ref, leftIndex);
        if (parent->right != NULL)
            setChildren(parent->right, ref, rightIndex);
        return;
    }

    void Program::prettyPrintTree() {
        queue<TreeNode*> treeQ;
        treeQ.push(this->root);
        cout << "Current Tree: { ";
        while (!treeQ.empty()) {
            TreeNode* ptr = treeQ.front();
            
            if (ptr == NULL) cout << "NULL, ";
            else cout << ptr->val << ", ";

            if (ptr != NULL) {
                treeQ.push(ptr->left);
                treeQ.push(ptr->right);
            }

            treeQ.pop();
        }
        cout << "}" << endl;
        return;
    }

    void Program::freeTree() {
        queue<TreeNode*> treeQ;
        treeQ.push(this->root);
        while (!treeQ.empty()) {
            TreeNode* ptr = treeQ.front();

            if (ptr->left != NULL)
                treeQ.push(ptr->left);
            if (ptr->right != NULL)
                treeQ.push(ptr->right);

            treeQ.pop();
            delete ptr;
        }
        return;
    }
};

int main() {
    using namespace Solution;
    Program obj;

    obj.initRoot(ref);
    obj.prettyPrintTree();
    obj.balanceBST(obj.root);
    obj.prettyPrintTree();
    obj.freeTree();

    obj.initRoot(ref2);
    obj.prettyPrintTree();
    obj.balanceBST(obj.root);
    obj.prettyPrintTree();
    obj.freeTree();
    return 0;
}