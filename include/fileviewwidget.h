#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QWidget>
#include <QFileInfo>

#include "include/common.h"

namespace Ui {
class FileViewWidget;
}

class FileViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileViewWidget(const QString &filePath, QWidget *parent = 0);
    ~FileViewWidget();

    QStringList getArgs();
    QString getFilePath();
    Common::MetaData getMetaData();


private:
    Ui::FileViewWidget *ui;
    QFileInfo _fileInfo;

};

#endif // FILEVIEWWIDGET_H
