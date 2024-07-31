#include "dialog.h"

class DialogData : public QSharedData
{
public:

};

Dialog::Dialog() : data(new DialogData)
{

}

Dialog::Dialog(const Dialog &rhs) : data(rhs.data)
{

}

Dialog &Dialog::operator=(const Dialog &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Dialog::~Dialog()
{

}
