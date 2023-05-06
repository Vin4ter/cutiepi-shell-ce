QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcore.cpp \
main.cpp \
    soundcontroller.cpp \
    wifimanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    appcore.h \
    soundcontroller.h \
    wifimanager.h

DISTFILES += \
    layouts/en_US/CtrlKey.qml \
    layouts/en_US/EscKey.qml \
    layouts/en_US/TabKey.qml \
    layouts/en_US/WSpaceKey.qml \
    layouts/en_US/dialpad.qml \
    layouts/en_US/digits.qml \
    layouts/en_US/handwriting.qml \
    layouts/en_US/main.qml \
    layouts/en_US/numbers.qml \
    layouts/en_US/symbols.qml \
    scripts/konsole.sh

