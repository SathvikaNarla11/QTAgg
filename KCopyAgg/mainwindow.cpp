#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customgraphicsview.h"
#include "customshapeitem.h"
#include <QDebug>
#include <QMimeData>
#include <QIcon>
#include <QTimer>

int n;
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,model(new IconListModel(this))
    ,modelBtn(new IconListModel(this))
    ,delegate(new CustomDelegate(38, this))
    ,delegateBtn(new CustomDelegate(34, this))
    ,scene(new QGraphicsScene(this))
    ,iconSize(38, 38)
    ,n(0)
{
    ui->setupUi(this);
    ui->groupBoxPaint->hide();
    QStringList labels = {"Item 1", "Item 2", "Item 3","Item 4", "Item 5", "Item 6", "Item 7"};
    QList<QIcon> icons;
    icons << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_bull_dozer.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dredge.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dump_truck.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_excavator.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_generic_material_source.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_loader.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_start_suger_pile.png");


    model->setData(labels, icons);
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    ui->listView->setIconSize(iconSize);

    QSize iconSizeBtn(30, 30);
    ui->listViewBtn->setParent(ui->groupBoxPaint);
    QStringList labels14 = {"Item 1"};
    QList<QIcon> icons14;
    icons14 << QIcon(":/Icons/DragDropIcons/Btn14-List/symbols_open_to_select_model.png");
    modelBtn->setData(labels14, icons14);
    ui->listViewBtn->setModel(modelBtn);
    ui->listViewBtn->setItemDelegate(delegateBtn);
    ui->listViewBtn->setDragEnabled(true);
    ui->listViewBtn->setIconSize(iconSizeBtn);


    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    /**********************************************/

    connect(ui->graphicsView, &CustomGraphicsView::mousePressed, this, &MainWindow::onGraphicsViewMousePressed);
    connect(ui->graphicsView, &CustomGraphicsView::mouseMoved, this, &MainWindow::onGraphicsViewMouseMoved);
    connect(ui->graphicsView, &CustomGraphicsView::mouseReleased, this, &MainWindow::onGraphicsViewMouseReleased);

    connect(ui->pushButtonList1, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList2, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList3, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList4, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList5, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList6, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList7, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList8, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList9, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList10, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList11, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList12, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonList13, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
    connect(ui->pushButtonPaint, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListView(int index)
{
    ui->groupBoxPaint->hide();
    QStringList labels = {"Item 1", "Item 2", "Item 3","Item 4", "Item 5", "Item 6", "Item 7"};
    QList<QIcon> icons;
    icons << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_bull_dozer.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dredge.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dump_truck.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_excavator.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_generic_material_source.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_loader.png")
          << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_start_suger_pile.png");

    QStringList labels2 = {"Item 1", "Item 2"};
    QList<QIcon> icons2;
    icons2 << QIcon(":/Icons/DragDropIcons/Btn2-List/apron_feeder.png")
           << QIcon(":/Icons/DragDropIcons/Btn2-List/belt_feeder.png");

    QStringList labels3 = {"Item 1", "Item 2","Item 3", "Item 4", "Item 5"};
    QList<QIcon> icons3;
    icons3  <<QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_conveyor_in_the_flow.png")
           <<QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_front_end_loader_in_the_flow.png")
          <<QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_haul_truck_in_the_flow.png")
         <<QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_reversible_conveyor_in_the_flow.png")
        <<QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_stock_pile_in_the_flow.png");

    QStringList labels4 = {"Item 1", "Item 2","Item 3", "Item 4", "Item 5"};
    QList<QIcon> icons4;
    icons4  <<QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_splitter_in_the_flow.png")
           <<QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_three_way_splitter_in_the_flow.png")
          <<QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_flop_gate_in_the_flow.png")
         <<QIcon(":/Icons/DragDropIcons/Btn4-List/place_an_overflow_box_in_the_flow.png")
        <<QIcon(":/Icons/DragDropIcons/Btn4-List/place_an_overflow_box_in_the_flow.png");

    QStringList labels5 = {"Item 1", "Item 2","Item 3", "Item 4", "Item 5"};
    QList<QIcon> icons5;
    icons5  <<QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_jaw_crusher_in_the_flow.png")
           <<QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_cone_crusher_in_the_flow.png")
          <<QIcon(":/Icons/DragDropIcons/Btn5-List/place_an_hsi_crusher_in_the_flow.png")
         <<QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_roll_crusher_in_the_flow.png")
        <<QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_mill_crusher_in_the_flow.png");

    QStringList labels6 = {"Item 1", "Item 2", "Item 3","Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9"};
    QList<QIcon> icons6;
    icons6  <<QIcon(":/Icons/DragDropIcons/Btn6-List/grizzly_feeder_vibrating_scalper.png")
           <<QIcon(":/Icons/DragDropIcons/Btn6-List/1deck.png")
          <<QIcon(":/Icons/DragDropIcons/Btn6-List/2deck.png")
         <<QIcon(":/Icons/DragDropIcons/Btn6-List/3deck.png")
        <<QIcon(":/Icons/DragDropIcons/Btn6-List/4deck.png")
       <<QIcon(":/Icons/DragDropIcons/Btn6-List/5deck.png")
      <<QIcon(":/Icons/DragDropIcons/Btn6-List/place_a_custom_screen_in_the_flow_trommel_or_banana.png")
     <<QIcon(":/Icons/DragDropIcons/Btn6-List/place_a_custom_multi_screen_or_split_deck_screen_in_the_flow.png")
    <<QIcon(":/Icons/DragDropIcons/Btn6-List/air_seperator.png");

    QStringList labels7 = {"Item 1", "Item 2", "Item 3","Item 4", "Item 5", "Item 6", "Item 7"};
    QList<QIcon> icons7;
    icons7  <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_jaw_on_the_worksheet.png")
           <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_cone_on_the_worksheet.png")
          <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_hsi_on_the_worksheet.png")
         <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_vsi_on_the_worksheet.png")
        <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_screen_on_the_worksheet.png")
       <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_wash_unit_on_the_worksheet.png")
      <<QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_conveyor_on_the_worksheet.png");

    model->clear();
    switch (n)
    {
    case 1:
        model->setData(labels, icons);
        ui->listView->setModel(model);
        break;
    case 2:
        model->setData(labels2, icons2);
        ui->listView->setModel(model);
        break;
    case 3:
        model->setData(labels3, icons3);
        ui->listView->setModel(model);
        break;
    case 4:
        model->setData(labels4, icons4);
        ui->listView->setModel(model);
        break;
    case 5:
        model->setData(labels5, icons5);
        ui->listView->setModel(model);
        break;
    case 6:
        model->setData(labels6, icons6);
        ui->listView->setModel(model);
        break;
    case 7:
        model->setData(labels7, icons7);
        ui->listView->setModel(model);
        break;
    case 8:
        model->setData(labels2, icons2);
        ui->listView->setModel(model);
        break;
    case 9:
        break;
    case 14:
        ui->groupBoxListView->hide();
        ui->groupBoxPaint->show();
        break;
    default:
        break;
    }
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    ui->listView->setIconSize(iconSize);

}

void MainWindow::onPushButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton)
        return;

    QString objectName = clickedButton->objectName();
    int buttonNumber = -1;

    for (int i = 1; i < 14; ++i)
    {
        if (objectName == QString("pushButtonList%1").arg(i))
        {
            buttonNumber = i;
            break;
        }
    }

    if (objectName == "pushButtonPaint")
    {
        ui->groupBoxListView->hide(); // Hide the list view group box
        ui->groupBoxPaint->setParent(ui->groupBoxToolMain); // Ensure groupBoxPaint is a child of groupBoxToolMain
        ui->groupBoxToolMain->layout()->addWidget(ui->groupBoxPaint); // Reinsert groupBoxPaint in the layout
        ui->groupBoxPaint->show(); // Show the paint group box
    }
    else if (buttonNumber != -1)
    {
        ui->groupBoxPaint->hide(); // Hide the paint group box
        ui->groupBoxListView->setParent(ui->groupBoxToolMain); // Ensure groupBoxListView is a child of groupBoxToolMain
        ui->groupBoxToolMain->layout()->addWidget(ui->groupBoxListView); // Reinsert groupBoxListView in the layout
        ui->groupBoxListView->show(); // Show the list view group box
        n = buttonNumber;
        updateListView(n); // Update the list view based on the button number
    }
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
        qDebug() << "Mouse pressed at (view coordinates):" << event->pos();
        qDebug() << "Mouse pressed at (scene coordinates):" << origin;

        currentItem = new CustomShapeItem(shapeType);
        currentItem->setFlag(QGraphicsItem::ItemIsMovable, false);
        //        currentItem->setPos(origin);

        switch (shapeType)
        {
        case CustomShapeItem::Rectangle:
        case CustomShapeItem::Ellipse:
            currentItem->setShapeRect(QRectF(origin, QSizeF(0, 0)));
            break;
        case CustomShapeItem::Line:
        case CustomShapeItem::Arrow:
            currentItem->setShapeLine(QLineF(origin,origin));
            break;
        }

        scene->addItem(currentItem);
    }
}

void MainWindow::onGraphicsViewMouseMoved(QMouseEvent *event)
{
    if (drawing && currentItem)
    {
        QPointF currentPos = ui->graphicsView->mapToScene(event->pos());

        switch (shapeType)
        {
        case CustomShapeItem::Rectangle:
        case CustomShapeItem::Ellipse:
            currentItem->setShapeRect(QRectF(origin, currentPos)/*.normalized()*/);
            break;
        case CustomShapeItem::Line:
        case CustomShapeItem::Arrow:
            currentItem->setShapeLine(QLineF(origin, currentPos));
            break;
        }
        scene->update();
    }
}

void MainWindow::onGraphicsViewMouseReleased(QMouseEvent *event)
{
    if (drawing && event->button() == Qt::LeftButton)
    {
        drawing = false;
        currentItem->setFlag(QGraphicsItem::ItemIsMovable, true);
        currentItem = nullptr;
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    int n = ui->tabWidget->count();
    if(index+1 == n)
    {
        ui->tabWidget->setTabText(index, QString("page #%1").arg(n));
        QWidget *newTab = new QWidget();
        ui->tabWidget->addTab(newTab, "add new");

        QVBoxLayout *layout = new QVBoxLayout(newTab);

        CustomGraphicsView *newGraphicsView = new CustomGraphicsView(newTab);

        QGraphicsView *existingGraphicsView = new QGraphicsView(newTab);
        newGraphicsView->setScene(existingGraphicsView->scene());
        newGraphicsView->setRenderHints(existingGraphicsView->renderHints());
        newGraphicsView->setBackgroundBrush(existingGraphicsView->backgroundBrush());

        layout->addWidget(newGraphicsView);

        QTimer::singleShot(0, [this, newTab]()
        {
            ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(newTab));
        });
    }
}


