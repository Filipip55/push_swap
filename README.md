*This project has been created as part of the 42 curriculum by icoman.*

# push_swap


`push_swap` is a sorting algorithm project: given a list of integers passed as arguments, the program must output the minimal sequence of operations to sort stack A in ascending order, using a second auxiliary stack B.

---

## Operations

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap the top two elements of stack A / B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top element of B onto A / top of A onto B |
| `ra` / `rb` | Rotate A / B upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate A / B (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Algorithm — Turkish sort

For inputs of 1 or 2 elements the program applies a simple swap if needed. For 3 elements, `sort_three` handles all cases with at most 2 moves.

For larger inputs, the program uses the cost-based algorithm known as the **Turkish sort**:

### Phase 1 — push A to B

Two elements are pushed to B unconditionally to give the cost calculator something to work with. Then, for each remaining node in A:

1. `update_index` assigns each node its position (index) and marks it `above_median` if it sits in the upper half of its stack.
2. `set_target_a` finds, for each node in A, the best target position in B: the largest value in B that is still smaller than the node. If no such value exists, the target is the maximum of B.
3. `set_cost_a` computes the total number of rotations needed to bring both the node and its target to the top of their respective stacks. Nodes above the median cost `index` rotations via `ra`; nodes below cost `len - index` via `rra`. The same logic applies to the target in B.
4. `set_cheapest` marks the node with the lowest total cost.
5. `move_a_to_b` moves that node: if both are above median, `rr` is used simultaneously (`keep_rotating`); if both are below, `rrr` (`reverse_keep_rotating`); otherwise they are rotated independently. Then `pb` places the node on top of B.

This continues until only 3 elements remain in A, which are sorted with `sort_three`.

### Phase 2 — push B back to A

For each node in B, `set_target_b` finds the smallest value in A that is still greater than the node. If none exists, the target is the minimum of A. The node in A is then rotated to the top with `prep_for_push` and `pa` transfers the B node.

### Phase 3 — final alignment

After all nodes are back in A, `move_min_on_top` rotates A until the minimum value is at the top, completing the sort.

---

## Checker

The `checker` binary reads a sequence of operations from stdin, applies them to the initial stack, and prints `OK` if the result is sorted and stack B is empty, or `KO` otherwise. It uses `get_next_line` to read one instruction per line.

```sh
ARG="3 2 1 5 4"; ./push_swap $ARG | ./checker $ARG
```

---

## Structure

```
push_swap/
├── main.c               # Entry point
├── sorting.c            # sort_three, sort_stacks, move_min_on_top
├── sorting_utils.c      # update_index, set_cheapest, prep_for_push
├── stack_a_utils.c      # init_stack_a, prepare_nodes_a, set_target_a, set_cost_a, move_a_to_b
├── stack_b_utils.c      # prepare_nodes_b, set_target_b, move_b_to_a, add_node_back
├── stack_utils.c        # is_stack_sorted, stack_len, get_cheapest, get_min_node, get_max_node
├── error_management.c   # check_sintax, is_duplicate, free_stack, free_errors
├── swap.c               # sa, sb, ss
├── push.c               # pa, pb
├── rotate.c             # ra, rb, rr, keep_rotating
├── reverse_rotate.c     # rra, rrb, rrr, reverse_keep_rotating
├── checker.c            # checker entry point and instruction dispatcher
├── get_next_line.c      # line-by-line stdin reader
├── push_swap.h
├── checker.h
├── get_next_line.h
└── Makefile
```

---

## AI usage
 
I used AI for the more tedious aspects towards the end of the project,	
for example debugging memory leaks and unit testing.
It was great for helping me visualize the algorithm step by step so i could write pseudo code
 
---

## Build instructions

```sh
make          # builds push_swap
make bonus    # builds checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + make
```

---

## Resources
 
- [C Function Pointers](https://www.w3schools.com/c/c_functions_pointers.php) — W3Schools
- [Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/) — GeeksforGeeks
- [Push swap — the least amount of moves with two stacks](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — articolo brillante e salvavita
- [Push swap visualizer](https://www.youtube.com/watch?v=4dMsuxfqufg) — YouTube
- [Push swap explained](https://youtu.be/wRvipSG4Mmk?si=CTGF7kZAiDT4gtO_) — YouTube
 
---