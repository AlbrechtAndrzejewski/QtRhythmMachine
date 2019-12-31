#include "stepsequencerswitch.h"
#include <QPainter>
#include "stepsequencerswitchdelegate.h"

StepSequencerSwitch::StepSequencerSwitch(int switchId)
{
    m_switchId = switchId;
    m_delegate = nullptr;
    m_activated = false;
    this->setFixedSize(16,28);
}


void StepSequencerSwitch::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor black(Qt::black);
    painter.fillRect(0,0,16,28, black);
    QColor gray(Qt::gray);
    QColor white(Qt::white);
    QColor red(Qt::red);
    if (m_activated) {
        painter.fillRect(0,0,16,28, gray);
        painter.fillRect(3,3,10,3, red);
    } else {
        painter.fillRect(0,0,16,28, black);
        painter.fillRect(3,3,10,3, white);
    }
}


void StepSequencerSwitch::mouseReleaseEvent(QMouseEvent *event) {
    m_activated = !m_activated;
    if (m_delegate) m_delegate->litStateChanged(m_switchId, m_activated);
    this->update();
}


void StepSequencerSwitch::setDelegate(StepSequencerSwitchDelegate* delegate) {
    m_delegate = delegate;
};
