#ifndef DRUMSAMPLEPLAYER_H
#define DRUMSAMPLEPLAYER_H

#include "Synth/sampleplayer.h"
#include <string>

class DrumSamplePlayer : public SamplePlayer
{
public:
    DrumSamplePlayer(const std::string&);
};

#endif // DRUMSAMPLEPLAYER_H
