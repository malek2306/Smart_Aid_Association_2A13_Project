#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "evenement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_afficher_clicked();

    void on_pushButton_clicked();

    void on_pushButton_supp_clicked();

    void on_event_activated(const QModelIndex &index);

    void on_pushButton_modif_clicked();

private:


    Ui::MainWindow *ui;
    evenement e ;

};
#endif // MAINWINDOW_H
