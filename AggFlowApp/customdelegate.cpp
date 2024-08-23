#include "customdelegate.h"

CustomDelegate::CustomDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Custom painting logic, if needed
    QStyledItemDelegate::paint(painter, option, index); // Call the base class method for default behavior
}

QSize CustomDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Custom size logic, if needed
    return QStyledItemDelegate::sizeHint(option, index); // Call the base class method for default behavior
}
