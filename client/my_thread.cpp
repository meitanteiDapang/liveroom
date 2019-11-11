#include "my_thread.h"
#include "udp_socket.h"
#include "w1.h"
#include "w2.h"
#include "w3.h"
#include "protocol.h"
#include "common.h"

My_thread::My_thread()
{

}

void My_thread::run()
{

    //准备基础信息
    Udp_pro updu;
    memset(&updu, 0, sizeof(Udp_pro));
    updu.id = W1::get_instance().get_id();
    updu.room_id = updu.id;
    strcpy(updu.username, W1::get_instance().get_username());
    updu.is_caster = true;//这是主播流
    updu.is_getout = false;


    //获得直播图片
    while(true)
    {
        W3::get_instance().send_udp_to_server(&updu);
        msleep(INTERVAL);
    }
}
