#include <QGuiApplication>

#include "Navigation/NavPresenter.h"


namespace
{
  const std::string qmlEntryPoint = "qrc:/Mine/main.qml";
}

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);
  Navigation::NavPresenter navPresenter(qmlEntryPoint);
  return app.exec();
}
