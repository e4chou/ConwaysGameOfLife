```markdown
# Conway's Game of Life

Runs Conway's Game of Life. The program takes 2 integers x and y from standard input, followed by a mapping of an initial seed (with x times y 0/1 values). 


## Features

Command Line arguments:
- "-graphics" enables an Xming window display

Run-time commands:
- 		  'p' : prints the game board
- 't [int n]' : moves the game forwards 1 (or n, if specified) tick(s)
- 		  's' : runs the game forever (warning: can't be stopped)


## Installation

1. Copy repo
2. Run exec file ``conway``, e.g.
```bash
./conway -graphics
```


## Sample input

``101.in``
```
20 16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 1 1 0 1 1 0 0 0 0 0 0 0 0 1 1 0 1 1 0
0 1 1 0 1 0 0 1 1 1 1 1 1 0 0 1 0 1 1 0
0 0 0 0 1 0 1 0 1 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 1 0 1 0 1 0 0 0 0
0 1 1 0 1 0 0 1 1 1 1 1 1 0 0 1 0 1 1 0
0 1 1 0 1 1 0 0 0 0 0 0 0 0 1 1 0 1 1 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
p
t 5
```

See *.in files for more examples. Alternatively, use runSuite on suite.txt.


## Screenshots
![101 pattern](http://url/image.png)
![Gosper glider gun]()
