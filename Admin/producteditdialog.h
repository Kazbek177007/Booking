#include <QDialog>
#include "rep_admin_replica.h"

namespace Ui {
class ProductEditDialog;
}

class ProductEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductEditDialog(const Product& product, QWidget* parent = nullptr);
    ~ProductEditDialog();

    Product editedProduct() const;

private slots:
    void onSelectIconClicked();

private:
    Ui::ProductEditDialog *ui;
    Product product;
    QByteArray iconData;
};

