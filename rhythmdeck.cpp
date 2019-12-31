#include "rhythmdeck.h"
#include "Leds/stepsequencerledrowview.h"
#include "RhythmSwitchs/stepsequencerswitchrowcontroller.h"
#include "Synth/DrumKit/drumsampleplayer.h"
#include <QWidget>
#include <QLayout>
#include <iostream>
#include <QMouseEvent>

#include "Synth/DrumKit/DR110Kit.h"
#include "Synth/DrumKit/drumsampleplayer.h"

RhythmDeck::RhythmDeck()
{
    initSynths();
    initSequencers();

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    StepSequencerLedRowView *leds = new StepSequencerLedRowView();
    gridLayout->addWidget(leds,0,0);

    std::vector<StepSequencerSwitchrowController*> switchs;
    for (size_t i=0; i<m_instruments.size(); i++) {
        switchs.push_back(new StepSequencerSwitchrowController());
        switchs[i]->linkToInstrument(m_instruments[i]);
        gridLayout->addWidget(switchs[i]->view(),i+1,0);
    }
    setLayout(gridLayout);
}

void RhythmDeck::initSynths() {
    m_instruments.push_back(new DrumSamplePlayer(DR110Kit::KICK));
    m_instruments.push_back(new DrumSamplePlayer(DR110Kit::SNARE));
    m_instruments.push_back(new DrumSamplePlayer(DR110Kit::HIHAT));
    m_instruments.push_back(new DrumSamplePlayer(DR110Kit::CLAPS));
}


void RhythmDeck::initSequencers() {
}


void RhythmDeck::mouseReleaseEvent(QMouseEvent *event) {
    std::cout << "Deck clicked" << event->x() << ":"<< event->y() << std::endl;
}


RhythmDeck::~RhythmDeck() {
    for (size_t i=0; i<m_instruments.size(); i++) {
        delete m_instruments[i];
    }
}
