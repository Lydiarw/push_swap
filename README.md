*This project has been created as part of the 42 curriculum by si-wong.*

# push_swap

## Description

The **push_swap** project sorts a stack of integers using a limited set of operations and two stacks (A and B). The goal is to sort the numbers in ascending order with the minimum number of operations.

I've implemented the **Turk Sort algorithm**, an efficient strategy that reduces the number of operations by calculating optimal moves between stacks and minimizing total cost per operation.

The project emphasizes:
- Algorithm optimization
- Complexity reduction
- Low-level data manipulation using stacks
- Writing clean and efficient C code

### Algorithm (Turk Sort)

1. Pushes 2 nodes from stack A to B as a starting point
2. Calculate the cost for each node to move from stack A to B
    - Moving the node to the top of stack A
    - Find a target node in stack B
    - Moving the target node to the top of stack B
3. The node with the lowest cost will be selected to move
4. Move all nodes in stack A to B and leave the last 3 nodes
5. Sort the 3 nodes in stack A
6. Apply the same logic as above to move the nodes from stack B to A
7. Rotate the smaller numbers to the top in stack A

---

## Instructions

### Compilation
To compile the project, run:

```bash
make
```

The above will generate an executable:
./push_swap

Go ahead and input the stack of integers together with the executable either with or without the double quotation marks:
```bash
./push_swap 5 8 3 0 8 6 2
./push_swap "5 8 3 0 8 6 2"
```

---

## Resources
- [push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)] (https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s)
- [Push_Swap Turk algorithm explained in 6 steps] (https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push Swap — A journey to find most efficient sorting algorithm] (https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [push_swap TUTORIAL!] (https://www.youtube.com/watch?v=wRvipSG4Mmk&t=574s)