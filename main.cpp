#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include "appcore.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    qputenv("QT_QPA_PLATFORM", "eglfs");
    qputenv("LD_LIBRARY_PATH", "/usr/local/lib:$LD_LIBRARY_PATH");
     qputenv("QT_IM_MODULE", "qtvirtualkeyboard");
     qputenv("QT_VIRTUALKEYBOARD_LAYOUT_PATH", "/opt/cutiepi-shell/layouts/");
      qputenv("QT_QAYLAND_CLIENT_BUFFER_INTEGRATION", "wayland-egl");
        qputenv("XDG_RUNTIME_DIR", "XDG_RUNTIME_DIR=$HOME/.xdg");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
 AppCore appCore;
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
     context->setContextProperty("coreShell", &appCore);
    const QUrl url(QStringLiteral("qrc:/compositor.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
