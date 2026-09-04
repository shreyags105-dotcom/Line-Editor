# Simple Line Editor (C)

A command-line line editor built for the Portfolio Building Studio Course coding competition (3rd Semester).

## Team
- Riya Shelke
- Shreya

## Features Implemented
- Insert a line (`i`)
- Delete a line (`d`)
- Display the document (`p`)
- Save to file (`w`) — bonus
- Load from file (`r`) — bonus

## Data Structure
The document is stored as an array of `char*` (`lines[]`), with a `line_count` tracking how many lines currently exist. This was chosen over a linked list because insert/delete are simpler to implement correctly under time pressure, and display is a straightforward loop over a contiguous array — the O(n) shifting cost on insert/delete is negligible for the small documents this editor is designed for.

## How to Compile
Requires `gcc` (MinGW-w64 on Windows).
gcc editor_core.c editor_main.c -o editor.exe

## How to Run
./editor.exe
Then type commands at the `>` prompt. See `HELP.md` for the full command list and examples.
