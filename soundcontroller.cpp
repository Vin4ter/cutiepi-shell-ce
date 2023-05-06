#include "soundcontroller.h"

soundController::soundController(QObject *parent) : QObject(parent)
{

}

void soundController::setAudioVolume(int volume)
{
    proc.startDetached("amixer sset 'Master' "+QString::number(volume)+"%");
}
