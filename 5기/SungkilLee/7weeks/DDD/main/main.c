#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "how_to_malloc.h"

const char welcom_message[] = "\n저희 시스템을 찾아주셔서 감사합니다.\n";
const char not_loggedined_option_message[] = "1번 (회원가입) 2번 (로그인) 중 원하는 작업을 선택해주세요.\n";

void print_welcome_message(void)
{
    int welcome_message_length = strlen(welcom_message);
    int option_message_length = strlen(not_loggedined_option_message);
    int message_length = welcome_message_length + option_message_length + 1;

    char* message = (char *)malloc(sizeof(char) * message_length);

    strncat(message, welcom_message, welcome_message_length);
    strncat(message, not_loggedined_option_message, option_message_length);

    printf(message);
}

int get_user_selected_number(void)
{
    char selected_number = 0;
    char message[] = "원하는 동작을 입력하세요 : ";
    int message_length = strlen(message);

    //selected_number = getchar();

    write(1, message, message_length);
    read(0, &selected_number, 2);

    printf("selected Number = %d\n", selected_number - 0x30);

    return selected_number;
}

char join_member_domain ()
{
    printf("\n회원가입 도메인 입니다. \n");

    char join_id[10];
    printf("아이디를 입력해 주세요 :");
    scanf("%s", join_id);

    char join_password[10];
    printf("비밀번호를 입력해 주세요 :");
    scanf("%s", join_password);

    char join_nickname[10];
    printf("닉네임을 입력해 주세요 :");
    scanf("%s", join_nickname);

    printf("\n회원가입이 완료 되었습니다.\n");
    printf("ID : %s \n",join_id);
    printf("PASSWORD : %s \n",join_password);
    printf("NICKNAME : %s \n",join_nickname);

    return join_nickname;

}

void log_in_domain (void)
{
    printf("\n로그인 도메인 입니다.\n");

    char log_id[10];
    printf("아이디를 입력해 주세요 :");
    scanf("%s", log_id);

    char log_password[10];
    printf("비밀번호를 입력해 주세요 :");
    scanf("%s", log_password);

    char join_nickname = *join_member_domain;
    printf("\n환영합니다. %s 님! \n", join_nickname);

}

int main (void)
{
    // F7 : Build
    // Shift + F5 : Run;
    // Ctrl + F5 : Debug
    bool is_finished = false;

    printf("malloc 동적 할당 테스트\n");

	how_to_malloc_data();

    for(; !is_finished;)
    {
        // TODO : 특정 파일을 읽어서 로그인 여부를 판정합니다.
        //        [MALLOC-MEMBER-6]
        bool is_loged_in = false;

        if(!is_loged_in)
        {
            print_welcome_message();
        }

        //get_user_selected_number();

        char selected_number = get_user_selected_number() - 0x30;

        if(selected_number == 1)
        {
            char join_nickname = join_member_domain();
        }
        else if(selected_number == 2)
        {
            log_in_domain();
            return 0;
        }
        else
        {
            printf("%d는 잘못 된 입력입니다. 시스템을 종료합니다.\n", selected_number);
            return 0;
        }

    }

    return 0;
}