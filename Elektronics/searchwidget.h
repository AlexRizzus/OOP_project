#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSlider>

class QLabel;

class SearchWidget : public QWidget
{
    Q_OBJECT
private:
    QComboBox* ramMemory;
    QSlider* sprezzo;
    QLabel* valueprezzo;
    QComboBox* cpu;
    QComboBox* gpuMemory;
    QComboBox* hddMemory;
    QComboBox* sizeSchermo;

public:
    SearchWidget(QWidget* = nullptr);
    std::string getMemory();
    std::string getCpu();
    std::string getGpu();
    int getSchermo();
    std::string getHdd();
    int getValuePrezzo();
signals:
    void searchChanged();
private slots:
    void setValuePrezzo();
};

#endif // SEARCHWIDGET_H
