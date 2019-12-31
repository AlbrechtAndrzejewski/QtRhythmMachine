#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <QWidget>

class ViewController
{
public:
    ViewController() {m_view = nullptr;}
    virtual ~ViewController() {delete m_view;};

    QWidget* view()
    {
       return m_view;
    };

protected:
    QWidget* m_view;

};

#endif // VIEWCONTROLLER_H
