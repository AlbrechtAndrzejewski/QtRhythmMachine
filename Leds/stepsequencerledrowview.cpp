#include "stepsequencerledrowview.h"
#include <iostream>
#include "BPMClock/BPMClockService.h"
#include <QPainter>
#include <QLayout>
#include "led.h"
#include "constants.h"

StepSequencerLedRowView::StepSequencerLedRowView()
{
    this->connectToClock();
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    m_currentStep = 0;

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->setMargin(15);
    mainLayout->setContentsMargins(0,0,0,0);
    for (size_t i=0; i<Constants::STEP_RESOLUTION; i++) {
         m_leds[i] = new Led();
         mainLayout->addWidget(m_leds[i]);
    }

    setLayout(mainLayout);
}


void StepSequencerLedRowView::connectToClock(){
    BPMClockService* BPMclock = BPMClockService::getInstance();
    m_currentStep = 0;
    connect(BPMclock, &BPMClockService::beatTicked, this, &StepSequencerLedRowView::timerHasTicked);
}


void StepSequencerLedRowView::timerHasTicked() {
    for (int i=0; i<Constants::STEP_RESOLUTION; i++) {
         m_leds[i]->lit(false);
    }
    m_leds[m_currentStep]->lit(true);
    m_currentStep == 15 ? m_currentStep = 0 : m_currentStep++;
    this->update();
}
