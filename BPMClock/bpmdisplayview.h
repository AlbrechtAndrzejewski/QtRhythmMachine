#ifndef BPMDISPLAYVIEW_H
#define BPMDISPLAYVIEW_H

#include <QWidget>

class QLabel;

class BPMDisplayView : public QWidget
{
    Q_OBJECT
public:
    BPMDisplayView();

public slots:
    void onBPMChanged(int bpm);


private:
    QLabel* m_bpmLabel;
};

#endif // BPMDISPLAYVIEW_H
