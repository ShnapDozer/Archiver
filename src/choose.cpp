#include "include/choose.h"

#include "ui_choose.h"
#include "include/encoding.h"
#include "include/decoding.h"

// Конструктор:
Choose::Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);

    connect(ui->compressButton, SIGNAL(clicked()), this, SLOT(showCompressDialog()));
    connect(ui->decompressButton, SIGNAL(clicked()), this, SLOT(showDecompressDialog()));
}

// Деструктор:
Choose::~Choose()
{
    delete ui;
}

// Показать диалоговое окно для сжатия данных:
void Choose::showCompressDialog()
{
    Encoding* en = new Encoding();
    en->setWindowTitle("Сжатие данных");
    en->show();

//    this->close();
}

// Показать диалоговое окно для восстановления данных:
void Choose::showDecompressDialog()
{
    Decoding* de = new Decoding();
    de->setWindowTitle("Восстановление данных сжатых по алгоритму Хаффмана");
    de->show();

//    this->close();
}
