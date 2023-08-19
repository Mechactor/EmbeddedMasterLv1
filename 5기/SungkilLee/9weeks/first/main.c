#include <stdio.h>

#include "command/command.h"
#include "command/command_handler.h"
#include "command/command_call_table.h"

void main_command_controller (void);

int main (void) {

    main_command_controller();
    return 0;
}

void main_command_controller (void)
{
    //init in memory data base를 만들어야 함 / member, product, order를 관리

    while (!check_user_input_close())
    {
        print_basic_command();
        int command = input_user_command();
        command_call_table[command]();
    }
}