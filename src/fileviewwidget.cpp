#include "include/fileviewwidget.h"
#include "ui_fileviewwidget.h"


FileViewWidget::FileViewWidget(const QString &filePath, QWidget *parent)
    : QWidget(parent), ui(new Ui::FileViewWidget()), _fileInfo(filePath)
{
    ui->setupUi(this);

    ui->filePath->setReadOnly(true);

    ui->fileName->setText(_fileInfo.fileName());
    ui->filePath->setText(_fileInfo.filePath());
}

FileViewWidget::~FileViewWidget()
{
    delete ui;
}

QStringList FileViewWidget::getArgs()
{
    QStringList args;

    if(ui->huffmanCheckBox->isChecked()) {
        args << "--huffman";
    }
    if(ui->lzCheckBox->isChecked()) {
        args << "--LZ";
    }
    if(ui->interferenceCheckBox->isChecked()) {
        args << "--noise";
    }
    return args;
}

QString FileViewWidget::getFilePath()
{
    return _fileInfo.absoluteFilePath();
}

Common::MetaData FileViewWidget::getMetaData()
{
    Common::MetaData ret;

    ret.fileName = _fileInfo.fileName();
    ret.nameSize = ret.fileName.size();
    ret.compressionSize = -1;

    if(ui->huffmanCheckBox->isChecked()) {
       ret.args[0] = '1';
    }
    if(ui->lzCheckBox->isChecked()) {
         ret.args[1] = '1';
    }
    if(ui->interferenceCheckBox->isChecked()) {
        ret.args[2] = '1';
    }

    return ret;
}
