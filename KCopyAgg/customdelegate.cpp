#include "customdelegate.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QAbstractItemView>
#include <QDebug>

IconListModel::IconListModel(QObject* parent) : QStandardItemModel(parent)
{
}

void IconListModel::setData(const QStringList& labels, const QList<QIcon>& icons)
{
    Q_ASSERT(labels.size() == icons.size());

    for (int i = 0; i < labels.size(); ++i)
    {
        QStandardItem* item = new QStandardItem(icons.at(i), QString());
        item->setData(icons.at(i), Qt::UserRole + 1); // Store the icon for drag and drop
        item->setData(labels.at(i), Qt::ToolTipRole);
        appendRow(item);
    }
}

CustomDelegate::CustomDelegate(int rowHeight, QObject *parent) : QStyledItemDelegate(parent), m_rowHeight(rowHeight)
{

}

QSize CustomDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    return QSize(option.rect.width(), m_rowHeight);
}

void CustomDelegate::setRowHeight(int rowHeight)
{
    m_rowHeight = rowHeight;
    emit sizeHintChanged();
}


