#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include "appcore.h"
#include <QQmlContext>
#include "QNetworkConfigurationManager"
#include "wifimanager.h"
#include "soundcontroller.h"
int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "eglfs");
    qputenv("LD_LIBRARY_PATH", "/usr/local/lib:$LD_LIBRARY_PATH");
     qputenv("QT_IM_MODULE", "qtvirtualkeyboard");
     qputenv("QT_VIRTUALKEYBOARD_LAYOUT_PATH", "qrc:/layouts/");
      qputenv("QT_QAYLAND_CLIENT_BUFFER_INTEGRATION", "wayland-egl");
       qputenv("XDG_RUNTIME_DIR", "XDG_RUNTIME_DIR=$HOME/.xdg");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QCoreApplication::setOrganizationName("CutiePi Community Project");
    QCoreApplication::setApplicationName("CutiePi-Shell");

 AppCore appCore;
 wifiManager wm;
 soundController am;
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
     context->setContextProperty("coreShell", &appCore);
     context->setContextProperty("wifiManager", &wm);
       context->setContextProperty("audioManager", &am);
    const QUrl url(QStringLiteral("qrc:/compositor.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//wm.connectWifi("ZYXEL","aeroprof2013");




    return app.exec();
}
