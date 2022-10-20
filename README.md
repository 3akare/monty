

# Monty Interpreter

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:


# Installing and Using
- Must have git installed
```
sudo apt-get install git
```
- Clone the repo into a new directory
```
git clone https://github.com/3akare/monty.git
```
Complile with:
```
gcc @flags *.c -o monty
```
Run the interpreter on a file
```
./monty file.m
```

# Usage
## push `<int>`
Add an integer to the stack
```
push 1
push 2
push 3
```
## pall
Prints all the values on the stack and takes no value
```
push 1
push 2
push 3
pall
```
```
3
2
1
```
## pint
Prints the value at the top of the stack
```
push 1
pint
push 2
pint
push 3
pint
```
```
1
2
3
```
## pop
Removes the element at the top of the stack
```
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
```
```
3
2
1
2
1
1
```

## Other Opcodes
| Opcode         | Description | Usage|
| -------------- | -------------------------- | -------------------- |
| swap           | swaps the top two elements of the stack | `swap`
| add           | add the top two elements of the stack | `add`
| mul           | multiplies the top two elements of the stack | `mul`
| sub           | subtracts the top element from the element below it on the stack | `sub`
| div           | divides the second top element of the stack by the top element | `div`
| mod           | computes the rest of the division of the second top element of the stack by the top element of the stack | `mod`
| pchar          | prints the char at top of the stack | `pchar`
| pstr          | prints the string starting at the top of the stack | `pstr`
| stack         | sets the format of the data to a stack (LIFO). This is the default behavior of the program. | `stack`
| queue         | sets the format of the data to a queue (FIFO). | `queue`
| rotr          | Rotates the stack to the bottom | `rotr`
| rotl          | Rotates the stack to the top | `rotl`
| nop           | Does nothing | `nop`

# Authors
- [David Bakare](./https://github.com/3akare)
- [Ereek71](./https://github.com/Ereek71)

# Acknowledgments
This project was written as part of the curriculum for Holberton/ALX-SE program.
