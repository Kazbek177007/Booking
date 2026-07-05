#include "producteditdialog.h"
#include "ui_producteditdialog.h"
#include <QFileDialog>
#include <QPixmap>

ProductEditDialog::ProductEditDialog(const Product& product, QWidget* parent)
    : QDialog(parent),
    ui(new Ui::ProductEditDialog),
    product(product),
    iconData(product.preview().icon())
{
    ui->setupUi(this);

    ui->nameEdit->setText(product.preview().name());
    ui->priceSpinBox->setValue(product.preview().price());

    QPixmap pixmap;
    pixmap.loadFromData(iconData);
    if (!pixmap.isNull())
        ui->iconPreview->setPixmap(pixmap.scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    connect(ui->selectIconButton, &QPushButton::clicked, this, &ProductEditDialog::onSelectIconClicked);
}

ProductEditDialog::~ProductEditDialog()
{
    delete ui;
}

void ProductEditDialog::onSelectIconClicked()
{
    QString path = QFileDialog::getOpenFileName
    (
        this,
        tr("Select Icon"),
        QString(),
        tr("Images (*.png *.jpg *.jpeg *.bmp)")
    );
    if (path.isEmpty())
        return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return;

    iconData = file.readAll();

    QPixmap pixmap;
    pixmap.loadFromData(iconData);
    if (!pixmap.isNull())
        ui->iconPreview->setPixmap(pixmap.scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

Product ProductEditDialog::editedProduct() const
{
    ProductPreview preview(
        product.preview().id(),
        ui->nameEdit->text(),
        iconData,
        ui->priceSpinBox->value()
    );
    return Product(preview, product.isPublished());
}
