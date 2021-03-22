#ifndef SAMPLEPLAYER_H
#define SAMPLEPLAYER_H

#include <QObject>
#include <iostream>
#include <string>

#include "Core/wavplayer.h"

using namespace std;

class SamplePlayer : public QObject
{
    Q_OBJECT
public:
    SamplePlayer(const std::string&);
    virtual ~SamplePlayer();

    virtual void play() {
        m_player->play();
    };

    void onSoundLoaded();

private:
    WavPlayer* m_player;
    const std::string& m_path;
};

#endif // SAMPLEPLAYER_H
