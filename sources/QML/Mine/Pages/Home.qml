import QtQuick 2.5
import QtQuick.Controls 2.5
//import QtQml.Models 2.12

Rectangle {
  anchors.fill: parent
  color: "#444444"

  Text { id: title
    anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 20 }
    text: qsTr("Mine")
    color: "#AAAAAA"
    font { family: "Arial"; bold: true; capitalization: Font.SmallCaps; pixelSize: 150 }
    style: Text.Sunken
    styleColor: "white"
  }

  function goTo(pageName)
  {
    if (pageName === "quitApp")
      Qt.quit()
    else
      navPresenter.loadPage(pageName)
  }

  ListModel { id: navButtonModel
    ListElement {
      name: "Start a game"
      destination: "mineGame"
    }
    ListElement {
      name: "Settings"
      destination: "settings"
    }
    ListElement {
      name: "Quit"
      destination: "quitApp"
    }
  }

  Column {
    anchors { horizontalCenter: parent.horizontalCenter; top: title.bottom; topMargin: 60 }
    spacing: 30
    
    Repeater {
      model: navButtonModel
      delegate: Button {
        text: name
        onClicked: goTo(destination)
      }
    }
  }
}
