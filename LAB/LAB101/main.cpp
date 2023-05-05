#include <QApplication>
#include <Qt3DExtras>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QMesh>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[])
{
QApplication app(argc, argv);

// Создание окна
Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
QWidget* container = QWidget::createWindowContainer(view);
container->setMinimumSize(QSize(800, 600));

// Создание вертикального макета и добавление виджета в него
QVBoxLayout* layout = new QVBoxLayout();
layout->addWidget(container);

// Создание сущности
Qt3DCore::QEntity* entity = new Qt3DCore::QEntity();

// Создание и настройка компонента QMesh
Qt3DRender::QMesh* mesh = new Qt3DRender::QMesh();
mesh->setSource(QUrl::fromLocalFile("C://Users/peter/Downloads/Body1.obj")); // Загрузка модели линии

// Добавление компонента QMesh к сущности
entity->addComponent(mesh);

// Создание контроллера орбитальной камеры
Qt3DExtras::QOrbitCameraController* cameraController = new Qt3DExtras::QOrbitCameraController(entity);
cameraController->setLinearSpeed(50.0f);
cameraController->setLookSpeed(180.0f);
cameraController->setCamera(view->camera());

// Установка корневой сущности
view->setRootEntity(entity);

// Отображение окна
QWidget* window = new QWidget();
window->setWindowTitle(QStringLiteral("Qt3D Line Example"));
window->setLayout(layout);
window->show();

return app.exec();
}
