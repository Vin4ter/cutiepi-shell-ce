#include "appcore.h"
#include "QStandardPaths"
#include "QDebug"
#include "QProcess"


AppCore::AppCore(QObject* parent) : QObject(parent)
{
    //receiveFromQml();
}

void AppCore::receiveFromQml()
{

}
void AppCore::receiveOpenKonsole(){
    QProcess().startDetached("konsole");
}
