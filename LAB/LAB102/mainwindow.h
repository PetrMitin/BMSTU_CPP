#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Q3DSurface>
#include <QtMath>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void generatePointsFile();

    void fillSurfaceDataSeries();

private:
    QSurface3DSeries *dataSeries;

    const QString pointsFilepath = "C://Users/peter/BMSTU/BMSTU_CPP/LAB/LAB102/points.txt";

    const float xLeftBound = M_PI_4 * -1;
    const float xRightBound = M_PI_4 * 3;
    const float precision = 0.01;
};
#endif // MAINWINDOW_H
