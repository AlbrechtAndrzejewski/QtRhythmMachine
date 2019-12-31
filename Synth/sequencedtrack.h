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
        void timerHasTicked();

    private :
        unsigned char m_steps[16];
        int m_currentStep;
        SamplePlayer* m_instrument;

};

#endif // SEQUENCEDTRACK_H
