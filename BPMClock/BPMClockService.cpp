#include "bpmclockservice.h"
#include <iostream>
#include <iomanip>
#include <QTimer>
#include "constants.h"

static BPMClockService* sharedInstance = nullptr;

int getUpdatePeriodInMillisecondFromBpm(int bpm, int resolution) {

   double pms = 1 / (double) ((bpm / 60) * (resolution/4)) * 1000;
   return pms;
}

BPMClockService* BPMClockService::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new BPMClockService();
    }
    return sharedInstance;
}


BPMClockService::BPMClockService()
{
    m_bpm = Constants::DEFAULT_BPM;
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, QOverload<>::of(&BPMClockService::tick));
    m_timer->start(getUpdatePeriodInMillisecondFromBpm(m_bpm, Constants::STEP_RESOLUTION));
}


int BPMClockService::getBPM()
{
    return m_bpm;
}


void BPMClockService::setBPM(int newValue)
{
    m_bpm = newValue;
    m_timer->stop();
    m_timer->start(getUpdatePeriodInMillisecondFromBpm(m_bpm, Constants::STEP_RESOLUTION));
    emit bpmChanged(m_bpm);
}


void BPMClockService::tick() {
    emit beatTicked();
}




