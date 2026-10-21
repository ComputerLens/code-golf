# Episode 3 — Printing Playing-Card Suits

Companion programs for Episode 3 of the [Computer Lens Code Golf series](https://youtube.com/@ComputerLens).

This episode explores the same visual challenge in **C**, **Python**,
and **Pyth**: drawing playing-card suit shapes as ASCII art in a terminal.
It compares compact programming techniques across three languages.

## Files

| Language | File | How it runs |
|----------|------|-------------|
| C | [`suits.c`](suits.c) | Compile with GCC, then run the executable |
| Python | [`suits.py`](suits.py) | Run with Python 3 |
| Pyth | [`suits.pyth`](suits.pyth) | Run with the Pyth interpreter |

The diagrams are made with text characters, rather than displaying
Unicode playing-card symbols or graphical images. Output appearance can
depend on the terminal's monospace font and whitespace handling.

## Requirements

- GCC (to compile the C program)
- Python 3 (to run Python and the Pyth interpreter)
- The [Pyth interpreter](https://github.com/isaacg1/pyth) (to run the Pyth file)

## Running the programs

Run these commands from the **repository root** (the directory containing
`ep01`, `ep02`, and `ep03`).

### C

```bash
gcc -w ep03/suits.c -o /tmp/codegolf-suits
/tmp/codegolf-suits
```

The `-w` option suppresses compiler warnings; it does not fix
compilation errors or change the source file. The executable is stored
outside the repository so that it is not accidentally committed.

### Python

```bash
python3 ep03/suits.py
```

### Pyth

**Pyth is a separate language from Python.** Do not try to run a Pyth
source file using `python3 ep03/suits.pyth`.

If the interpreter is installed at `/home/pyth/pyth.py`, run:

```bash
python3 /home/pyth/pyth.py ep03/suits.pyth
```

If you need to install the interpreter, clone its source and adjust the
path in the command above:

```bash
git clone https://github.com/isaacg1/pyth.git ~/pyth
python3 ~/pyth/pyth.py ep03/suits.pyth
```

You can check that the interpreter starts successfully with:

```bash
python3 /home/pyth/pyth.py -c '+1 1'
```

That test should print `2`.

## Counting bytes

From the repository root:

```bash
wc -c ep03/suits.c ep03/suits.py ep03/suits.pyth
```

`wc -c` counts **bytes**, including whitespace and any final newline.
Count the source files, not the compiled C executable. The sizes should
be checked against the final programs used in the video, as even a single
extra newline changes the score.

## Notes

The programs illustrate code golf, not recommended production coding
style. Shorter source does not necessarily mean a faster, clearer, or
more portable program. The three languages may take different approaches
to the same visual task.

[Back to the complete Code Golf series](../README.md)
