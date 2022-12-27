#include "include/decoding.h"
#include "ui_decoding.h"

#include <QFileDialog>
#include <QLineEdit>
#include <QDebug>

// Конструктор:
Decoding::Decoding(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Decoding)
{
    ui->setupUi(this);

    connect(ui->browseButton, SIGNAL(clicked()), this, SLOT(browseInputFile()));
    connect(ui->browsePathsButto, SIGNAL(clicked()), this, SLOT(browsePaths()));
    connect(ui->decodeButton, SIGNAL(clicked()), this, SLOT(decompressFile()));
    connect(ui->inputFile, &QLineEdit::textChanged, this, &Decoding::filePahChanged);

    ui->inputFile->setText("C:\\Users\\ReWoodPC\\Downloads\\Qt Projects\\TestArchive\\TestArch.usa");
    ui->outputPath->setText("C:\\Users\\ReWoodPC\\Downloads\\Qt Projects\\TestArchive\\Ans");
}

// Деструктор:
Decoding::~Decoding()
{
    delete ui;
}

// Метод для выбора файла для восстановления:
void Decoding::browseInputFile()
{
    const QString inputFile = QFileDialog::getOpenFileName(this, "Открыть файл", QString(), "Аривы (*.usa)");
    ui->inputFile->setText(inputFile);
}

// Метод для выбора пути для восстановления:
void Decoding::browsePaths()
{
    const QString outputPath = QFileDialog::getExistingDirectory(this, tr("Выбрать путь"), QString());
    ui->outputPath->setText(outputPath + "/");
}

// Восстановить сжатый файл:
void Decoding::decompressFile()
{
    const QString inputFile = ui->inputFile->text();
    const QString outputPath = ui->outputPath->text();


    const QString outputFile = outputPath + "/test.exe";
    huffmanDecode(inputFile.toStdString().c_str(), outputFile.toStdString().c_str(), 0);

//    if(!_metaData.isEmpty() && !outputPath.isEmpty()) {

//        int beginPos = _headMeteSpace;
//        foreach(Common::MetaData metaData, _metaData) {
//            const QString outputFile = outputPath + metaData.fileName;

//            huffmanDecode(inputFile.toStdString().c_str(), outputFile.toStdString().c_str(), beginPos);

//            beginPos += metaData.compressionSize;
//        }
//    }
}

void Decoding::filePahChanged()
{
//    const QString inputFile_S = ui->inputFile->text();
//    _inputFile = new QFile(inputFile_S);
//    if(_inputFile->exists()) {
//        if (!_inputFile->open(QIODevice::ReadWrite | QIODevice::Text)) {
//            Common::showDoneMessage("Ошибка создания выходного файла", "Сжатие данных");
//            return;
//        }

//        _inStream = new QDataStream(_inputFile);

//        auto fileHeader = Common::readFileHeader(*_inStream);
//        qDebug() << char(fileHeader.index[0]) << char(fileHeader.index[1]) << char(fileHeader.index[2]);
//        qDebug() << fileHeader.version[0] << fileHeader.version[1] << fileHeader.version[2];

//        _metaData = Common::readMetaData(*_inStream);

//        _headMeteSpace = _inStream->device()->pos();

//        int count = 0;
//        foreach(Common::MetaData metaData, _metaData) {

//            QLineEdit *file = new QLineEdit(this);
//            file->setReadOnly(true);
//            file->setText(metaData.fileName + "\t" + QString::number(metaData.originalSize));
//            ui->files->insertWidget(count, file);

//            qDebug() << metaData.fileName;
//            qDebug() << metaData.originalSize;
//            qDebug() << metaData.compressionSize;
//            qDebug() << char(metaData.args[0]) << char(metaData.args[1]) << char(metaData.args[2]);

//            qDebug() << "---------------------";

//            count++;
//        }
//    }
}
