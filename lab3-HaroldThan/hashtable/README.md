# CS50 Lab 3
## CS50 Summer 2021

### hashtable

A `hashtable` is a set of ordered collection of slots (datatype of Set).
The `hashtable` starts empty, grows as the caller adds one _(key-item)pair_ at a time.
It could be empty, or could contain hundreds of _(key-item)pair_.
_Item_ is identified by a _key_ , so the _get_ function can return _item_ from the `hashtable` by looking through every _(key-item)pair_.

### Usage

The *hashtable* module, defined in `hashtable.h` and implemented in `hashtable.c`, implements a hashtable of `void*`, and exports the following functions:

```c
hashtable_t *hashtable_new(void);
void hashtable_insert(hashtable_t *ht, void *item);
void *hashtable_find(hashtable_t *ht);
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, void *item));
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, void *item) );
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) );
```

### Implementation

We implement this hashtable as using it as a bigger set of sets
The *hashtable* itself is represented as a `struct hashtable` containing a specified `num_slots`

Each node in the list is a `set_t`, a type defined in `set.h`

To insert a new item in the hashtable we create a new slot (slots[i]) to hold the `set_t`, and insert the set to slot at location of
hash_key which is JenkinsHash of the input key.

To find an item from the hashtable we iterate over every node in the list and return the specified item.
We return NULL if any of the inputs for the function is NULL

`hashtable_print` : call `set_print` on every slot

`hashtable_iterate`: calls the `itemfunc` function on each item by scanning the linked list.

`hashtable_delete` : calls  `set_delete` on every slot
It ends by freeing the `struct hashtable`.

### Assumptions

No assumptions beyond those that are clear from the spec.
Pray to god that set.c works correctly because this entire thing rely on set.h to work

### Files

* `Makefile` - compilation procedure
* `hashtable.h` - the interface
* `hashtable.c` - the implementation
* `hashtabletest.c` - unit test driver
* `test.names` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make`.

### Testing

The `hashtabletest.c` program reads from hardcoded `hashtable_insert` and stuffs them into a hashtable.
It tests a few error and edge cases.
This test is somewhat minimal.
A lot more could be done!

To test, simply `make test`.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.
