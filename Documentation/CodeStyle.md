# leickh*able* Code Style Statement

## General Style

Code block indents are done using four spaces. Tabs aren't supposed to
be used in the leick*hable* coding style.

Pointer asterisks  are written  next to the  variable  identifier, not
next  to the  type's  name.  When a  function  returns a  pointer, the
asterisk is  free-standing; surrounded by a space to the  left and the
right side.

When splitting  function arguments into multiple lines, the additional
lines  are   indented  with  four  spaces,  except   for  the  closing
parenthesis, which  does  not have  any indents  past  the base level.
When defining a function, the parameters occupy one line each as well.
The  opening curly  brace goes  into  the  same  line as  the  closing
parenthesis of the parameter list.

### Examples

Parameter indentation:

```C
int main(
    int argc,
    char **argv
) {
    return 0;
}
```

Pointer Asterisk placement:

```C
char * repeat_string(
    char *string
    int32_t repetitions
) {
    // ...
}
```

## Naming

The leickh*able* naming scheme should  be followed with few exceptions
can be condensed into the following six rules:

1. Functions and variables should be named in:  
    `snake_case`
2. Structures, enumerations and typedefs should be named in:  
    `PascalCase`
3. Constants, macros, defines and enum values should be named in:  
    `UPPER_SNAKE_CASE`
4. Rather short words (with less than 6 characters.) should be written
    out completely and not abbreviated.
5. Function names shouldn't be complete sentences.
6. Function names should be imperative (do_xyz, create_abc), beginning
    with the prefix, directly  followed by the verb of the action they
    are supposed to perform.

### Allocator Naming

The naming scheme for allocation-/initialization - functions has a few
special cases:

When the function  allocates memory on the heap  using `malloc()` or a
similar, rather performance-heavy  approach, the used *action verb* is
supposed to be `new`  for creation and `free` for  deletion. It should
be possible to assumed that those functions also initialize the data.

For a function that configures a  structure the pointer to which it is
given, the creation  function should be use the  *action verb* `init`,
with the deletion function using `destruct`.

Pool allocators should use the word `pool` for allocating a structure
while using `unpool` to return the memory to the pool.

### Prefixes

A prefix should use  at most five characters, with  two or three being
preferred but  using only  one being  discouraged. For  functions, the
prefix should be lowercase, followed by an underscore. The same should
be done for constants, only with uppercase characters. For structures,
enumerations and typedefs, the first character of the prefix should be
uppercase, without a separating underscore. Variables should only have
prefixes if they  are global, and then, they follow  the naming scheme
that functions do.

### Wording

Some words shouldn't be used in names  as they are simply meaningless.
The following list contains words that are either implied by something
else or that are informal and shouldn't be used because of that.

- State, Context, etc..  
  To quote Andrew Kelley (from Zig): "Everything is a value, all types
  are data everything is context, all logic  manages state. Nothing is
  communicated by using a word that applies to all types.".  
  Words that aren't necessary shouldn't be used. This may be difficult
  to follow for some time, but it makes sense and should be upheld.


The wording in  function names should  be rather formal,  but function
names still  shouldn't  use "exotic"  words  that an average developer
must look up.  Exceptions are words that are  in the project's nature;
physics engines will  have different specialized words  than a command
line application

A selection of  words that  should be avoided  to avoid  potential for
misunderstandings  and comical  statements  is listed here (with  some
alternatives):
- `parent` (use `super` or `super_structure`)
- `child` (use `inner`, `sub` or `sub_structure`)
- `kill` (use `destruct` or `vanish`)

This is  obviously a non-exhaustive  list; it  serves  as a  means  to
demonstrate the concept.

## Comments

Multi line comments are only used  to comment out pieces of code. They
aren't  used for  commenting functionality; for that,  multiple single
line comments are  used. After the comment starting  characters, there
must be a space for a cleaner look.

Documentation for  functions and structures is written  in the Doxygen
style, starting the comments  with three  slashes and using at-symbols
for the keywords.

