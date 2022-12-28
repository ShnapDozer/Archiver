#ifndef ENCODING_H
#define ENCODING_H

#include <QDialog>

#include "include/fileEncodewidget.h"

namespace Ui {
class Encoding;
}

class Encoding : public QDialog
{
    Q_OBJECT
    
public:

    explicit Encoding(QWidget *parent = 0);
    ~Encoding();

    virtual void dragEnterEvent(QDragEnterEvent *event) override;
    virtual void dropEvent(QDropEvent *event) override;

private:
    Ui::Encoding *ui;
    QVector<FileViewWidget*> files;

public slots:
    void onBrowsButtonClicked();
    void compressFiles();
};

#endif // ENCODING_H
