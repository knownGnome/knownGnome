# Matrix Multiplication Performance Programming Challenge

## Overview
Write a program which takes in two `n x n` matrices and calculates their product. Optimize your program for performance (i.e. runtime). Submit your program as either a python file or a Linux executable. In addition, submit a writeup documenting your matrix multiplication algorithm and (more importantly) your performance optimizations.

## Command Line Format

You will use the `checker.py` script to evaluate your program. Your program should be either a python3 script or a Linux executable. Your program will be executed by `checker.py` in the following format:

```bash
$: <program-name> <matrix-width>
```

### Example:

```bash
$: my_c_program 32

$: python3 my_python_program.py 64
```

## Input
`a.bin`, `b.bin`

Files `a.bin` and `b.bin` each contain a buffer of `n x n` 32-bit signed integers. These files should be read into your program as the matrices to multiply.

For example, the following matrix would be represented as such in the ```.bin``` files:

| 1 | 2 |
| - | - |
| 3 | 4 |

```bash
\x01\x00\x00\x00\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00
```

## Output
`c.bin`

Calculate the matrix `C = A * B` and output `C` to the file `c.bin` in the same format as the input files.

## Scoring
Your program will be evaluated based on runtime to calculate the matrix `C`. Programs that are not correct will not be scored. 

In your writeup, you will use the `benchmark` binary file and a size 2048x2048 matrix as a benchmark for measuring your runtime. Report your performance improvements relative to this benchmark (ex: 200% / 100% / 50% / 5% of benchmark runtime).

## Example Runtime

The `benchmark` file was run on the following system with the following results:

Test Environment:
 * Ubuntu 20.04.1 LTS
 * Intel® Core™ i5-8400H CPU @ 2.50GHz × 4
 * 8Gb Physical Memory
 * Runtime(2048x2048): 212.249455s

```bash
$ python3 checker.py benchmark
Generating random 2048x2048 matrixes A and B...
Running program:
>./benchmark 2048
Run time: 212.249455
```

