// LeetCode 865
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cout, std::endl, std::vector, std::queue;
using std::max;

static vector<int> nodes { 0, 1, 3, -1, 2 }; // -1 denote a NULL

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

class BinaryTree {
    private:
        TreeNode* createTree(vector<int>& nodes, int index);
        void levelTraversal(TreeNode* root);
    public:
        TreeNode* root;

        BinaryTree(vector<int>& _nodes) { this->root = this->createTree(_nodes, 0); this->levelTraversal(this->root); }
        ~BinaryTree();
};

TreeNode* BinaryTree::createTree(vector<int>& nodes, int index) {
    TreeNode* ptr = NULL;

    if (index >= nodes.size()) return NULL;
    if (index < nodes.size() && nodes[index] != -1) ptr = new TreeNode(nodes[index]);

    if (ptr != NULL) {
        ptr->left = this->createTree(nodes, 2*index + 1);
        ptr->right = this->createTree(nodes, 2*index + 2);
    }
    
    return ptr;
}

void BinaryTree::levelTraversal(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> levelQ;
    levelQ.push(this->root);
    
    while(!levelQ.empty()) {
        TreeNode* curr = levelQ.front();
        levelQ.pop();

        if (curr->left != NULL) levelQ.push(curr->left);
        if (curr->right != NULL) levelQ.push(curr->right);
        cout << curr->val << " ";
    }
    cout << endl;
}

BinaryTree::~BinaryTree() {
    cout << "Delete Binary Tree" << endl;
    queue<TreeNode*> levelQ;
    levelQ.push(this->root);
    
    while(!levelQ.empty()) {
        TreeNode* curr = levelQ.front();
        levelQ.pop();

        if (curr->left != NULL) levelQ.push(curr->left);
        if (curr->right != NULL) levelQ.push(curr->right);
        delete curr;
    }
}

namespace Solution {
    class Program{
        private:
            void findMaxDepth(TreeNode* curr, int currDepth, int& maxDepth);
            TreeNode* findSubtree(TreeNode* curr, int currDepth, int maxDepth);
        public:
            TreeNode* subtreeWithAllDeepest(TreeNode* root);
    };

    void Program::findMaxDepth(TreeNode* curr, int currDepth, int& maxDepth) {
        maxDepth = max(maxDepth, currDepth);

        if (curr->left != NULL) findMaxDepth(curr->left, currDepth+1, maxDepth);
        if (curr->right != NULL) findMaxDepth(curr->right, currDepth+1, maxDepth);

        return;
    }

    TreeNode* Program::findSubtree(TreeNode* curr, int currDepth, int maxDepth) {
        if (currDepth == maxDepth-1) {
            if (curr->left != NULL && curr->right != NULL) return curr;
            if (curr->left == NULL && curr->right != NULL) return curr->right;
            if (curr->left != NULL && curr->right == NULL) return curr->left;
            return NULL;
        }

        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if (curr->left != NULL) left = findSubtree(curr->left, currDepth+1, maxDepth);
        if (curr->right != NULL) right = findSubtree(curr->right, currDepth+1, maxDepth);

        if (left != NULL && right == NULL) return left;
        if (left == NULL && right != NULL) return right;
        if (left == NULL && right == NULL) return NULL;
        return curr;
    }

    TreeNode* Program::subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = 0;
        this->findMaxDepth(root, 0, maxDepth);

        if (root == NULL || (root->left == NULL && root->right == NULL)) return root;

        return findSubtree(root, 0, maxDepth);
    }
}

int main() {
    using namespace Solution;
    BinaryTree* bt = new BinaryTree(nodes);

    Program obj;
    cout << obj.subtreeWithAllDeepest(bt->root)->val << endl;
    delete bt;
    return 0;    
}