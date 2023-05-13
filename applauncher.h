#ifndef APPLAUNCHER_H
#define APPLAUNCHER_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include <QSettings>
#include "QProcess"
#include <QDirIterator>
struct AppInfo {
    QString name;
    QString icon{"application"};
    QString exec;
};

constexpr auto DESKTOP_FILE_SYSTEM_DIR = "/usr/share/applications";
constexpr auto DESKTOP_FILE_USER_DIR = "%1/.local/share/applications";
constexpr auto DESKTOP_ENTRY_STRING = "Desktop Entry";
class AppLauncher : public QObject
{
    Q_OBJECT
public:
    explicit AppLauncher(QObject *parent = nullptr);
public slots:
    void openApp(QString exec);
    void getAppList();
signals:
 void appendApp(QString name, QString icon, QString exec);
private:

    QSettings SettingsGroupRaii;
    QStringList Names;
    QStringList Icons;
    QStringList Execs;
};

#endif // APPLAUNCHER_H
