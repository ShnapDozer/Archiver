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
        unsigned int compressionSize;
        unsigned char args[3] { '0', '0', '0' };
    };

    void showDoneMessage(const char* msg, const char* title);
    char* toChar(const QString& text);
    qint64 getFileSize(const QString& filePath);

    FileHeader readFileHeader(FILE* file);
    void writeFileHeader(FileHeader fileHeader, FILE* file);

    QVector<MetaData> readMetaData(FILE* file);
    void writeMetaData(const QVector<MetaData> &metaData, FILE* file);

    void writeFile(const QString &inFile, FILE* outFile, bool deleteFile = false);
}

#endif // COMMON_H
