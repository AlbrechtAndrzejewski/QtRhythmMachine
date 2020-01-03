#ifndef SEQUENCEDTRACK_H
#define SEQUENCEDTRACK_H

#include <QObject>

class SamplePlayer;

class SequencedTrack : public QObject
{
    Q_OBJECT

    public:
        SequencedTrack(SamplePlayer* instrument);
        void setStepValue(int id, int velocity);

    protected slots:
        void timerHasTicked(std::chrono::time_point<std::chrono::system_clock> startTime);

    private :
        unsigned char m_steps[16];
        int m_currentStep;
        SamplePlayer* m_instrument;

};

#endif // SEQUENCEDTRACK_H
