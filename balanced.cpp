#include <cmath>
#include <iostream>
#include <random>
#include "tree_node.hpp"

/*
int main(){

    std::mt19937 e;
    std::uniform_int_distribution<int> u;

    tree_node<int>* my_tree = nullptr;
    const int num_insertions = 100000;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j < num_insertions * i; ++j) {
            tree_insert(my_tree, u(e));
        }

        int tree_size = num_insertions * i;
        double ratio = static_cast<double>(tree_height(my_tree)) / log(tree_size);

        std::cout << "n: " << tree_size << "\theight: " << tree_height(my_tree) << "\tconstant: " << ratio << std::endl;
    }
}
*/
