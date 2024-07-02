/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "TreeNode.hpp"
#include "Tree.hpp"
#include <QApplication>
#include "complex.hpp"
// #include "TreeDrawingClass.hpp"
// #include <qwidget.h>
using namespace std;

// int main(int argc, char *argv[])
int main()
{
    QApplication *app = QApplicationManager::getInstance();

    // QApplication app(argc, argv);
    TreeNode<double> *root_node = new TreeNode(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    TreeNode<double> *n1 = new TreeNode(1.2);
    TreeNode<double> *n2 = new TreeNode(1.3);
    TreeNode<double> *n3 = new TreeNode(1.4);
    TreeNode<double> *n4 = new TreeNode(1.5);
    TreeNode<double> *n5 = new TreeNode(1.6);
    // TreeNode<double> *n6 = new TreeNode(1.7);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // cout << tree;
    // tree.add_sub_node(n2, n6);

    tree.myHeap();
    cout<<tree;
    // cout << tree;

     TreeNode<Complex> *root_node2 = new TreeNode(Complex(1.1,1.1));
    Tree<Complex> tree2; // Binary tree that contains doubles.
    tree2.add_root(root_node2);
    TreeNode<Complex> *n12 = new TreeNode(Complex(1.2,1.2));
    TreeNode<Complex> *n22 = new TreeNode(Complex(1.3,1.3));
    TreeNode<Complex> *n32 = new TreeNode(Complex(1.4,1.4));
    TreeNode<Complex> *n42 = new TreeNode(Complex(1.5,1.5));
    TreeNode<Complex> *n52 = new TreeNode(Complex(1.6,1.6));
    tree2.add_sub_node(root_node2, n12);
    tree2.add_sub_node(root_node2, n22);
    tree2.add_sub_node(n12, n32);
    tree2.add_sub_node(n12, n42);
    tree2.add_sub_node(n22, n52);
    cout<<tree2;

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
    //  */

   

    cout << "Pre-order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << *node << endl;
    }

    cout << "Post-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << *node << endl;
    }

    for (auto TreeNode = tree.begin_in_order(); TreeNode != tree.end_in_order(); ++TreeNode)
    {
        cout << *TreeNode << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    for (auto TreeNode = tree.begin_bfs_scan(); TreeNode != tree.end_bfs_scan(); ++TreeNode)
    {
        cout << *TreeNode<< endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    
    //     Tree<double,3> three_ary_tree; // 3-ary tree.
    //     three_ary_tree.add_root(root_node);
    //     three_ary_tree.add_sub_node(root_node, n1);
    //     three_ary_tree.add_sub_node(root_node, n2);
    //     three_ary_tree.add_sub_node(root_node, n3);
    //     three_ary_tree.add_sub_node(n1, n4);
    //     three_ary_tree.add_sub_node(n2, n5);
    //     // three_ary_tree.add_sub_node(n3, n6);
    // cout<<three_ary_tree;
    // three_ary_tree.print();
    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
   
    app->exec();

   
    return 0;

}
