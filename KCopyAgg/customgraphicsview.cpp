#include "customgraphicsview.h"
#include "customdelegate.h"
#include <QDebug>
#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QIcon>
#include "customshapeitem.h"

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setAcceptDrops(true);
}
void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    emit mousePressed(event);
    QGraphicsView::mousePressEvent(event);

    QPointF scenePos = mapToScene(event->pos());
    QGraphicsItem* item = itemAt(event->pos());

    if (item)
    {
        QGraphicsPixmapItem* pixmapItem = dynamic_cast<QGraphicsPixmapItem*>(item);
        addPointsToItem(pixmapItem, 38, 38);
    }
}

void CustomGraphicsView::addPointsToItem(QGraphicsPixmapItem* item, int width, int height)
{
    QGraphicsEllipseItem* startPoint = new QGraphicsEllipseItem(-5, -5, 8, 8, item);
    startPoint->setBrush(Qt::red);
    startPoint->setPos(-4, height/2 - 2); // Red point at top-left
    startPoint->setZValue(1);
    startPoint->setData(0, "redPoint");

    QGraphicsEllipseItem* endPoint = new QGraphicsEllipseItem(-5, -5, 10, 10, item);
    endPoint->setBrush(Qt::blue);
    endPoint->setPos(width+2, height/2 -2); // Blue point at bottom-right
    endPoint->setZValue(1);
    endPoint->setData(0,"bluePoint");

    qDebug() << "Red point added at:" << startPoint->pos();
    qDebug() << "Blue point added at:" << endPoint->pos();
}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoved(event);
    QGraphicsView::mouseMoveEvent(event);
}

void CustomGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    emit mouseReleased(event);
    QGraphicsView::mouseReleaseEvent(event);
}

void CustomGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "Drag enter";
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        event->acceptProposedAction();
    }
}

void CustomGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug() << "Drag move";
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        event->acceptProposedAction();
    }
}

void CustomGraphicsView::dropEvent(QDropEvent *event)
{
    qDebug() << "Drop";
    if (event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist"))
    {
        QByteArray encodedData = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
        QDataStream stream(&encodedData, QIODevice::ReadOnly);
        int row, col;
        QMap<int, QVariant> roleDataMap;

        while (!stream.atEnd())
        {
            stream >> row >> col >> roleDataMap;
            QIcon icon = qvariant_cast<QIcon>(roleDataMap[Qt::UserRole + 1]);
            if (!icon.isNull())
            {
                QPixmap pixmap = icon.pixmap(QSize(38, 38)); // use correct icon size
                QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

                item->setFlag(QGraphicsItem::ItemIsMovable);
                item->setFlag(QGraphicsItem::ItemIsSelectable);

                QPointF scenePos = mapToScene(event->pos());
                QPointF offset(pixmap.width() / 2, pixmap.height() / 2);
                QPointF finalPos = scenePos - offset;

                item->setPos(finalPos);
                scene()->addItem(item);
            }
        }
        event->acceptProposedAction();
    }
}




