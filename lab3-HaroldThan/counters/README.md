# CS50 Lab 3
## CS50 Summer 2021

### counters

A `counters` is an unordered collection of _(key-count)pairs_.
The `counters` starts empty, grows as the caller adds one _(key-count)pair_ at a time.
It could be empty, or could contain hundreds of _(key-count)pair_.
_count_ is identified by a _key_ , so the _get_ function can return _count_ from the `counters` by looking through every _(key-count)pair_.

### Usage

The *counters* module, defined in `counters.h` and implemented in `counters.c`, and exports the following functions:

```c
counters_t *counters_new(void);
void counters_add(counters_t *counters, void *count);
int counters_get(counters_t *ctrs, const int key);
bool counters_set(counters_t *ctrs, const int key, int count);
void counters_print(counters_t *ctrs, FILE *fp){
void counters_iterate(counters_t *ctrs, void *arg, void (*countfunc)(void *arg, const int key, int count));
void counters_delete(counters_t *ctrs){
```

### Implementation

We implement this counters as a linked list.
The *counters* itself is represented as a `struct counters` containing a pointer to the head of the list; the head pointer is NULL when the counters is empty.

Each node in the list is a `struct counterspair`, a type defined internally to the module.
Each counterspair includes  `char key`, `void *count` and a pointer to the next counterspair on the list.

To insert a new count in the counters we create a new counterspair to hold the `count`, and insert it at the head of the list.

To find an count from the counters we iterate over every node in the list and return the specified count.
We return NULL if any of the inputs for the function is NULL

The `counters_print` method prints a the enclosure counters symbols `{}` around the list, and `,` between counts, and print out every counterspair in between

The `counters_iterate` method calls the `itemfunc` function on each counterspair by scanning the linked list.

The `counters_delete` freeing each counterspair as as it proceeds.
It ends by freeing the `struct counters`.

### Assumptions

No assumptions beyond those that are clear from the spec.

The `count` inserted cannot be <=0

### Files

* `Makefile` - compilation procedure
* `counters.h` - the interface
* `counters.c` - the implementation
* `counterstest.c` - unit test driver
* `test.number` - test data
* `TESTING.md` - testing results results

### Compilation

To compile, simply `make`.

### Testing

The `counterstest.c` program reads lines from stdin and stuffs them into a counters, then pulls them back out.
It tests a few error and edge cases.
This test is somewhat minimal.
A lot more could be done!

To test, simply `make test`.

Try testing with `MEMTEST` by editing Makefile to turn on that flag and then `make test`.

To test with valgrind, `make valgrind`.
