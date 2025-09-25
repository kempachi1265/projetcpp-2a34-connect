#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    // Navigation pages
    void showFinancePage();
    void showContentCreatorPage();
    void showSponsorPage();
    void showEmployeePage();

    // Boutons Finance
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onClearClicked();

    // Nouveaux boutons
    void onSortByMontantClicked();
    void onSearchByIdClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
