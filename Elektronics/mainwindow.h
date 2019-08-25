#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
class TableView;
class QTableModelAdapter;
class QFilterProxyModel;
class AddItemWidget;
class ItemInfo;
class QLineEdit;
class SearchWidget;

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    TableView* view;
    QString fileName;
    QTableModelAdapter* model;
    QFilterProxyModel* proxy;
    AddItemWidget* add;
    SearchWidget* search;
    QLineEdit* searchbar;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    QSize sizeHint() const override;

private slots:
    void addComputer();
    void removeComputer();
    void info();
    void textFilterChanged();
    void save();
    void load();
};

#endif // MAINWINDOW_H
