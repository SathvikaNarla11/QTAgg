#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customgraphicsview.h"
#include "customdelegate.h"
#include "iconlistmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButtonList14_clicked();
    void onIconClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    CustomDelegate *delegate;
    ShapeType currentShape;
    CustomGraphicsView* currentGraphicsView; // Current graphics view for drawing

    void addInnerTab(QTabWidget* innerTabWidget, const QString& tabName);
    void setupIcons();
};

#endif // MAINWINDOW_H
