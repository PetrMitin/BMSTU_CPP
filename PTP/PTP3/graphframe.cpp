#include "graphframe.h"

GraphFrame::GraphFrame(QWidget *parent) : QFrame(parent) {
    this->chartSeries = new QBarSeries();
    QChart *chart = new QChart();
    chart->addSeries(this->chartSeries);
    chart->setTitle("Stadiums chart");
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("Stadiums");
    chart->addAxis(axisX, Qt::AlignBottom);
    this->chartSeries->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 8);
    chart->addAxis(axisY, Qt::AlignLeft);
    this->chartSeries->attachAxis(axisY);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    this->chartView = new QChartView(chart);
    this->chartView->setGeometry(QRect(300, 300, 600, 400));
}
GraphFrame::~GraphFrame() {
    delete this->chartSeries;
    delete this->chartView;
}
void GraphFrame::fillChart(std::vector<Match> &matches) {
    this->chartSeries->clear();
    QMap<QString, int> stadiums;
    for (auto& match : matches) {
        QString stadium = match.stadium;
        if (stadiums.contains(stadium)) stadiums[stadium]++;
        else stadiums.insert(stadium, 1);
    }
    for (QString& stadium : stadiums.keys()) {
        QBarSet *newSet = new QBarSet(stadium);
        *newSet << stadiums[stadium];
        this->chartSeries->append(newSet);
    }
}
void GraphFrame::show() {
    this->chartView->show();
}
void GraphFrame::close() {
    this->chartView->close();
}
