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
#include <QVBoxLayout>
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
//        void undo();
//        void redo();


    void onGraphicsViewMousePressed(QMouseEvent *event);
    void onGraphicsViewMouseMoved(QMouseEvent *event);
    void onGraphicsViewMouseReleased(QMouseEvent *event);
    void onPushButtonClicked();


    void on_tabWidget_tabBarClicked(int index);
    void onDrawingModeSelected(int mode);

    void on_actionTop_triggered();

    void on_actionBottom_triggered();

    void on_actionLeft_triggered();

    void on_actionRight_triggered();

protected:

private:
    Ui::MainWindow *ui;
    int n;

    IconListModel *model;
    CustomDelegate *delegate;
    QGraphicsScene *scene;
    QGraphicsScene *scenetab2;
    QGraphicsScene *sceneTab;

    QVBoxLayout *layout;
    QGraphicsView *newGraphicsView;

    QSize iconSize;
    QUndoStack *undoStack;
    CustomShapeItem *currentItem = nullptr;
    bool drawing;
    CustomShapeItem::ShapeType shapeType;
    QPointF origin;

    void updateListView(int n);

    CustomGraphicsView *customGraphicsView;
};
#endif // MAINWINDOW_H
