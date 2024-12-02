// Leetcode 105
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> preorder { 3, 9, 20, 15, 7 };
static vector<int> inorder { 9, 3, 15, 20, 7 };

namespace Solution {
    class TreeNode {
        public:
            int val;
            TreeNode* left;
            TreeNode* right;

            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    class Tree {
        private:
            TreeNode* root;
            bool vecContains(int val, vector<TreeNode*>& branch);
            TreeNode* retNode(int val, vector<TreeNode*>& branch);
            void inorderDelete(TreeNode* root);
        public:
            TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
            Tree() : root(NULL) {}
            ~Tree() {
                inorderDelete(this->root);
                this->root = NULL;
            }
    };

    TreeNode* Tree::buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->root = new TreeNode(preorder[0]);
        int countLeft = 0;

        // Find the root in inorder traversal
        vector<int>::iterator rootIter;
        for (vector<int>::iterator it=inorder.begin(); it!=inorder.end(); it++) {
            if ((this->root->val) == *it) {
                rootIter = it;
                break;
            }
            countLeft++;
        }

        // Left Subtree, Build the leftmost subbranch
        vector<TreeNode*> subtree;
        TreeNode* nodePtr = this->root;
        int i=1;
        for (; i<=countLeft; i++) {
            nodePtr->left = new TreeNode(preorder[i]);
            nodePtr = nodePtr->left;
            subtree.push_back(nodePtr->left);
            if (preorder[i] == inorder[0])
                continue;
        }

        // Right Subtree, Right Branches
        nodePtr = this->root;
        for (; i<=countLeft; i++) {
            for (vector<int>::iterator it=inorder.begin(); it!=rootIter; it++) {
                if (*it+1 == preorder[i]) {
                    retNode(*it, subtree)->right = new TreeNode(preorder[i]);
                    break;
                }
            }
        }
        subtree.clear();

        // Right Subtree, Left Branches
        this->root->right = new TreeNode(preorder[i++]);
        subtree.push_back(this->root->right);
        nodePtr = this->root->right;
        for( ;i<preorder.size(); i++){
            nodePtr->left = new TreeNode(preorder[i]);
            subtree.push_back(nodePtr->left);
            nodePtr=nodePtr->left;
            if (*(rootIter+1) == preorder[i]) break;
        }

        // Right Subtree, right branches
        for (vector<int>::iterator it=rootIter+1; it!=inorder.end(); it++) {
            if (!vecContains(*it, subtree)) retNode(*(it-1), subtree)->right = new TreeNode(*it);
        }
        return this->root;
    }

    bool Tree::vecContains(int val, vector<TreeNode*>& branch) {
        for (vector<TreeNode*>::iterator it=branch.begin(); it!=branch.end(); it++)
            if (val == (*it)->val) return true;
        return false;
    }

    TreeNode* Tree::retNode(int val, vector<TreeNode*>& branch) {
        for(TreeNode* ptr : branch)
            if (ptr->val == val) return ptr;
        return NULL;
    }

    void Tree::inorderDelete(TreeNode* root) {
        if(root->left != NULL) inorderDelete(root->left);
        if(root->right != NULL) inorderDelete(root->right);
        delete root;
        return;
    }


}

int main() {
    using namespace Solution;
    Tree* bt = new Tree();
    bt->buildTree(preorder, inorder);
    delete bt;
    return 0;
}