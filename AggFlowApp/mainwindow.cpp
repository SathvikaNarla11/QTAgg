#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customgraphicsview.h"
#include "customdelegate.h"
#include "iconlistmodel.h"
#include <QDebug>
#include <QListView>
#include <QModelIndex>
#include <QTabWidget>
#include <QVBoxLayout>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , delegate(new CustomDelegate(this))
    , currentShape(ShapeType::None)
    , currentGraphicsView(nullptr) // Initialize to nullptr
{
    ui->setupUi(this);

    // Initial tab setup
    if (ui->tabWidget->count() > 0) // Check if there is at least one tab
    {
        QWidget* firstTab = ui->tabWidget->widget(0);
        QTabWidget* innerTabWidget = new QTabWidget(firstTab);

        addInnerTab(innerTabWidget, "Inner Tab 1");
        innerTabWidget->addTab(new QWidget(), "Add New");

        // Connect the inner tab widget's signal to handle adding new tabs
        connect(innerTabWidget, &QTabWidget::currentChanged, [this, innerTabWidget](int index)
        {
            if (innerTabWidget->tabText(index) == "Add New")
            {
                QString newTabName = QString("Inner Tab %1").arg(innerTabWidget->count());
                addInnerTab(innerTabWidget, newTabName);
                innerTabWidget->setCurrentIndex(innerTabWidget->count() - 2); // Set to the newly added tab
            }
        });

        QVBoxLayout* layout = new QVBoxLayout(firstTab);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(innerTabWidget);
        firstTab->setLayout(layout);
    }

    connect(ui->pushButtonList14, &QPushButton::clicked, this, &MainWindow::on_pushButtonList14_clicked);

    // Connect the list view selection to handle icon clicks
    connect(ui->listView->selectionModel(), &QItemSelectionModel::currentChanged,
        this, [this](const QModelIndex &current, const QModelIndex &previous) {
            onIconClicked(current);
        });
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Handles tab bar clicks to add new tabs
void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    QTabWidget* tabWidget = ui->tabWidget;
    int tabCount = tabWidget->count();

    if (index == tabCount - 1) // If the last tab is clicked
    {
        qDebug() << "Adding new tab at index:" << index;

        QWidget* newTab = new QWidget();
        QTabWidget* innerTabWidget = new QTabWidget(newTab);

        addInnerTab(innerTabWidget, "Inner Tab 1");
        innerTabWidget->addTab(new QWidget(), "Add New");

        // Connect the inner tab widget's signal to handle adding new tabs
        connect(innerTabWidget, &QTabWidget::currentChanged, [this, innerTabWidget](int index) {
            if (innerTabWidget->tabText(index) == "Add New")
            {
                QString newTabName = QString("Inner Tab %1").arg(innerTabWidget->count());
                addInnerTab(innerTabWidget, newTabName);
                innerTabWidget->setCurrentIndex(innerTabWidget->count() - 2); // Set to the newly added tab
            }
        });

        QVBoxLayout* layout = new QVBoxLayout(newTab);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(innerTabWidget);
        newTab->setLayout(layout);

        tabWidget->insertTab(tabCount - 1, newTab, QString("Plant Stage #%1").arg(tabCount));
        tabWidget->setCurrentIndex(tabWidget->indexOf(newTab));
    }
}

// Adds a new inner tab with a CustomGraphicsView
void MainWindow::addInnerTab(QTabWidget* innerTabWidget, const QString& tabName)
{
    QWidget* newInnerTab = new QWidget();
    QVBoxLayout* innerLayout = new QVBoxLayout(newInnerTab);
    CustomGraphicsView* customGraphicsView = new CustomGraphicsView(newInnerTab);
    innerLayout->addWidget(customGraphicsView);
    innerLayout->setContentsMargins(0, 0, 0, 0);
    newInnerTab->setLayout(innerLayout);

    // Set currentGraphicsView to the newly created view if it's the first tab
    if (innerTabWidget->count() == 1)
    {
        currentGraphicsView = customGraphicsView;
    }

    innerTabWidget->insertTab(innerTabWidget->count() - 1, newInnerTab, tabName);
}

// Sets up the list view with icons and labels
void MainWindow::on_pushButtonList14_clicked()
{
    QStringList labels = {
        "Reset Pointer", "Paint Brush", "Select Color", "Erase", "Multi-Line Notes",
        "Adjustable Text", "Arrow", "Line", "Polyline", "Ellipse", "Rectangle", "Symbols"
    };
    QList<QIcon> menuIcons = {
        QIcon(":/Icons/DragDropIcons/Btn14-List/reset_to_pointer_default_mouse_function.png"),
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
        QIcon(":/Icons/DragDropIcons/Btn14-List/symbols_open_to_select_model.png")
    };

    IconListModel *menuModel = new IconListModel(this);
    menuModel->setData(labels, menuIcons);

    ui->listView->setModel(menuModel);
    ui->listView->setFixedWidth(50);
    ui->listView->setItemDelegate(delegate);
    ui->listView->setDragEnabled(true);
    QSize iconSize(38, 38);
    ui->listView->setIconSize(iconSize);
}

// Handles icon clicks to set the current shape type
void MainWindow::onIconClicked(const QModelIndex &index)
{
    // Map icon index to shape type
    int iconIndex = index.row(); // Assuming row corresponds to icon index
    switch (iconIndex) {
    case 7: // Line icon index
        currentShape = ShapeType::Line;
        break;
    case 8: // Rectangle icon index
        currentShape = ShapeType::Rectangle;
        break;
    case 9: // Ellipse icon index
        currentShape = ShapeType::Ellipse;
        break;
    default:
        currentShape = ShapeType::None;
        break;
    }
    if (currentGraphicsView)
    {
        currentGraphicsView->setShapeType(currentShape);
    }
}
