#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <QObject>
#include <QProcess>
#include <QTimer>
class wifiManager : public QObject
{
    Q_OBJECT
public:
    explicit wifiManager(QObject *parent = nullptr);

private:
    QProcess * mainProc;
QStringList SSIDS_list;
QStringList SIGNALS_list;
QStringList SECURITY_list;
QTimer *timerUpdateList;
QString connectedWifiString;

signals:
    void putWifi(QString ssid, QString wsignal, QString wsec, int lindex, QString lstatus);
    void clearWifiList();
    void connectedWifi(QString status);
    void updateConnectedWifi(int lsignal,  QString lstatus);
public slots:
       void getWifiList();
       void chk();
       void connectWifi(QString ssid, QString password);
       void startConnectedWifiInfo();
private slots:


};

#endif // WIFIMANAGER_H
