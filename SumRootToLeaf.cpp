// LeetCode 1022
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using std::cout, std::endl, std::vector, std::queue, std::string;

static vector<int> treeLayout { 1, 0, 1, 0, 1, 0, 1 };

namespace Solution {
    class TreeNode {
        public:
            int val;
            TreeNode* left;
            TreeNode* right;

            TreeNode(): val(0), left(NULL), right(NULL) {}
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
            TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}

    };

    class Program {
        private:
            static void prettyPrint(TreeNode* root);
        public:
            TreeNode* root;

            Program(): root(NULL) {}
            ~Program();

            int sumRootToLeaf(TreeNode* root);
            void getAllPaths(string path, TreeNode* curr, vector<int>& paths);
            int getPathSum(string path);
            TreeNode* createTree(vector<int>& treeLayout);
            void freeTree();
    };

    Program::~Program() {
        freeTree();
    }

    void Program::prettyPrint(TreeNode* root) {
        queue<TreeNode*> bfsQ;
        bfsQ.push(root);

        cout << "Tree: { ";
        while(!bfsQ.empty()) {
            TreeNode* curr = bfsQ.front();
            if (curr->left != NULL) bfsQ.push(curr->left);
            if (curr->right != NULL) bfsQ.push(curr->right);
            cout << curr->val << " ";
            bfsQ.pop();
        }
        cout << "} \n" << endl;
        return;
    }

    int Program::sumRootToLeaf(TreeNode* root) {
        vector<int> pathNums;
        getAllPaths("", root, pathNums);

        int sum=0;
        for (int i : pathNums) sum += i;
        return sum;
    }

    void Program::getAllPaths(string path, TreeNode* curr, vector<int>& pathNums) {
        string newPath = path + std::to_string(curr->val);
        if (curr->left != NULL) getAllPaths(newPath, curr->left, pathNums);
        if (curr->right != NULL) getAllPaths(newPath, curr->right, pathNums);

        if (curr->left == NULL && curr->right == NULL) pathNums.push_back(getPathSum(newPath));
        return;
    }

    int Program::getPathSum(string path) {
        int sum=0, multiplier = 1;
        for (string::reverse_iterator itr = path.rbegin(); itr != path.rend(); itr++, multiplier*=2) {
            if (*itr == '0') continue;
            sum += multiplier;
        }

        return sum;
    }

    TreeNode* Program::createTree(vector<int>& treeLayout) {
        TreeNode* root = new TreeNode(treeLayout[0]);
        queue<TreeNode*> bfsQ;
        bfsQ.push(root);
        
        size_t i=1, length = treeLayout.size();
        while(!bfsQ.empty() && i < length) {
            TreeNode* curr = bfsQ.front();
            curr->left = new TreeNode(treeLayout[i++]);
            bfsQ.push(curr->left);
            if (i >= length) break;
            curr->right = new TreeNode(treeLayout[i++]);
            bfsQ.push(curr->right);
            bfsQ.pop();
        }

        this->root = root;
        prettyPrint(root);
        return root;
    }

    void Program::freeTree() {
        if (root == NULL) return;
        cout << "free tree" << endl;
        queue<TreeNode*> bfsQ;
        bfsQ.push(root);

        while(!bfsQ.empty()) {
            TreeNode* curr = bfsQ.front();
            if (curr->left != NULL) bfsQ.push(curr->left);
            if (curr->right != NULL) bfsQ.push(curr->right);
            delete curr;
            bfsQ.pop();
        }
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    TreeNode* root = obj.createTree(treeLayout);
    cout << obj.sumRootToLeaf(root) << endl;
    return 0;
}
