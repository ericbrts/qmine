#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>


namespace Navigation
{
  class NavPresenter : public QObject
  {
    Q_OBJECT

  public:
    NavPresenter() = delete;
    NavPresenter(const std::string & qmlEntryPoint);

  public slots:
    //void loadPage(const QString & pageName);
    //void onPageLoaded();

  private:
    QQmlApplicationEngine mEngine;
    QObject *mPageLoader;
  };
}