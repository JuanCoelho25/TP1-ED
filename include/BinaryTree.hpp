#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

template <typename T>

class TreeNode {
    private:
        T data;
        TreeNode* left;
        TreeNode* right;

    friend class BinaryTree<T>;

    public:
        TreeNode(T value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

template <typename T>
class BinaryTree{
    private:
        TreeNode <T>* root;

    public:
        BinaryTree() : root(nullptr) {}

        void recursiveInsert(TreeNode<T>* &p, T item){
            if(p == nullptr){
                p = new TreeNode <T> ();
                p->data = item;
            }
            else{
                if(root->data < p->data){
                    recursiveInsert(p->left, item);
                }
                else{
                    recursiveInsert(p->right, item);
                }
            }
        }

        void Insert(T item){
            recursiveInsert(root, item);
        }


    

};
#endif