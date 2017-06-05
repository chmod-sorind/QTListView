#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    for (int var = 0; var < 99; ++var)
    {   QListWidgetItem *itm = new QListWidgetItem(QString::number(var) + " Item", ui->listWidget);
        itm->setFlags(itm->flags()| Qt::ItemIsUserCheckable);
        itm->setCheckState(Qt::Unchecked);
    }

}

dialog::~dialog()
{
    delete ui;
}

void dialog::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setText("Test Text");
    itm->setTextColor(Qt::red);
    itm->setCheckState(Qt::Checked);
}
