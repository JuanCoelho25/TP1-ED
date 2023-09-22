#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

template <typename T>

class TreeNode {
    private:
        T data;
        TreeNode* left;
        TreeNode* right;

    public:
        TreeNode(T value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

#endif