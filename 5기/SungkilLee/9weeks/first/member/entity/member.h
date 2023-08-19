#ifndef __MEMBER_H__
#define __MEMBER_H__

#define MAX_USER_INPUT          50

typedef struct _member member;
struct _member
{
    int unique_value;
    char *id;
    char password[MAX_USER_INPUT];
    char *nickname;
};


extern int unique_member_value_count;

member *init_member (char *id, char *password, char *nickname);
member *found_member (char *id, char *password);

void print_member (member *member_object);
void free_member (member *member_object);

extern int member_count;
extern int member_capacity;

extern member *member_info_list;

#endif