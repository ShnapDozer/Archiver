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

QVector<Common::MetaData> Common::readMetaData(FILE* file)
{
    QVector<MetaData> data;

    int countFiles = -1;
    fread(&countFiles, 1, sizeof(countFiles), file);

    for(int i = 0; i < countFiles; ++i) {
        MetaData mData;
        fread(&mData.compressionSize, 1, sizeof(mData.compressionSize), file);
        fread(mData.args, 1, sizeof(mData.args), file);
        fread(&mData.nameSize, 1, sizeof(mData.nameSize), file);

        int byte;
        for(int j=0; j < mData.nameSize; ++j) {
            byte = fgetc(file);
            mData.fileName.append(byte);
        }

        data.push_back(mData);
    }

    return data;
}

void Common::writeMetaData(const QVector<MetaData> &metaData, FILE*file)
{
    int countFiles = metaData.size();
    fwrite(&countFiles, 1, sizeof(countFiles), file);

    foreach(MetaData mData, metaData) {
        fwrite(&mData.compressionSize, 1, sizeof(mData.compressionSize), file);
        fwrite(mData.args, 1, sizeof(mData.args), file);
        fwrite(&mData.nameSize, 1, sizeof(mData.nameSize), file);

        foreach(char byte, mData.fileName.toStdString()) {
            fputc(byte, file);
        }

    }
}

void Common::writeFile(const QString &inFile, FILE*outFile, bool deleteFile)
{
    QFile readfile(inFile);
    FILE* inputFile = fopen(inFile.toStdString().c_str(), "rb");

    if (inFile == NULL) {
        qDebug() << QString("Невозможно открыть файл на чтение и запись: %1").arg(inFile);
        return;
    }

    const size_t BUFFER_SIZE = 4096;
    char buf[BUFFER_SIZE];
    size_t size;

    while (size = fread(buf, 1, BUFFER_SIZE, inputFile)) {
        fwrite(buf, 1, size, outFile);
    }

    fclose(inputFile);

    if(deleteFile) {
        readfile.remove();
    }
}

Common::FileHeader Common::readFileHeader(FILE*file)
{
    FileHeader fileHeader;

    fread(fileHeader.index, sizeof(*fileHeader.index), 3, file);
    fread(fileHeader.version, sizeof(*fileHeader.version), 3, file);

    return fileHeader;
}

void Common::writeFileHeader(FileHeader fileHeader, FILE* file)
{
    fwrite(fileHeader.index, 1, sizeof(fileHeader.index), file);
    fwrite(fileHeader.version, 1, sizeof(fileHeader.version), file);
}
