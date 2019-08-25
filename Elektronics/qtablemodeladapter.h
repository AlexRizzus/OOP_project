#ifndef QTABLEMODELADAPTER_H
#define QTABLEMODELADAPTER_H

#include <QAbstractTableModel>

class Model;
class AddItemWidget;
class SearchWidget;

class QTableModelAdapter : public QAbstractTableModel
{
private:
    Model* model;
    AddItemWidget* add;
    SearchWidget* search;
public:
    QTableModelAdapter(QObject* parent = nullptr, AddItemWidget* = nullptr, SearchWidget* = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex & index,const QVariant& value, int role);
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool info(const QModelIndex& = QModelIndex());
    bool matchRegExp(int r, const QRegExp&, const QString&);
    bool save(std::string);
    bool load(std::string);
};

#endif // QTABLEMODELADAPTER_H
