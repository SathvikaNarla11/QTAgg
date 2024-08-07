#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customgraphicsview.h"
#include "customshapeitem.h"
#include <QDebug>
#include <QMimeData>
#include <QIcon>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,model(new IconListModel(this))
    ,model2(new IconListModel(this))
    ,delegate(new CustomDelegate(38, this))
    ,delegate2(new CustomDelegate(38, this))
    ,scene(new QGraphicsScene(this))
    ,iconSize(38, 38)
{
    ui->setupUi(this);

    /****************** LISTVIEW 1*****************/
    QStringList labels = {"Item 1", "Item 2", "Item 3"};
    QList<QIcon> icons;
    icons <<QIcon(":/Images/Icons/list1-1.png")
         <<QIcon(":/Images/Icons/list1-2.png")
        <<QIcon(":/Images/Icons/list1-3.png");

    model->setData(labels, icons);
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    ui->listView->setIconSize(iconSize);
    /**********************************************/

    /****************** LISTVIEW 2*****************/
    QStringList labels2 = {"Item 1", "Item 2"};
    QList<QIcon> icons2;
    icons2 <<QIcon(":/Images/Icons/list2-1.png")
          <<QIcon(":/Images/Icons/list2-1.png");

    model2->setData(labels2, icons2);
    ui->listView2->setModel(model2);
    ui->listView2->setItemDelegate(delegate2);
    ui->listView2->setDragEnabled(true);
    ui->listView2->setIconSize(iconSize);

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    /**********************************************/

    connect(ui->graphicsView, &CustomGraphicsView::mousePressed, this, &MainWindow::onGraphicsViewMousePressed);
    connect(ui->graphicsView, &CustomGraphicsView::mouseMoved, this, &MainWindow::onGraphicsViewMouseMoved);
    connect(ui->graphicsView, &CustomGraphicsView::mouseReleased, this, &MainWindow::onGraphicsViewMouseReleased);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonList1_clicked()
{
    qDebug()<<"pbtn1";
    ui->listView2->hide();
    ui->listView->show();
}
void MainWindow::on_pushButtonList2_clicked()
{
    qDebug()<<"pbtn1";
    ui->listView->hide();
    ui->listView2->show();
}


void MainWindow::on_pushButtonRect_clicked()
{
    qDebug()<<"Rectangle selected";
    shapeType = CustomShapeItem::Rectangle;
    drawing = true;
}


void MainWindow::on_pushButtonEllipse_clicked()
{
    qDebug()<<"Ellipse selected";
    shapeType = CustomShapeItem::Ellipse;
    drawing = true;
}


void MainWindow::on_pushButtonLine_clicked()
{
    qDebug()<<"Line selected";
    shapeType = CustomShapeItem::Line;
    drawing = true;
}


void MainWindow::on_pushButtonArrow_clicked()
{
    qDebug()<<"Arrow selected";
    shapeType = CustomShapeItem::Arrow;
    drawing = true;
}

void MainWindow::onGraphicsViewMousePressed(QMouseEvent *event)
{
    if (drawing && event->button() == Qt::LeftButton)
    {
        origin = ui->graphicsView->mapToScene(event->pos());
        currentItem = new CustomShapeItem(shapeType);
        currentItem->setPos(origin);
        scene->addItem(currentItem);
    }
}

void MainWindow::onGraphicsViewMouseMoved(QMouseEvent *event)
{
    if (drawing && currentItem)
    {
        QPointF currentPos = ui->graphicsView->mapToScene(event->pos());
        QRectF newRect(origin, currentPos);
        currentItem->setShapeRect(newRect.normalized());
        scene->update();
    }
}

void MainWindow::onGraphicsViewMouseReleased(QMouseEvent *event)
{
    if (drawing && event->button() == Qt::LeftButton)
    {
        drawing = false;
        currentItem = nullptr;
    }
}
