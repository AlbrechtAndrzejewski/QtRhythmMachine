#include <iostream>
#include <chrono>

#include "BPMClock/bpmclockservice.h"
#include "sequencedtrack.h"
#include "sampleplayer.h"
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


void SequencedTrack::timerHasTicked(std::chrono::time_point<std::chrono::system_clock> startTime) {

    if (m_steps[m_currentStep] > 0) {
       m_instrument->play();
    }
    auto playTime = std::chrono::system_clock::now();
    std::chrono::duration<double> latency = playTime - startTime;
    if (latency.count() > 0.001) {
        std::cout << "Latency : " << latency.count() << std::endl;
    }
    m_currentStep == (Constants::STEP_RESOLUTION-1) ? m_currentStep = 0 : m_currentStep++;
}
