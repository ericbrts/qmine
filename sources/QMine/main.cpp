#include <QGuiApplication>
#include <QString>

#include "Navigation/NavPresenter.h"
#include "Navigation/NavFactory.h"


namespace
{
  const std::string qmlEntryPoint = "qrc:/Mine/main.qml";
  const QString firstPageName = "home";
}

int main(int argc, char* argv[])
{
  QGuiApplication app(argc, argv);
  Navigation::NavPresenter navPresenter(qmlEntryPoint);
  Navigation::NavFactory::BuildPages(navPresenter);
  navPresenter.loadPage(firstPageName);
  return app.exec();
}
