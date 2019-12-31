#ifndef StepSequencerLedRowView_H
#define StepSequencerLedRowView_H

#include <QWidget>

class Led;

class BPMClockService;

class StepSequencerLedRowView : public QWidget
{
public:
    StepSequencerLedRowView();

protected slots:
    void timerHasTicked();

private:
    Led* m_leds[16];
    int m_currentStep;
    void connectToClock();

};

#endif // StepSequencerLedRowView_H
