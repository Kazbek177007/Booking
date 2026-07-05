#include "adminproductwidget.h"
#include "ui_adminproductwidget.h"
#include "producteditdialog.h"
#include "admin.h"
#include <QMessageBox>
#include <QPixmap>

AdminProductWidget::AdminProductWidget(const Product& product, QWidget* parent)
    : QWidget(parent),
    ui(new Ui::AdminProductWidget),
    product(product)
{
    ui->setupUi(this);

    QPixmap pixmap;
    pixmap.loadFromData(product.preview().icon());
    if (!pixmap.isNull())
        ui->iconLabel->setPixmap(pixmap.scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->nameLabel->setText(product.preview().name());
    ui->priceLabel->setText(QString::number(product.preview().price(), 'f', 2));

    ui->publishButton->setChecked(product.isPublished());
    ui->publishButton->setText(product.isPublished() ? "Unpublish" : "Publish");

    connect(ui->editButton,    &QPushButton::clicked, this, &AdminProductWidget::onEditClicked);
    connect(ui->removeButton,  &QPushButton::clicked, this, &AdminProductWidget::onRemoveClicked);
    connect(ui->publishButton, &QPushButton::clicked, this, &AdminProductWidget::onPublishToggled);
}

AdminProductWidget::~AdminProductWidget()
{
    delete ui;
}

void AdminProductWidget::onEditClicked()
{
    ProductEditDialog* dialog = new ProductEditDialog(product, this);
    connect(dialog, &QDialog::accepted, [dialog, this]()
    {
        if (auto listOfProducts = Admin::instance()->listOfProducts)
            listOfProducts->changeProductInfo(dialog->editedProduct());
    });
    dialog->open();
}

void AdminProductWidget::onRemoveClicked()
{
    auto reply = QMessageBox::question
    (
        this,
        tr("Remove product"),
        tr("Are you sure you want to remove \"%1\"?").arg(product.preview().name()),
        QMessageBox::Yes | QMessageBox::No
    );
    if (reply == QMessageBox::Yes)
    {
        if (auto listOfProducts = Admin::instance()->listOfProducts)
            listOfProducts->removeProduct(product.preview().id());
    }
}

void AdminProductWidget::onPublishToggled()
{
    Product updated = product;
    updated.setIsPublished(!product.isPublished());
    if (auto listOfProducts = Admin::instance()->listOfProducts)
        listOfProducts->changeProductInfo(updated);
}
