#!/usr/bin/python3
import sys, random, time, os, struct, numpy

#### Check parameters
if (len(sys.argv) != 3 and len(sys.argv) != 2):
    print("Usage: >python3 checker.py <filename> [<matrix-size>]")
    exit()

try:
    n = int(sys.argv[2]) if len(sys.argv) == 3 else 2048
except ValueError:
    print("Invalid <matrix-size> argument")
    exit()


#### Generate matrixes
print("Generating random " + str(n) + "x" + str(n) + " matrixes A and B...")

A = numpy.random.randint(20, size=(n, n))
B = numpy.random.randint(20, size=(n, n))
f_a = open("a.bin", "wb")
f_b = open("b.bin", "wb")
for i in range(n):
    for j in range(n):
        f_a.write(struct.pack("i", A[i][j]))
        f_b.write(struct.pack("i", B[i][j]))
f_a.close()
f_b.close()


#### Prepare program call
command = "./" + sys.argv[1] + " " + str(n)
if ".py" in command:
    command = "python3 " + command

print("Running program:")
print(">" + command)


#### Time program execution
start = time.time()

if os.system(command) != 0:
    print("[!] The program crashed")
    exit()

end = time.time()


#### Minimal check of output matrix
first = 0
for i in range(n):
    first += A[0][i] * B[i][0]
try:
    with open("c.bin", "rb") as f_c:
        c_first = struct.unpack("i", f_c.read(4))
        if first != c_first[0]:
            print("[!] Incorrect matrix multiplication")
except FileNotFoundError:
    print("[!] No output file 'c.bin' found")


#### Give runtime
print("Run time: %0.6f" % (end-start))


#### Cleanup
os.system("rm a.bin b.bin c.bin")
