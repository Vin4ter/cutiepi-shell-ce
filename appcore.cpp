#include "appcore.h"
#include "QStandardPaths"
#include "QDebug"
#include "QProcess"
#include <QScreen>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui/QGuiApplication>
#include <QScreen>
#include <qpa/qplatformscreen.h>
AppCore::AppCore(QObject* parent) : QObject(parent)
{
    //receiveFromQml();
}

void AppCore::receiveFromQml()
{

}
void AppCore::receiveOpenKonsole(){
    qputenv("CUTIEPI_SHELL", QByteArray("true"));
       qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));
       qputenv("EGL_PLATFORM", QByteArray("wayland"));
       qunsetenv("QT_IM_MODULE");
           qputenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1");

       //qputenv("WAYLAND_DISPLAY", ((QQmlApplicationEngine *)parent())->rootObjects()[0]->property("socketName").toString().toUtf8());
       QStringList args = QStringList();
       args.append("-c");
       args.append("konsole");
       if (!QProcess::startDetached("bash", args))
           qDebug() << "Failed to run";

}
