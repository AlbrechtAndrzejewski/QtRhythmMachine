#ifndef SAMPLEPLAYER_H
#define SAMPLEPLAYER_H

#include <QObject>
#include <QSoundEffect>
#include <iostream>
#include <string>

class SamplePlayer : public QObject
{
    Q_OBJECT
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
    void onSoundLoaded();

private:
    QSoundEffect* m_effect;
    const std::string& m_path;
};

#endif // SAMPLEPLAYER_H
