#include <QWidget>
#include "productsmanagerwidget.h"

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget* parent = nullptr);
    ~AdminMainWindow();

private slots:
    void showProductsManager();

private:
    Ui::AdminMainWindow* ui;
    ProductsManagerWidget* productsManager;
};

