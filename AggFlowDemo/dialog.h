#ifndef DIALOG_H
#define DIALOG_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class DialogData;

class Dialog
{
    Q_OBJECT
public:
    Dialog();
    Dialog(const Dialog &);
    Dialog &operator=(const Dialog &);
    ~Dialog();

private:
    QSharedDataPointer<DialogData> data;
};

#endif // DIALOG_H
