#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP


struct CharPosition {
    char character;
    int position;
};

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

        void recursiveInsert(TreeNode<T>* &p, T expression) {
        // Count the number of occurrences of 'a' or 'e'
        int count = 0;
        for (char ch : expression) {
            if (ch == 'a' || ch == 'e') {
                count++;
            }
        }

        // Dynamically allocate the array of CharPosition
        CharPosition* charPositions = new CharPosition[count];

        // Populate the array with characters and their positions
        int indexCount = 0;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == 'a' || expression[i] == 'e') {
                charPositions[indexCount].character = expression[i];
                charPositions[indexCount].position = i;
                indexCount++;
            }
        }

        if (p == nullptr) {
            p = new TreeNode<T>();
            p->data = item; 
        } else {
            // Add your condition to check if all 'E' were used and replaced
            bool allEsUsed = true;
            for (int i = 0; i < count; i++) {
                if (charPositions[i].character == 'e' && !isEAlreadyUsedInTree(p, charPositions[i].position)) {
                    allEsUsed = false;
                    break;
                }
            }

            if (allEsUsed) {
                // All 'E' were used and replaced in the tree, implement your logic here
            } else {
                // Implement your logic when not all 'E' were used and replaced
            }
        }

        // Don't forget to free the dynamically allocated memory
        delete[] charPositions;
    }

        void Insert(T item){
            recursiveInsert(root, item);
        }


    

};
#endif