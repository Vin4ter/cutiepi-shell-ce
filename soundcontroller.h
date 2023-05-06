#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <QObject>
#include <QProcess>

class soundController: public QObject
{
    Q_OBJECT
public:
    explicit soundController(QObject *parent = nullptr);
private:
    QProcess proc;
public slots:
void setAudioVolume(int volume);
};

#endif // SOUNDCONTROLLER_H
