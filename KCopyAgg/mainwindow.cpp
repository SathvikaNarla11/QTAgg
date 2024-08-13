#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customgraphicsview.h"
#include "customshapeitem.h"
#include <QDebug>
#include <QMimeData>
#include <QIcon>
#include <QTimer>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,model(new IconListModel(this))
    ,delegate(new CustomDelegate(38, this))
    ,scene(new QGraphicsScene(this))
    ,scenetab2(new QGraphicsScene(this))
    ,iconSize(38, 38)
{
    ui->setupUi(this);
    QStringList labels = {"Item 1", "Item 2", "Item 3","Item 4", "Item 5", "Item 6", "Item 7"};
    QList<QIcon> icons;
    icons
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_loader.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dump_truck.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_excavator.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_bull_dozer.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dredge.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_generic_material_source.png")
            << QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_start_suger_pile.png");


    model->setData(labels, icons);
    ui->listView->setModel(model);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    ui->listView->setIconSize(iconSize);

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    ui->graphicsView_2->setScene(scenetab2);
    scenetab2->setSceneRect(0, 0, ui->graphicsView_2->width(), ui->graphicsView_2->height());
    ui->graphicsView_2->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView_2->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->graphicsView_2->setDragMode(QGraphicsView::RubberBandDrag);
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
    connect(ui->pushButtonList14, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListView(int index)
{
    QStringList labels;
    IconListModel *menuModel = new IconListModel(this);
    QList<QIcon> menuIcons;

    switch (index) {
    case 1:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_loader.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dump_truck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_excavator.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_bull_dozer.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_dredge.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_generic_material_source.png"),
                     QIcon(":/Icons/DragDropIcons/Btn1-List/start_points_start_suger_pile.png")};
        break;
    case 2:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn2-List/apron_feeder.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/feeder.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/belt_feeder.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/suger_bin.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/pan_feeder.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/suger_bin_with_feeder.png"),
                     QIcon(":/Icons/DragDropIcons/Btn2-List/dust_collector.png")};
        break;
    case 3:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_conveyor_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_reversible_conveyor_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_haul_truck_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_front_end_loader_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_stock_pile_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/place_a_surge_bin_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/bucket_elevator.png"),
                     QIcon(":/Icons/DragDropIcons/Btn3-List/screw_conveyor.png")};
        break;
    case 4:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_splitter_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_three_way_splitter_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_flop_gate_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn4-List/place_an_overflow_box_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn4-List/place_a_finger_gate_in_the_flow.png")};
        break;
    case 5:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_jaw_crusher_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_cone_crusher_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn5-List/place_an_hsi_crusher_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_vsi_crusher_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_roll_crusher_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn5-List/place_a_mill_crusher_in_the_flow.png")};
        break;
    case 6:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn6-List/grizzly_feeder_vibrating_scalper.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/1deck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/2deck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/3deck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/4deck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/5deck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/place_a_custom_screen_in_the_flow_trommel_or_banana.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/place_a_custom_multi_screen_or_split_deck_screen_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn6-List/air_seperator.png")};
        break;
    case 7:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_jaw_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_cone_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_hsi_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_vsi_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_screen_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_wash_unit_on_the_worksheet.png"),
                     QIcon(":/Icons/DragDropIcons/Btn7-List/place_a_mobile_conveyor_on_the_worksheet.png")};
        break;
    case 8:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn8-List/scrubbing_and_attrition_equipment.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/classification_equipment.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/sand_washing_dewatering.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/place_an_overflow_box_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/mixing_box.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/place_a_slurry_box_in_the_flow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/slurry_pump.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/slurry_valve.png"),
                     QIcon(":/Icons/DragDropIcons/Btn8-List/water_treatment_or_recycling_recover_water.png")};
        break;
    case 9:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn9-List/inventory_suger_pile_with_feeders.png"),
                     QIcon(":/Icons/DragDropIcons/Btn9-List/inventory_suger_bin_with_feeders.png")};
        break;
    case 10:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_product_pile.png"),
                     QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_haul_truck.png"),
                     QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_haul_railway_transport.png"),
                     QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_haul_water_transport.png"),
                     QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_product_bin.png"),
                     QIcon(":/Icons/DragDropIcons/Btn10-List/end_point_blending_station.png")};
        break;
    case 11:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn11-List/clean_water_source.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/clean_Watersource.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/water_pump.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/water_splitter.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/waterSplitter.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/water_tank.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/water_valve.png"),
                     QIcon(":/Icons/DragDropIcons/Btn11-List/water_spray_nozzles.png")};
        break;
    case 12:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn12-List/sample_bucket.png")};
        break;
    case 13:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn13-List/external_power_source.png"),
                     QIcon(":/Icons/DragDropIcons/Btn13-List/internal_power_source.png"),
                     QIcon(":/Icons/DragDropIcons/Btn13-List/fuel_tank.png"),
                     QIcon(":/Icons/DragDropIcons/Btn13-List/personnel.png")};
        break;
    case 14:
        menuIcons = {QIcon(":/Icons/DragDropIcons/Btn14-List/reset_to_pointer_default_mouse_function.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/paint_brush.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/select_color_for_paint_brush.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/erase_color.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/multi_line_notes.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/adjustable_text.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/arrow.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/line.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/polyline.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/ellipse.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/rectangle.png"),
                     QIcon(":/Icons/DragDropIcons/Btn14-List/symbols_open_to_select_model.png")};

        connect(ui->listView, &QListView::clicked, [this](const QModelIndex &index) {
            onDrawingModeSelected(index.row());
        });

        break;
    default:
        menuIcons = {QIcon()};
        break;
    }

    for (int i = 0 ; i<menuIcons.size(); i++ )
    {
        labels.append("Item " + QString::number(i));
    }

    menuModel->setData(labels, menuIcons);
    ui->listView->setModel(menuModel);
    ui->listView->setFixedWidth(50);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    ui->listView->setIconSize(iconSize);
}

void MainWindow::onDrawingModeSelected(int mode)
{
    ui->listView->setDragEnabled(false);
    switch (mode)
    {
    case 0:
        qDebug() << "default mouse function";
        break;
    case 1:
        qDebug() << "paint brush";
        break;
    case 2:
        QColorDialog::getColor();
        qDebug() << "brush paint color";
        break;
    case 3:
        qDebug() << "erase color";
        break;
    case 4:
        qDebug() << "Multiline note";
        break;
    case 5:
        qDebug() << "adjustable text ";
        break;
    case 6:
        qDebug()<<"Arrow selected";
        shapeType = CustomShapeItem::Arrow;
        drawing = true;
        break;
    case 7:
        qDebug()<<"Line selected";
        shapeType = CustomShapeItem::Line;
        drawing = true;
        break;
    case 8:
        qDebug()<<"Polyline";
        break;
    case 9:
        qDebug()<<"Ellipse selected";
        shapeType = CustomShapeItem::Ellipse;
        drawing = true;
        break;
    case 10:
        qDebug()<<"Rectangle selected";
        shapeType = CustomShapeItem::Rectangle;
        drawing = true;
        break;
    case 11:
        ui->listView->setDragEnabled(true);
        break;
    }
}


void MainWindow::onPushButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (!clickedButton)
        return;

    QString objectName = clickedButton->objectName();
    int buttonNumber = -1;

    for (int i = 1; i <= 15; ++i)
    {
        if (objectName == QString("pushButtonList%1").arg(i))
        {
            buttonNumber = i;
            qDebug()<<buttonNumber<<"-"<<i;
            break;
        }
    }
    if (buttonNumber != -1)
    {
        ui->groupBoxListView->setParent(ui->groupBoxToolMain);
        ui->groupBoxToolMain->layout()->addWidget(ui->groupBoxListView);
        ui->groupBoxListView->show();
        n = buttonNumber;
        qDebug()<<buttonNumber<<" -n "<<n;
        updateListView(n);
    }
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
            currentItem->setShapeRect(QRectF(origin, currentPos));
            break;
        case CustomShapeItem::Line:
        case CustomShapeItem::Arrow:
            currentItem->setShapeLine(QLineF(origin, currentPos));
            break;
        }
        scene->update();
        scenetab2->update();
    }
}

void MainWindow::onGraphicsViewMouseReleased(QMouseEvent *event)
{
    if (drawing && event->button() == Qt::LeftButton)
    {
        qDebug()<<"3";
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
        qDebug()<<index<<"-"<<n;
        ui->tabWidget->setTabText(index, QString("page #%1").arg(n));
        QWidget *newTab = new QWidget();
        ui->tabWidget->addTab(newTab, "add new");

        layout = new QVBoxLayout(newTab);
        layout->setContentsMargins(0,0,0,0);
        newGraphicsView = new CustomGraphicsView(newTab);
        sceneTab = new QGraphicsScene(newGraphicsView);
        newGraphicsView->setScene(sceneTab);
        sceneTab->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
        newGraphicsView->setRenderHints(QPainter::Antialiasing);
        layout->addWidget(newGraphicsView);

        ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(newTab)-1);
    }
}
