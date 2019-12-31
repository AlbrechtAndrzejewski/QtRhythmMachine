#ifndef BPMClockService_H
#define BPMClockService_H

#include <QObject>

class QTimer;

class BPMClockService : public QObject
{
    Q_OBJECT
public:
    static BPMClockService* getInstance();

signals:
    void beatTicked();

private:
    BPMClockService();
    QTimer *m_timer;
    void tick();
};

#endif // BPMClockService_H
