#include "stepsequencerswitchrowview.h"
#include <QLayout>
#include <QLabel>
#include "stepsequencerswitch.h"
#include "constants.h"

using namespace std;

static string normalizeTo8char(string str) {
    if (str.length()>8) {
        return str.substr(0,8);
    } else if (str.length()<8) {
        return str.append(8-str.length(), ' ');
    }
    return str;
}


StepSequencerSwitchrowView::StepSequencerSwitchrowView(const string& displayName)
{
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    auto *mainLayout = new QHBoxLayout();
    mainLayout->setMargin(15);
    mainLayout->setContentsMargins(0,0,0,0);

    string normalized = normalizeTo8char(displayName);
    m_displayNameLabel = new QLabel(normalized.c_str(), this);
    QFont f("Andale Mono", 11, QFont::Bold);
    f.setStyleHint(QFont::Monospace);
    m_displayNameLabel->setFont(f);
    mainLayout->addWidget(m_displayNameLabel);

    for (int i=0; i<Constants::STEP_RESOLUTION; i++) {
         m_switches[i] = new StepSequencerSwitch(i);
         mainLayout->addWidget(m_switches[i]);
    }
    setLayout(mainLayout);
}


void StepSequencerSwitchrowView::showDisplayName(bool show) {
    show ? m_displayNameLabel->show() : m_displayNameLabel->hide();
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
