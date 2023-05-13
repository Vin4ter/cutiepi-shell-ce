#include "applauncher.h"
#include "QDebug"

AppLauncher::AppLauncher(QObject *parent) : QObject(parent)
{





}

void AppLauncher::openApp(QString exec)
{
    qputenv("CUTIEPI_SHELL", QByteArray("true"));
       qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));
       qputenv("EGL_PLATFORM", QByteArray("wayland"));
       qunsetenv("QT_IM_MODULE");
           qputenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1");

       //qputenv("WAYLAND_DISPLAY", ((QQmlApplicationEngine *)parent())->rootObjects()[0]->property("socketName").toString().toUtf8());
       QStringList args = QStringList();
       args.append("-c");
       args.append(exec);
       if (!QProcess::startDetached("bash", args))
           qDebug() << "Failed to run";
}

void AppLauncher::getAppList()
{
    QDirIterator it(DESKTOP_FILE_SYSTEM_DIR, {"*.desktop"}, QDir::NoFilter, QDirIterator::Subdirectories);


    while (it.hasNext()) {
        const auto filename = it.next();
        QSettings desktopFile(filename, QSettings::IniFormat);

        if (!desktopFile.childGroups().contains(DESKTOP_ENTRY_STRING))
            continue;

        //SettingsGroupRaii raii(desktopFile, DESKTOP_ENTRY_STRING);
        desktopFile.beginGroup(DESKTOP_ENTRY_STRING );

        if (desktopFile.contains("NoDisplay")) if (desktopFile.value("NoDisplay").toBool() == true) continue;
        if(desktopFile.value("Icon").toString()=="") continue;

        AppInfo app;
        app.exec = desktopFile.value("Exec").toString().remove("\"").remove(QRegExp(" %."));
        app.icon = "file:///usr/share/icons/Papirus/64x64/apps/"+desktopFile.value("Icon").toString();
        app.name = desktopFile.value("Name").toString();

       Names.append(app.name);
      Icons.append(app.icon);
      Execs.append(app.exec);

        }

    for(int i=0; i<Names.count(); i++){
        emit appendApp(Names.at(i), Icons.at(i), Execs.at(i));
    }
qDebug()<<"lists names"<< Names;
qDebug()<<"lists icons"<< Icons;
          qDebug()<<"lists execs"<< Execs;
}
