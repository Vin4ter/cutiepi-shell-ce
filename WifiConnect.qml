import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: rectangle1
    color:"#2E3440"
 width: 400
 height: 150
 radius: 15
 anchors.verticalCenter: parent.verticalCenter
 anchors.verticalCenterOffset: -100
 anchors.horizontalCenter: parent.horizontalCenter
 Text {
     width: 209
     height: 36

     text: "Please enter the password"
     horizontalAlignment: Text.AlignHCenter
     verticalAlignment: Text.AlignVCenter
     minimumPointSize: 14
     minimumPixelSize: 14
     anchors.verticalCenterOffset: -57
     color: "#ECEFF4"
     anchors{
         verticalCenter: parent.verticalCenter
         left: parent.left
         leftMargin: 96
     }
     font.pointSize: 12
 }

 TextField {
     id: passwordt
     x: 12
     y: 48
     width: 376
     height: 32
     placeholderText: qsTr("password")
            background: Rectangle {
                radius: 2
                implicitWidth: 100
                implicitHeight: 24
                border.color: "#333"
                border.width: 1
            }

 }

 Button {
     id: button
     y: 92
     text: qsTr("done")

     background: Rectangle {
                implicitWidth: 100
                implicitHeight: 40
                color: button.down ? "#d6d6d6" : "#f6f6f6"
                border.color: "#26282a"
                border.width: 1
                radius: 4

     }
     onClicked: {
  root.state="normal"
      wifiManager.connectWifi(select_ssid, passwordt.text)
     }
 }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
