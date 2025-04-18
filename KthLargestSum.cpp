#include <iostream>
#include <vector>

using std::cout,std::cin,std::endl;
using std::vector;

namespace Solution {
    class Node{
          public:
            int id;
            Node* left;
            Node* right;
            int level;
            Node (int val = (int) NULL) {
                this->id = val;
                this->left = NULL;
                this->right = NULL;
                this->level = 0;
            }
    };
    
    class BST {
        private:
            vector<int>::iterator findMax();

        public:
            Node* root;
            vector<Node*> nums;
            vector<int> list;
            int maxLevel;
            void readBST(Node* root);
            void destroyBST(Node* root);
            void createBST();
            int kthLargestSum(int k);
            void insertNums(Node* root, int level);

            BST() {
                this->root = NULL;
            }
    };

    int BST::kthLargestSum(int k) {
        int sum=0;

        // Get All Sums from kth level
        for (int i=0; i<maxLevel+1; i++) {
            this->insertNums(this->root, i);
            for (vector<Node*>::iterator it=this->nums.begin(); it!=this->nums.end(); it++) sum += (*it)->id;
            list.push_back(sum);
            sum=0;
            nums.clear();
        }

        // Erase Max from list, up until the kth largest
        for (int i=k-1; i>0; i--) list.erase(this->findMax());
        return *(this->findMax());
    }

    vector<int>::iterator BST::findMax() {
        vector<int>::iterator max = this->list.begin();
        for(vector<int>::iterator it=this->list.begin()+1; it!=this->list.end(); it++)
            if(*max < *it) max = it;
        return max;
    }

    void BST::insertNums(Node* root,int level) {
        if (root->level == level) {
            this->nums.push_back(root);
            return;
        }
        if (root->left != NULL) insertNums(root->left, level);
        if (root->right != NULL) insertNums(root->right, level);
    }

    // Test Suite
    void BST::createBST() { 
        // level 0
        this->root = new Node(5);
        this->root->level = 0;

        // level 1
        this->root->left = new Node(8);
        this->root->right = new Node(9);
        this->root->left->level = 1;
        this->root->right->level = 1;

        // level 2
        this->root->left->left = new Node(2);
        this->root->left->right = new Node(1);
        this->root->right->left = new Node(3);
        this->root->right->right = new Node(7);
        this->root->left->left->level = 2;
        this->root->left->right->level = 2;
        this->root->right->left->level = 2;
        this->root->right->right->level = 2;

        // level 3
        this->root->left->left->left = new Node(4);
        this->root->left->left->right = new Node(6);
        this->root->left->left->left->level = 3;
        this->root->left->left->right->level = 3;
        this->maxLevel = 3;
        return;
    }

    void BST::readBST(Node* root) {
        if (root->left != NULL) this->readBST(root->left);
        if (root->right != NULL) this->readBST(root->right);
        cout << root->id << " ";
        return;
    }

    void BST::destroyBST(Node* root) {
        if (root->left != NULL) this->destroyBST(root->left);
        if (root->right != NULL) this->destroyBST(root->right);
        delete root;
    }
}

int main() {
    using namespace Solution;
    BST* obj = new BST();
    obj->createBST();
    obj->readBST(obj->root);
    cout << endl;
    cout << obj->kthLargestSum(2);
    obj->destroyBST(obj->root);
    delete obj;
    return 0;
}