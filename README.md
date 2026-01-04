# push_swap

*This project has been created as part of the 42 curriculum by achahi.*

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The project involves two stacks (stack A and stack B) and a specific set of allowed operations.

The goal is to sort stack A in ascending order using only these operations:
- `sa`, `sb`, `ss`: swap the first two elements
- `pa`, `pb`: push an element from one stack to another
- `ra`, `rb`, `rr`: rotate the stack upward
- `rra`, `rrb`, `rrr`: rotate the stack downward

This project teaches algorithm optimization, complexity analysis, and efficient problem-solving strategies.

### Algorithm Overview: "Modern Times (turk based)"

The implemented algorithm uses a hybrid approach that combines the Turk algorithm principles with optimization techniques:

1. **Initial Setup**: Push the first two elements to stack B
2. **Cost Calculation Phase**: For each remaining element in stack A (except the last 3):
   - Calculate the cost to move it to its optimal position in stack B
   - Consider both rotation costs in stack A and stack B
   - Find synergies when both stacks need to rotate in the same direction
3. **Synergy Optimization**: Use dual operations (`rr` or `rrr`) when both stacks rotate in the same direction, reducing the total move count
4. **Iterative Pushing**: Move the cheapest element to stack B and repeat until only 3 elements remain in stack A
5. **Final Sorting**:
   - Sort the remaining 3 elements in stack A
   - Position stack B so the maximum value is on top
   - Push all elements back to stack A in the correct order using the "zipper" technique

This approach minimizes the number of operations by always choosing the least costly move and leveraging simultaneous rotations when beneficial.

## Instructions

### Compilation

```bash
make
```

This will generate the `push_swap` executable.

### Execution

```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 3 2 5 1 4
```

The program will output the sequence of operations needed to sort the stack.

### Testing

You can verify the output using the provided checker (if available):
```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

Or count the number of operations:
```bash
./push_swap 3 2 5 1 4 | wc -l
```

### Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Rebuild everything
```

## Algorithm Breakdown

### Key Functions

**`modern_times()`**: The main sorting function that orchestrates the entire algorithm.

**`synergy()`**: Optimizes moves by performing simultaneous rotations on both stacks when they need to rotate in the same direction (using `rr` or `rrr`).

**`move_stack()`**: Executes the calculated rotations to position elements optimally before pushing.

**`order_stacks()`**: Prepares stacks for the final merge by positioning the maximum of stack B on top and sorting the last 3 elements in stack A.

**`zipper()`**: Merges stack B back into stack A in sorted order by strategically positioning elements.

### Cost Calculation

The algorithm calculates two costs for each element:
- `steps_a`: Number of rotations needed in stack A to bring the element to the top
- `steps_b`: Number of rotations needed in stack B to position it correctly

The total cost considers whether these rotations can be performed simultaneously (synergy), making the actual cost `max(|steps_a|, |steps_b|)` instead of `|steps_a| + |steps_b|`.

### Complexity

- **Time Complexity**: O(n²) in the worst case, but optimized through cost analysis
- **Space Complexity**: O(n) for the two stacks
- **Move Count**: Typically achieves good performance (well under 700 operations for 100 numbers, under 5500 for 500 numbers)

## Resources

### Documentation and Tutorials
- [Push_swap Tutorial by Oceano](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Overview of common approaches
- [Turk Algorithm Explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Cost-based sorting strategy
- [42 Docs - Push_swap](https://harm-smits.github.io/42docs/projects/push_swap) - Project requirements and testing strategies
- [Visualizer Tool](https://github.com/o-reo/push_swap_visualizer) - Helpful for debugging and understanding the algorithm

### AI Usage

AI was used in the following ways during this project:

- **Algorithm Research**: Used Claude to understand and compare different sorting strategies (Turk algorithm, chunk-based approaches, greedy algorithms)
- **Optimization Ideas**: Discussed synergy optimization techniques and cost calculation methods
- **Debugging Assistance**: Help identifying edge cases and logical errors in the implementation
- **README Creation**: Generated this README.md file based on the algorithm code and project requirements

The core algorithm logic, implementation, and optimization decisions were developed through manual coding and testing, with AI serving as a research and documentation assistant.

## Features

- Efficient sorting algorithm optimized for minimizing operations
- Synergy detection for simultaneous rotations
- Cost-based decision making for optimal element selection
- Handles edge cases (duplicates detection, invalid input)
- Special optimization for small stacks (3 elements)

## Technical Choices

- **Cost-based approach**: Rather than using chunks or median-based splitting, this implementation calculates the exact cost for each possible move and always chooses the cheapest option
- **Synergy optimization**: Leverages `rr` and `rrr` operations to reduce move count when both stacks need rotation
- **Zipper merging**: Final merge strategy that maintains sorted order while minimizing operations
- **Dynamic recalculation**: Recalculates costs after each move to adapt to the changing stack configuration