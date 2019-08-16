#include "QMine/NavPresenter.h"

#include <QQuickItem>
#include <QDebug>
#include <QQmlContext>


namespace Navigation
{
  NavPresenter::NavPresenter(const std::string & qmlEntryPoint)
    : mPageLoader(nullptr)
  {
    mEngine.addImportPath(QStringLiteral("qrc:///"));
    mEngine.rootContext()->setContextProperty(QStringLiteral("navPresenter"), this);
    mEngine.load(QUrl(QString::fromStdString(qmlEntryPoint)));
    auto mainItem = mEngine.rootObjects().first();
    mPageLoader = mainItem->findChild<QObject*>("pageLoader");
    if (mPageLoader)
      QObject::connect(mPageLoader, SIGNAL(loaded()), this, SLOT(onPageLoaded()));
    else
      qDebug() << "Could not find pageLoader Item in main.qml";
  }
}