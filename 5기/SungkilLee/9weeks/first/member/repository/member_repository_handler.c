#include "member_repository_handler.h"

#include "../../data_structure/list/list.h"
#include "../../utility/ui/console/input_process.h"
#include "../entity/member.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int member_count = 1;
int member_capacity = 1;

member *member_info_list = NULL;

void member_save_repository (member *member_object)
{   
    printf("member repository: save()\n");

    // 리스트가 가득 찬 경우, 더 큰 크기의 배열로 재할당
    if (member_count >= member_capacity) {
        member_capacity *= 2;
        member_info_list = (member *)realloc(member_info_list, sizeof(member) * member_capacity);
    }

    // 회원 정보 추가
    member_info_list[member_count].unique_value = member_count + 1; // 고유한 값으로 회원 정보 구조체 식별자 사용
    member_info_list[member_count].id = strdup(member_object->id);
    strcpy(member_info_list[member_count].password, member_object->password);
    member_info_list[member_count].nickname = strdup(member_object->nickname);

    member_count++; // 회원 수 증가

    // 입력 받은 정보로 회원 정보를 저장
    // member_info_table[empty_slot].id = strdup(member_object->id); // strdup는 문자열을 복제하는 함수
    // strcpy(member_info_table[empty_slot].password, member_object->password);
    // member_info_table[empty_slot].nickname = strdup(member_object->nickname);
    // strcpy(member_info_table[empty_slot].unique_value, member_object->unique_value);

    char success_msg[] = "회원 가입이 완료되었습니다!\n";
    print_input_msg (success_msg);

}

    
void member_find_by_id_repository (member *member_object)
{
    printf("member repository: find_by_id() \n");

    member *found_member = NULL;

    printf("found_member 초기화 \n");

    if (member_info_list == NULL) {
        printf("member_info_list가 초기화되지 않음\n");
        return; // 초기화되지 않은 경우 함수 종료
    }

    for (int i = 0; i < member_capacity; i++)
    {
        printf("for문 진입 횟수 : %d \n",i);

        if (member_info_list[i].id != NULL && strcmp(member_info_list[i].id, member_object->id) == 0)
        {
            found_member = &member_info_list[i];
            break;
        }
    }

    if (found_member != NULL)
    {
        printf("찾은 회원: id = %s, password = %s, nickname = %s\n", found_member->id, found_member->password, found_member->nickname);
    }

    else
    {
        printf("회원을 찾을 수 없음\n");
    }

}

void member_find_all_repository (member *member_object)
{
    printf("member repository: find_all()\n");

    member *found_member;

    printf("found member 재정의");

    if (found_member != NULL && strcmp(found_member->password, member_object->password) == 0)
    {
        char success_msg[50];
        sprintf(success_msg, "로그인 성공! 환영합니다, %s", found_member->nickname);
        print_input_msg(success_msg);
    }
    else
    {
        char error_msg[] = "로그인 실패: 아이디 또는 비밀번호가 잘못되었습니다.\n";
        print_input_msg(error_msg);
    }

}