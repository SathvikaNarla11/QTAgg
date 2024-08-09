#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customgraphicsview.h"
#include "customshapeitem.h"
#include <QDebug>
#include <QMimeData>
#include <QIcon>

int n;
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,model(new IconListModel(this))
    ,delegate(new CustomDelegate(38, this))
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



    //    case 4:
    //        menuIcons = {QIcon(":/icons/dragIcon/place_a_jaw_crusher_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/place_a_cone_crusher_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/place_an_hsi_crusher_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/place_a_vsi_crusher_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/place_a_roll_crusher_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mill_crusher_in_the_flow.png")};
    //        break;
    //    case 5:
    //        menuIcons = {QIcon(":/icons/dragIcon/grizzly_feeder_vibrating_scalper.png"),
    //                     QIcon(":/icons/dragIcon/1deck.png"),
    //                     QIcon(":/icons/dragIcon/2deck.png"),
    //                     QIcon(":/icons/dragIcon/3deck.png"),
    //                     QIcon(":/icons/dragIcon/4deck.png"),
    //                     QIcon(":/icons/dragIcon/5deck.png"),
    //                     QIcon(":/icons/dragIcon/place_a_custom_screen_in_the_flow_trommel_or_banana.png"),
    //                     QIcon(":/icons/dragIcon/place_a_custom_multi_screen_or_split_deck_screen_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/air_seperator.png")};
    //        break;
    //    case 6:
    //        menuIcons = {QIcon(":/icons/dragIcon/place_a_mobile_jaw_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_cone_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_hsi_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_vsi_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_screen_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_wash_unit_on_the_worksheet.png"),
    //                     QIcon(":/icons/dragIcon/place_a_mobile_conveyor_on_the_worksheet.png")};
    //        break;
    //    case 7:
    //        menuIcons = {QIcon(":/icons/dragIcon/scrubbing_and_attrition_equipment.png"),
    //                     QIcon(":/icons/dragIcon/classification_equipment.png"),
    //                     QIcon(":/icons/dragIcon/sand_washing_dewatering.png"),
    //                     QIcon(":/icons/dragIcon/place_an_overflow_box_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/mixing_box.png"),
    //                     QIcon(":/icons/dragIcon/place_a_slurry_box_in_the_flow.png"),
    //                     QIcon(":/icons/dragIcon/slurry_pump.png"),
    //                     QIcon(":/icons/dragIcon/slurry_valve.png"),
    //                     QIcon(":/icons/dragIcon/water_treatment_or_recycling_recover_water.png")};
    //        break;
    //    case 8:
    //        menuIcons = {QIcon(":/icons/dragIcon/inventory_suger_pile_with_feeders.png"),
    //                     QIcon(":/icons/dragIcon/inventory_suger_bin_with_feeders.png")};
    //        break;
    //    case 9:
    //        menuIcons = {QIcon(":/icons/dragIcon/end_point_product_pile.png"),
    //                     QIcon(":/icons/dragIcon/end_point_haul_truck.png"),
    //                     QIcon(":/icons/dragIcon/end_point_haul_railway_transport.png"),
    //                     QIcon(":/icons/dragIcon/end_point_haul_water_transport.png"),
    //                     QIcon(":/icons/dragIcon/end_point_product_bin.png"),
    //                     QIcon(":/icons/dragIcon/end_point_blending_station.png")};
    //        break;
    //    case 10:
    //        menuIcons = {QIcon(":/icons/dragIcon/clean_water_source.png"),
    //                     QIcon(":/icons/dragIcon/clean_Watersource.png"),
    //                     QIcon(":/icons/dragIcon/water_pump.png"),
    //                     QIcon(":/icons/dragIcon/water_splitter.png"),
    //                     QIcon(":/icons/dragIcon/waterSplitter.png"),
    //                     QIcon(":/icons/dragIcon/water_tank.png"),
    //                     QIcon(":/icons/dragIcon/water_valve.png"),
    //                     QIcon(":/icons/dragIcon/water_spray_nozzles.png")};
    //        break;
    //    case 11:
    //        menuIcons = {QIcon(":/icons/dragIcon/sample_bucket.png")};
    //        break;
    //    case 12:
    //        menuIcons = {QIcon(":/icons/dragIcon/external_power_source.png"),
    //                     QIcon(":/icons/dragIcon/internal_power_source.png"),
    //                     QIcon(":/icons/dragIcon/fuel_tank.png"),
    //                     QIcon(":/icons/dragIcon/personnel.png")};
    //        break;
    //    case 13:
    //        menuIcons = {QIcon(":/icons/dragIcon/reset_to_pointer_default_mouse_function.png"),
    //                     QIcon(":/icons/dragIcon/paint_brush.png"),
    //                     QIcon(":/icons/dragIcon/select_color_for_paint_brush.png"),
    //                     QIcon(":/icons/dragIcon/erase_color.png"),
    //                     QIcon(":/icons/dragIcon/multi_line_notes.png"),
    //                     QIcon(":/icons/dragIcon/adjustable_text.png"),
    //                     QIcon(":/icons/dragIcon/arrow.png"),
    //                     QIcon(":/icons/dragIcon/line.png"),
    //                     QIcon(":/icons/dragIcon/polyline.png"),
    //                     QIcon(":/icons/dragIcon/ellipse.png"),
    //                     QIcon(":/icons/dragIcon/rectangle.png"),
    //                     QIcon(":/icons/dragIcon/symbols_open_to_select_model.png")};


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
        ui->groupBoxPaint->show();
        break;
    case 7:
        model->setData(labels, icons);
        ui->listView->setModel(model);
        break;
    case 8:
        model->setData(labels2, icons2);
        ui->listView->setModel(model);
        break;
    case 9:
        ui->groupBoxPaint->show();
        break;
    case 14:
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

    for (int i = 1; i <= 14; ++i)
    {
        if (objectName == QString("pushButtonList%1").arg(i))
        {
            buttonNumber = i;
            break;
        }
    }

    if (objectName == "pushButtonPaint") {
        buttonNumber = 14;
    }

    if (buttonNumber != -1)
    {
        n = buttonNumber;
        updateListView(n);
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
        currentItem->setPos(origin);

        switch (shapeType)
        {
        case CustomShapeItem::Rectangle:
        case CustomShapeItem::Ellipse:
            currentItem->setShapeRect(QRectF(origin, QSizeF(0, 0)));
            break;
        case CustomShapeItem::Line:
        case CustomShapeItem::Arrow:
            currentItem->setShapeLine(QLineF(origin, origin));
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
        qDebug() << "Updating shape to:" << currentPos;

        switch (shapeType)
        {
        case CustomShapeItem::Rectangle:
        case CustomShapeItem::Ellipse:
            currentItem->setShapeRect(QRectF(origin, currentPos).normalized());
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
        currentItem = nullptr;
    }
}





