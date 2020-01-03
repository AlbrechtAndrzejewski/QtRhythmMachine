#ifndef BPMClockService_H
#define BPMClockService_H

#include <QObject>
#include <QThread>
#include <chrono>

class QTimer;

class BPMClockService : public QObject
{
    Q_OBJECT

public:
    static BPMClockService* getInstance();
    int getBPM();
    void setBPM(int bpm);
signals:
    void beatTicked(std::chrono::time_point<std::chrono::system_clock> timeEmitted);
    void bpmChanged(int newValue);


private:
    BPMClockService();

    QTimer *m_timer;
    void tick();
    int m_bpm;

    std::chrono::time_point<std::chrono::system_clock> m_lastUpdatedTime;
};

#endif // BPMClockService_H
