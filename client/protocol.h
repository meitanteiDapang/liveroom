#ifndef PROTOCOL_H
#define PROTOCOL_H

//msg_type shupazu

#define ADD_RETURN 50000

#define ERROR_TYPE 0
#define OK_TYPE 1

#define LOGIN_TYPE 101
#define REGIST_TYPE 102
#define LOGOUT_TYPE 103

struct Protocol
{
    int msg_type;
    char username[32];
    char password[32];
    char data[128];
    bool result;
    int id;


    Protocol();
};

#endif // PROTOCOL_H
