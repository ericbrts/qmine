import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4


ApplicationWindow {
  visible: true
  visibility: "AutomaticVisibility"
  width: 1024
  height: 768
  title: qsTr("Mine")
  style: ApplicationWindowStyle {
    background: Rectangle{ anchors.fill: parent; color: "white" }
  }

  Loader { id: pageLoader
    objectName: "pageLoader"
    anchors.fill: parent
  }
}

