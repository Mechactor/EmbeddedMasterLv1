#include "member_command_handler.h"
#include "../entity/member.h"

#include "../service/member_service_command.h"
#include "../service/member_service_handler.h"
#include "../service/member_service_command_table.h"

#include "../service/request/member_request.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

#define MAX_USER_INPUT    17

int INITIAL_ALLOC = 10;


char print_id_msg[] = "아이디를 입력하세요 : ";
char print_password_msg[] = "비밀번호를 입력하세요 : ";
char print_nickname_msg[] = "닉네임을 입력하세요 : ";

char id[MAX_USER_INPUT];
char password[MAX_USER_INPUT];
char nickname[MAX_USER_INPUT];

void member_register (void)
{
    char user_input[17] = { 0 };

    char message[] = "회원 가입을 진행합니다!\n";
    write(1, message, strlen(message));

    write(1, print_id_msg, strlen(print_id_msg));
    read(0, id, MAX_USER_INPUT);

    write(1, print_password_msg, strlen(print_password_msg));
    read(0, password, MAX_USER_INPUT);

    write(1, print_nickname_msg, strlen(print_nickname_msg));
    read(0, nickname, MAX_USER_INPUT);

    //char id[3] = "id";
    //char password[9] = "password";

    //printf("member controller: register()\n");

    member_request *member_request_object = init_member_request(id, password);
    member_service_table[MEMBER_REGISTER_SERVICE](member_request_object);

    free_member_request(member_request_object);
}

void member_login (void)
{
    char user_id[MAX_USER_INPUT] = { 0 };
    char user_password[MAX_USER_INPUT] = { 0 };
    char message[] = "로그인 시퀀스를 진행합니다!\n";
    int message_length = strlen(message);


    printf("로그인 성공!\n");
}

void member_list (void)
{
    printf("unique value: %d\n", unique_member_value_count);
    //printf("id: %s", member_info_table[0].id)
}