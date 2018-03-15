#Using LLBD(Having issues with GDB for Mac despite being installed, took time to switch/figure out the problem)
I first compiled the program then ran the LLBD.
##lldb a.out
I did llbd a.out

## (lldb) r
I ran the llbd with r.

##(lldb) breakpoint set --name main
Did a breakpoint at main
Problem Part 1: 
break line 20: i should be less than capacity not more

##(lldb) next
I used this to get to the next section of the code
Problem Part 2
break line 34: min is set to 0 but the array cant be less than 0. It should be set to the 1st element of the array.

Problem 3: Capacity variable should be i < capacity - 1 because it's going out of range 


