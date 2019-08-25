#ifndef QFILTERPROXYMODEL_H
#define QFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QComboBox>


class QFilterProxyModel : public QSortFilterProxyModel
{
private:
    QComboBox* searchType;
public:
    QFilterProxyModel(QObject* = nullptr, QComboBox* = new QComboBox());

    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool info(const QModelIndex& = QModelIndex());
    bool save(std::string);
    bool load(std::string);
protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // QFILTERPROXYMODEL_H
