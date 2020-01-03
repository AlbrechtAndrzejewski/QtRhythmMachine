#include "sequencedtrack.h"
#include "sampleplayer.h"
#include "BPMClock/bpmclockservice.h"
#include <iostream>
#include "constants.h"


SequencedTrack::SequencedTrack(SamplePlayer* instrument)
{
    m_instrument = instrument;
    memset(m_steps,0,Constants::STEP_RESOLUTION);
    m_currentStep = 0;
    connect(BPMClockService::getInstance(), &BPMClockService::beatTicked, this, &SequencedTrack::timerHasTicked);
}


void SequencedTrack::setStepValue(int id, int velocity) {
    m_steps[id] = velocity;

}


void SequencedTrack::timerHasTicked() {
    if (m_steps[m_currentStep] > 0) {
         m_instrument->play();
    }
    m_currentStep == (Constants::STEP_RESOLUTION-1) ? m_currentStep = 0 : m_currentStep++;
}
