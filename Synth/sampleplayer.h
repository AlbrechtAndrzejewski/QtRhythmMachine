#ifndef SAMPLEPLAYER_H
#define SAMPLEPLAYER_H

#include <QObject>
#include <QSoundEffect>
#include <iostream>
#include <string>

class SamplePlayer
{
public:
    SamplePlayer(const std::string&);
    virtual ~SamplePlayer();

    virtual void play() {
        m_effect->play();
    };
    void stop() {
        m_effect->stop();
    };
    void setSample(const std::string& source) {
        m_effect->setSource(QUrl::fromLocalFile(source.c_str()));
    };

private:
    QSoundEffect* m_effect;
};

#endif // SAMPLEPLAYER_H
