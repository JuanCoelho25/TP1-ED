#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

template <typename T>

class TreeNode {
    private:
        T data;
        TreeNode* left;
        TreeNode* right;

    friend class BinaryTree;

    public:
        TreeNode(T value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinaryTree{
    
    BinaryTree(){
        TreeNode* root = nullptr;
    }

    

};
#endif