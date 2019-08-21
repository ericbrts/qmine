import QtQuick 2.5

Rectangle {
  anchors.fill: parent

  function goTo(pageName)
  {
    if (pageName === "quitApp")
      Qt.quit()
    else
      navPresenter.loadPage(pageName)
  }
}