#ifndef CUSTOMSHAPEITEM_H
#define CUSTOMSHAPEITEM_H

#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <QObject>
#include <QAction>

class CustomShapeItem : public QGraphicsItem
{
//    Q_OBJECT
public:
    enum ShapeType { Rectangle, Ellipse, Line, Arrow, FixedLine };

    CustomShapeItem(ShapeType shapeType, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setShapeRect(const QRectF &rect);
    QRectF getShapeRect() const;
    QLineF getShapeLine() const;
    void setShapeLine(const QLineF &line);
    ShapeType getShapeType() const;
    ShapeType shapeType;

    void setPen(const QPen &pen) { m_pen = pen; update(); }
    QPen pen() const { return m_pen; }
    void changeLineWidth();

    QAction *lineWidthAction;

signals:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QRectF shapeRect;
    QLineF shapeLine;
    QPen m_pen;

    enum HandleType { TopLeft, TopRight, BottomLeft, BottomRight, MiddleLeft, MiddleRight, TopCenter, BottomCenter };
    QVector<QGraphicsEllipseItem*> handles;
};

#endif // CUSTOMSHAPEITEM_H














//#ifndef CUSTOMSHAPEITEM_H
//#define CUSTOMSHAPEITEM_H

//#include <QGraphicsItem>
//#include <QPen>
//#include <QBrush>
//#include <QObject>

//class CustomShapeItem : public QGraphicsItem
//{
//    Q_OBJECT
//public:
//    enum ShapeType { Rectangle, Ellipse, Line, Arrow, FixedLine };

//    CustomShapeItem(ShapeType shapeType, QGraphicsItem *parent = nullptr);

//    QRectF boundingRect() const override;
//    QPainterPath shape() const override;
//    void setShapeRect(const QRectF &rect);
//    QRectF getShapeRect() const;
//    QLineF getShapeLine() const;
//    void setShapeLine(const QLineF &line);
//    ShapeType getShapeType() const;
//    ShapeType shapeType;

//    void setPen(const QPen &pen) { m_pen = pen; update(); }
//    QPen pen() const { return m_pen; }
//    void changeLineWidth();

//signals:


//protected:
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//private:

//    QRectF shapeRect;
//    QLineF shapeLine;
//    QPen m_pen;

//    enum HandleType { TopLeft, TopRight, BottomLeft, BottomRight, MiddleLeft, MiddleRight, TopCenter, BottomCenter };
//    QVector<QGraphicsEllipseItem*> handles;
//};

//#endif // CUSTOMSHAPEITEM_H

