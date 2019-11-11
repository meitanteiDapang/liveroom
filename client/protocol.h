#ifndef PROTOCOL_H
#define PROTOCOL_H

//msg_type shupazu

#define ADD_RETURN 50000

#define ERROR_TYPE 0
#define OK_TYPE 1

#define LOGIN_TYPE 101
#define REGIST_TYPE 102
#define LOGOUT_TYPE 103

#define CREATE_TYPE 201
#define RELOAD_LIST_TYPE 202
#define TOPUP_TYPE 203
#define ENTER_ROOM_TYPE 204
#define GET_BALANCE_TYPE  205


#define QUIT_ROOM_TYPE 302
#define CASTER_QUIT_TYPE 303
#define GROUP_CHAT_TYPE  304
#define SEND_ROCKET_TYPE 305
#define COMMING_ROCKET_TYPE  306


struct Protocol
{
    int msg_type;
    char username[32];
    char roomname[32];
    char password[32];
    char data[128];
    bool result;//is_caster?//list not end?
    int id;
    int room_id;
    float balance;
    int count;
    int num;
    bool isevent;
    float money;


    Protocol();
};

#endif // PROTOCOL_H
