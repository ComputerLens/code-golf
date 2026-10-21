# Code Golf

Companion code for the Code Golf series on
[Computer Lens](https://youtube.com/@ComputerLens).

## Episode 1 — Primes below 100

Ten programs, each printing the 25 primes below 100 by trial
division. Scores are the complete source in bytes.

| Language   | File          | Bytes |
|------------|---------------|------:|
| Perl       | `primes.pl`   |    51 |
| Ruby       | `primes.rb`   |    58 |
| Python     | `primes.py`   |    64 |
| JavaScript | `primes.js`   |    68 |
| C          | `primes.c`    |   101 |
| C++        | `primes.cpp`  |   104 |
| Prolog     | `primes.pro`  |   105 |
| Go         | `primes.go`   |   108 |
| Scheme     | `primes.scm`  |   121 |
| Java       | `Primes.java` |   131 |

Four land at 68 bytes or below, six at 101 or above, and nothing
in between.

Check the counts with `wc -c ep01/*`.

These are ten particular implementations, not a ranking of
languages. Improvements welcome.

## Episode 2 — The 47-Byte Prime Test

We asked an LLM to shorten the 64-byte Python program from Episode 1.
The resulting 47-byte version prints the correct primes below 100, but
uses a base-two Fermat test instead of trial division.

Changing only the upper bound to 1000 adds one byte to each program
and exposes three false positives in the shorter version.

| File | Bytes | Method | Numbers printed |
|------|------:|--------|----------------:|
| [`trial100.py`](ep02/trial100.py) | 64 | Trial division, below 100 | 25 |
| [`short100.py`](ep02/short100.py) | 47 | Base-two Fermat test, below 100 | 25 |
| [`trial1000.py`](ep02/trial1000.py) | 65 | Trial division, below 1000 | 168 |
| [`short1000.py`](ep02/short1000.py) | 48 | Base-two Fermat test, below 1000 | 171 |

### Run the programs

Python 3 is required. Run these commands from the repository root:

```bash
python3 ep02/trial100.py
python3 ep02/short100.py
python3 ep02/trial1000.py
python3 ep02/short1000.py
```

Check the source sizes and the number of printed values:

```bash
wc -c ep02/*.py
python3 ep02/trial1000.py | wc -w
python3 ep02/short1000.py | wc -w
```

The byte counts match the versions used in the video, with no final
newline in any of the four Python files. An editor that adds a final
newline will increase the affected file's count by one byte.

### Find the extra numbers

In Bash, compare the outputs with one number per line:

```bash
comm -13 \
  <(python3 ep02/trial1000.py | tr ' ' '\n' | sort) \
  <(python3 ep02/short1000.py | tr ' ' '\n' | sort)
```

Expected output:

```text
341
561
645
```

`comm -13` keeps only lines present in the second input and absent from
the first. Use ordinary `sort` here, because `comm` compares text order.

All three extra numbers are composite:

- 341 = 11 × 31
- 561 = 3 × 11 × 17
- 645 = 3 × 5 × 43

### Why the shortcut fails

For every odd prime `n`, Fermat's little theorem guarantees that
`2**n % n == 2`. Passing this test does not prove that `n` is prime:
some composites pass too. The examples above are Fermat pseudoprimes
to base two. The shorter programs print 2 separately.

The shortcut is correct for the original below-100 task. It is not a
general prime generator, and it changes the algorithm required by
Episode 1's comparison. These files preserve the demonstration from
the video; the shorter versions are intentionally included to show
the limits of the test.

## Episode 3 — Printing Playing-Card Suits

Three code-golf programs draw playing-card suit shapes as terminal art,
using C, Python, and Pyth. The challenge is to produce recognizable
suits with compact source code; Pyth and Python are different languages.

| Language | Source |
|----------|--------|
| C        | [`suits.c`](ep03/suits.c) |
| Python   | [`suits.py`](ep03/suits.py) |
| Pyth     | [`suits.pyth`](ep03/suits.pyth) |

### Run the programs

From the repository root, compile the C program with GCC and run it:

```bash
gcc -w ep03/suits.c -o /tmp/codegolf-suits
/tmp/codegolf-suits
```

Run the Python version with Python 3:

```bash
python3 ep03/suits.py
```

Pyth needs its **own interpreter**. If the Pyth interpreter is installed
at `/home/pyth/pyth.py`, as in the recording environment, run:

```bash
python3 /home/pyth/pyth.py ep03/suits.pyth
```

Measure the exact source size of each file with:

```bash
wc -c ep03/suits.c ep03/suits.py ep03/suits.pyth
```

Byte counts depend on the exact saved files, including any final newline.
The C executable's size is not its code-golf score.

See [Episode 3 notes and setup](ep03/README.md) for details.
