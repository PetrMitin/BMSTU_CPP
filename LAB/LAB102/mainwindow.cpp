#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Q3DSurface *graph = new Q3DSurface();
    graph->setFlags(graph->flags() ^ Qt::FramelessWindowHint);
    graph->axisX()->setRange(-0.8, 2.4);
    graph->axisY()->setRange(-1, 1);
    graph->axisZ()->setRange(-1, 1);
    QWidget *container = QWidget::createWindowContainer(graph, this);
    container->setGeometry(QRect(0, 0, 1000, 800));
    //this->generatePointsFile();
    this->fillSurfaceDataSeries();
    graph->addSeries(this->dataSeries);
    this->resize(QSize(1800, 1000));
}

MainWindow::~MainWindow()
{
    delete this->dataSeries;
}

void MainWindow::generatePointsFile() {
    QFile pointsFile(this->pointsFilepath);
    if (pointsFile.open(QIODevice::WriteOnly)) {
        QTextStream pointsFileStream(&pointsFile);
        int rowCount = (this->xRightBound - this->xLeftBound) / this->precision;
        for (int i = 0; i < rowCount; i++) {
            int pointsInRowCount = 2 * M_PI / this->precision + 1;
            float currX = qMin(this->xRightBound, (i * this->precision + this->xLeftBound));
            float currRadius = qAbs(qSin(currX));
            for (int j = 0; j <= pointsInRowCount; j++) {
                float currAngle = j * this->precision;
                float currY = currRadius * qCos(currAngle);
                float currZ = currRadius * qSin(currAngle);
                pointsFileStream << i << ' ' << currX << ' ' << currY << ' ' << currZ << '\n';
            }
        }
        pointsFile.close();
    }
}

void MainWindow::fillSurfaceDataSeries() {
    QFile pointsFile(this->pointsFilepath);
    if (pointsFile.open(QIODevice::ReadOnly)) {
        QTextStream pointsFileStream(&pointsFile);
        QSurfaceDataArray *dataArray = new QSurfaceDataArray;
        while(!pointsFileStream.atEnd()) {
            QStringList coordinates = pointsFileStream.readLine().split(' ');
            int currRow = coordinates[0].toInt();
            float currX = coordinates[1].toFloat();
            float currY = coordinates[2].toFloat();
            float currZ = coordinates[3].toFloat();
            if ((*dataArray).length() <= currRow) dataArray->append(new QSurfaceDataRow);
            *((*dataArray)[currRow]) << QVector3D(currX, currY, currZ);
        }
        pointsFile.close();

        QSurfaceDataProxy *dataProxy = new QSurfaceDataProxy();
        dataProxy->resetArray(dataArray);
        this->dataSeries = new QSurface3DSeries(dataProxy);
        this->dataSeries->setFlatShadingEnabled(true);
        this->dataSeries->setDrawMode(QSurface3DSeries::DrawSurface);

        QLinearGradient gr;
        gr.setColorAt(0.0, Qt::blue);
        gr.setColorAt(0.33, Qt::green);
        gr.setColorAt(0.67, Qt::yellow);
        gr.setColorAt(1.0, Qt::red);
        this->dataSeries->setBaseGradient(gr);
        this->dataSeries->setColorStyle(Q3DTheme::ColorStyleRangeGradient);
    } else {
        QMessageBox::warning(this, "Error", "Could not open data file");
    }
}
