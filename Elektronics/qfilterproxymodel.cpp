#include "qfilterproxymodel.h"
#include "qtablemodeladapter.h"

using std::string;

QFilterProxyModel::QFilterProxyModel(QObject* parent, QComboBox* s): QSortFilterProxyModel (parent), searchType(s)
{

}

bool QFilterProxyModel::insertRows(int begin, int count, const QModelIndex& index)
{
    bool result = sourceModel()->insertRows(begin, count, index);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::removeRows(int begin, int count, const QModelIndex& index)
{
    bool result = sourceModel()->removeRows(begin, count, index);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::info(const QModelIndex& i)
{
    bool result = static_cast<QTableModelAdapter*>(sourceModel())->info(i);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::filterAcceptsRow(int row_source, const QModelIndex&) const
{
    //QModelIndex index_source = sourceModel()->index(row_source,0);
    return static_cast<QTableModelAdapter*>(sourceModel())->matchRegExp(row_source, filterRegExp(),searchType->currentText());
}

bool QFilterProxyModel::save(std::string s)
{
    static_cast<QTableModelAdapter*>(sourceModel())->save(s);
    return true;
}

bool QFilterProxyModel::load(std::string s)
{
    static_cast<QTableModelAdapter*>(sourceModel())->load(s);
    return false;
}
