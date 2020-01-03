QT += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./ViewControllerBase/ ./BPMClock/ ./RythmSwitchs

SOURCES += \
    BPMClock/bpmclockservice.cpp \
    BPMClock/bpmdisplayview.cpp \
    Leds/led.cpp \
    Leds/stepsequencerledrowview.cpp \
    RhythmSwitchs/stepsequencerswitch.cpp \
    RhythmSwitchs/stepsequencerswitchrowcontroller.cpp \
    RhythmSwitchs/stepsequencerswitchrowview.cpp \
    Synth/DrumKit/drumsampleplayer.cpp \
    Synth/sampleplayer.cpp \
    Synth/sequencedtrack.cpp \
    main.cpp \
    rhythmdeck.cpp

HEADERS += \
    BPMClock/bpmclockservice.h \
    BPMClock/bpmdisplayview.h \
    Leds/led.h \
    Leds/stepsequencerledrowview.h \
    RhythmSwitchs/stepsequencerswitch.h \
    RhythmSwitchs/stepsequencerswitchdelegate.h \
    RhythmSwitchs/stepsequencerswitchrowcontroller.h \
    RhythmSwitchs/stepsequencerswitchrowview.h \
    Synth/DrumKit/DR110Kit.h \
    Synth/DrumKit/drumsampleplayer.h \
    Synth/sampleplayer.h \
    Synth/sequencedtrack.h \
    ViewControllerBase/viewcontroller.h \
    colors.h \
    constants.h \
    rhythmdeck.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Resources.qrc
