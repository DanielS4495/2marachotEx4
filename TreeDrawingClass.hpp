//danielsamson10@gmail.com
//211358486
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include "complex.hpp"

template <typename T, int K>
class TreeDrawingClass
{
private:
    TreeNode<T> *root;

public:
    TreeDrawingClass(TreeNode<T> *root) : root(root) {}

    void drawTree(QGraphicsScene *scene, TreeNode<T> *node, int x, int y, int offset)
    {
        if (!scene || !node)
            return; // Add null pointer checks
        const int radius = 30;
        QPen nodePen(Qt::blue);
        nodePen.setWidth(2);
        scene->addEllipse(x - radius, y - radius, 2 * radius, 2 * radius, nodePen);
        QString text;
        Complex c = node->key;
        if (c.getImag() != 0)
        {
            text = QString::fromStdString(std::to_string(c.getReal())) + "+" +
                   QString::fromStdString(std::to_string(c.getImag())) + "i";
        }
        else
            text = QString::fromStdString(std::to_string(c.getReal()));
        QGraphicsTextItem *textItem = scene->addText(text);
        QFont font = textItem->font();
        font.setBold(true);
        font.setPointSize(15);
        textItem->setFont(font);
        textItem->setDefaultTextColor(Qt::black);
        textItem->setPos(x - textItem->boundingRect().width() / 2, y - textItem->boundingRect().height() / 2);
        int childIndex = 0;
        for (auto &child : node->children)
        {
            int childX = x + (childIndex - (node->children.size() - 1) / 2.0) * offset;
            int childY = y + 100;
            float dx = childX - x;
            float dy = childY - y;
            float length = sqrt(dx * dx + dy * dy);
            dx /= length;
            dy /= length;

            int startX = x + radius * dx;
            int startY = y + radius * dy;
            int endX = childX - radius * dx;
            int endY = childY - radius * dy;
            QPen linePen(Qt::black);
            linePen.setWidth(2);
            scene->addLine(startX, startY, endX, endY, linePen);
            drawTree(scene, child, childX, childY, offset / 2);
            childIndex++;
        }
    }
};
