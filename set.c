#include <stdlib.h>
#include <stdio.h>

#include "set.h"
#include "set.h"
#include "list.h"

struct word
{
    char **string;
};

struct set
{
    cmpfunc_t cmpfunc;
    word_t **word;
    int size;
    list_t *list;
    void *elm;
};


struct set_iter
{
    set_t *set;
};

int mainty()
{
    set_t *t=set_create(compare_strings);
}
/*
 * Creates a new set using the given comparison function
 * to compare elements of the set.
 */
set_t *set_create(cmpfunc_t cmpfunc)
{
    
    set_t *set= malloc(sizeof(set_t));
    set->cmpfunc=cmpfunc;
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

/*
 * Adds the given element to the given set.
 */
void set_add(set_t *set, void *elem)
{
    
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
    t= set;
    return t;
}

/*
 * The type of set iterators.
 */


/*
 * Creates a new set iterator for iterating over the given set.
 */
set_iter_t *set_createiter(set_t *set)
{
    set_iter_t *t= malloc(sizeof(set_t));
    t->set=set;
    return t;
}

/*
 * Destroys the given set iterator.
 */
void set_destroyiter(set_iter_t *iter)
{
    
}

/*
 * Returns 0 if the given set iterator has reached the end of the
 * set, or 1 otherwise.
 */
int set_hasnext(set_iter_t *iter)
{
    return 1;
}

/*
 * Returns the next element in the sequence represented by the given
 * set iterator.
 */
void *set_next(set_iter_t *iter)
{
    //return iter->set->list->next;
}
