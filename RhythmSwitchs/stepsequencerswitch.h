#ifndef STEPSEQUENCERSWITCH_H
#define STEPSEQUENCERSWITCH_H

#include <QWidget>

class StepSequencerSwitchDelegate;

class StepSequencerSwitch : public QWidget
{
Q_OBJECT

public:
    StepSequencerSwitch(int switchId);
    void mouseReleaseEvent(QMouseEvent *event) override;
    void setDelegate(StepSequencerSwitchDelegate*);

protected:
    int m_switchId;
    void paintEvent(QPaintEvent *event) override;
    bool m_activated;
    StepSequencerSwitchDelegate* m_delegate;
};

#endif // STEPSEQUENCERSWITCH_H
