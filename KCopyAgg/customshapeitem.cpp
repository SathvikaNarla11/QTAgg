#include "customshapeitem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QDebug>
#include <QMenu>
#include <QInputDialog>
#include <QWidget>

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

    painter->setPen(m_pen);
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
        qDebug() << "SHAPECLICK";
        QGraphicsItem::mousePressEvent(event);
    }
    else if (event->button() == Qt::RightButton)
    {
        qDebug() << "Right button clicked:";

        if (shapeType == Rectangle || shapeType == Ellipse || shapeType == Line)
        {
            QMenu *contextMenu = new QMenu();

            lineWidthAction = contextMenu->addAction(QIcon(":/Icons/RightClickShape/lineWidth.png"), "Line Width");
            contextMenu->addAction(QIcon(":/Icons/RightClickShape/lineColor.png"), "Line Color...");
            contextMenu->addSeparator();
            contextMenu->addAction(QIcon(":/Icons/RightClickShape/fillColor.png"), "Fill Color...");
            contextMenu->addAction(QIcon(":/Icons/RightClickShape/transparent.png"), "Transparent");
            contextMenu->addSeparator();
            contextMenu->addAction(QIcon(":/Icons/RightClickShape/sendBack.png"), "Send Back");
            contextMenu->addAction(QIcon(":/Icons/RightClickShape/bringForward.png"), "Bring Forward");
            contextMenu->addSeparator();
            contextMenu->addAction("Make Circle");
            contextMenu->addAction("Circle Diameter?");
            contextMenu->addSeparator();
            contextMenu->addAction(QIcon(":/Icons/MenuIcons/cut.png"), "Cut");
            contextMenu->addAction(QIcon(":/Icons/MenuIcons/copy.png"), "Copy");
            contextMenu->addAction(QIcon(":/Icons/MenuIcons/delete.png"), "Delete");

//            connect(lineWidthAction, &QAction::triggered, this, &CustomShapeItem::changeLineWidth);
            contextMenu->exec(event->screenPos());

            delete contextMenu;
        }
    }
}

void CustomShapeItem::changeLineWidth()
{
    bool ok;
    int newWidth = QInputDialog::getInt(nullptr, QWidget::tr("Set Line Width"), QWidget::tr("Line Width:"), m_pen.width(), 1, 100, 1, &ok);

    if (ok)
    {
        m_pen.setWidth(newWidth);
        update(); // Redraw the item to reflect the new line width
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

