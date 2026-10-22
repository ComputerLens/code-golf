# Episode 4 — Brainfuck: `Computer Lens` in 77 bytes

Each program prints exactly `Computer Lens`: 13 bytes, no newline.

| File | Bytes | How it works |
|---|---:|---|
| `loop.bf` | 110 | A loop runs 11 times and builds 33, 66, 110 and 99 |
| `wrap.bf` | 91 | A counter starts at 9 and loses 7 per pass; with wraparound it reaches 0 after 111 passes |
| `computer_lens.bf` | 77 | A 28-byte setup loop found with BF-Crunch, then 49 bytes of printing |

## Rules

- Print exactly `Computer Lens`, with no newline at the end.
- Score: bytes in the source file, as `wc -c` counts them. The files end without a newline.
- 30,000 cells of 8 bits, all starting at 0. `+` and `-` wrap around: 255 + 1 = 0.
- The pointer never moves left of cell 0.

`loop.bf` never needs wraparound; `wrap.bf` and `computer_lens.bf` do.

## Run

```bash
beef computer_lens.bf; echo
beef computer_lens.bf | od -c
wc -c *.bf
```

## The wraparound loop (91 bytes)

`+++++++++[>---->+>+>------>-->+++<<<<<<-------]`

The counter starts at 9 and loses 7 per pass. It is exactly 0 when
7 × passes ≡ 9 (mod 256), which first happens after 111 passes:
7 × 111 = 777 = 3 × 256 + 9. Each other cell ends up holding its step
× 111, modulo 256.

| Cell | Step | Value | Char | Prints |
|---:|---:|---:|:---:|---|
| 1 | −4 | 68 | `D` | C |
| 2 | +1 | 111 | `o` | o, m, n |
| 3 | +1 | 111 | `o` | p, u, t, r, s |
| 4 | −6 | 102 | `f` | e, e |
| 5 | −2 | 34 | `"` | space |
| 6 | +3 | 77 | `M` | L |

## The 77-byte program

`-[+[<->->->>+>>>-<<<<<<]>++]`

At each cell, the outer loop adds 1. The inner loop then empties the
cell, subtracting its value from both neighbours, adding it three cells
to the right and subtracting it six cells to the right. The outer loop
then moves right and adds 2. It stops at cell 488 after 1,204,690
commands. Cells 480 and 481 hold a space and an `L` exactly; cells 482,
483, 484 and 490 hold `q`, `f`, `p` and `D`, each one step from the
`p`, `e`, `o` and `C` we need. The first pass only zeroes cell 0, so the
program never touches a cell left of it.

Found with [BF-Crunch](https://github.com/primo-ppcg/BF-Crunch) by primo.

## References

- Brainfuck reference by Daniel B. Cristofani: https://brainfuck.org/brainfuck.html
- Brainfuck on the Esolang wiki: https://esolangs.org/wiki/Brainfuck
