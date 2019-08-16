#pragma once

#include <QString>
#include <QQmlContext>


namespace Navigation
{
  class APage
  {
  public:
    APage(const QString & qmlPageUrl)
      : mQmlPageUrl(qmlPageUrl)
    {}

    virtual ~APage() = default;

    virtual void load(QQmlContext * qmlContext) = 0;
    virtual void unload() = 0;

  protected:
    QString mQmlPageUrl;
  };
}
