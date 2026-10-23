# Episode 5 — Ook!

The challenge is to print `Computer Lens` in **Ook!**, an esoteric language
that encodes Brainfuck instructions as pairs of `Ook.` / `Ook?` / `Ook!` tokens.
The files contain the same **77 Brainfuck instructions**, represented in two languages:

| File | Bytes | Run with |
|---|---:|---|
| `computer_lens.ook` | 769 | `rob ook computer_lens.ook` |
| `computer_lens.bf` | 77 | `beef computer_lens.bf` |

Both programs output `Computer Lens` without a newline. These are byte counts
of the **source files**, not the interpreter or executable. The 77-byte
Brainfuck program is not claimed to be optimal.

## Run on Ubuntu

Install the interpreters if needed:

```bash
sudo apt install cargo beef
cargo install rob-vm
```

From the **`ep05` directory**, run:

```bash
rob ook computer_lens.ook
beef computer_lens.bf
wc -c computer_lens.ook computer_lens.bf
```

The byte-count command reports **769** and **77** bytes (846 total). The
Brainfuck program does not print a final newline, so to keep the terminal prompt
on a separate line during a demonstration, use:

```bash
beef computer_lens.bf; printf '\n'
```

For the complete series, see the [main Code Golf README](../README.md).
