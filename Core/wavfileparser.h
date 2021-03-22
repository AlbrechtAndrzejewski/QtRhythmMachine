#ifndef WAVFILEPARSER_H
#define WAVFILEPARSER_H

#include <iostream>
#include "pcmwave.h"

class QDataStream;

class WavFileParser {
public:
    WavFileParser() {};
    bool loadWaveFile(const std::string& pathToRead, PCMWave* wave);
    static void printWavFileMetaData(const std::string& path);
private:
    static bool seekToDataChunk(QDataStream* in);
    static void skipToNextD(QDataStream* in);
};

#endif // WAVFILEPARSER_H
