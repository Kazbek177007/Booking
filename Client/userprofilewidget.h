#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QWidget>

namespace Ui {
class UserProfileWidget;
}

class UserProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserProfileWidget(QWidget *parent = nullptr);
    ~UserProfileWidget();

private:
    Ui::UserProfileWidget *ui;
};

#endif // USERPROFILEWIDGET_H
