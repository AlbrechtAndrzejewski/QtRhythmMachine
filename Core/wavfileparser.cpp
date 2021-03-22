#include "wavfileparser.h"
#include <QDataStream>
#include <QFile>
#include <QFileDevice>
#include "pcmwave.h"


bool WavFileParser::loadWaveFile(const std::string& pathToRead, PCMWave* wave) {
    QFile wavFile(pathToRead.c_str());
    wavFile.open(QIODevice::ReadOnly);
    QDataStream in(&wavFile);
    char chunk1ID[4];
    in.readRawData(chunk1ID,4);
    if (std::string(chunk1ID,4).compare("RIFF") != 0) {
        return false;
    }
    in.skipRawData(4);
    char format[4];
    in.readRawData(format,4);
    if (std::string(format,4).compare("WAVE") != 0) {
        return false;
    }
    char chunk2ID[4];
    in.readRawData(chunk2ID,4);
    if (std::string(chunk2ID,4).compare("fmt ") != 0) {
        return false;
    }
    in.skipRawData(4);
    char formatCode[2];
    in.readRawData(formatCode,2);
    if (*(uint16_t*)formatCode != PCM_FORMAT_CODE) {
        return false;
    }
    char numberOfChannel[2];
    in.readRawData(numberOfChannel,2);
    if(*(uint16_t*)numberOfChannel != 1 && *(uint16_t*)numberOfChannel != 2) {
        return false;
    } else {
        wave->numberOfChannels=*(uint16_t*)numberOfChannel;
    }
    char samplerate[4];
    in.readRawData(samplerate,4);
    wave->sampleRate = *(uint32_t*)samplerate;
    in.skipRawData(6);
    char bitsPerSample[2];
    in.readRawData(bitsPerSample,2);
    wave->bitsPerSample = *(uint16_t*)bitsPerSample;
    if (!WavFileParser::seekToDataChunk(&in)) {
        return false;
    } else {
        char datasize[4];
        in.readRawData(datasize,4);
        wave->dataSize = *(uint32_t*)datasize;
        wave->data = (char*)malloc(wave->dataSize * sizeof(char));
        in.readRawData(wave->data,wave->dataSize * sizeof(char));
        return true;
    }
}


void WavFileParser::skipToNextD(QDataStream* in) {
    char seekDataBuffer[1] = {0};
    while(*seekDataBuffer != 'd' && !in->atEnd()) {
       in->readRawData(seekDataBuffer,1);
    }
}


bool WavFileParser::seekToDataChunk(QDataStream* in) {
    WavFileParser::skipToNextD(in);
    if (in->atEnd()) {
        std::cout << "Data chunk not found "<< std::endl;
        return false;
    }
    char seekBuffer[3];
    in->readRawData(seekBuffer,3);
    if (std::string(seekBuffer,3).compare("ata") == 0) {
        return true;
    } else {
        WavFileParser::seekToDataChunk(in);
    }
    return false;
}


void WavFileParser::printWavFileMetaData(const std::string& pathToRead) {
    QFile wavFile(pathToRead.c_str());
    wavFile.open(QIODevice::ReadOnly);
    QDataStream in(&wavFile);
    char chunk1ID[4];
    in.readRawData(chunk1ID,4);
    std::cout << "Chunk Name : " << std::string(chunk1ID,4) << std::endl;
    char chunk1SizeBuf[4];
    in.readRawData(chunk1SizeBuf,4);
    std::cout << "ChunkSize : " << *(uint32_t*)chunk1SizeBuf << std::endl;
    char format[4];
    in.readRawData(format,4);
    std::cout << "Format : " << std::string(format,4) << std::endl;
    char chunk2ID[4];
    in.readRawData(chunk2ID,4);
    std::cout << "Chunk Name : " << std::string(chunk2ID,4) << std::endl;
    char chunk2SizeBuf[4];
    in.readRawData(chunk2SizeBuf,4);
    std::cout << "ChunkSize : " << *(uint32_t*)chunk2SizeBuf << std::endl;
    char formatCode[2];
    in.readRawData(formatCode,2);
    std::cout << "Format code (1 : PCM / 3 : IEEE float / 6 : a-law / 7 : u-law) : " << *(uint16_t*)formatCode << std::endl;
    char numberOfChannel[2];
    in.readRawData(numberOfChannel,2);
    std::cout << "Channels (1 : mono 2: stereo): " << *(uint16_t*)numberOfChannel << std::endl;
    char samplerate[4];
    in.readRawData(samplerate,4);
    std::cout << "Sample Rate : " << *(uint32_t*)samplerate << std::endl;
    in.skipRawData(6);
    char bitsPerSample[2];
    in.readRawData(bitsPerSample,2);
    std::cout << "BitsPerSample : " << *(uint16_t*)bitsPerSample << std::endl;
    WavFileParser::seekToDataChunk(&in);
    char datasize[4];
    in.readRawData(datasize,4);
    std::cout << "Data size : " << *(uint32_t*)datasize << std::endl;
}
