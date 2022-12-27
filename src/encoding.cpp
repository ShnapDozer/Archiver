#include "include/encoding.h"
#include "ui_encoding.h"

#include "QFileDialog"
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QDataStream>
#include <QFile>

#include "include/common.h"
#include "include/huffman.h"

// Конструктор:
Encoding::Encoding(QWidget *parent)
    : QDialog(parent), ui(new Ui::Encoding)
{
    ui->setupUi(this);

    setAcceptDrops(true);

    ui->outputFileName->setText("TestArch");
    ui->outputFilePath->setText("/media/rewood/Other/Qt_Projects/build/test");


    connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(onBrowsButtonClicked()));
    connect(ui->encodeButton, SIGNAL(clicked()), this, SLOT(compressFiles()));
}

// Деструктор:
Encoding::~Encoding()
{
    delete ui;
}

void Encoding::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void Encoding::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

       if (mimeData->hasUrls()) {
         QList<QUrl> urlList = mimeData->urls();

         FileViewWidget *file;
         for (int i = 0; i < urlList.size() && i < 32; ++i) {
             file = new FileViewWidget(urlList.at(i).toLocalFile(), this);

             ui->filesPathsLayout->insertWidget(files.size(), file);
             files.push_back(file);
         }
       }

}

// Слот, нажатие на кнопку обзор:
void Encoding::onBrowsButtonClicked()
{
    const QString outputPath = QFileDialog::getExistingDirectory(this, tr("Выбрать путь"), QString());
    ui->outputFilePath->setText(outputPath);
}

// Метод для сжатия файла:
void Encoding::compressFiles()
{
    const QString outputFileName = ui->outputFileName->text();
    const QString outputFilePath = ui->outputFilePath->text();

    if (outputFileName == "" || outputFilePath == "" || files.size() == 0) {
        Common::showDoneMessage("Нет файлов или пустая строка с именем сжатого файла", "Сжатие данных");
        return;
    }

    QStringList tmpFiles;
    QVector<Common::MetaData> meteDatas;
    for(int i = 0; i < files.size(); ++i) {

        Common::MetaData metaData = files[i]->getMetaData();
        const QStringList fileArgs = files[i]->getArgs();

        const QString inputFile = files[i]->getFilePath();
        const QString tmpOutputFile = outputFilePath + "/tmp/tmp_" + metaData.fileName.section(".",0,0) + ".tmp";


        if(fileArgs.contains("--huffman")) {
            huffmanEncode(inputFile.toStdString().c_str(), tmpOutputFile.toStdString().c_str());
            metaData.args[0] = 'a';
        }

        metaData.compressionSize = Common::getFileSize(tmpOutputFile);

        tmpFiles << tmpOutputFile;
        meteDatas.push_back(metaData);
    }

    QFile outFile(outputFilePath + "/" + outputFileName + ".usa");
    if (!outFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        Common::showDoneMessage("Ошибка создания выходного файла", "Сжатие данных");
        return;
    }
    if(!meteDatas.isEmpty()) {
        QDataStream outStream(&outFile);

        Common::writeFileHeader(Common::FileHeader(), outStream);
        Common::writeMetaData(meteDatas, outStream);

        foreach(QString tmpFile, tmpFiles) {
            Common::writeFile(tmpFile, outStream, true);

        }

        outFile.close();
    }
}
