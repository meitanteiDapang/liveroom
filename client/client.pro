QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 sdk_no_version_check

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common.cpp \
    main.cpp \
    my_thread.cpp \
    #my_thread_audience.cpp \
    #my_thread_audience_read.cpp \
    #myeventloop.cpp \
    protocol.cpp \
    #rocket_thread.cpp \
    udp_socket.cpp \
    udp_socket_audience.cpp \
    w1.cpp \
    w2.cpp \
    w3.cpp

HEADERS += \
    common.h \
    my_thread.h \
    #my_thread_audience.h \
    #my_thread_audience_read.h \
    #myeventloop.h \
    protocol.h \
    #rocket_thread.h \
    udp_socket.h \
    udp_socket_audience.h \
    w1.h \
    w2.h \
    w3.h

FORMS += \
    w1.ui \
    w2.ui \
    w3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
