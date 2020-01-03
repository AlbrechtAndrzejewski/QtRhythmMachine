#ifndef MAINDECK_H
#define MAINDECK_H

#include <QWidget>
#include <map>

class StepSequencerSwitchrowController;

class SamplePlayer;

class RhythmDeck : public QWidget
{
public:
    RhythmDeck();
    ~RhythmDeck();

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void initSynths();
    void initSequencers();

    std::map<std::string, SamplePlayer*> m_instruments;
    std::vector<StepSequencerSwitchrowController*> m_switchs;

};

#endif // MAINDECK_H
