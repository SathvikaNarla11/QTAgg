#ifndef ICONLISTMODEL_H
#define ICONLISTMODEL_H

#include <QStandardItemModel>
#include <QIcon>
#include <QStringList>

class IconListModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit IconListModel(QObject *parent = nullptr);

    void setData(const QStringList &labels, const QList<QIcon> &icons);
};

#endif // ICONLISTMODEL_H
