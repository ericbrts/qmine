#pragma once

#include <QUrl>
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

    QUrl GetUrl() const
    {
      return mQmlPageUrl;
    }

    virtual void Load(QQmlContext * qmlContext) = 0;
    virtual void Unload() = 0;

  protected:
    QUrl mQmlPageUrl;
  };
}
