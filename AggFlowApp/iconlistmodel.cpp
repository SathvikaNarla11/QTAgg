#include "iconlistmodel.h"

IconListModel::IconListModel(QObject *parent)
    : QStandardItemModel(parent)
{
}

void IconListModel::setData(const QStringList &labels, const QList<QIcon> &icons)
{
    clear();  // Clear the model before setting new data

    for (int i = 0; i < labels.size(); ++i)
    {
        QStandardItem *item = new QStandardItem(icons.value(i), labels.at(i));
        appendRow(item);
    }
}
