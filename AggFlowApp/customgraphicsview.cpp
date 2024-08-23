#include "customgraphicsview.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QDebug>

CustomGraphicsView::CustomGraphicsView(QWidget *parent)
    : QGraphicsView(parent), currentShape(ShapeType::None), drawing(false)
{
}

void CustomGraphicsView::setShapeType(ShapeType shapeType) {
    currentShape = shapeType;
}

void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"......";
    if (currentShape != ShapeType::None)
    {
        startPoint = event->pos();
        drawing = true;
    }
    QGraphicsView::mousePressEvent(event);
}

void CustomGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    if (drawing && currentShape != ShapeType::None) {
        QPoint endPoint = event->pos();
        // Clear previous shape if necessary
        scene()->clear(); // This might not be ideal for clearing, use with caution

        if (currentShape == ShapeType::Rectangle)
        {
            int x = qMin(startPoint.x(), endPoint.x());
            int y = qMin(startPoint.y(), endPoint.y());
            int width = qAbs(startPoint.x() - endPoint.x());
            int height = qAbs(startPoint.y() - endPoint.y());
            scene()->addRect(x, y, width, height, QPen(Qt::black));
        }
        else if (currentShape == ShapeType::Ellipse)
        {
            int x = qMin(startPoint.x(), endPoint.x());
            int y = qMin(startPoint.y(), endPoint.y());
            int width = qAbs(startPoint.x() - endPoint.x());
            int height = qAbs(startPoint.y() - endPoint.y());
            scene()->addEllipse(x, y, width, height, QPen(Qt::black));
        }
        // Implement other shapes like Line if needed
    }
    QGraphicsView::mouseMoveEvent(event);
}

void CustomGraphicsView::mouseReleaseEvent(QMouseEvent *event) {
    if (drawing && currentShape != ShapeType::None)
    {
        QPoint endPoint = event->pos();
        // Finalize the shape
        drawing = false;
    }
    QGraphicsView::mouseReleaseEvent(event);
}
