#include "qtablelistview.h"

#include <QMouseEvent>

TableView::TableView(QWidget* parent): QTableView(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

QSize TableView::sizeHint() const
{
    return QSize(400, 600);

}
bool TableView::showGrid() const
{
    return false;
}
void TableView::mousePressEvent(QMouseEvent* event)
{
    if (!indexAt(event->pos()).isValid()) {
       clearSelection();
       selectionModel()->clearCurrentIndex();
   }
   // altrimenti richiama il comportamento standard della QTableView (che seleziona l'elemento cliccato)
   QTableView::mousePressEvent(event);
}
