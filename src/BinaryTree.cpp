#include "../include/BinaryTree.hpp"
#include "../include/BooleanEvaluation.hpp"
#include "../include/Node.hpp"
#include <string>


BinaryTree::BinaryTree(const std::string& expression){
    root_ = this->buildTree(expression, 0);
    expression_ = expression;
}

void BinaryTree::nodeEvaluation(TreeNode* node){
    BooleanEvaluation avaliator;
    node->boolean_result = avaliator.evaluateExpression(node->data);
}


TreeNode* BinaryTree::buildTree(std::string expression, unsigned int index){
    TreeNode* root = new TreeNode(expression);

    for (unsigned int i = index; i < expression.length(); i++){
        if (expression[i] == 'e' || expression[i] == 'a') {
            std::string left = expression;
            left[i] = '0';
            root->left = buildTree(left, i + 1);

            std::string right = expression;
            right[i] = '1';
            root->right = buildTree(right, i + 1);
            

            break;
        }
    }
    return root;
}

std::string BinaryTree::treeEvaluation(int start = 0) {
    treeEvaluation(root_, expression_, start);
        if (root_->boolean_result == 0) {
            return "0";
        }
    expFilter(root_->data);
    return "1 " + root_->data;
}

void BinaryTree::treeEvaluation(TreeNode* root, std::string& expression, unsigned int index){
    if (root == nullptr) return;

    treeEvaluation(root->left, expression, index + 1);
    treeEvaluation(root->right, expression, index + 1);

    if (root->left == nullptr && root->right == nullptr) {
        nodeEvaluation(root);
        return;
    }

    if ((root->left->boolean_result == 1) && (root->right->boolean_result == 1)){
        for (unsigned int i = 0; i < root->data.length(); i++){
            if (root->right->data[i] != root->left->data[i]) {
                root->data[i] = 'a';
            }
            else {
                root->data[i] = root->left->data[i];
            }
        }
        root->boolean_result = 1;
    }

    else if ((root->left->boolean_result) || (root->right->boolean_result)){
        unsigned int position = index;
        while (position < root->data.length() && root->data[position] != 'e' && expression[position] != 'a') {
            position++;
        }
        if (root->data[position] == 'a'){
            root->boolean_result = 0;
            return;
        }
        std::string value;
        if (root->right->boolean_result) value = root->right->boolean_result;
        else {value = root->left->boolean_result;}
        for (unsigned int i = position; i < root->data.length(); i++) {
            if (root->data[i] == 'e') {
                root->data[i] = '1';
        }
    }
        root->data[position] = '1';
        root->boolean_result = 1;
    }
    
    else {
        root->boolean_result = 0;
        root->data[index] = '0';
    }
}

void BinaryTree::printTree(TreeNode* root) {
    if (root) {
        printTree(root->left);
        std::cout << root->data << " ";
        printTree(root->right);
    }
}


void BinaryTree::BinaryTreeDestructor(TreeNode* node){
    if(node == nullptr) return;

    BinaryTreeDestructor(node->left);
    BinaryTreeDestructor(node->right);
}

void BinaryTree::expFilter(std::string& expression){
    std::string input_str = expression;

    std::string filtered_str = "";

    for (char c : input_str) {
        if (c == 'a' || c == 'e' || c == '0' || c == '1') {
            filtered_str += c;
        }
    }
    expression = filtered_str;
}

BinaryTree::~BinaryTree(){
    BinaryTreeDestructor(root_);
}