#ifndef _S_LIST_H_
#define _S_LIST_H_

typedef struct _SList SList;

struct _SList{
    void* data;

    SList* next;
};

SList* s_list_last(SList* list);
SList* s_list_revert(SList* list);
SList* s_list_concat(SList* list1,SList* list2);
SList* s_list_append(SList* list,void* data);
SList* s_list_prepend(SList* list,void* data);
SList* s_list_push(SList* list,void* data);
SList* s_list_pop(SList* list,void** data);
SList* s_list_search(SList* list,void* data,int (*cmp_func)(void*,void*));

//void s_list_foreach(SList* list,void (*func)(void* data_list,void* data_arg),void* arg);

#endif /* _S_LIST_H_ */
