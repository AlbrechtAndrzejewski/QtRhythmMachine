#ifndef LED_H
#define LED_H

#include <QWidget>


class Led : public QWidget
{
Q_OBJECT

public:
    Led();
    void lit(bool);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool m_islit;
};

#endif // LED_H
