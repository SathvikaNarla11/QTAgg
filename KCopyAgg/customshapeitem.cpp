#include "customshapeitem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

CustomShapeItem::CustomShapeItem(ShapeType shapeType, QGraphicsItem *parent)
    : QGraphicsItem(parent), shapeType(shapeType)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF CustomShapeItem::boundingRect() const
{
    return shapeRect;
}

void CustomShapeItem::setShapeRect(const QRectF &rect)
{
    prepareGeometryChange();
    shapeRect = rect;
}

CustomShapeItem::ShapeType CustomShapeItem::getShapeType() const
{
    return shapeType;
}

void CustomShapeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::black);
    if (isSelected())
    {
        pen.setStyle(Qt::DashLine);
    }
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    switch (shapeType)
    {
        case Rectangle:
            painter->drawRect(shapeRect);
            break;
        case Ellipse:
            painter->drawEllipse(shapeRect);
            break;
        case Line:
            painter->drawLine(shapeRect.topLeft(), shapeRect.bottomRight());
            break;
        case Arrow:
            painter->drawLine(shapeRect.topLeft(), shapeRect.bottomRight());
            // Add arrowhead drawing logic here
            break;
    }
}

void CustomShapeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
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
