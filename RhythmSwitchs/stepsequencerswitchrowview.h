#ifndef STEPSEQUENCERSWITCHROWVIEW_H
#define STEPSEQUENCERSWITCHROWVIEW_H

#include <QWidget>

class StepSequencerSwitch;
class StepSequencerSwitchDelegate;

class StepSequencerSwitchrowView : public QWidget
{
    Q_OBJECT

public:
    StepSequencerSwitchrowView();
    ~StepSequencerSwitchrowView();

    void setDelegate(StepSequencerSwitchDelegate* delegate);

private:
    StepSequencerSwitch* m_switches[16];
};

#endif // STEPSEQUENCERSWITCHROWVIEW_H
