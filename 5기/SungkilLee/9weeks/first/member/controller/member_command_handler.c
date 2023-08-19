#include "member_command_handler.h"
#include "../entity/member.h"

#include "../service/member_service_command.h"
#include "../service/member_service_handler.h"
#include "../service/member_service_command_table.h"

#include "../service/request/member_request.h"

#include "../../utility/ui/console/input_process.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>

//#define MAX_USER_INPUT    17



char print_id_msg[] = "아이디를 입력하세요 : ";
char print_password_msg[] = "비밀번호를 입력하세요 : ";
char print_nickname_msg[] = "닉네임을 입력하세요 : ";

char id[USER_COMMAND_INPUT_MAX];
char password[USER_COMMAND_INPUT_MAX];
char nickname[USER_COMMAND_INPUT_MAX];

void member_register (void)
{
    char real_user_input[USER_COMMAND_INPUT_MAX] = { 0 };

    char message[] = "회원 가입을 진행합니다!\n";

    print_input_msg (message);

    custom_user_input_with_msg(print_id_msg, id);
    custom_user_input_with_msg(print_password_msg, password);
    custom_user_input_with_msg(print_nickname_msg, nickname);

       
    // char user_input[17] = { 0 };

    // char message[] = "회원 가입을 진행합니다!\n";
    // write(1, message, strlen(message));

    // write(1, print_id_msg, strlen(print_id_msg));
    // read(0, id, MAX_USER_INPUT);

    // write(1, print_password_msg, strlen(print_password_msg));
    // read(0, password, MAX_USER_INPUT);

    // write(1, print_nickname_msg, strlen(print_nickname_msg));
    // read(0, nickname, MAX_USER_INPUT);

    //char id[3] = "id";
    //char password[9] = "password";

    //printf("member controller: register()\n");

    member_request *member_request_object = init_member_request(id, password, nickname);
    member_service_table[MEMBER_REGISTER_SERVICE](member_request_object);

    free_member_request(member_request_object);
}

void member_login (void)
{
    char user_input[17] = { 0 };

    char message[] = "로그인 시퀀스를 진행합니다!\n";
    write(1, message, strlen(message));

    write(1, print_id_msg, strlen(print_id_msg));
    read(0, id, MAX_USER_INPUT);

    write(1, print_password_msg, strlen(print_password_msg));
    read(0, password, MAX_USER_INPUT);

    //char user_id[MAX_USER_INPUT] = { 0 };
    //char user_password[MAX_USER_INPUT] = { 0 };
    //char message[] = "로그인 시퀀스를 진행합니다!\n";
    //int message_length = strlen(message);

// member *found_member = NULL;
//     for (int i = 0; i < INITIAL_ALLOC; i++)
//     {
//         if (member_info_table[i].id != NULL && strcmp(member_info_table[i].id, user_id) == 0)
//         {
//             found_member = &member_info_table[i];
//             break;
//         }
//     }
    
    member_request *member_request_object = found_member_request(id,password);
    member_service_table[MEMBER_LOGIN_SERVICE](member_request_object);

    free_member_request(member_request_object);
}

void member_list (void)
{
    printf("unique value: %d\n", unique_member_value_count);
    //printf("id: %s", member_info_table[0].id)
}