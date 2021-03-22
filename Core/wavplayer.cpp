#include "wavplayer.h"
#include <QBuffer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <iostream>
#include "pcmwave.h"
#include "Core/wavfileparser.h"

using namespace std;


static void printQAudioFormat(QAudioFormat* format) {
    cout << "codec: " << format->codec().toStdString() << endl;
    cout << "byteorder: " << format->byteOrder() << endl;
    cout << "samplerate: " << format->sampleRate() << endl;
    cout << "samplesize: " << format->sampleSize() << endl;
    cout << "channels: " << format->channelCount() << endl;
    cout << "SampleType: " << format->sampleType() << endl;
}


WavPlayer::WavPlayer() {
    m_buffer = new QBuffer();
    m_wave = new PCMWave();
}


void WavPlayer::loadFile(std::string filePath) {
    WavFileParser parser;
    if (!parser.loadWaveFile(filePath.c_str(), m_wave)) {
            cerr << "Error while loading file" << endl;
            exit(1);
    }
    m_buffer->setData(m_wave->data, m_wave->dataSize * sizeof(char));
    m_buffer->open(QIODevice::ReadOnly);

    QAudioFormat format;
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleRate(m_wave->sampleRate);
    format.setSampleSize(m_wave->bitsPerSample);
    format.setChannelCount(m_wave->numberOfChannels);
    format.setCodec("audio/pcm");
    format.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (info.isFormatSupported(format)) {
        cout << "opening audio output" << endl;
        m_audio = new QAudioOutput(format);
        m_audio->setBufferSize(m_wave->dataSize * sizeof(char));
        connect(m_audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));
        emit loadedChanged();
    } else {
        cerr << "Format not supported" << endl;
        printQAudioFormat(&format);
    }
}


void WavPlayer::play() {
    m_audio->start(m_buffer);
}


void WavPlayer::handleStateChanged(QAudio::State newState) {
    switch (newState) {
    case QAudio::IdleState:
        m_audio->stop();
        break;
    case QAudio::InterruptedState :
        cout << "interrupted" << endl;
        break;
    case QAudio::StoppedState:
        m_buffer->seek(0);
        break;
    default:
        break;
    }
}


WavPlayer::~WavPlayer() {
    m_audio->stop();
    m_buffer->close();
    delete m_buffer;
    delete m_wave;
}
