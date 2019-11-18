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
#include "udp_socket.h"
#include "udp_socket_audience.h"
#include <my_thread.h>
//#include <my_thread_audience.h>
//#include <my_thread_audience_read.h>
#include <QPixmap>
#include <QByteArray>
#include <QBuffer>
#include <rocket_thread.h>
#include <QTextBrowser>
#include <QLabel>
#include <QTimer>

namespace Ui {
class W3;
}

class W3 : public QWidget
{
    Q_OBJECT

signals:
    void please_stop_capture();
    void go_on_process_picpic();
public slots:
    void when_captured(int id, QImage image);
public:
    Udp_pro m_pdup;
    QPixmap* m_pic_pic;
    QByteArray* m_bytearray;
    QBuffer* m_buffer;
    bool is_capture_done;

    explicit W3(QWidget *parent = nullptr);
    ~W3();
    virtual void closeEvent(QCloseEvent *event);

    //获得私有成员变量
    static W3 &get_instance();
    QTextBrowser* get_msg_tb();
    QCamera* get_camera();
    bool get_is_caster();
    int get_room_id();
    QCameraViewfinder* get_viewfinder();
    QString get_room_name();
    My_thread* get_thread();

    //修改私有成员变量
    void being_caster();
    void being_audience();
    void set_room_id(int id);
    void set_room_name(QString room_name);
    void add_room_name_test(QString room_name);

    //开始自拍的一些操作
    void start_camera_selfie();


    void add_chat_text(QString data);
    void clear_chat_text();
    void send_udp_to_server(Udp_pro* updu);
    void show_live_data(QByteArray b);

    //发送截屏信号
    void get_now_pic();

    //退出时，对摄像头及组件做一些处理
    void better_go_out();

    //展示弹幕（未完成)
    void show_danmu(QString data);

    //火箭图片发生
    void show_huojian();

    //向服务器发送加载直播间内人信息
    void load_people();

    //让m_count_count++
    void count_plus_plus();

    //利用pdu操作增加人列表
    void insert_into_table(Protocol& pdu);

    //刷新重载 人列表 发起函数
    void reload_people();



    //msg_tb与rocket_label互相整活
    void set_msg_tb();
    void unset_msg_tb();
    void set_rocket_label();
    void unset_rocket_label();


private slots:
    void on_quit_pb_clicked();

    void on_send_pb_clicked();

    void on_rocket_pb_clicked();

    void rocket_move();



    void on_refresh_people_pb_clicked();

private:
    Ui::W3 *ui;
    QCamera* m_camera;
    QCameraViewfinder* m_viewfinder;
    QCameraImageCapture* m_imageCapture;
    bool m_is_caster;
    int m_room_id;//房间主播id
    QString m_room_name;
    My_thread* m_thread;
    int m_load_count;
    int m_rows_num;
    QLabel* m_rocket_label;
    QVector<QTimer*> m_timer_vec;
    int m_ix;
    int m_iy;
};

#endif // W3_H
