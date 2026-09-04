# Simple Line Editor — Help

A command-line line editor written in C. Type a command at the `>` prompt and press Enter.

## Commands

### Insert a line
i <line#> <text>
Inserts `<text>` at the given line number, shifting existing lines down.

**Example:**
i 1 hello world
Inserts "hello world" as line 1.

### Delete a line
d <line#>
Removes the line at the given number, shifting lines below it up.

**Example:**
d 1
Deletes line 1.

### Display the document
p
Prints every current line with its line number.

**Example:**
p
1: hello world
2: this is line two

### Save to file
w <filename>
Writes the current document to a `.txt` file.

**Example:**
w test.txt
Saves the document as `test.txt`.

### Load from file
r <filename>
Reads a `.txt` file into memory, replacing the current document.

**Example:**
r test.txt
Loads `test.txt` back into the editor.

### Quit
Loads `test.txt` back into the editor.

q
Exits the editor.

## Notes
- Line numbers start at 1, not 0.
- Invalid line numbers (too high, too low, or an empty document) print an error message instead of crashing.
