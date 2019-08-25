#include "qtablemodeladapter.h"
#include "Model.h"
#include "additemwidget.h"
#include "productinfo.h"
#include "searchwidget.h"

QTableModelAdapter::QTableModelAdapter(QObject* parent, AddItemWidget* a, SearchWidget* s): QAbstractTableModel(parent), add(a), search(s)
{
    model = new Model();
}

int QTableModelAdapter::columnCount(const QModelIndex&) const
{
    return 3;
}
int QTableModelAdapter::rowCount(const QModelIndex&) const
{
    return static_cast<int>(model->getSize());
}

QVariant QTableModelAdapter::headerData(int column, Qt::Orientation ori, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if(ori == Qt::Horizontal)
        switch(column)
        {
            case 0:
            return QString("Nome");
        case 1:
            return QString("Marca");
        case 2:
            return QString("Tipo");
        default:
            return QVariant();
        }
    return QVariant();
}
QVariant QTableModelAdapter::data(const QModelIndex& index, int role) const
{
    if (static_cast<unsigned int>(index.row()) >= model->getSize()|| !index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        Container<articolo>::iteratore it = model->begin();
        for(int i = 0; i < index.row(); i++)
        {
            it++;
        }
        if (index.column() == 0)
        {
        string s = (*it)->getNome();
        return QString::fromStdString((*it)->getNome());
        }
        else if (index.column() == 1)
        {
            return QString::fromStdString((*it)->getMarca());
        }
        else if (index.column() == 2)
        {
            Computer* c = (*it).p;
            string s = c->getTipo();
            return QString::fromStdString(s);
        }
    }

    return QVariant();
}

bool QTableModelAdapter::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (!index.isValid() && role == Qt::EditRole)
        return false;
    switch(index.column())
    {
    case 0:
        model->getElement(index.row())->setNome(value.toString().toStdString()); break;
    case 1:
        model->getElement(index.row())->setPrezzo(value.toString().toDouble()); break;
    case 2:
        model->getElement(index.row())->setMarca(value.toString().toStdString()); break;
    }
    emit dataChanged(index, index);
    return true;
}

bool QTableModelAdapter::insertRows(int begin, int count, const QModelIndex& index)
{
    beginInsertRows(index, begin, begin + count - 1);
    string s = add->getTipo();
    Computer* p = nullptr;
    if (s == "Computer")
    {
        p = new Computer(add->getNome(), add->getRam(), add->getCPU(), add->getGPU(), add->getHardDisk(), add->getCool(), add->getPrezzo(), add->getColore(), add->getMarca());
    }
    else if (s == "Tablet")
    {
        p = new Tablet(add->getNome(), add->getRam(), add->getCPU(), add->getGPU(), add->getHardDisk(), add->getCool(), add->getPrezzo(), add->getColore(), add->getMarca(), add->getBattery(), add->gettouchTablet(), add->getmultitouchTablet(), add->getPennaTablet());
    }
    else if (s == "PC")
    {
        p = new PC(add->getNome(), add->getRam(), add->getCPU(), add->getGPU(), add->getHardDisk(), add->getCool(), add->getPrezzo(), add->getColore(), add->getMarca(), add->getBattery(), add->getWeightPC(), new class Tastiera(add->getTipoTast(), add->getretroTast()), add->getFotocamera());
    }
    else if (s == "TwoInOne")
    {
        p = new TwoInOne(add->getNome(), add->getRam(), add->getCPU(), add->getGPU(), add->getHardDisk(), add->getCool(), add->getPrezzo(), add->getColore(), add->getMarca(), add->getBattery(), add->getWeightPC(), new class Tastiera(add->getTipoTast(), add->getretroTast()), add->getFotocamera(), add->gettouchTablet(), add->getmultitouchTablet(), add->getPennaTablet(), add->getTastTwoInOne());
    }
    else
    {
        p = new SmartPhone(add->getNome(), add->getRam(), add->getCPU(), add->getGPU(), add->getHardDisk(), add->getCool(), add->getPrezzo(), add->getColore(), add->getMarca(), add->getBattery(), add->getwifi(), add->getSim(), add->getGPS(), add->getFotocamera(), add->getFotocamera(), add->getTouchPhone(), add->get4g(), add->getSd(), add->getSensore(), add->getSchermo(), add->getmultitouchSmart(), add->getPeso(), add->getScocca(), add->getOS());
    }
    articolo a = articolo(p);
    model->add(a);
    endInsertRows();
    return true;
}

bool QTableModelAdapter::removeRows(int begin, int count, const QModelIndex& index)
{
        beginRemoveRows(index, begin, begin+count - 1);
        model->remove(static_cast<unsigned int>(begin));
        endRemoveRows();
    return true;
}

bool QTableModelAdapter::info(const QModelIndex& i)
{
    Computer* p = model->getElement(i.row());
    ProductInfo* window = new ProductInfo(p);
    window->setWindowFlag(Qt::Window);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
    return true;
}

bool QTableModelAdapter::matchRegExp(int r, const QRegExp& s, const QString& c)
{
    if (model->getElement(r)->getCPU()->getNome() != search->getCpu() && search->getCpu() != "none")
    {
        return false;
    }
    if (std::to_string(model->getElement(r)->getHDD()->getGb()) != search->getHdd() && search->getHdd() != "none")
    {
        return false;
    }
    if ((!dynamic_cast<SmartPhone*>(model->getElement(r)) && search->getSchermo() != 0) || (dynamic_cast<SmartPhone*>(model->getElement(r)) && static_cast<SmartPhone*>(model->getElement(r))->getSchermo()->getSize() < search->getSchermo() && search->getSchermo() != 0))
    {
        return false;
    }
    if (std::to_string(model->getElement(r)->getGPU()->getMemory()) != search->getGpu() && search->getGpu() != "none")
    {
        return false;
    }
    if (model->getElement(r)->getPrezzo() <= search->getValuePrezzo() && model->getElement(r)->getPrezzo() != 0)
    {
        return false;
    }
    if (std::to_string(model->getElement(r)->getRam()->getGb()) != search->getMemory() && search->getMemory() != "none")
    {
        return false;
    }
    if (c == QString::fromStdString("Nome"))
    {
    return QString::fromStdString(model->getElement(r)->getNome()).contains(s);
    }
    if (c == "CPU")
    {
        return QString::fromStdString(model->getElement(r)->getCPU()->getNome()).contains(s);
    }
    if (c == "GPU")
    {
        return QString::fromStdString(model->getElement(r)->getGPU()->getNome()).contains(s);
    }
    if (c == "Marca")
    {
        return QString::fromStdString(model->getElement(r)->getMarca()).contains(s);
    }
    if (c == "Ram")
    {
        return QString::fromStdString(model->getElement(r)->getRam()->getNome()).contains(s);
    }
    if (c == "Tipo")
    {
        return QString::fromStdString(model->getElement(r)->getTipo()).contains(s);
    }
    return  false;
}

bool QTableModelAdapter::save(std::string s)
{
    model->save(s);
    return true;
}

bool QTableModelAdapter::load(std::string s)
{
    layoutAboutToBeChanged();
    model->load(s);
    layoutChanged();
    return true;
}

