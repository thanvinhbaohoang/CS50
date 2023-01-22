# CS50 Lab 3
## CS50 Summer 2021

### set

A `set` is an unordered collection of _(key-item)pairs_.
The `set` starts empty, grows as the caller adds one _(key-item)pair_ at a time.
It could be empty, or could contain hundreds of _(key-item)pair_.
_Item_ is identified by a _key_ , so the _get_ function can return _item_ from the `set` by looking through every _(key-item)pair_.

### Usage

The *set* module, defined in `set.h` and implemented in `set.c`, implements a set of `void*`, and exports the following functions:

```c
set_t *set_new(void);
void set_insert(set_t *set, void *item);
void *set_find(set_t *set);
void set_print(set_t *set, FILE *fp, 
	       void (*itemprint)(FILE *fp, void *item));
void set_iterate(set_t *set, void *arg, void (*itemfunc)(void *arg, void *item) );
void set_delete(set_t *set, void (*itemdelete)(void *item) );
```

### Implementation

We implement this set as a linked list.
The *set* itself is represented as a `struct set` containing a pointer to the head of the list; the head pointer is NULL when the set is empty.

Each node in the list is a `struct setpair`, a type defined internally to the module.
Each setpair includes a pointer to the `char key`, and one to `void *item` and a pointer to the next setpair on the list.

To insert a new item in the set we create a new setpair to hold the `item`, and insert it at the head of the list.

To find an item from the set we iterate over every node in the list and return the specified item.
We return NULL if any of the inputs for the function is NULL

`set_print` : prints a the enclosure set symbols `{}` around the list, and `,` between items, but mostly calls the `itemprint` function on each item by scanning the linked list.

`set_iterate`: calls the `itemfunc` function on each item by scanning the linked list.

`set_delete` : calls the `itemdelete` function on each item by scanning the linked list, freeing each setpair and its item as it proceeds.
It ends by freeing the `struct set`.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `item` inserted cannot be NULL, and thus a NULL return from `set_find` must indicate either error or empty set, not a NULL `item` coming out of the set.

Because of the semantics of a *set*, we have great freedom in our implementation.

### Files

* `Makefile` - compilation procedure
* `set.h` - the interface
* `set.c` - the implementation
* `settest.c` - unit test driver
* `test.names` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make`.

### Testing

The `settest.c` program reads from hardcoded `set_insert` and stuffs them into a set.
It tests a few error and edge cases.
This test is somewhat minimal.
A lot more could be done!

To test, simply `make test`.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.
