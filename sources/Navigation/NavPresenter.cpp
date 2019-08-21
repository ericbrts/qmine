#include "Navigation/NavPresenter.h"

#include <QQuickItem>
#include <QDebug>
#include <QQmlContext>
#include <QGuiApplication>


namespace Navigation
{
  NavPresenter::NavPresenter(const std::string & qmlEntryPoint)
    : mPageLoader(nullptr)
  {
    QObject::connect(&mEngine, &QQmlApplicationEngine::objectCreated, this, &NavPresenter::onMainObjectCreated, Qt::DirectConnection);
    QObject::connect(&mEngine, &QQmlApplicationEngine::quit, &QGuiApplication::quit);

    mEngine.addImportPath(QStringLiteral(":/"));
    mEngine.rootContext()->setContextProperty(QStringLiteral("navPresenter"), this);
    mEngine.load(QUrl(QString::fromStdString(qmlEntryPoint)));
  }

  void NavPresenter::AddPage(const QString & pageName, std::unique_ptr<APage> page)
  {
    mPageList[pageName] = std::move(page);
  }

  void NavPresenter::loadPage(const QString & pageName)
  {
    auto pageIt = mPageList.find(pageName);
    if (pageIt == mPageList.end())
    {
      throw std::runtime_error("Page not found: " + pageName.toStdString());
    }

    const auto & page = pageIt->second;
    page->Load(mEngine.rootContext());
    mPageLoader->setProperty("source", page->GetUrl());
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
