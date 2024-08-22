#include "customshapeitem.h"
#include "customgraphicsview.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QDebug>

CustomShapeItem::CustomShapeItem(ShapeType shapeType, QGraphicsItem *parent)
    : QGraphicsItem(parent), shapeType(shapeType)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);

}

QRectF CustomShapeItem::boundingRect() const
{
    if (shapeType == Line || shapeType == Arrow)
    {
        return QRectF(shapeLine.p1(), shapeLine.p2());
    }
    else
    {
        return shapeRect;
    }
}

QPainterPath CustomShapeItem::shape() const
{
    QPainterPath path;
    switch (shapeType)
    {
    case Rectangle:
        path.addRect(shapeRect);
        break;
    case Ellipse:
        path.addEllipse(shapeRect);
        break;
    case Line:
        path.moveTo(shapeLine.p1());
        path.lineTo(shapeLine.p2());
        break;
    case Arrow:
        path.moveTo(shapeLine.p1());
        path.lineTo(shapeLine.p2());
        //ADD LOGIC FOR ARROW HEAD
        break;
    }
    return path;
}

void CustomShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    switch (shapeType)
    {
    case Rectangle:
        painter->drawRect(shapeRect);
        break;
    case Ellipse:
        painter->drawEllipse(shapeRect);
        break;
    case Line:
        painter->drawLine(shapeLine.p1(), shapeLine.p2());
        break;
    case Arrow:
        painter->drawLine(shapeLine.p1(), shapeLine.p2());
        // Add arrowhead drawing logic here
        break;
    }

    if (option->state & QStyle::State_Selected)
    {
        painter->setPen(QPen(Qt::DashLine));
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect());

    }
}


void CustomShapeItem::setShapeRect(const QRectF &rect)
{
    prepareGeometryChange();
    shapeRect = rect;
    update();
}

QRectF CustomShapeItem::getShapeRect() const
{
    return shapeRect;
}

void CustomShapeItem::setShapeLine(const QLineF &line)
{
    prepareGeometryChange();
    shapeLine = line;
    update();
}

QLineF CustomShapeItem::getShapeLine() const
{
    return shapeLine;
}
void CustomShapeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        qDebug()<<"SHAPECLICK";
        QGraphicsItem::mousePressEvent(event);
    }
}

void CustomShapeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void CustomShapeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}


/*#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QLineF>

class ResizeHandle : public QGraphicsItem
{
    Q_OBJECT

public:
    enum ResizeCorner { TopLeft, TopRight, BottomLeft, BottomRight };

    ResizeHandle(QGraphicsItem *resizeItem, ResizeCorner corner, QGraphicsItem *parent = nullptr)
        : QGraphicsItem(parent), m_resizeItem(resizeItem), m_resizeCorner(corner), m_isResizingStart(false) {}

    void setResizeItem(QGraphicsItem *item) { m_resizeItem = item; }
    void setResizeCorner(ResizeCorner corner) { m_resizeCorner = corner; }

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsItem *m_resizeItem;
    ResizeCorner m_resizeCorner;
    bool m_isResizingStart;
};

void ResizeHandle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_resizeItem)
    {
        QPointF newPos = mapToParent(event->pos());

        if (auto rectItem = dynamic_cast<QGraphicsRectItem*>(m_resizeItem))
        {
            QRectF oldRect = rectItem->rect();
            QPointF topLeft = oldRect.topLeft();
            QPointF bottomRight = oldRect.bottomRight();

            // Determine which corner is being resized
            if (m_resizeCorner == TopLeft)
            {
                topLeft = newPos;
            }
            else if (m_resizeCorner == TopRight)
            {
                topLeft.setY(newPos.y());
                bottomRight.setX(newPos.x());
            }
            else if (m_resizeCorner == BottomLeft)
            {
                topLeft.setX(newPos.x());
                bottomRight.setY(newPos.y());
            }
            else if (m_resizeCorner == BottomRight)
            {
                bottomRight = newPos;
            }

            QRectF newRect(topLeft, bottomRight);
            rectItem->setRect(newRect.normalized());
        }
        else if (auto ellipseItem = dynamic_cast<QGraphicsEllipseItem*>(m_resizeItem))
        {
            QRectF oldRect = ellipseItem->rect();
            QPointF topLeft = oldRect.topLeft();
            QPointF bottomRight = oldRect.bottomRight();

            // Determine which corner is being resized
            if (m_resizeCorner == TopLeft)
            {
                topLeft = newPos;
            }
            else if (m_resizeCorner == TopRight)
            {
                topLeft.setY(newPos.y());
                bottomRight.setX(newPos.x());
            }
            else if (m_resizeCorner == BottomLeft)
            {
                topLeft.setX(newPos.x());
                bottomRight.setY(newPos.y());
            }
            else if (m_resizeCorner == BottomRight)
            {
                bottomRight = newPos;
            }

            QRectF newRect(topLeft, bottomRight);
            ellipseItem->setRect(newRect.normalized());
        }
        else if (auto lineItem = dynamic_cast<QGraphicsLineItem*>(m_resizeItem))
        {
            QPointF handlePos = mapToParent(event->pos());
            if (QLineF(handlePos, lineItem->line().p1()).length() < QLineF(handlePos, lineItem->line().p2()).length())
            {
                m_isResizingStart = true;
            }
            else
            {
                m_isResizingStart = false;
            }

            QLineF line = lineItem->line();
            if (m_isResizingStart)
            {
                line.setP1(mapToScene(event->pos()));
            }
            else
            {
                line.setP2(mapToScene(event->pos()));
            }
            lineItem->setLine(line);
        }

        m_resizeItem->update();
    }

    QGraphicsItem::mouseMoveEvent(event);
}*/
