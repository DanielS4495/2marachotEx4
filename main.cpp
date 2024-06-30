#include "Tree.h"
#include "Complex.h"
#include <iostream>

int main() {
    Tree<int> intTree;
    intTree.add_root(1);
    intTree.add_sub_node(1, 2);
    intTree.add_sub_node(1, 3);
    intTree.add_sub_node(2, 4);
    intTree.add_sub_node(2, 5);
    intTree.add_sub_node(3, 6);

    std::cout << "Pre-Order Traversal: ";
    for (auto it = intTree.begin_pre_order(); it != intTree.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS Traversal: ";
    for (auto it = intTree.begin_bfs_scan(); it != intTree.end_bfs_scan(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Tree<Complex> complexTree;
    complexTree.add_root(Complex(1, 1));
    complexTree.add_sub_node(Complex(1, 1), Complex(2, 2));
    complexTree.add_sub_node(Complex(1, 1), Complex(3, 3));

    std::cout << "Complex Tree Pre-Order Traversal: ";
    for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
