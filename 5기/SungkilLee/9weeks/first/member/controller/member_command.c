#include "member_command.h"

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
    printf("%s", member_command_msg);
}

#define USER_COMMAND_BUFFER_SIZE 10

int input_user_member_command (void)
{
    char selected_number[USER_COMMAND_BUFFER_SIZE] = {0, };
    char message[] = "원하는 명령을 입력하세요: ";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    read(0, &selected_number, USER_COMMAND_BUFFER_SIZE);

    return atoi(selected_number);

    //return 0;
}