#ifndef STEPSEQUENCERSWITCHROWCONTROLLER_H
#define STEPSEQUENCERSWITCHROWCONTROLLER_H

#include <QObject>
#include "viewcontroller.h"
#include "stepsequencerswitchdelegate.h"
#include "stepsequencerswitchrowview.h"

class SequencedTrack;
class SamplePlayer;

class StepSequencerSwitchrowController : public ViewController, StepSequencerSwitchDelegate {
public:
    StepSequencerSwitchrowController();
    ~StepSequencerSwitchrowController();

    void litStateChanged(int id, bool islit) override;
    void linkToInstrument(SamplePlayer*);

private:
    SequencedTrack* m_sequencedTrack;
};

#endif // STEPSEQUENCERSWITCHROWCONTROLLER_H
