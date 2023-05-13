import QtQuick 2.14

// setting sheet 
Rectangle {
    id: settingSheet
    width:   setting.width - 20
    height: 600 
    color: "#2E3440"
    anchors { right: parent.right;  }
    y: -600
    radius: 22
    z: 3 

    Connections {
         target: wifiManager

         onPutWifi: {
             console.log(ssid+" "+wsignal+" "+wsec+" "+lindex+ " "+lstatus);


         wifiListModel.append( {"wifiSsid" : ssid, "strength" : wsignal, "rsec" : wsec, "findex" : lindex, "cstatus": lstatus } )
           // playlistModel.append( { "path" : current_line, } )
            //console.log(ssid);
         }
         onClearWifiList:{
          wifiListModel.clear()
         }
         onConnectedWifi:{
             console.log(status) //ok  error
             if(status=="ok"){
                 conected_wifi_ssid=select_ssid
                 select_ssid=""
             }
         }
     }
    Connections {
         target: audioManager
     }



    // volume bar
    Rectangle{
        id: volumeBar
        anchors{
            topMargin: 75
            top: parent.top
            left: parent.left
            right: parent.right
        }
        width: parent.width - 20
        height: 30
        color: "transparent"

        Image {
            id: volumeMuted
            source: "icons/audio-volume-muted-symbolic.svg"
            width: 30; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
            anchors{
                left: parent.left
                leftMargin: 15
                verticalCenter: parent.verticalCenter
            }
        }

        Image {
            id: volumeHigh
            source: "icons/audio-volume-high-symbolic.svg"
            width: 30; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
            anchors{
                right: parent.right
                rightMargin: 20
                verticalCenter: parent.verticalCenter
            }
        }

        Rectangle{
            id: volumeBarTrack
            anchors{
                verticalCenter: parent.verticalCenter
                right: volumeHigh.left
                left: volumeMuted.right
                rightMargin: 20
                leftMargin: 20
            }
            height: 2
            radius: 1
            color: "#ECEFF4"
        }

        Rectangle{
            id: volumeBarThumb
            height: 30
            width: 30
            radius: 15
            y: volumeBarTrack.y - height/2
            x: volumeBarTrack.x + volumeBarTrack.width/2

            MouseArea{
                anchors.fill: parent
                drag.target: volumeBarThumb; drag.axis: Drag.XAxis; drag.minimumX: volumeBarTrack.x; drag.maximumX: volumeBarTrack.x - width + volumeBarTrack.width
            }

            onXChanged: {
                var fullrange = volumeBarTrack.width - volumeBarThumb.width
                var vol = 100*(volumeBarThumb.x - volumeBarTrack.x)/fullrange
                audioManager.setAudioVolume(vol)
                if(vol <= 2)
                    setting.audio.source = "icons/audio-volume-muted-symbolic.svg"

                else if(vol < 25)
                    setting.audio.source = "icons/audio-volume-low-symbolic.svg"
                else if(vol < 75)
                    setting.audio.source = "icons/audio-volume-medium-symbolic.svg"
                else
                    setting.audio.source = "icons/audio-volume-high-symbolic.svg"
            }
        }
    }

    // orientation lock
    Rectangle{
        id: orientationLock
        anchors{
            topMargin: 10
            top: volumeBar.bottom
            left: parent.left
            right: parent.right
        }

        width: parent.width - 25
        height: 40
        color: "transparent"

        Text {
            text: "Orientation Lock"
            color: "#ECEFF4"
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 10
            }
            font.pointSize: 9
        }

        Rectangle{
            id: toggleTrack
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: 20
            }
            width: 60
            height: 30
            radius: 15
            color: sensorEnabled ? "grey" : "limegreen"

            Rectangle{
                id: toggleThumb
                anchors{
                    top: parent.top
                    bottom: parent.bottom
                    right: parent.right
                }
                width: 30
                height: 30
                radius: 15
                color: "white"

                states: [
                    State {
                        name: "enabled"
                        AnchorChanges { target: toggleThumb; anchors.left: undefined; anchors.right: parent.right }
                    },
                    State {
                        name: "disabled"
                        AnchorChanges { target: toggleThumb; anchors.left: parent.left; anchors.right: undefined }
                    }
                ]
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    sensorEnabled = !sensorEnabled
                    if (sensorEnabled)
                        toggleThumb.state = "enabled"
                    else
                        toggleThumb.state = "disabled"
                }
            }
        }
    }

    // separator
    Rectangle{
        id: separator
        anchors{
            right: parent.right
            left:parent.left
            top: orientationLock.bottom
            topMargin: 10
            leftMargin: 20; rightMargin: 20
        }
        height: 1
        color: "#ECEFF4"
    }
    ListModel {
           id: wifiListModel
       }

    // wifi scan result 
    ListView {
        id: wifiListView
        visible: true
        clip: true
        anchors {
            bottomMargin: 15
            topMargin: 15
            top: separator.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        model: wifiListModel
        delegate: Rectangle {
            height: 45
            width: parent.width 
            color: 'transparent' 
            Text {
                text: findex
                visible: false
            }
            Row {
                width: parent.width - 40 
                height: parent.height
                spacing: 10

                Rectangle { 
                    width: 30
                    height: 20
                    color: 'transparent'
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        font.family: icon.name 
                        font.pixelSize: 12
                        text: cstatus
                        color: "#ECEFF4"
                        anchors.left: parent.left
                        anchors.leftMargin: 210
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                Text {
                    text: wifiSsid
                    color: "#ECEFF4"
                    elide: Text.ElideRight
                    width: 230
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 9
                }
            }
            Row {
                anchors {
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    rightMargin: 30
                }
                width: 50
                spacing: 10
                Rectangle {
                    width: 20
                    height: 20 
                    color: 'transparent'
                    anchors.verticalCenter: parent.verticalCenter
                    Image { 
                        width: 20; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
                        source: if(rsec=="security"){return "qrc:/icons/network-wireless-encrypted-symbolic.svg"} else {return ""}
                    }
                }
                Image {
                    width: 20; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
                    source: if (strength >= 80 ) { return "qrc:/icons/network-wireless-signal-excellent-symbolic.svg" }
                    else if (strength >= 70 ) { return "qrc:/icons/network-wireless-signal-good-symbolic.svg" }
                    else if (strength >= 55 ) { return "qrc:/icons/network-wireless-signal-ok-symbolic.svg" }
                    else if (strength >= 0 ) { return "qrc:/icons/network-wireless-signal-weak-symbolic.svg" }
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked:  {
                selectWindex = findex
                select_ssid = wifiSsid
               wmSlate.state  = "opened"
                    settingSlate.state="closed"
 //    console.log("windex: "+selectWindex)

                    }
                }
            }
        }

    }

