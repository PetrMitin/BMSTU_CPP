#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Q3DSurface>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void generatePointsFile();

    void fillSurfaceDataSeries();

public slots:
    void setSelectedMark();

    void updateCurrentMark(QString label);

    void saveCurrentMark();

    void deleteMark();

private:
    Ui::MainWindow *ui;

    QSurface3DSeries *dataSeries;

    const QString pointsFilepath = "C://Users/peter/BMSTU/BMSTU_CPP/LAB/LAB11/points.txt";
    const QString marksFilepath = "C://Users/peter/BMSTU/BMSTU_CPP/LAB/LAB11/marks.txt";
    const float xLeftBound = M_PI_4 * -1;
    const float xRightBound = M_PI_4 * 3;
    const float precision = 0.01;
    float currX = 0;
    float currY = 0;
    float currZ = 0;

    QStringList getExistingMarksOptions();

    void setMark(float x, float y, float z);

    QString saveMark(float x, float y, float z);
};
#endif // MAINWINDOW_H
