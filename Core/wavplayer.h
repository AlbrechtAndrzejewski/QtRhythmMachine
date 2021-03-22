#ifndef WAVPLAYER_H
#define WAVPLAYER_H
#include <QAudio>
#include <QObject>

struct PCMWave;
class QAudioOutput;
class QBuffer;

class WavPlayer : public QObject {
    Q_OBJECT
public:
   WavPlayer();
   void loadFile(std::string path);
   virtual ~WavPlayer();

public slots:
   void play();
   void handleStateChanged(QAudio::State newState);
signals:
    void loadedChanged();
    void finished();
private:
   PCMWave* m_wave;
   QAudioOutput* m_audio;
   QBuffer* m_buffer;

};

#endif // WAVPLAYER_H
