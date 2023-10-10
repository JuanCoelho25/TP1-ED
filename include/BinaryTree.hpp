#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>


class TreeNode {
    public:
        std::string data;
        TreeNode* left;
        TreeNode* right;
        bool boolean_result;

        TreeNode(std::string value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinaryTree{
    public:
        TreeNode* root;

        BinaryTree();

        TreeNode* buildTree(const std::string& expression, unsigned int index);

        void nodeEvaluation(TreeNode* node);

        void treeEvaluation(TreeNode* root, std::string& expression, unsigned int index);
        
        void BinaryTreeDestructor(TreeNode* node);

        ~BinaryTree();




    

};
#endif