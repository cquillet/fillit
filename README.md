# fillit


## Abstract
  This project calcultates the smallest square which can be filled with given [tetrominos](https://en.wikipedia.org/wiki/Tetromino). It uses the [Knuth](https://cs.stanford.edu/~knuth/)'s [Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X) and the [Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links) optimization.

## Requirements
  **You will need to download the [`libs`](https://github.com/cquillet/libs) project in the same directory you will clone `fillit` to run it!**

## Installation
  do `make` in the directory `fillit`

## Usage
   `fillit file`  
   where `file` is a mandatory argument that represents the list of tetrominos you want to pack in the smallest possible square.

### Input
  The input file is a text file. Each tetromino is written in 4 lines and 4 columns where `.` represents a blank and `#` represents a block of a the tetromino. Theremust be an empty line between each tetromino.  
  The 7 basic tetrominos are available :
  * I-tetromino (2 possible rotations)  
  	`####`  `.#..`  
  	`....`  `.#..`  
  	`....`  `.#..`  
  	`....`  `.#..`  
  * O-tetromino (1 possible rotation)  
    `....`  
    `....`  
    `..##`  
    `..##`  
   * T-tetromino (4 possible rotations)  
    `.#..`  `....`  `.#..`  `....`  
    `###.`  `#...`  `##..`  `....`  
    `....`  `##..`  `.#..`  `###.`  
    `....`  `#...`  `....`  `.#..`  
  * J-tetromino (4 possible rotations)  
    `....`  `....`  `.#..`  `.###`  
    `##..`  `....`  `.#..`  `...#`  
    `#...`  `#...`  `##..`  `....`  
    `#...`  `###.`  `....`  `....`  
  * L-tetromino (4 possible rotations)  
    `....`  `...#`  `.#..`  `....`  
    `.##.`  `.###`  `.#..`  `....`  
    `..#.`  `....`  `.##.`  `###.`  
    `..#.`  `....`  `....`  `#...`  
  * S-tetromino (2 possible rotations)  
    `....`  `..#.`  
    `.##.`  `..##`  
    `##..`  `...#`  
    `....`  `....`  
  * Z-tetromino (2 possible rotations)  
    `.##.`  `....`  
    `..##`  `..#.`  
    `....`  `.##.`  
    `....`  `.#..`  


  No matter where the tetromino is placed in the 4x4-blocks area, the program considers it as the same piece.  
  For example :
  >  `....`  `##..`  `....`  `..##`  
  >  `.##.`  `.#..`  `##..`  `...#`  
  >  `..#.`  `.#..`  `.#..`  `...#`  
  >  `..#.`  `....`  `.#..`  `....`  
  >  are seen as the same piece
  
  **The file must contains 26 tetrominos at most!**
  
### Output
  The program displays the smallest square filled with the given tetrominos.
  * 1st tetromino is written with `A`
  * 2nd tetromino is written with `B`
  * 3rd tetromino is written with `C`
  * 4th tetromino is written with `D`
  * and so on...
  
## Examples
  examples will be provided later
