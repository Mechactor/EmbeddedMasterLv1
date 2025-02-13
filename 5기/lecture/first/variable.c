#include <stdio.h>

// vi에서 입력 할 땐 'i' 혹은 'a' 키를 누릅니다.
// 입력할 내용이 더 이상 없는 경우엔 'esc' 키를 눌러서 명령 모드로 전환합니다.
// 추가적으로 저장하고 나고 싶은 경우엔 ':wq' 를 입력하고 앤터치면 됩니다.

// 컴파일을 하고 싶은 분들은 아래 명령을 입력합니다.
// gcc variable.c

// 이후 ls를 입력하면 a.out 실행 파일이 보일 것입니다.
// ./a.out 으로 실행할 수 있으며
// './' 는 현재 위치에 있는 무엇무엇을 의미합니다.
// 그러므로 현 위치에 있는 a.out을 실행하세요라는 뜻을 가집니다.

// 실행파일명을 구별하기 위해 별도의 추가 옵션을 줄 수 있습니다.
// gcc -o 실행파일명 소스코드

// 위의 형태로 컴파일하면 실행파일명으로 실행파일을 만들 수 있습니다.
// a.out으로 나오지 않기 때문에 파일명만 명확하다면
// 목적을 분명하게 전달 할 수 있습니다.
int main (void)
{
	int variable = 3;
	printf("variable = %d\n", variable);

	return 0;
}
