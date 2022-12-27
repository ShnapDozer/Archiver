#include "include/common.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// Показать информационное сообщение:
void Common::showDoneMessage(const char* msg, const char* title)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setWindowTitle(title);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

char *Common::toChar(const QString& text)
{
    QByteArray text_BA = text.toLocal8Bit();
    return text_BA.data();
}

qint64 Common::getFileSize(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    return fileInfo.size();
}

QVector<Common::MetaData> Common::readMetaData(FILE*file)
{
    QVector<MetaData> data;
//    int countFiles;

//    file >> countFiles;
//    qDebug() << countFiles;
//    for(int i = 0; i < countFiles; ++i) {
//        MetaData mData;
//        unsigned char args[3];

//        file >> mData.originalSize >> mData.compressionSize;
//        file >> args[0] >> args[1] >> args[2];
//        file >> mData.nameSize;
//        qDebug() <<  mData.nameSize;

//        char byte;
//        for(int j = 0; j < mData.nameSize; ++j) {
//            file >> byte;
//            mData.fileName.append(byte);
//        }

//        data.push_back(mData);
//    }

        return data;
}

void Common::writeMetaData(const QVector<MetaData> &metaData, FILE*file)
{
//    int countFiles = metaData.size();
//    file << countFiles;
//    qDebug() << metaData.size();
//    foreach(MetaData mData, metaData) {
//        file << mData.originalSize << mData.compressionSize;
//        file << mData.args[0] << mData.args[1] << mData.args[2];
//        file << mData.nameSize;

//        foreach(char byte, mData.fileName.toStdString()) {
//            file << byte;
//        }

//    }
}

void Common::writeFile(const QString &inFile, FILE*outFile, bool deleteFile)
{
//    QFile readfile(inFile);

//    if (!readfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug() << QString("Невозможно открыть файл на чтение и запись: %1").arg(inFile);
//        return;
//    }
//    QDataStream readStream (&readfile);

//    unsigned char byteBuffer;
//    while(!readStream.atEnd()) {
//        readStream >> byteBuffer;
//        outFile << byteBuffer;
//    }

//    if(deleteFile) {
//        readfile.remove();
//    }
}

Common::FileHeader Common::readFileHeader(FILE*file)
{
    FileHeader fileHeader;
    fscanf (file, "%c%c%c", &fileHeader.index[0]);
    fscanf (file, "%d%d%d", &fileHeader.version[0]);
//    file >> fileHeader.index[0] >> fileHeader.index[1] >> fileHeader.index[2];
//    file >> fileHeader.version[0] >> fileHeader.version[1] >> fileHeader.version[2];

    return fileHeader;
}

void Common::writeFileHeader(FileHeader fileHeader, FILE* file)
{
    fwrite(&fileHeader.index[0], 1, sizeof(fileHeader.index), file);
    fwrite(&fileHeader.version[0], 1, sizeof(fileHeader.version), file);
//    file << fileHeader.index[0] << fileHeader.index[1] << fileHeader.index[2];
//    file << fileHeader.version[0] << fileHeader.version[1] << fileHeader.version[2];
}
