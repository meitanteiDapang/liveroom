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
    virtual void closeEvent(QCloseEvent *event);
    int get_room_id();
    void set_room_id(int id);
    bool get_is_caster();
    QCamera* get_camera();

private slots:
    void on_quit_pb_clicked();

    void on_send_pb_clicked();

    void on_rocket_pb_clicked();

private:
    Ui::W3 *ui;
    QCamera* m_camera;
    QCameraViewfinder* m_viewfinder;
    QCameraImageCapture* m_imageCapture;
    bool m_is_caster;
    int m_room_id;//房间主播id

};

#endif // W3_H
