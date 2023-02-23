# Cache Lab: Understanding Cache Memories

## Part A:Writing a Cache Simulator
address = tag + set index + block offset  
S = 1 << s  
B = 1 << b  
E   
Set_Index = (address >> b) & (S - 1)  
Tag = address >> (s + b)  
