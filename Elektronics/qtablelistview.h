#ifndef QTABLELISTVIEW_H
#define QTABLELISTVIEW_H

#include <QTableView>

class TableView : public QTableView
{
public:
    TableView(QWidget* parent);
    QSize sizeHint() const;
    bool showGrid() const;
    void mousePressEvent(QMouseEvent* event);
};


#endif // QTABLELISTVIEW_H
