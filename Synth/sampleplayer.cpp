#include "sampleplayer.h"

SamplePlayer::SamplePlayer(const std::string& pathToResourceFile)
{
    m_effect = new QSoundEffect();
    m_effect->setSource(QUrl::fromLocalFile(pathToResourceFile.c_str()));
    m_effect->setLoopCount(1);
    m_effect->setVolume(0.25f);
}


SamplePlayer::~SamplePlayer()
{
    delete m_effect;
}
