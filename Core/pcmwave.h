#ifndef PCMWAVE_H
#define PCMWAVE_H

#include <QtGlobal>

#define PCM_FORMAT_CODE 1

struct PCMWave {
    qint16  numberOfChannels;
    quint32 sampleRate;
    qint16  bitsPerSample;
    quint32 dataSize;
    char* data;
};

#endif // PCMWAVE_H
