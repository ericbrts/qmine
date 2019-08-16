#include <QGuiApplication>

#include "Navigation/NavPresenter.h"
#include "Navigation/NavFactory.h"


namespace
{
  const std::string qmlEntryPoint = "qrc:/Mine/main.qml";
}

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);
  Navigation::NavPresenter navPresenter(qmlEntryPoint);
  Navigation::NavFactory::BuildPages(navPresenter);
  return app.exec();
}
