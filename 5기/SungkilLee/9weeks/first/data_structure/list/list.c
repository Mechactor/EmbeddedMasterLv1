#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "list.h"


void init_member_info_list (void)
{
    member_capacity = 10;
    member_info_list = (member *)malloc(sizeof(member) * member_capacity);

}
