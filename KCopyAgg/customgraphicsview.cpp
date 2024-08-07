#include "customgraphicsview.h"
#include "customdelegate.h"
#include <QDebug>
#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QIcon>

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setAcceptDrops(true);
}
void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    emit mousePressed(event);
    QGraphicsView::mousePressEvent(event);
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

                qDebug() << "Drop position (view coordinates):" << event->pos();
                qDebug() << "Drop position (scene coordinates):" << scenePos;
                qDebug() << "Drop position (scene coordinates):" << offset;
                qDebug() << "Adjusted position:" << finalPos;

                item->setPos(finalPos);
                scene()->addItem(item);
            }
        }
        event->acceptProposedAction();
    }
}
