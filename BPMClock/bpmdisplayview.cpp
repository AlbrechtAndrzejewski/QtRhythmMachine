#include "bpmdisplayview.h"
#include <QLabel>
#include <QPainter>
#include <string>
#include "bpmclockservice.h"
#include <iostream>

BPMDisplayView::BPMDisplayView()
{
    BPMClockService* BPMclock = BPMClockService::getInstance();

    m_bpmLabel = new QLabel(this);
    std::string bpm = std::to_string(BPMclock->getBPM());
    bpm = bpm + " BPM";
    m_bpmLabel->setText(bpm.c_str());
    connect(BPMclock, &BPMClockService::bpmChanged, this, &BPMDisplayView::onBPMChanged);

}


void BPMDisplayView::onBPMChanged(int bpm) {
    std::string bpmToDisplay = std::to_string(bpm) + " BPM";
    m_bpmLabel->setText(bpmToDisplay.c_str());
}
