#ifndef W3_H
#define W3_H

#include <QWidget>
#include "w2.h"


#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>



namespace Ui {
class W3;
}

class W3 : public QWidget
{
    Q_OBJECT

public slots:

public:
    explicit W3(QWidget *parent = nullptr);
    ~W3();
    static W3 &get_instance();
    void start_camera_selfie();

    void being_caster();
    void being_audience();

private slots:
    void on_quit_pb_clicked();

private:
    Ui::W3 *ui;
    QCamera* m_camera;
    QCameraViewfinder* m_viewfinder;
    QCameraImageCapture* m_imageCapture;
    bool m_is_caster;

};

#endif // W3_H