#ifndef DECODING_H
#define DECODING_H

#include <QDialog>
#include <QFile>
#include <QDataStream>

#include "include/huffman.h"
#include "include/common.h"

namespace Ui {
class Decoding;
}

class Decoding : public QDialog
{
    Q_OBJECT
    
public:

    explicit Decoding(QWidget *parent = 0);
    ~Decoding();
    
private:
    Ui::Decoding *ui;

    QVector<Common::MetaData> _metaData;
    QDataStream *_inStream;
    QFile *_inputFile;
    qint64 _headMeteSpace;

public slots:
    void browseInputFile();
    void browsePaths();

    void decompressFile();
    void filePahChanged();
};

#endif // DECODING_H
