#include "stepsequencerswitchrowview.h"
#include <QLayout>
#include "stepsequencerswitch.h"
#include "constants.h"

StepSequencerSwitchrowView::StepSequencerSwitchrowView()
{
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    auto *mainLayout = new QHBoxLayout();
    mainLayout->setMargin(15);
    mainLayout->setContentsMargins(0,0,0,0);

    for (int i=0; i<Constants::STEP_RESOLUTION; i++) {
         m_switches[i] = new StepSequencerSwitch(i);
         mainLayout->addWidget(m_switches[i]);
    }
    setLayout(mainLayout);
}


void StepSequencerSwitchrowView::setDelegate(StepSequencerSwitchDelegate* delegate) {
    for (size_t i=0; i<Constants::STEP_RESOLUTION; i++) {
        m_switches[i]->setDelegate(delegate);
    }
}


StepSequencerSwitchrowView::~StepSequencerSwitchrowView() {
    for (int i=0; i<Constants::STEP_RESOLUTION; i++) {
        delete m_switches[i];
    }
}
