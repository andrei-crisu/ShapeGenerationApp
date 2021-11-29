QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_use.cpp \
    customscene.cpp \
    inheritedgraphicsellipse.cpp \
    inheritedgraphicspolygon.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    basic_use.h \
    customscene.h \
    inheritedgraphicsellipse.h \
    inheritedgraphicspolygon.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon_files/settings.png \
    stylesheets/AMOLED.qss \
    stylesheets/AMOLED.qss \
    stylesheets/Adaptic.png \
    stylesheets/Adaptic.png \
    stylesheets/Adaptic.qss \
    stylesheets/Adaptic.qss \
    stylesheets/Aqua.qss \
    stylesheets/Aqua.qss \
    stylesheets/ConsoleStyle.qss \
    stylesheets/ConsoleStyle.qss \
    stylesheets/Devsion.png \
    stylesheets/Devsion.png \
    stylesheets/Devsion.qss \
    stylesheets/Devsion.qss \
    stylesheets/Diffnes.png \
    stylesheets/Diffnes.png \
    stylesheets/Diffnes.qss \
    stylesheets/Diffnes.qss \
    stylesheets/ElegantDark.qss \
    stylesheets/ElegantDark.qss \
    stylesheets/Gravira.png \
    stylesheets/Gravira.png \
    stylesheets/Gravira.qss \
    stylesheets/Gravira.qss \
    stylesheets/Incrypt.png \
    stylesheets/Incrypt.png \
    stylesheets/Incrypt.qss \
    stylesheets/Incrypt.qss \
    stylesheets/License.txt \
    stylesheets/License.txt \
    stylesheets/MacOS.qss \
    stylesheets/MacOS.qss \
    stylesheets/ManjaroMix.qss \
    stylesheets/ManjaroMix.qss \
    stylesheets/MaterialDark.qss \
    stylesheets/MaterialDark.qss \
    stylesheets/NeonButtons.qss \
    stylesheets/NeonButtons.qss \
    stylesheets/Perstfic.png \
    stylesheets/Perstfic.png \
    stylesheets/Perstfic.qss \
    stylesheets/Perstfic.qss \
    stylesheets/QSS_IMG/go-down-symbolic.symbolic.png \
    stylesheets/QSS_IMG/go-next-symbolic.symbolic.png \
    stylesheets/QSS_IMG/go-previous-symbolic.symbolic.png \
    stylesheets/QSS_IMG/go-up-symbolic.symbolic.png \
    stylesheets/QSS_IMG/object-select-symbolic.symbolic.png \
    stylesheets/SpyBot.png \
    stylesheets/SpyBot.png \
    stylesheets/SpyBot.qss \
    stylesheets/SpyBot.qss \
    stylesheets/Ubuntu.qss \
    stylesheets/Ubuntu.qss \
    stylesheets/Webmas.png \
    stylesheets/Webmas.png \
    stylesheets/Webmas.qss \
    stylesheets/Webmas.qss

RESOURCES += \
    icons.qrc \
    resources.qrc
