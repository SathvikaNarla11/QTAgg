#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStandardItemModel>
#include <QIcon>
#include <QStyledItemDelegate>
#include <QMimeData>
#include <QDrag>
#include <QAbstractItemView>
#include <QStyledItemDelegate>
#include <QDrag>
#include <QMimeData>
#include <QIcon>
#include <QPixmap>
#include <QAbstractItemView>
#include <QModelIndex>
#include <QPoint>
#include <QRect>

/*************************************************************************/
class IconListModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit IconListModel(QObject* parent = nullptr);

    void setData(const QStringList& labels, const QList<QIcon>& icons);
};

/*************************************************************************/
class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomDelegate(int rowHeight, QObject *parent = nullptr);

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setRowHeight(int rowHeight);

signals:
    void sizeHintChanged();

private:
    int m_rowHeight;
};


#endif // CUSTOMDELEGATE_H
