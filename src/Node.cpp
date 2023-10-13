#include "../include/Node.hpp"
#include "../include/Stack.hpp"

template <typename T>
StackNode<T>::StackNode(T n){
			this->data = n;
			this->link = NULL;
		}

TreeNode::TreeNode(std::string value){
        data = value;
        left = nullptr;
        right = nullptr;
    }

TreeNode::~TreeNode(){
        delete left;
        delete right;
    }

template class StackNode<char>;
template class StackNode<bool>;
