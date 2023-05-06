#include "wifimanager.h"
#include "QDebug"
#include "QRegExp"
#include "QProcess"
#include "QSettings"
#include "QStandardPaths"
wifiManager::wifiManager(QObject *parent) : QObject(parent)
{
    mainProc = new QProcess(this);
    timerUpdateList = new QTimer(this);
    connect(timerUpdateList, &QTimer::timeout, this, &wifiManager::getWifiList);
    timerUpdateList->setInterval(4000);
    timerUpdateList->start(); //time specified in ms

}

void wifiManager::getWifiList()
{

  emit clearWifiList();
    SECURITY_list.clear();
    SIGNALS_list.clear();
    SSIDS_list.clear();


qDebug()<<"wifibuf ";
QProcess * proc = new QProcess(this);

    proc->start("nmcli device wifi list");
   // process2.start("sudo -S shutdown -r now");
    proc->setProcessChannelMode(QProcess::ForwardedChannels);
    QString buffer="";
    proc->waitForFinished(); // sets current thread to sleep and waits for pingProcess end
    //QString output(pingProcess.readAllStandardOutput());
     buffer = proc->readAll();
    proc->close();
    delete proc;

 qDebug()<<"parser"<< buffer;
     QStringList parserList;
    parserList = buffer.split("\n");


    int ssidOffset=0;
    int signalOffset=0;
  int secOffset=0;

    QString main = parserList.at(0);
   // qDebug()<<"main "<<main;
    QString select="";
    for(int c=0; c<main.count(); c++){
    if(main.at(c)==' '){

     qDebug()<<"select "<<select;
     if(select=="SSID"){
         ssidOffset=c-4;
        // qDebug()<<"select "<<select;
         select="";
     }else if(select=="SIGNAL"){
         signalOffset=c-6;
         select="";
     }else if(select=="SECURITY"){
         secOffset=c-8;
         select="";
     }
     select.clear();
    }else{
        if(main.at(c)=='S'){
             select+='S';
             qDebug()<<"s";
        }else
            if(main.at(c)=='E'){
                 select+='E';
                 qDebug()<<"E";
            }else
                if(main.at(c)=='C'){
                     select+='C';
                     qDebug()<<"C";
                }else
                    if(main.at(c)=='U'){
                         select+='U';
                         qDebug()<<"s";
                    }else
                         if(main.at(c)=='R'){
                              select+='R';
                              qDebug()<<"R";

                    }else
                             if(main.at(c)=='T'){
                                  select+='T';
                                  qDebug()<<"T";

                            }else
                                 if(main.at(c)=='Y'){
                                      select+='Y';
                                      qDebug()<<"Y";
                                 }else
        if(main.at(c)=='I'){
            select+='I';
        }else
        if(main.at(c)=='D'){
             select+='D';
          }else
        if(main.at(c)=='B'){
                  select+='B';

        }else
        if(main.at(c)=='G'){
             select+='G';
        }else
        if(main.at(c)=='N'){
         select+='N';
        }else
        if(main.at(c)=='A'){
         select+='A';
        }else
        if(main.at(c)=='L'){
         select+='L';
    }

    }



   }

//qDebug()<<"ssidOffset<< "<<ssidOffset;
//qDebug()<<"signalOffset<< "<<signalOffset;
//qDebug()<<"secOffset<< "<<secOffset;
QString ssid_lane="";
QString signal_lane="";
QString sec_lane="";
QString curLine="";
    for(int i=1; i<parserList.count()-1; i++){
    curLine=parserList.at(i);
    int s_check=0;
    int sig_check=0;
    int sec_check=0;
        //qDebug()<< parserList.at(i);
      for(int f=0; f<curLine.count(); f++){
       if(f==secOffset){
           sec_check=1;
       }else if(f==ssidOffset){
           s_check=1;
       }else if(f==signalOffset){
           sig_check=1;
       }else   if(curLine.at(f)==" "){
           s_check=0;
           sig_check=0;
           sec_check=0;
       }




          if(s_check==1){
             ssid_lane+=curLine.at(f);

          }else if(sig_check==1){
              signal_lane+=curLine.at(f);

          }else if(sec_check==1){
              sec_lane+=curLine.at(f);
          }



      }
      SIGNALS_list.append(signal_lane);
      SSIDS_list.append(ssid_lane);
      if((sec_lane=="WPA") or ( sec_lane=="WPA2") or ( sec_lane=="WPA1") or ( sec_lane=="WPA3")){
       SECURITY_list.append("security");
      }else{
       SECURITY_list.append("open");
      }
      ssid_lane.clear();
      signal_lane.clear();
      sec_lane.clear();
     }
    QString status="";
    qDebug()<<"ssids list<< "<<SSIDS_list;
        qDebug()<<"signals list<< "<<SIGNALS_list;
    qDebug()<<"sec list<< "<<SECURITY_list;
        for(int i=0; i<SSIDS_list.count(); i++){
            if(SSIDS_list.at(i)==connectedWifiString){
                  status="connected";
            }else{
                status="";
            }
           emit putWifi(SSIDS_list.at(i), SIGNALS_list.at(i), SECURITY_list.at(i), i, status);

        }
  startConnectedWifiInfo();
}

void wifiManager::chk()
{
      QSettings settings(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"/main.conf", QSettings::IniFormat);
    timerUpdateList->start();
    settings.beginGroup( "NetworkManager" );
    settings.value( "wpasswd").toString();
    connectWifi( settings.value( "wssid").toString(),settings.value( "wpasswd").toString());
    settings.endGroup();
}

void wifiManager::connectWifi(QString ssid, QString password)
{
        QProcess * wproc = new QProcess(this);
    qputenv("LC_ALL", "C.UTF-8");
    wproc->start("/bin/sh", QStringList()<< "-c" << "nmcli device wifi connect "+ssid+" password "+password);
    QString buffer="";
    wproc->waitForFinished(); // sets current thread to sleep and waits for pingProcess end
    //QString output(pingProcess.readAllStandardOutput());
    buffer = wproc->readAll();
    wproc->close();
    delete wproc;
       QString lane ="";
        for(int i=0; i<buffer.count(); i++){
 //qDebug()<<"lanes "<<lane;
            if(buffer.at(i)!=" "){
              lane+=buffer.at(i);
          }else if(buffer.at(i)==" "){

                lane.clear();

          }
            if(lane=="successfully"){
                qDebug()<<"CONNECTED OK!";
                connectedWifiString=ssid;


                QSettings settings(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"/main.conf", QSettings::IniFormat);
                settings.beginGroup( "NetworkManager" );
                settings.setValue( "wssid", ssid);
                settings.setValue( "wpasswd", password );
                settings.endGroup();
                emit connectedWifi("ok");
            }else if(lane=="Error:"){
                qDebug()<<"Error connect!";
                emit connectedWifi("error");

}



        }


}

void wifiManager::startConnectedWifiInfo()
{
    int index;
    int signal=0;
    QString status;
    status="noconnected";
    signal=0;


        for(int i=0; i<SSIDS_list.count(); i++){
            if(SSIDS_list.at(i)==connectedWifiString){
              index= i;
              status="connected";
 signal = SIGNALS_list.at(index).toInt();
       }
        }

           emit updateConnectedWifi(signal, status);




}





