#include "sampleplayer.h"

SamplePlayer::SamplePlayer(const std::string& pathToResourceFile) : m_path(pathToResourceFile)
{
    m_player = new WavPlayer();
    connect(m_player, &WavPlayer::loadedChanged, this, &SamplePlayer::onSoundLoaded);
    m_player->loadFile(pathToResourceFile.c_str());
}


SamplePlayer::~SamplePlayer()
{
    delete m_player;
}


void SamplePlayer::onSoundLoaded() {
    std::cout << m_path << " loaded" << std::endl;
}
