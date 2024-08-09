#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "customgraphicsview.h"
#include <QUndoStack>
#include "customshapeitem.h"
#include "customdelegate.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addItem(const QString &itemText);

private slots:
//    void on_pushButtonList1_clicked();
//    void on_pushButtonList2_clicked();
//    void on_pushButtonPaint_clicked();
//        void undo();
//        void redo();

    void on_pushButtonRect_clicked();
    void on_pushButtonEllipse_clicked();
    void on_pushButtonLine_clicked();
    void on_pushButtonArrow_clicked();

    void onGraphicsViewMousePressed(QMouseEvent *event);
    void onGraphicsViewMouseMoved(QMouseEvent *event);
    void onGraphicsViewMouseReleased(QMouseEvent *event);
    void onPushButtonClicked();


protected:

private:
    Ui::MainWindow *ui;
    int n;

    IconListModel *model;
    CustomDelegate *delegate;

    QGraphicsScene *scene;
    QSize iconSize;
    QUndoStack *undoStack;
    CustomShapeItem *currentItem = nullptr;
    bool drawing;
    CustomShapeItem::ShapeType shapeType;
    QPointF origin;

    void updateListView(int n);
};
#endif // MAINWINDOW_H
