#include "BPMClockService.h"
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
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, QOverload<>::of(&BPMClockService::tick));
    m_timer->start(getUpdatePeriodInMillisecondFromBpm(Constants::DEFAULT_BPM, Constants::STEP_RESOLUTION));
}


void BPMClockService::tick() {
    emit beatTicked();
}




