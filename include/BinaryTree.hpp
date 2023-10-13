#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>

class TreeNode {
public:
    std::string data;
    TreeNode* left;
    TreeNode* right;
    bool boolean_result;

    // Constructor for TreeNode
    TreeNode(std::string value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    // Destructor for TreeNode
    ~TreeNode(){
        delete left;
        delete right;
    }
};

class BinaryTree {
    private:
        TreeNode* root_;
        std::string expression_;

    public:
        // Constructor for BinaryTree
        BinaryTree(const std::string& expression);

        // Builds a binary tree based on the given expression
        TreeNode* buildTree(const std::string expression, unsigned int index);

        // Evaluates a leaf node and sets its boolean result
        void nodeEvaluation(TreeNode* node);

        // Initiates the tree evaluation process and returns the result as a string
        std::string treeEvaluation(int start);

        // Recursive function for evaluating internal nodes of the tree
        void treeEvaluation(TreeNode* root, std::string& expression, unsigned int index);

        // Recursive destructor for releasing allocated memory
        void BinaryTreeDestructor(TreeNode* node);

        // Filters out unwanted characters from the expression
        void expFilter(std::string& expression);

        // Prints the tree
        void printTree(TreeNode* root);

        // Destructor for BinaryTree
        ~BinaryTree();
};

#endif
