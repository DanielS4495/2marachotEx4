//danielsamson10@gmail.com
//211358486
#pragma once
#include "TreeDrawingClass.hpp"
#include "TreeNode.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
class Iterator;

class QApplicationManager
{
private:
    QApplicationManager() = default; // Private constructor to prevent instantiation
    static QApplication *app;

public:
    static QApplication *getInstance(int argc = 0, char *argv[] = {})
    {
        return app;
    }
    static void destroyInstance()
    {
        if (app)
        {
            delete app;
            app = nullptr;
        }
    }
};
int argc = 0;
char *argv[] = {};
QApplication *QApplicationManager::app = new QApplication(argc, argv);
template <typename T, int K = 2>
class Tree
{
private:
    TreeNode<T> *root; // root of the tree
    void deleteTree(TreeNode<T> *node);
    std::vector<T> heap;

public:
    Tree();
    ~Tree();

    TreeNode<T> *get_root() const;

    void add_root(TreeNode<T> *node);

    void add_sub_node(TreeNode<T> *perant_node, TreeNode<T> *child_key);

    // Iterators
    PreOrderIterator<T> begin_pre_order();
    PreOrderIterator<T> end_pre_order();

    PostOrderIterator<T> begin_post_order();
    PostOrderIterator<T> end_post_order();

    InorderIterator<T> begin_in_order();
    InorderIterator<T> end_in_order();

    BfsIterator<T> begin_bfs_scan();
    BfsIterator<T> end_bfs_scan();

    DfsIterator<T> begin_dfs_scan();
    DfsIterator<T> end_dfs_scan();

    HeapIterator<T> begin_heap_scan();
    HeapIterator<T> end_heap_scan();

    void myHeap();
    void make_heap(TreeNode<T> *node);
    void print(); // GUI print method
    friend std::ostream &operator<<(std::ostream &os, const Tree<T, K> &tree)
    {
        QMainWindow *window = new QMainWindow();
        QGraphicsScene *scene = new QGraphicsScene(window);
        QGraphicsView *view = new QGraphicsView(scene, window);
        window->setCentralWidget(view);
        view->setSceneRect(0, 0, 800, 600);
        TreeDrawingClass<T, K> treeDrawingClass(tree.get_root());
        treeDrawingClass.drawTree(scene, tree.get_root(), 400, 50, 200);
        window->show();
        return os;
    }
};

// Constructor
template <typename T, int K>
Tree<T, K>::Tree() : root(nullptr) {}

// Destructor
template <typename T, int K>
Tree<T, K>::~Tree()
{
    deleteTree(root);
}

template <typename T, int K>
TreeNode<T> *Tree<T, K>::get_root() const
{
    return this->root;
}

template <typename T, int K>
void Tree<T, K>::add_root(TreeNode<T> *root)
{
    this->root = root;
}

// Helper function to delete the tree
template <typename T, int K>
void Tree<T, K>::deleteTree(TreeNode<T> *node)
{
    if (node)
    {
        if (node->children.size() == 0)
        {
            delete node;
            node = nullptr;
            return;
        }
        // Recursively delete children nodes
        for (auto &child : node->children)
        {
            deleteTree(child);
        }
        node->children.clear(); // Clear children pointers after deletion

        // Delete current node
        delete node;
        node = nullptr; // Optional: Set node to nullptr after deletion (defensive programming)
    }
}

// Add a child to a parent node
template <typename T, int K>
void Tree<T, K>::add_sub_node(TreeNode<T> *parent_node, TreeNode<T> *child_node)
{
    try
    {
        if (parent_node->children.size() <= K)
            parent_node->addChild(child_node);
        else
            throw std::runtime_error("The parent node has reached the maximum number of children");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Pre-Order Iterator
template <typename T, int K>
PreOrderIterator<T> Tree<T, K>::begin_pre_order()
{
    return PreOrderIterator<T>(root);
}

template <typename T, int K>
PreOrderIterator<T> Tree<T, K>::end_pre_order()
{
    return PreOrderIterator<T>(nullptr);
}

// Post-Order Iterator
template <typename T, int K>
PostOrderIterator<T> Tree<T, K>::begin_post_order()
{
    return PostOrderIterator<T>(root);
}

template <typename T, int K>
PostOrderIterator<T> Tree<T, K>::end_post_order()
{
    return PostOrderIterator<T>(nullptr);
}

// In-Order Iterator
template <typename T, int K>
InorderIterator<T> Tree<T, K>::begin_in_order()
{
    return InorderIterator<T>(root);
}

template <typename T, int K>
InorderIterator<T> Tree<T, K>::end_in_order()
{
    return InorderIterator<T>(nullptr);
}

// BFS Iterator
template <typename T, int K>
BfsIterator<T> Tree<T, K>::begin_bfs_scan()
{
    return BfsIterator<T>(root);
}

template <typename T, int K>
BfsIterator<T> Tree<T, K>::end_bfs_scan()
{
    return BfsIterator<T>(nullptr);
}

// DFS Iterator
template <typename T, int K>
DfsIterator<T> Tree<T, K>::begin_dfs_scan()
{
    return DfsIterator<T>(root);
}

template <typename T, int K>
DfsIterator<T> Tree<T, K>::end_dfs_scan()
{
    return DfsIterator<T>(nullptr);
}
// Heap Iterator
template <typename T, int K>
HeapIterator<T> Tree<T, K>::begin_heap_scan()
{
    return HeapIterator<T>(root);
}

template <typename T, int K>
HeapIterator<T> Tree<T, K>::end_heap_scan()
{
    return HeapIterator<T>(nullptr);
}

using namespace std;
template <typename T, int K>
void Tree<T, K>::myHeap()
{
    if (K > 2)
    {
        cout << "K greater than 2" << endl;
        return;
    }
    heap.clear();
    if (root)
    {
        make_heap(root);
    }
    std::make_heap(heap.begin(), heap.end(), std::greater<T>()); // determaning size of elements
}

template <typename T, int K>
void Tree<T, K>::make_heap(TreeNode<T> *node)
{
    if (!node)
    {
        return;
    }
    if (node->children.size() > 0 && node->children[0] != nullptr)
    {
        make_heap(node->children[0]);
    }
    heap.push_back(node->key);
    if (node->children.size() > 1 && node->children[1] != nullptr)
    {
        make_heap(node->children[1]);
    }
}

template <typename T, int K>
void Tree<T, K>::print()
{
    QWidget *window = new QWidget;
    QGraphicsScene *scene = new QGraphicsScene(window);
    QGraphicsView *view = new QGraphicsView(scene, window);

    // Set the window size
    window->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    view->setFixedSize(800, 600);
    view->setBackgroundBrush(QBrush(Qt::black));
    view->scale(1, -1); // Flip the y-axis to match typical graphics coordinates
    view->setAlignment(Qt::AlignCenter);
    view->setFrameShape(QFrame::NoFrame);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create a TreeDrawingClass instance and pass the root node
    TreeDrawingClass<T, K> treeDrawer(root);

    // Draw the tree in the graphics scene
    treeDrawer.drawTree(scene);

    // Set the window layout and display it
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(view);
    window->setLayout(layout);
    window->show();
}
