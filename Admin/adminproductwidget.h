#include <QWidget>
#include "rep_admin_replica.h"

namespace Ui {
class AdminProductWidget;
}

class AdminProductWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminProductWidget(const Product& product, QWidget* parent = nullptr);
    ~AdminProductWidget();

private slots:
    void onEditClicked();
    void onRemoveClicked();
    void onPublishToggled();

private:
    Ui::AdminProductWidget* ui;
    Product product;
};

