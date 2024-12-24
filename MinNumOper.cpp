// LeetCode 2471
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::queue, std::pair, std::sort;

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
        private:
            void deleteTree();
        public:
            TreeNode* root;

            void createTree1();
            void createTree2();
            BinaryTree() : root(NULL) {}
            ~BinaryTree() {
                deleteTree();
            }
    };

    class Program {
        private:
            void countSwaps(vector<int>& sortedNodes, vector<TreeNode*>& nodes, int& countSwaps );
        public:
            int minimumOperations(TreeNode* root);
    };

    void BinaryTree::deleteTree() {
        vector<TreeNode*> nodes;
        queue<TreeNode*> queue;
        queue.push(this->root);
        while (!queue.empty()) {
            TreeNode* top = queue.front();
            nodes.push_back(top);
            queue.pop();
            if (top->left != NULL) queue.push(top->left);
            if (top->right != NULL) queue.push(top->right);
        }
        for (TreeNode* ptr : nodes)
            delete ptr;
        return;
    }

    void BinaryTree::createTree1() {
        // level 0
        this->root = new TreeNode(1);
        TreeNode* ptr = this->root;
        // level 1
        ptr->left = new TreeNode(4);
        ptr->right = new TreeNode(3);
        // level 2 
        TreeNode* ptrLeft = ptr->left;
        ptrLeft->left = new TreeNode(7);
        ptrLeft->right = new TreeNode(6);
        TreeNode* ptrRight = ptr->right;
        ptrRight->left = new TreeNode(8);
        ptrRight->right = new TreeNode(5);
        // level 3
        ptr = ptrRight->left;
        ptr->left = new TreeNode(9);
        ptr = ptrRight->right;
        ptr->left = new TreeNode(10);
        return;
    }

    void BinaryTree::createTree2() {
        // level 0
        this->root = new TreeNode(1);
        TreeNode* ptr = this->root;
        // level 1
        ptr->left = new TreeNode(3);
        ptr->right = new TreeNode(2);
        // level 2
        TreeNode* ptrLeft = ptr->left;
        ptrLeft->left = new TreeNode(7);
        ptrLeft->right = new TreeNode(6);
        TreeNode* ptrRight = ptr->right;
        ptrRight->left = new TreeNode(5);
        ptrRight->right = new TreeNode(4);
        return;
    }

    void Program::countSwaps(vector<int>& sortedNodes, vector<TreeNode*>& nodes, int& countSwaps) {
        if (nodes.size() == 1) return;
        for (int i=0; i<sortedNodes.size(); i++) {
            for (int j=0 ;j<nodes.size(); j++) {
                if (sortedNodes[i] == nodes[j]->val && i != j) {
                    int temp = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = temp;
                    countSwaps++;
                    break;
                }
            }
        }
        return;
    }

    int Program::minimumOperations(TreeNode* root) {
        int swaps = 0;
        queue<pair<TreeNode*, int>> levelTraversal;
        levelTraversal.push(pair<TreeNode*, int> (root, 0));
        vector<TreeNode*> nodes;
        vector<int> sortedNodes;
        int level = 0;

        while (!levelTraversal.empty()) {
            pair<TreeNode*, int> top = levelTraversal.front();
            if (level < top.second) {
                sort(sortedNodes.begin(), sortedNodes.end());
                countSwaps(sortedNodes, nodes, swaps);
                level = top.second;
                sortedNodes.clear();
                nodes.clear();
            }

            nodes.push_back(top.first);
            sortedNodes.push_back(top.first->val);
            levelTraversal.pop();
            if (top.first->left != NULL) levelTraversal.push(pair<TreeNode*, int> (top.first->left, top.second+1));
            if (top.first->right != NULL) levelTraversal.push(pair<TreeNode*, int> (top.first->right, top.second+1));
        }

        if (nodes.size() > 1) {
            sort(sortedNodes.begin(), sortedNodes.end());
            countSwaps(sortedNodes, nodes, swaps);
        }
        return swaps;
    }

}

int main() {
    using namespace Solution;
    Program obj;
    BinaryTree* bt = new BinaryTree();
    bt->createTree1();
    cout << obj.minimumOperations(bt->root) << endl;
    delete bt;

    BinaryTree* bt1 = new BinaryTree();
    bt1->createTree2();
    cout << obj.minimumOperations(bt1->root) << endl;
    delete bt1;
}


