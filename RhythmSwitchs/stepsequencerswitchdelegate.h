#ifndef STEPSEQUENCERSWITCHDELEGATE_H
#define STEPSEQUENCERSWITCHDELEGATE_H


class StepSequencerSwitchDelegate
{
public:
    virtual void litStateChanged(int id, bool islit) = 0;
};

#endif // STEPSEQUENCERSWITCHDELEGATE_H
