#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QStandardPaths>
#include <QFileInfo>


class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = nullptr);

signals:
    void sendString(QString current_line);

public slots:
    void receiveFromQml();
    void receiveOpenKonsole();

private:

};

#endif // APPCORE_H
