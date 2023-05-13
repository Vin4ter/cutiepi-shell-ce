import QtQuick 2.14
import QtWayland.Compositor 1.14

ShellSurfaceItem {
     anchors { top: parent.top; topMargin: 85; left: parent.left; }
   // anchors.fill: parent
      moveItem: sidebar
    sizeFollowsSurface: true
    autoCreatePopupItems: true
    touchEventsEnabled: false
    shellSurface: modelData
    //maximizedRect : this
    onSurfaceDestroyed: shellSurfaces.remove(index)
    onSurfaceChanged: {

    }

    visible: sidebar.tabListView.currentIndex == index
    MultiPointTouchArea {
          anchors.fill: parent
          mouseEnabled: true
         // enabled: root.state === "appScreen"
          onPressed: {
              for (let i = 0; i < touchPoints.length; i++) {
                  compositor.defaultSeat.sendTouchPointPressed(parent.shellSurface.surface, touchPoints[i].pointId,
                      Qt.point(touchPoints[i].x / shellScaleFactor, touchPoints[i].y / shellScaleFactor));
              }
              compositor.defaultSeat.sendTouchFrameEvent(parent.shellSurface.surface.client);
              parent.takeFocus();
          }
          onReleased: {
              for (let i = 0; i < touchPoints.length; i++) {
                 compositor.defaultSeat.sendTouchPointReleased(parent.shellSurface.surface, touchPoints[i].pointId,
                      Qt.point(touchPoints[i].x / shellScaleFactor, touchPoints[i].y / shellScaleFactor));
              }
              compositor.defaultSeat.sendTouchFrameEvent(parent.shellSurface.surface.client);
          }
          onUpdated: {
              for (let i = 0; i < touchPoints.length; i++) {
                  compositor.defaultSeat.sendTouchPointMoved(parent.shellSurface.surface, touchPoints[i].pointId,
                      Qt.point(touchPoints[i].x / shellScaleFactor, touchPoints[i].y / shellScaleFactor));
              }
             compositor.defaultSeat.sendTouchFrameEvent(parent.shellSurface.surface.client);
          }
      }
}
