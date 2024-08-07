#ifndef CUSTOMSHAPEITEM_H
#define CUSTOMSHAPEITEM_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>

class CustomShapeItem : public QGraphicsItem
{
public:
    enum ShapeType { Rectangle, Ellipse, Line, Arrow };

    CustomShapeItem(ShapeType shapeType, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setShapeRect(const QRectF &rect);
    void setShapeLine(const QLineF &line);
    ShapeType getShapeType() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    ShapeType shapeType;
    QRectF shapeRect;
    QLineF shapeLine;
};

#endif // CUSTOMSHAPEITEM_H
