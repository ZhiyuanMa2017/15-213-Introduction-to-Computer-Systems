This is an x86-64 bomb for self-study students.

## phase_1:

**Border relations with Canada have never been better.**

## phase_2:

**1 2 4 8 16 32**

## phase_3:

**2 707**

## phase_4:

**1/3/7 0**

See Solution.java for details.
1

## phase_5:

**ionefg**

"aduiersnfotvbylSo you think you can stop the bomb with ctrl-c, do you?"

If your input is abcdef, the output is aduier.  
The above string is the key-value map to translate your input.  
The target is "flyers", so the input should be "ionefg".

## phase_6:

**4 3 2 1 6 5**

If input is 1 2 3 4 5 6, then the nodes' order is 6 5 4 3 2 1.


|       | address  | value      | decimal value |
| :---: | :------: | ---------- | :-----------: |
| node6 | 0x603320 | 0x000001bb |      443      |
| node5 | 0x603310 | 0x000001dd |      477      |
| node4 | 0x603300 | 0x000002b3 |      691      |
| node3 | 0x6032f0 | 0x0000039c |      924      |
| node2 | 0x6032e0 | 0x000000a8 |      168      |
| node1 | 0x6032d0 | 0x0000014c |      332      |

Nodes' order should be 3 4 5 6 1 2, so input should be 4 3 2 1 6 5.
