#pragma once

#include <QSlider>

#include "3rdparty/QMW/Includes/qtmaterialslider.h"

class Slider : public QtMaterialSlider
{
	Q_OBJECT

public:
    explicit Slider(QWidget *parent = nullptr);
	~Slider();

    void setRange(double Min, double Max);
    void setMinimum(double Min);
    double minimum() const;
    void setMaximum(double Max);
    double maximum() const;
    double value() const;
    
public slots:
    void setValue(int value);
    void setValue(double Value, bool BlockSignals = false);

private slots:

signals:
    void click_event(double Value);
    void valueChanged(double Value);
    void rangeChanged(double Min, double Max);
protected:
    void mousePressEvent(QMouseEvent* ev)
    {

        //ע��Ӧ�ȵ��ø��������������¼����������Բ�Ӱ���϶������
        QtMaterialSlider::mousePressEvent(ev);
        qDebug() << "clicked";
        double cxctl = 0;  // ������
        double cxwnd = 0;  // ���۳���
        double mxpos = 0;  // ��갴�µ�λ��
        cxctl = this->minimumSizeHint().width();
        cxwnd = this->width();
        if (this->invertedAppearance())
            mxpos = cxwnd - ev->x();
        else
            mxpos = ev->x();
        if (cxwnd <= cxctl)
        {
            //
        }
        double scpos = this->minimum() +
            (double)((this->maximum() - this->minimum()) *
                ((mxpos - cxctl / 2.0) / (cxwnd - cxctl)));

        if (this->sliderPosition() == scpos)
        {
            //
        }
        emit click_event(scpos);
        ////�򸸴��ڷ����Զ����¼�event type�������Ϳ����ڸ������в�������¼����д���
        //QEvent evEvent(static_cast<QEvent::Type>(QEvent::User + 1));
        //QCoreApplication::sendEvent(parentWidget(), &evEvent);

    }
private:
    double	m_Multiplier;
};
