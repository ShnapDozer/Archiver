#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QDataStream>

namespace Common {

    struct FileHeader{
        unsigned char index[3] {'U', 'S', 'A'};
        int version [3] {1,0,0};
    };

    struct MetaData{
        QString fileName;
        unsigned int nameSize;
        unsigned int originalSize;
        unsigned int compressionSize;
        unsigned char args[3] { '0', '0', '0' };
    };

    void showDoneMessage(const char* msg, const char* title);
    char* toChar(const QString& text);
    qint64 getFileSize(const QString& filePath);

    FileHeader readFileHeader(QDataStream &file);
    void writeFileHeader(FileHeader fileHeader, QDataStream &file);

    QVector<MetaData> readMetaData(QDataStream &file);
    void writeMetaData(QVector<MetaData> metaData, QDataStream &file);

    void writeFile(const QString &inFile, QDataStream &outFile, bool deleteFile = false);
}

#endif // COMMON_H
