#include <stdlib.h>
#include <stdio.h>

#include "set.h"
#include "list.h"


struct set
{
    set_node_t *head;
    set_node_t *tail;
    cmpfunc_t cmpfunc;
    int size;
};

struct set_node
{
    void *element;
    set_node_t *next;
    set_node_t *prev;

};
struct set_iter
{
    set_t *set;
    set_node_t *node;
};

/*
 * Creates a new set using the given comparison function
 * to compare elements of the set.
 */
set_t *set_create(cmpfunc_t cmpfunc)
{
    
    set_t *set= malloc(sizeof(set_t));
    if (set==NULL)
    {
        return NULL;
    }
    set->cmpfunc=cmpfunc;
    set->head=NULL;
    set->size=0;
    set->tail=NULL;
    return set;
}

/*
 * Destroys the given set.  Subsequently accessing the set
 * will lead to undefined behavior.
 */
void set_destroy(set_t *set)
{

}

/*
 * Returns the size (cardinality) of the given set.
 */
int set_size(set_t *set)
{
    return set->size;
}

char *get_current_item(set_iter_t *iter)
{
    //printf("%s\n",iter->node->element);
    return iter->node->element;
}

set_node_t *get_current_node(set_iter_t *iter)
{
    return iter->node;
}
/*
 * Adds the given element to the given set.
 */
void set_add(set_t *set, void *elem)
{   
    set_node_t *prev;
    set_node_t *next;
    set_node_t *node = newnode(elem);
    node->element=elem;
    if(set_size(set)==0)
    {
        set->head=node;
        set->size=0;
        node->next=NULL;
        node->prev=NULL;
        return;
    }
    set_iter_t *iter = set_createiter(set);
    next=set->head;
    prev=NULL;
    while(set_hasnext(iter))
	{
        if(set->cmpfunc(elem,get_current_item(iter))==0){return;}
        if(set->cmpfunc(elem,get_current_item(iter))>0)
        {
            prev=get_current_node(iter);
            next=prev->next;
        }
        set_next(iter);  
	}
       
    if(next==set->head)
    {
        node->next=set->head;
        set->head=node;
        set->size++;
        return;
    }
    prev->next=node;
    node->next=next;
    set->size++;
}
/*
 * Returns 1 if the given element is contained in
 * the given set, 0 otherwise.
 */
int set_contains(set_t *set, void *elem)
{
    return 1;
}

/*
 * Returns the union of the two given sets; the returned
 * set contains all elements that are contained in either
 * a or b.
 */
set_t *set_union(set_t *a, set_t *b)
{
    set_t *t= malloc(sizeof(set_t));
    return t;
}

/*
 * Returns the intersection of the two given sets; the
 * returned set contains all elements that are contained
 * in both a and b.
 */
set_t *set_intersection(set_t *a, set_t *b)
{
    set_t *t= malloc(sizeof(set_t));
    return t;
}

/*
 * Returns the set difference of the two given sets; the
 * returned set contains all elements that are contained
 * in a and not in b.
 */
set_t *set_difference(set_t *a, set_t *b)
{
    set_t *t= malloc(sizeof(set_t));
    return t;
}

/*
 * Returns a copy of the given set.
 */
set_t *set_copy(set_t *set)
{
    set_t *t= malloc(sizeof(set_t));
    t = set;
    return t;
}

/*
 * The type of set iterators.
 */
void set_destroyiter(set_iter_t *iter)
{

}


/*
 * Creates a new set iterator for iterating over the given set.
 */
set_iter_t *set_createiter(set_t *set)
{
    set_iter_t *iter = malloc(sizeof(set_t));
    if (iter==NULL)
    {
        return NULL;
    }
    iter->set=set;
    iter->node=set->head;
    return iter;
}

/*
 * Returns 0 if the given set iterator has reached the end of the
 * set, or 1 otherwise.
 */
int set_hasnext(set_iter_t *iter)
{
    if (iter->node->next == NULL)
    {
	    return 0;
    }
    return 1;
}

/*
 * Returns the next element in the sequence represented by the given
 * set iterator.
 */
void *set_next(set_iter_t *iter)
{
    //printf("%s\n",iter->node->element);

    iter->node=iter->node->next;
    void *element=iter->node->element;
    return element;
}

set_node_t *newnode(void *elem)
{
    set_node_t *node = malloc(sizeof(set_node_t));
    if (node == NULL)
        return NULL;
    
    node->next = NULL;
    node->prev = NULL;
    node->element = elem;
    return node;
}