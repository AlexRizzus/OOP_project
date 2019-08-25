#include "mainwindow.h"
#include "qtablemodeladapter.h"
#include "qfilterproxymodel.h"
#include "qtablelistview.h"
#include "additemwidget.h"
#include "productinfo.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLayout>
#include <QMenuBar>
#include <QMessageBox>
#include "searchwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), view(new TableView(this)), searchbar(new QLineEdit(this)), search(new SearchWidget(this))
{
    QComboBox* searchType = new QComboBox(this);
    searchType->addItem("Nome");
    searchType->addItem("CPU");
    searchType->addItem("GPU");
    searchType->addItem("Ram");
    searchType->addItem("Marca");
    searchType->addItem("Tipo");

    proxy = new QFilterProxyModel(this,searchType);
    add = new AddItemWidget(this);
    model = new QTableModelAdapter(this, add, search);
    proxy->setSourceModel(model);
    view->setModel(proxy);
    setFixedSize(1800,900);

    for (int col=0; col<3; col++)
    {
       view->setColumnWidth(col,342);
    }
    setWindowTitle(tr("Elektronics"));
    QMenuBar* menu = new QMenuBar(this);
    QAction* salva = new QAction("save",this);
    QAction* carica = new QAction("load",this);
    menu->addAction(salva);
    menu->addAction(carica);
    QPushButton* addButton = new QPushButton("Aggiungi", this);
    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    QPushButton* infoButton = new QPushButton("Info", this);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* searchLayout = new QHBoxLayout();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    QHBoxLayout* centralLayout = new QHBoxLayout();
    QVBoxLayout* viewbuttonLayout = new QVBoxLayout();
    mainLayout->addWidget(menu);
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(searchType);
    viewbuttonLayout->addLayout(searchLayout);
    viewbuttonLayout->addWidget(view);
    viewbuttonLayout->addLayout(buttonsLayout);
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(infoButton);
    buttonsLayout->addWidget(removeButton);
    centralLayout->addWidget(search);
    centralLayout->addLayout(viewbuttonLayout);
    centralLayout->addWidget(add);
    mainLayout->addLayout(centralLayout);
    setLayout(mainLayout);
    add->setFixedWidth(500);


    //CONNECT
    connect(addButton, SIGNAL(clicked()), this, SLOT(addComputer()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeComputer()));
    connect(infoButton, SIGNAL(clicked()), this, SLOT(info()));
    connect(searchbar,SIGNAL(textChanged(const QString&)),this, SLOT(textFilterChanged()));
    connect(salva,SIGNAL(triggered()),this,SLOT(save()));
    connect(carica,SIGNAL(triggered()),this,SLOT(load()));
    connect(search,SIGNAL(searchChanged()),this,SLOT(textFilterChanged()));
}

MainWindow::~MainWindow()
{
    delete view;
    delete proxy;
    delete add;
}

QSize MainWindow::sizeHint() const
{
    return QSize(1700,1000);
}

void MainWindow::addComputer()
{
    proxy->insertRows(proxy->rowCount(), 1);
    view->clearSelection();
    view->selectionModel()->clearCurrentIndex();
    view->selectionModel()->select(proxy->index(model->rowCount() - 1, 0), QItemSelectionModel::Select);
}

void MainWindow::removeComputer()
{
    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
    if (view->selectionModel()->selectedIndexes().isEmpty())
    {

    }
    else
    proxy->removeRows(selection.at(0).row(),1);
}

void MainWindow::info()
{
    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
    if (selection.size() > 0)
        proxy->info(selection.at(0));
}

void MainWindow::textFilterChanged()
{
    QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxy->setFilterRegExp(regex);
}

void MainWindow::save()
{
    fileName = QFileDialog::getSaveFileName(this, tr("Save to a file"), "",tr("XML (*.xml);;All Files (*)"));
    if(!fileName.isEmpty()){
        setWindowTitle(QFileInfo(fileName).fileName() + tr("-- Elektronics"));
        try {
            model->save(fileName.toStdString());
        } catch (std::exception) {
            QMessageBox box(QMessageBox::Warning, "Errore", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
            box.exec();
        }
    }
}

void MainWindow::load()
{
    if (proxy->sourceModel()->rowCount() )
    {
    QMessageBox box(QMessageBox::Warning, "Warning", "Sei sicuro? in questo modo tutti gli oggetti non salvati andranno persi.");
    box.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    box.setDefaultButton(QMessageBox::Save);
    int ret = box.exec();
    if (ret != QMessageBox::Cancel)
    {
        if (ret == QMessageBox::Save)
            save();
        fileName = QFileDialog::getOpenFileName(this,tr("Load from a file"), "",tr("XML (*.xml);;All Files (*)"));
        if(!fileName.isEmpty()){
            setWindowTitle(QFileInfo(fileName).fileName() + tr(" - Elektronics"));
            model->load(fileName.toStdString());
     }
    }
    }
    else
    {
        fileName = QFileDialog::getOpenFileName(this,tr("Load from a file"), "",tr("XML (*.xml);;All Files (*)"));
        if(!fileName.isEmpty()){
            setWindowTitle(QFileInfo(fileName).fileName() + tr(" - Elektronics"));
            model->load(fileName.toStdString());
    }
    }
}

