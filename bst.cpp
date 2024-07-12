// Binary search tree basic examples
#include <iostream>
#include <utility>
#include <random>

template <typename T>
struct tree_node {
    T key;
    tree_node* left = nullptr, * right = nullptr;
};

template <typename T>
void tree_insert(tree_node<T>*& t, const T& key)
{
    if (t == nullptr) {
        t = new tree_node<T>{ key };
        return;
    }
    if (key < t->key) tree_insert(t->left, key);
    else tree_insert(t->right, key);
}

template <typename T>
void tree_inorder_traversal(const tree_node<T>* t)
{
    if (t == nullptr) return;
    tree_inorder_traversal(t->left);
    std::cout << t->key << '\n';
    tree_inorder_traversal(t->right);
}

template <typename T>
int tree_height(const tree_node<T>* t) {
    if (t == nullptr) return -1;
    int left_height = tree_height(t->left);
    int right_height = tree_height(t->right);
    return 1 + std::max(left_height, right_height);
}

template <typename T>
int tree_size(const tree_node<T>* t) {
    if (t == nullptr) return 0;
    return 1 + tree_size(t->left) + tree_size(t->right);
}
template <typename T>
bool tree_search(const tree_node<T>* t, const T& key) {
    if (t == nullptr) return false;
    if (t->key == key) return true;
    return tree_search(t->left, key) and tree_search(t->right, key);
}
/*
int main()
{
    tree_node<int>* my_tree = nullptr; // empty tree

    // insert random data into the tree
    for (auto n : { 5, 3, 7, 20, 10, 8, 4, 1 }) {
        tree_insert(my_tree, n);
    }
    tree_inorder_traversal(my_tree);

    std::cout << "\nThis height of the tree is: " << tree_height(my_tree) << std::endl;
    std::cout << "The size of the tree is: " << tree_size(my_tree) << std::endl;

    int search_key = 11;
    if (tree_search(my_tree, search_key)) 
         std::cout << "The key '" << search_key << "' is in the tree" << std::endl;
    else std::cout << "The key '" << search_key << "' is not in the tree" << std::endl;
}
*/