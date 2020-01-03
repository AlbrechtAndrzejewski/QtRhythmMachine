#include "rhythmdeck.h"
#include "Leds/stepsequencerledrowview.h"
#include "RhythmSwitchs/stepsequencerswitchrowcontroller.h"
#include "BPMClock/bpmdisplayview.h"
#include <QWidget>
#include <QLayout>
#include <iostream>
#include <QMouseEvent>

#include <QLabel>

#include "Synth/DrumKit/DR110Kit.h"
#include "Synth/DrumKit/drumsampleplayer.h"

#include "BPMClock/bpmclockservice.h"

RhythmDeck::RhythmDeck()
{
    initSynths();
    initSequencers();

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    QHBoxLayout* aRow = new QHBoxLayout();
    aRow->setSpacing(0);
    BPMDisplayView* bpmDisplay = new BPMDisplayView();
    aRow->addWidget(bpmDisplay);
    StepSequencerLedRowView *leds = new StepSequencerLedRowView();
    aRow->addWidget(leds);
    gridLayout->addLayout(aRow,0,0);

    int localCounter = 0;
    for (const auto &pair : m_instruments) {
        m_switchs.push_back(new StepSequencerSwitchrowController(pair.first));
        m_switchs[localCounter]->linkToInstrument(pair.second);
        gridLayout->addWidget(m_switchs[localCounter]->view(),localCounter+1,0);
        localCounter++;
    }
    setLayout(gridLayout);
}

void RhythmDeck::initSynths() {
    m_instruments["HIHAT"] = new DrumSamplePlayer(DR110Kit::HIHAT);
    m_instruments["CLAP"] = new DrumSamplePlayer(DR110Kit::CLAPS);
    m_instruments["SNARE"] = new DrumSamplePlayer(DR110Kit::SNARE);
    m_instruments["KICK"] = new DrumSamplePlayer(DR110Kit::KICK);
}


void RhythmDeck::initSequencers() {
}


void RhythmDeck::mouseReleaseEvent(QMouseEvent *event) {
    std::cout << "Deck clicked" << event->x() << ":"<< event->y() << std::endl;
}


RhythmDeck::~RhythmDeck() {
    for (const auto &pair : m_instruments) {
        delete pair.second;
    }
}
