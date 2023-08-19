#include "command.h"
#include "../utility/ui/console/input_process.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char basic_msg[] = "다음의 명령들이 수행 가능합니다!\n"
                   "0 (program exit)\n"
                   "1 (member)\n";

int user_input_command = 1;

bool check_user_input_close (void)
{
    return user_input_command == 0;
}

void print_basic_command (void)
{
    print_input_msg (basic_msg);
}

#define USER_COMMAND_BUFFER_SIZE 3

int input_user_command (void)
{

    char message[] = "원하는 명령을 입력하세요: ";

    //return 1;

    char real_user_input[USER_COMMAND_INPUT_MAX] = { 0 };
    custom_user_input_with_msg(message, real_user_input);
    return atoi(real_user_input);
}