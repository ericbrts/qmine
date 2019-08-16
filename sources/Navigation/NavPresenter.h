#pragma once

#include <map>
#include <memory>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class NavPresenter : public QObject
  {
    Q_OBJECT

  public:
    NavPresenter() = delete;
    NavPresenter(const std::string & qmlEntryPoint);
    
    void AddPage(const QString & pageName, std::unique_ptr<APage> page);

  public slots:
    void loadPage(const QString & pageName);
    void onPageLoaded();

  private slots:
    void onMainObjectCreated(QObject *object, const QUrl &url);

  private:
    QQmlApplicationEngine mEngine;
    QObject *mPageLoader;

    std::map<QString, std::unique_ptr<APage>> mPageList;
  };
}