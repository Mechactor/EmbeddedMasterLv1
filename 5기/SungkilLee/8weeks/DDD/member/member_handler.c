#include "member_handler.h"
#include "member.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <unistd.h>

#define MAX_USER_INPUT    17

int INITIAL_ALLOC = 10;


char print_id_msg[] = "아이디를 입력하세요 : ";
char print_password_msg[] = "비밀번호를 입력하세요 : ";

char user_id[MAX_USER_INPUT];
char user_password[MAX_USER_INPUT];

void member_register (void)
{
    char user_input[17] = { 0 };

    char message[] = "회원 가입을 진행합니다!\n";
    write(1, message, strlen(message));

    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_id, MAX_USER_INPUT);

    write(1, print_password_msg, strlen(print_password_msg));
    read(0, user_password, MAX_USER_INPUT);

    // member_info_table에서 빈 공간을 찾아서 사용자 정보를 저장
    int empty_slot = -1;
    for (int i = 0; i < INITIAL_ALLOC; i++)
    {
        if (member_info_table[i].id == NULL)
        {
            empty_slot = i;
            break;
        }
    }

    // 빈 공간이 없는 경우, 더 많은 공간으로 확장
    if (empty_slot == -1)
    {
        int new_size = INITIAL_ALLOC * 2;
        member *new_table = (member *)realloc(member_info_table, sizeof(member) * new_size);
        if (new_table == NULL)
        {
            char error_msg[] = "메모리를 할당할 수 없습니다. 회원 가입에 실패했습니다.\n";
            write(1, error_msg, strlen(error_msg));
            return;
        }
        member_info_table = new_table;
        INITIAL_ALLOC = new_size;
    }

    // 입력 받은 정보로 회원 정보를 저장
    member_info_table[empty_slot].id = strdup(user_id); // strdup는 문자열을 복제하는 함수
    strcpy(member_info_table[empty_slot].password, user_password);

    char success_msg[] = "회원 가입이 완료되었습니다!\n";
    write(1, success_msg, strlen(success_msg));

}

void member_login (void)
{
    char message[] = "로그인 시퀀스를 진행합니다!\n";
    write(1, message, strlen(message));

    // 사용자로부터 아이디와 비밀번호를 입력 받음
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_id, MAX_USER_INPUT);

    write(1, print_password_msg, strlen(print_password_msg));
    read(0, user_password, MAX_USER_INPUT);

    // 입력한 아이디와 비밀번호 확인을 위해 디버깅 코드
    //printf("입력한 아이디: %s\n", user_id);
    //printf("입력한 비밀번호: %s\n", user_password);

    // member_info_table에서 해당 아이디의 정보를 찾음
    member *found_member = NULL;
    for (int i = 0; i < INITIAL_ALLOC; i++)
    {
        if (member_info_table[i].id != NULL && strcmp(member_info_table[i].id, user_id) == 0)
        {
            found_member = &member_info_table[i];
            break;
        }
    }

    // 디버깅을 위해 회원 정보를 출력
    //if (found_member != NULL)
    //{
    //    printf("회원 정보를 찾았습니다:\n");
    //    printf("ID: %s\n", found_member->id);
    //    printf("Password: %s\n", found_member->password);
    //}

    // 사용자가 입력한 아이디와 비밀번호를 확인하여 로그인 여부 판단
    if (found_member != NULL && strcmp(found_member->password, user_password) == 0)
    {
        char success_msg[50];
        sprintf(success_msg, "로그인 성공! 환영합니다, %s", found_member->id);
        write(1, success_msg, strlen(success_msg));
    }
    else
    {
        char error_msg[] = "로그인 실패: 아이디 또는 비밀번호가 잘못되었습니다.\n";
        write(1, error_msg, strlen(error_msg));
    }
}