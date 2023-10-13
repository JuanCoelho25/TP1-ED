#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <string>
#include "../include/Node.hpp"

/**
 * @brief Represents a binary tree for evaluating boolean expressions.
 *
 * The BinaryTree class builds and evaluates a binary tree based on a boolean expression.
 * It supports operations such as building the tree, evaluating nodes, initiating the
 * tree evaluation process, and printing the tree. The tree nodes are instances of the
 * TreeNode class.
 */
class BinaryTree {
private:
    TreeNode* root_;        
    std::string expression_; 

public:
    /**
     * @brief Constructor: Initializes a binary tree with a given boolean expression.
     *
     * @param expression The boolean expression used to build the tree.
     */
    BinaryTree(const std::string& expression);

    /**
     * @brief Builds a binary tree based on the given expression.
     *
     * @param expression The boolean expression to build the tree from.
     * @param index The current index in the expression during the recursive build.
     * @return A pointer to the root of the built binary tree.
     */
    TreeNode* buildTree(const std::string expression, unsigned int index);

    /**
     * @brief Evaluates a leaf node and sets its boolean result.
     *
     * @param node The TreeNode representing a leaf node to be evaluated.
     */
    void nodeEvaluation(TreeNode* node);

    /**
     * @brief Initiates the tree evaluation process and returns the result as a string.
     *
     * @param start The starting index for tree evaluation.
     * @return The result of the tree evaluation as a string.
     */
    std::string treeEvaluation(int start);

    /**
     * @brief Recursive function for evaluating internal nodes of the tree.
     *
     * @param root The root of the subtree to be evaluated.
     * @param expression The boolean expression.
     * @param index The current index in the expression during recursive evaluation.
     */
    void treeEvaluation(TreeNode* root, std::string& expression, unsigned int index);

    /**
     * @brief Recursive destructor for releasing allocated memory.
     *
     * @param node The root of the subtree to be destructed.
     */
    void BinaryTreeDestructor(TreeNode* node);

    /**
     * @brief Filters out unwanted characters from the expression.
     *
     * @param expression The boolean expression to be filtered.
     */
    void expFilter(std::string& expression);

    /**
     * @brief Prints the tree.
     *
     * @param root The root of the tree to be printed.
     */
    void printTree(TreeNode* root);

    /**
     * @brief Destructor for BinaryTree.
     */
    ~BinaryTree();
};

#endif
