// LeetCode 1261
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl, std::vector;
using std::queue;

static vector<int> tree1 { -1, INT_MIN, -1 };
static vector<int> tree2 { -1, -1, -1, -1, -1 };
static vector<int> tree3 { -1, INT_MIN, -1, -1, INT_MIN, -1 };

namespace Solution {
    class TreeNode {
        public:
            int val;
            TreeNode* left;
            TreeNode* right;

            TreeNode() : val(0), left(NULL), right(NULL) {}
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class BinaryTree {
        public:
            TreeNode* root;

            TreeNode* insertLevelOrder(vector<int>& arr, int i, int n);
            void createTree(vector<int>& arr);
            void levelTraversal();
            ~BinaryTree();
            BinaryTree() : root(NULL) {}
    };

    class FindElements {
        private:
            TreeNode* root;
            bool levelOrderTraversal(TreeNode* ptr, int target);
            void recoverTree(TreeNode* ptr);
        public:
            bool find(int target);
            FindElements(TreeNode* root) {
                root->val = 0;
                recoverTree(root);
                this->root = root;
            }
    };

    TreeNode* BinaryTree::insertLevelOrder(vector<int>& arr, int i, int n) {
        TreeNode* newNode = NULL;
        if (i < n) {
            if (arr[i] == INT_MIN) return NULL;
            newNode = new TreeNode(arr[i]);

            newNode->left = insertLevelOrder(arr, (2*i)+1, n);
            newNode->right = insertLevelOrder(arr, (2*i)+2, n);
        }
        return newNode;
    }
    
    void BinaryTree::createTree(vector<int>& arr) {
        this->root = insertLevelOrder(arr, 0, arr.size());
        return;
    }

    void BinaryTree::levelTraversal() {
        queue<TreeNode*> levelQ;
        levelQ.push(root);
        while(!levelQ.empty()) {
            TreeNode* ptr = levelQ.front();
            cout << ptr->val << endl;
            levelQ.pop();
            if (ptr->left != NULL) levelQ.push(ptr->left);
            if (ptr->right != NULL) levelQ.push(ptr->right);
        }
        return;
    }

    BinaryTree::~BinaryTree() {
        queue<TreeNode*> levelQ;
        levelQ.push(this->root);
        while(!levelQ.empty()) {
            TreeNode* ptr = levelQ.front();
            if (ptr->left != NULL) levelQ.push(ptr->left);
            if (ptr->right != NULL) levelQ.push(ptr->right);
            levelQ.pop();
            delete ptr;
        }
    }

    void FindElements::recoverTree(TreeNode* ptr) {
        if (ptr->left != NULL) {
            ptr->left->val = (2 * ptr->val) + 1;
            recoverTree(ptr->left);
        }

        if (ptr->right != NULL) {
            ptr->right->val = (2 * ptr->val) + 2;
            recoverTree(ptr->right);
        }
        return;
    }

    bool FindElements::find(int target) {
        queue<TreeNode*> levelQ;
        levelQ.push(this->root);
        while (!levelQ.empty()) {
            TreeNode* ptr = levelQ.front();
            if (target == ptr->val) {
                while(!levelQ.empty()) levelQ.pop();
                return true;
            }
            levelQ.pop();

            if (ptr->left != NULL) levelQ.push(ptr->left);
            if (ptr->right != NULL) levelQ.push(ptr->right);
        }
        return false;
    }
}

int main() {
    using namespace Solution;
    BinaryTree* bt = new BinaryTree();
    bt->createTree(tree1);
    
    FindElements* findElements = new FindElements(bt->root);
    cout << findElements->find(1) << endl;
    cout << findElements->find(2) << endl;
    cout << endl;
    delete bt;
    delete findElements;

    bt = new BinaryTree();
    bt->createTree(tree2);

    findElements = new FindElements(bt->root);
    cout << findElements->find(1) << endl;
    cout << findElements->find(3) << endl;
    cout << findElements->find(5) << endl;
    cout << endl;
    delete bt;
    delete findElements;

    bt = new BinaryTree();
    bt->createTree(tree3);

    findElements = new FindElements(bt->root);
    cout << findElements->find(2) << endl;
    cout << findElements->find(3) << endl;
    cout << findElements->find(4) << endl;
    cout << findElements->find(5) << endl;
    cout << endl;
    delete bt;
    delete findElements;
    return 0;
}