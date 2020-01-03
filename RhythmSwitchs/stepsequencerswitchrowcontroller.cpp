#include "stepsequencerswitchrowcontroller.h"
#include "stepsequencerswitchrowview.h"
#include "Synth/sequencedtrack.h"

static const int MAX_VELOCITY = 127;

StepSequencerSwitchrowController::StepSequencerSwitchrowController(const std::string& displayName)
{
    m_sequencedTrack = nullptr;
    m_displayName = displayName;
    auto view = new StepSequencerSwitchrowView(displayName);
    view->setDelegate(this);
    m_view = view;
    ViewController::m_view = view;
}


void StepSequencerSwitchrowController::linkToInstrument(SamplePlayer* instrument) {
    delete m_sequencedTrack;
    m_sequencedTrack = new SequencedTrack(instrument);
}


void StepSequencerSwitchrowController::showDisplayName(bool show) {
    m_view->showDisplayName(show);
}


void StepSequencerSwitchrowController::litStateChanged(int stepid, bool islit) {
    char velocity = islit ? MAX_VELOCITY : 0;
    if (m_sequencedTrack) m_sequencedTrack->setStepValue(stepid,velocity);
}


StepSequencerSwitchrowController::~StepSequencerSwitchrowController()
{
    delete m_view;
    delete m_sequencedTrack;
}
