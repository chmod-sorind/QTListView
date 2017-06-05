#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

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
    if(ui->listWidget->isItemSelected(itm))
    {
        if(itm->checkState() == "Qt::CheckState(Unchecked)" )
        {
            itm->setText("Checked");
            itm->setTextColor(Qt::blue);
            itm->setCheckState(Qt::Checked);
        }
        else if (itm->checkState() == "Qt::CheckState(Checked)")
        {
            itm->setText("Unchecked");
            itm->setTextColor(Qt::red);
            itm->setCheckState(Qt::Unchecked);
        }
    }
}
