#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexion menu
    connect(ui->btnFinance, &QPushButton::clicked, this, &MainWindow::showFinancePage);
    connect(ui->btnContentCreator, &QPushButton::clicked, this, &MainWindow::showContentCreatorPage);
    connect(ui->btnSponsor, &QPushButton::clicked, this, &MainWindow::showSponsorPage);
    connect(ui->btnEmployee, &QPushButton::clicked, this, &MainWindow::showEmployeePage);

    // Connexion boutons Finance
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(ui->btnEdit, &QPushButton::clicked, this, &MainWindow::onEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::onClearClicked);

    // Connexion nouveaux boutons
    connect(ui->btnSortByMontant, &QPushButton::clicked, this, &MainWindow::onSortByMontantClicked);
    connect(ui->btnSearchById, &QPushButton::clicked, this, &MainWindow::onSearchByIdClicked);

    // Page par défaut
    showFinancePage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Navigation pages ---
void MainWindow::showFinancePage()
{
    ui->formBox->show();
    ui->tableFactures->show();
    // Masquer autres pages si ajoutées
}

void MainWindow::showContentCreatorPage()
{
    ui->formBox->hide();
    ui->tableFactures->hide();
}

void MainWindow::showSponsorPage()
{
    ui->formBox->hide();
    ui->tableFactures->hide();
}

void MainWindow::showEmployeePage()
{
    ui->formBox->hide();
    ui->tableFactures->hide();
}

// --- Boutons Finance ---
void MainWindow::onAddClicked()
{
    int row = ui->tableFactures->rowCount();
    ui->tableFactures->insertRow(row);
    ui->tableFactures->setItem(row, 0, new QTableWidgetItem(ui->lineId->text()));
    ui->tableFactures->setItem(row, 1, new QTableWidgetItem(ui->lineMontant->text()));
    ui->tableFactures->setItem(row, 2, new QTableWidgetItem(ui->dateEmission->date().toString("dd/MM/yyyy")));
    ui->tableFactures->setItem(row, 3, new QTableWidgetItem(ui->dateEcheance->date().toString("dd/MM/yyyy")));
    ui->tableFactures->setItem(row, 4, new QTableWidgetItem(ui->comboStatut->currentText()));
}

void MainWindow::onEditClicked()
{
    int row = ui->tableFactures->currentRow();
    if(row >= 0) {
        ui->tableFactures->setItem(row, 0, new QTableWidgetItem(ui->lineId->text()));
        ui->tableFactures->setItem(row, 1, new QTableWidgetItem(ui->lineMontant->text()));
        ui->tableFactures->setItem(row, 2, new QTableWidgetItem(ui->dateEmission->date().toString("dd/MM/yyyy")));
        ui->tableFactures->setItem(row, 3, new QTableWidgetItem(ui->dateEcheance->date().toString("dd/MM/yyyy")));
        ui->tableFactures->setItem(row, 4, new QTableWidgetItem(ui->comboStatut->currentText()));
    } else {
        QMessageBox::warning(this,"Edit","Veuillez sélectionner une ligne !");
    }
}

void MainWindow::onDeleteClicked()
{
    int row = ui->tableFactures->currentRow();
    if(row >= 0) {
        ui->tableFactures->removeRow(row);
    } else {
        QMessageBox::warning(this,"Delete","Veuillez sélectionner une ligne !");
    }
}

void MainWindow::onClearClicked()
{
    ui->lineId->clear();
    ui->lineMontant->clear();
    ui->dateEmission->setDate(QDate::currentDate());
    ui->dateEcheance->setDate(QDate::currentDate());
    ui->comboStatut->setCurrentIndex(0);
}

// --- Nouveaux boutons ---
void MainWindow::onSortByMontantClicked()
{
    ui->tableFactures->sortItems(1, Qt::AscendingOrder); // colonne Montant
}

void MainWindow::onSearchByIdClicked()
{
    QString idToFind = ui->searchBox->text();
    bool found = false;

    for(int i = 0; i < ui->tableFactures->rowCount(); ++i)
    {
        if(ui->tableFactures->item(i,0)->text() == idToFind)
        {
            ui->tableFactures->selectRow(i);
            found = true;
            break;
        }
    }

    if(!found)
        QMessageBox::information(this, "Recherche", "ID non trouvé !");
}
