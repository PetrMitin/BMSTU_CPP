#ifndef GRAPHFRAME_H
#define GRAPHFRAME_H

#include <QFrame>
#include <QtCharts>
#include "match.h"

class GraphFrame : public QFrame
{
    Q_OBJECT

public:
    explicit GraphFrame(QWidget *parent = nullptr);

    ~GraphFrame();

    void fillChart(std::vector<Match> &matches);

public slots:
    void show();

    void close();

private:
    QBarSeries *chartSeries;

    QChartView *chartView;
};

#endif // GRAPHFRAME_H
