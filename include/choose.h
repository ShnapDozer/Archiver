#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>

namespace Ui {
class Choose;
}

// Главное диалоговое окно приложения:
class Choose : public QDialog
{
    Q_OBJECT
    
public:
    // Конструктор:
    explicit Choose(QWidget *parent = 0);

    // Деструктор:
    ~Choose();
    
private:
    Ui::Choose *ui;

private slots:
    void showCompressDialog();
    void showDecompressDialog();
};

#endif // CHOOSE_H
