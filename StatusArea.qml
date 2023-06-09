import QtQuick 2.14

Rectangle {
    property alias audio: audio 
    property int wasignal
    property string wastatus
    color: "#2E3440"
    width: 360 + 20 
    height: 65
    anchors {
        top: parent.top
        right: parent.right
        rightMargin: -20
    }
    radius: 22
    z: 4 

    Connections {
         target: wifiManager
        onUpdateConnectedWifi:{
        wastatus = lstatus
        wasignal = lsignal
            console.log("wasignal>> "+wasignal)
             console.log("wastatus>> "+wastatus)

            if (wastatus == "noconnected") { wifiIndicator.source="qrc:/icons/network-wireless-signal-none-symbolic.svg" } // no wifi connection
                            else if (wastatus=="connected" && wasignal >= 80 ) { wifiIndicator.source="qrc:/icons/network-wireless-signal-excellent-symbolic.svg" }
                            else if (wastatus=="connected" && wasignal >= 70 ) {  wifiIndicator.source="qrc:/icons/network-wireless-signal-good-symbolic.svg" }
                            else if (wastatus=="connected"  && wasignal  >= 55 ) {  wifiIndicator.source="qrc:/icons/network-wireless-signal-ok-symbolic.svg" }
                            else if (wastatus=="connected"  && wasignal  >= 0 ) {  wifiIndicator.source="qrc:/icons/network-wireless-signal-weak-symbolic.svg" }



        }
     }


    Row { 
        id: statusAreaBar 
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 15
            rightMargin: 20 + 15
        }
        height: 45 
        spacing: 10

        Text { 
            font.pointSize: 8
            text: (batteryCharging) ? "charging" : batteryPercentage + "%"
            anchors.topMargin: 5
            anchors.rightMargin: (batteryCharging) ? -5 : -2 
            anchors.top: parent.top 
            color: "#ECEFF4"
        }

        // battery 
        Image {
            source: if (batteryCharging) { "icons/battery-full-charged-symbolic.svg" } 
                else if (batteryPercentage >= 80) { "icons/battery-full-symbolic.svg" } 
                else if (batteryPercentage >= 50) { "icons/battery-good-symbolic.svg" } 
                else if (batteryPercentage >= 30) { "icons/battery-low-symbolic.svg" } 
                else if (batteryPercentage >= 20) { "icons/battery-caution-symbolic.svg" } 
                else { "icons/battery-empty-symbolic.svg" } 
            width: 34; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
        }

        // audio
        Image {
            id: audio
            source: "icons/audio-volume-high-symbolic.svg"
            width: 34; height: width; sourceSize.width: width*2; sourceSize.height: height*2;
        }


        Image {
            id: wifiIndicator

            width: 34; height: width; sourceSize.width: width*2; sourceSize.height: height*2; 
        }

        Text {
            font.pointSize: 16
            text: Qt.formatDateTime(new Date(), formatDateTimeString)
            color: "#ECEFF4"
            anchors.leftMargin: 5
            Timer { 
                repeat: true 
                interval: 60000
                running: true 
                onTriggered: { 
                    parent.text = Qt.formatDateTime(new Date(), formatDateTimeString);
                    lockscreen.lockscreenTime.text = Qt.formatDateTime(new Date(), "HH:mm");
                    lockscreen.lockscreenDate.text = Qt.formatDateTime(new Date(), "dddd, MMMM d"); 
                }
            }
        }
    }

    MouseArea {
        anchors.fill: parent 
        drag.target: settingSheet; drag.axis: Drag.YAxis; drag.minimumY: -535; drag.maximumY: 0
        //onPressAndHold: {
        //    screenshotTimer.start();
        //}
        onClicked: { 
            if (settingSheet.y > -535) { settingSlate.state = "closed" } else {settingSlate.state= "opened" }
        } 
        onReleased: { 
            if (settingSheet.y > -535) {settingSlate.state="opened" } else {settingSlate.state = "closed" }
        }
    }
}
