#ifndef BPMClockService_H
#define BPMClockService_H

#include <QObject>

class QTimer;

class BPMClockService : public QObject
{
    Q_OBJECT

public:
    static BPMClockService* getInstance();
    int getBPM();
    void setBPM(int bpm);

signals:
    void beatTicked();
    void bpmChanged(int newValue);

private:
    BPMClockService();
    QTimer *m_timer;
    void tick();
    int m_bpm;
};

#endif // BPMClockService_H
