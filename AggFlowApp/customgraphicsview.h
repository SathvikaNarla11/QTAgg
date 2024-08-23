#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QPoint>

// Enum for shape types
enum class ShapeType {
    None,
    Line,
    Rectangle,
    Ellipse
};

class CustomGraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    explicit CustomGraphicsView(QWidget *parent = nullptr);

    // Method to set the current shape type
    void setShapeType(ShapeType shapeType);

protected:
    // Override mouse event handlers
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    ShapeType currentShape; // Current shape type to be drawn
    QPoint startPoint;      // Starting point for drawing shapes
    bool drawing;           // Flag to track if a shape is being drawn
};

#endif // CUSTOMGRAPHICSVIEW_H
