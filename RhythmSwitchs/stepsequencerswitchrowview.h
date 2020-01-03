#ifndef STEPSEQUENCERSWITCHROWVIEW_H
#define STEPSEQUENCERSWITCHROWVIEW_H

#include <QWidget>

class QLabel;
class StepSequencerSwitch;
class StepSequencerSwitchDelegate;

class StepSequencerSwitchrowView : public QWidget
{
    Q_OBJECT

public:
    StepSequencerSwitchrowView(const std::string& displayName);
    ~StepSequencerSwitchrowView();

    void setDelegate(StepSequencerSwitchDelegate* delegate);
    void showDisplayName(bool);


private:
    StepSequencerSwitch* m_switches[16];
    QLabel* m_displayNameLabel;
};

#endif // STEPSEQUENCERSWITCHROWVIEW_H
