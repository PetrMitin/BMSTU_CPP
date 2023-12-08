#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QPoint>
#include <cmath>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Q3DSurface *graph = new Q3DSurface();
    graph->setFlags(graph->flags() ^ Qt::FramelessWindowHint);
    graph->axisX()->setRange(-0.8, 2.4);
    graph->axisY()->setRange(-1, 1);
    graph->axisZ()->setRange(-1, 1);
    delete this->ui->surfaceWidget;
    this->ui->surfaceWidget = QWidget::createWindowContainer(graph, this);
    this->ui->surfaceWidget->setGeometry(QRect(0, 100, 700, 500));
    //this->generatePointsFile();
    this->fillSurfaceDataSeries();
    graph->addSeries(this->dataSeries);
    this->ui->selectMarkOptions->addItem("-No Mark-");
    this->ui->selectMarkOptions->setItemData(0, 0, Qt::UserRole - 1);
    this->ui->selectMarkOptions->addItems(this->getExistingMarksOptions());
    this->ui->selectMarkOptions->setCurrentIndex(0);
    this->ui->saveMarkButton->setDisabled(true);

    connect(this->dataSeries, SIGNAL(itemLabelChanged(QString)), this, SLOT(updateCurrentMark(QString)));
    connect(this->ui->selectMarkOptions, SIGNAL(currentTextChanged(QString)), this, SLOT(setSelectedMark()));
    connect(this->ui->saveMarkButton, SIGNAL(clicked(bool)), this, SLOT(saveCurrentMark()));
    connect(this->ui->deleteMarkButton, SIGNAL(clicked(bool)), this, SLOT(deleteMark()));
    connect(this->ui->closeAppButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->dataSeries;
}

void MainWindow::generatePointsFile() {
    QFile pointsFile(this->pointsFilepath);
    if (pointsFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
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
    if (pointsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
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

void MainWindow::setSelectedMark() {
    if (this->ui->selectMarkOptions->currentIndex() != 0) {
        QString selectedMarkTitle = this->ui->selectMarkOptions->currentText();
        QStringList coordsList = selectedMarkTitle.split('(')[1].remove(")").split(", ");
        this->setMark(coordsList[0].toFloat(), coordsList[1].toFloat(), coordsList[2].toFloat());
    }
}

void MainWindow::updateCurrentMark(QString label) {
    if (label.length() > 0) {
        QStringList coords = label.split(',');
        this->currX = coords[0].toFloat();
        this->currY = coords[1].toFloat();
        this->currZ = coords[2].toFloat();
        this->ui->saveMarkButton->setDisabled(false);
    } else {
        this->currX = -10;
        this->currY = -10;
        this->currZ = -10;
        this->ui->saveMarkButton->setDisabled(true);
    }
}

void MainWindow::setMark(float x, float y, float z) {
    int rowPosition = std::ceil((x - this->xLeftBound) / this->precision);
    QSurfaceDataRow *currentRow = this->dataSeries->dataProxy()->array()->at(qMin(rowPosition, this->dataSeries->dataProxy()->array()->length()-1));
    for (int i = 0; i < currentRow->length(); i++) {
        QSurfaceDataItem currentPoint = currentRow->at(i);
        float roundedCurrY = std::round(currentPoint.y() * 100) / 100;
        float roundedCurrZ = std::round(currentPoint.z() * 100) / 100;
        if (y == roundedCurrY && z == roundedCurrZ) this->dataSeries->setSelectedPoint(QPoint(rowPosition, i));
    }
}

QString MainWindow::saveMark(float x, float y, float z) {
    QString newMarkName = QInputDialog::getText(this, "Create mark", "Enter name of the new mark");
    QString result = "";
    if (newMarkName.length()) {
        QFile marksFile(this->marksFilepath);
        if(marksFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            QTextStream t(&marksFile);
            t << newMarkName << ' ' << x << ' ' << y << ' ' << z << '\n';
            marksFile.close();
            result = newMarkName;
        }
    }
    return result;
}

void MainWindow::saveCurrentMark() {
    if (this->currX != -10 && this->currY != -10 && this->currZ != -10) {
        QString newMarkName = this->saveMark(this->currX, this->currY, this->currZ);
        if (newMarkName.length()) {
            this->ui->selectMarkOptions->addItem(newMarkName + " (" + QString::number(this->currX) + ", " + QString::number(this->currY) + ", " + QString::number(this->currZ) + ")");
            this->ui->selectMarkOptions->setCurrentIndex(this->ui->selectMarkOptions->count() - 1);
        }
    }
}

void MainWindow::deleteMark() {
    QString markToDeleteName = QInputDialog::getText(this, "Delete mark", "Enter name of mark to delete");
    if (markToDeleteName.length()) {
        bool isFound = false;
        QFile marksFile(this->marksFilepath);
        if(marksFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QString s;
            QTextStream t(&marksFile);
            int counter = 1;
            while(!t.atEnd())
            {
                QString line = t.readLine();
                if(!(line.split(' ')[0] == markToDeleteName)) s.append(line + "\n");
                else {
                    isFound = true;
                    if (this->ui->selectMarkOptions->currentIndex() == counter) {
                        this->dataSeries->setSelectedPoint(this->dataSeries->invalidSelectionPosition());
                        this->ui->selectMarkOptions->setCurrentIndex(0);
                    }
                    this->ui->selectMarkOptions->removeItem(counter);
                }
                counter++;
            }
            marksFile.resize(0);
            t << s;
            marksFile.close();
        }
        if (!isFound) QMessageBox::critical(this, "Error", "Mark with such name doesn't exist!");
    }
}

QStringList MainWindow::getExistingMarksOptions() {
    QStringList result;
    QFile marksFile(this->marksFilepath);
    if(marksFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream t(&marksFile);
        while(!t.atEnd())
        {
            QStringList nameAndCoords = t.readLine().split(' ');
            QString formattedOption = nameAndCoords[0] + " (" + nameAndCoords[1] + ", " + nameAndCoords[2] + ", " + nameAndCoords[3] + ")";
            result.append(formattedOption);
        }
    }
    return result;
}
