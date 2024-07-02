//danielsamson10@gmail.com
//211358486
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"

TEST_CASE("making nodes")
{
    Node<double> root_node = Node<double>(1.1);
    CHECK(root_node.get_data() == 1.1);
    Tree<double> tree;
    tree.add_root(&root_node);
    CHECK(tree.getRoot() == &root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    CHECK(n1.get_data() == 1.2);
    
}

TEST_CASE("bfs scan")
{
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    auto it = tree.begin_bfs_scan();
    CHECK(*it == 1.1);
    ++it;
    CHECK(*it == 1.2);
    ++it;
    CHECK(*it == 1.3);
    ++it;
    CHECK(*it == 1.4);
    ++it;
    CHECK(*it == 1.5);
    ++it;
    CHECK(*it == 1.6);
    ++it;
}

TEST_CASE("dfs scan")
{
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    auto it = tree.begin_dfs_scan();
    CHECK(*it == 1.1);
    ++it;
    CHECK(*it == 1.2);
    ++it;
    CHECK(*it == 1.4);
    ++it;
    CHECK(*it == 1.5);
    ++it;
    CHECK(*it == 1.3);
    ++it;
    CHECK(*it == 1.6);
    ++it;
}

TEST_CASE("pre order"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    auto it = tree.begin_pre_order();
    CHECK(*it == 1.1);
    ++it;
    CHECK(*it == 1.2);
    ++it;
    CHECK(*it == 1.3);
    ++it;
    CHECK(*it == 1.4);
    ++it;
    CHECK(*it == 1.5);
    ++it;
    CHECK(*it == 1.6);
    ++it;
}

TEST_CASE("post order"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    auto it = tree.begin_post_order();
    CHECK(*it == 1.4);
    ++it;
    CHECK(*it == 1.5);
    ++it;
    CHECK(*it == 1.2);
    ++it;
    CHECK(*it == 1.6);
    ++it;
    CHECK(*it == 1.3);
    ++it;
    CHECK(*it == 1.1);
    ++it;



}

TEST_CASE("children addition"){
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    CHECK(root_node.get_children().size() == 2);
    CHECK(n1.get_children().size() == 2);
    CHECK(n2.get_children().size() == 1);
    CHECK(n3.get_children().size() == 0);
    CHECK(n4.get_children().size() == 0);
    CHECK(n5.get_children().size() == 0);

    CHECK_THROWS(tree.add_sub_node(root_node, n3));
}

TEST_CASE("heap"){
    Node<double> root_node = Node<double>(1.9);
    Tree<double> tree;
    tree.add_root(&root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.1);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    auto it = tree.begin_heap();
    CHECK(*it == 1.1);
}