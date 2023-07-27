#include "command.h"

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
    printf("%s", basic_msg);
}

#define USER_COMMAND_BUFFER_SIZE 3

int input_user_command (void)
{
    char selected_number[USER_COMMAND_BUFFER_SIZE] = {0, };
    char message[] = "원하는 명령을 입력하세요: ";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    read(0, &selected_number, USER_COMMAND_BUFFER_SIZE);

    return atoi(selected_number);

    //return 1;
}