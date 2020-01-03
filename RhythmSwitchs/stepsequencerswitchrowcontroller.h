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
    StepSequencerSwitchrowController(const std::string&);
    ~StepSequencerSwitchrowController();

    void litStateChanged(int id, bool islit) override;
    void linkToInstrument(SamplePlayer*);
    void showDisplayName(bool);

private:
    StepSequencerSwitchrowView* m_view;
    SequencedTrack* m_sequencedTrack;
    std::string m_displayName;

};

#endif // STEPSEQUENCERSWITCHROWCONTROLLER_H
