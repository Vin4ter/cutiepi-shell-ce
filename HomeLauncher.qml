import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
id: homeLauncher
width: view.width
height: view.height-75
//width: 400
//height: 800
x:0
color: "transparent"
//anchors { top: parent.top; topMargin: 85; left: parent.left; right: parent.right; bottom: parent.bottom }
Connections {
      target: appLauncher
      onAppendApp: {
         appListModel.append( { "namec" : name, "iconc": icon, "execc": exec } )
      }
  }

Component.onCompleted: {
    appLauncher.getAppList();
}



Image {
    id: image
    anchors.fill: parent
    source: "icons/bg.jpg"
    anchors.topMargin: 10
    fillMode: Image.PreserveAspectCrop



    ListModel {
            id: appListModel
        }




    GridView {
        id: widgetGrid
        anchors.fill: parent
               model: appListModel
               cellWidth: width / 4
               cellHeight: width / 4
               clip: true

               delegate: Item {
                   width: widgetGrid.cellWidth
                   height: widgetGrid.cellWidth
                       id: appDelegate

                       Image {
                           id: icon
                           x: 8
                           y: 0
                           width: 99
                           height: 107
                           sourceSize.width: 512
                                  sourceSize.height: 512
                           source: iconc
                           fillMode: Image.PreserveAspectFit
                       }

                       Text {
                           id: text1
                           x: 0
                           y: 107
                           color: "white"
                           width: 115
                           height: 25
                           text: namec
                           font.pixelSize: 14
                           horizontalAlignment: Text.AlignHCenter
                           verticalAlignment: Text.AlignVCenter
                       }
                       Text {
                           id: exect
                           visible: false;
                           text: execc
                       }

                       MouseArea{
                             anchors.fill: parent
                             onClicked: {
                                 launcherState.state= "closed"
                                 appLauncher.openApp(exect.text);
                             }
                       }
                   }
               }
           }

MouseArea{
    id: swipeArea
    height: 10
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: parent.top
    anchors.rightMargin: 0
    anchors.leftMargin: 0
    anchors.topMargin: 0
    //}
    /*
   drag.target: homeLauncher
   drag.axis: Drag.YAxis
   drag.minimumY: 590
   drag.maximumY: 85
   */
    onClicked: {

     //launcherState.state= "closed"
        //if (homeLauncher.y > 550) { launcherState.state= "closed" } else {launcherState.state= "opened" }
    }
    onReleased: {
        if(launcherState.state=="closed"){
             launcherState.state= "opened"
        }else{
             launcherState.state= "closed"
        }


       //if (homeLauncher.y < 550) {launcherState.state="opened" } else {launcherState.state = "closed" }
    }

//    onPressed: {
  //         launcherState.state="opened"
    //}
}

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
