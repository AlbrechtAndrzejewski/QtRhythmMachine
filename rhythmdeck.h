#ifndef MAINDECK_H
#define MAINDECK_H

#include <QWidget>
#include <vector>

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

    std::vector<SamplePlayer*> m_instruments;
};

#endif // MAINDECK_H
