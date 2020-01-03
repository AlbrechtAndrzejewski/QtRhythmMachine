#include "sampleplayer.h"

SamplePlayer::SamplePlayer(const std::string& pathToResourceFile) : m_path(pathToResourceFile)
{
    m_effect = new QSoundEffect();
    m_effect->setSource(QUrl::fromLocalFile(pathToResourceFile.c_str()));
    m_effect->setLoopCount(1);
    m_effect->setVolume(0.25f);
    connect(m_effect, &QSoundEffect::loadedChanged, this, &SamplePlayer::onSoundLoaded);
}


SamplePlayer::~SamplePlayer()
{
    delete m_effect;
}


void SamplePlayer::onSoundLoaded() {
    std::cout << m_path << " loaded" << std::endl;
}
