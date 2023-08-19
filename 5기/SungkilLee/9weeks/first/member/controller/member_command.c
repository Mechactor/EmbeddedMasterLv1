#include "member_command.h"
#include "../../utility/ui/console/input_process.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char member_command_msg[] = "다음 명령들이 수행 가능합니다!\n"
                            "0 (member register)\n"
                            "1 (member login)\n"
                            "2 (member list)\n";

void print_member_command (void)
{
    print_input_msg (member_command_msg);
}

#define USER_COMMAND_BUFFER_SIZE 10

int input_user_member_command (void)
{

    char message[] = "원하는 명령을 입력하세요: ";


    char real_user_input[USER_COMMAND_INPUT_MAX] = { 0 };
    custom_user_input_with_msg(message, real_user_input);
    return atoi(real_user_input);

    //return 0;
}