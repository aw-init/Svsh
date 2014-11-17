#ifndef lLIST_H
#define lLIST_H
struct pidlist_t {
	int pid; 
	struct pidlist_t *next;
};

// create a new one-element list
struct pidlist_t* pl_new(int value);

// free the memory owned by the list
// this assumes all strings are malloc'd and not owned by anything else
void pl_free(struct pidlist_t* head);

// prepend a list with a new value
struct pidlist_t *pl_cons(int value, struct pidlist_t *head);

// get the first value in the list
int pl_car(struct pidlist_t *head);

// get the rest of the list
struct pidlist_t *pl_cdr(struct pidlist_t *head);

// return the list with the first n elements chopped off
struct pidlist_t *pl_slice(struct pidlist_t *head, int n);

//  get the value at index
int pl_nth(struct pidlist_t *head, int index);

// get the length of the list
int pl_length(struct pidlist_t *head);

// get the single element list at the end of the list
struct pidlist_t *pl_last_node(struct pidlist_t *head);

// combine two lists
struct pidlist_t *pl_append(struct pidlist_t *left, struct pidlist_t *right);

#ifndef pl_foreach
#define pl_foreach(X, CODE) if (X != NULL) do { CODE } while ( (X = X->next) != NULL)
#endif
#endif
