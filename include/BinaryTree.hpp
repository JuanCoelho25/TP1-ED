#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>


class TreeNode {
    public:
        std::string data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(char value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinaryTree{
    public:
        TreeNode* root;

        BinaryTree() : root(nullptr) {}

        TreeNode* buildTree(const std::string& expression, size_t pos = 0){
            if (pos >= expression.size()) {
                return nullptr;
            }

            TreeNode* root = new TreeNode(expression[pos]);

            if (expression[pos] == 'a' || expression[pos] == 'e') {
                // If the variable is 'a' or 'e', create two children nodes with '0' and '1'
                root->left = buildTree(expression, pos + 1);
                root->left->data = '0';

                root->right = buildTree(expression, pos + 1);
                root->right->data = '1';
            }

            return root;
        }



    

};
#endif