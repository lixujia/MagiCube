#include <stdio.h>
#include <stdlib.h>

#include "s-list.h"

SList* s_list_last(SList* list){
    if (NULL == list)
        return NULL;

    while (NULL != list->next){
        list = list->next;
    }

    return list;
}

SList* s_list_revert(SList* list){
    SList* ret_list = NULL;
    SList* tmp;

    while (NULL != list){
        tmp = list;
        
        list = list->next;

        tmp->next = ret_list;
        ret_list = tmp;
    }

    return ret_list;
}

SList* s_list_concat(SList* list1,SList* list2){
    SList* tmp;
    
    tmp = s_list_last(list1);

    if (NULL == tmp)
        return list2;

    tmp->next = list2;

    return list1;
}

SList* s_list_append(SList* list,void* data){
    SList* node;
    
    if (NULL == data)
        return list;

    if (NULL == (node = (SList*)malloc(sizeof(SList)))){
        fprintf(stderr,"Fail to alloc memory.\n");

        return NULL;
    }

    node->data = data;
	node->next = NULL;

    return s_list_concat(list,node);
}

SList* s_list_prepend(SList* list,void* data){
    SList* node;

    if (NULL == data)
        return list;

    if (NULL == (node = (SList*)malloc(sizeof(SList)))){
        fprintf(stderr,"Fail to alloc memory.\n");

        return NULL;
    }

    node->data = data;
    node->next = list;
    
    return node;
}

SList* s_list_push(SList* list,void* data){
    return s_list_prepend(list,data);
}

SList* s_list_pop(SList* list,void** data){
	SList* next;

	if (NULL == list) {
        *data = NULL;
		return NULL;
	}

	*data = list->data;
	next = list->next;
	free(list);

	return next;
}

void s_list_foreach(SList* list,void (*func)(void*,void*),void* arg){
    SList* iter;

    for (iter = list; NULL != iter; iter = iter->next){
        func(iter->data,arg);
    }
}

SList* s_list_search(SList* list,void* data,int (*cmp_func)(void*,void*)) {
	SList* iter;

	for (iter = list; NULL != iter; iter = iter->next) {
		if (0 == cmp_func(iter->data,data)) {
			return iter;
		}
	}

	return NULL;
}

