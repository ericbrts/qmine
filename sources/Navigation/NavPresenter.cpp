#include "Navigation/NavPresenter.h"

#include <QQuickItem>
#include <QDebug>
#include <QQmlContext>


namespace Navigation
{
  NavPresenter::NavPresenter(const std::string & qmlEntryPoint)
    : mPageLoader(nullptr)
  {
    QObject::connect(&mEngine, &QQmlApplicationEngine::objectCreated, this, &NavPresenter::onMainObjectCreated, Qt::DirectConnection);

    mEngine.addImportPath(QStringLiteral(":/"));
    mEngine.rootContext()->setContextProperty(QStringLiteral("navPresenter"), this);
    mEngine.load(QUrl(QString::fromStdString(qmlEntryPoint)));
  }

  void NavPresenter::onPageLoaded()
  {

  }

  void NavPresenter::onMainObjectCreated(QObject * mainObject, const QUrl &url)
  {
    if (mainObject == nullptr)
    {
      throw std::runtime_error("QML entry point was not properly created");
    }

    mPageLoader = mainObject->findChild<QObject*>("pageLoader");
    if (mPageLoader == nullptr)
    {
      throw std::runtime_error("QML entry was not properly created");
    }
    QObject::connect(mPageLoader, SIGNAL(loaded()), this, SLOT(onPageLoaded()));  
  }
}
