#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QString>
#include <QUrl>


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
    void onPageLoaded();

  private slots:
    void onMainObjectCreated(QObject *object, const QUrl &url);

  private:
    QQmlApplicationEngine mEngine;
    QObject *mPageLoader;
  };
}