# Tic-Tac-Toe_AI 
![download](https://github.com/Ahsan-Ra2a/Tic-Tac-Toe_AI/assets/144048378/54a831bc-f437-4c91-aa47-f8b69ba017e4)

### Team Members
<table>
<tr>
	<th>Name</th>
	<th>Seat Number</th>
</tr>
<tr>
	<td> Ahsan</td>
	<td> 23k-0884</td>
</tr>
<tr>
	<td> Urooj Baloch </td>
	<td> 23k-0071 </td>
</tr>
  <tr>
	<td> Mukesh </td>
	<td> 23k-0903 </td>
</tr>
</table>

### OBJECTIVES
Our project is to develop a Tic Tac Toe game using C language. It mainly consists of developing and implementing a AI that plays Tic Tac Toe against another player.
In order to understand what Tic Tac Toe game is and how to play the game, below is the description.

### DESCRIPTION
Tic Tac Toe is a two-player game (one of them being played by AI or other player). In this game, there is a board with 3 x 3 squares.

The two players take turns putting marks on a 3x3 board. The goal of Tic Tac Toe game is to be one of the players to get three same symbols in a row - horizontally, vertically or diagonally on a 3 x 3 grid. The player who first gets 3 of his/her symbols (marks) in a row - vertically, horizontally, or diagonally wins the game, and the other loses the game. The game can be played by two players. There are two options for players: 

(a) Player VS Player
(b) Player VS AI

### GAME RULES
A player can choose between two symbols with his opponent, usual game uses “X” and “O”.

Player 1 and 2 take turns making moves with Player 1 playing mark “X” and Player 2 playing mark “O” or vice versa

A player marks any of the 3x3 squares with his mark (“X” or “O”) and their aim is to create a straight line horizontally, vertically or diagonally with two intensions:

a. One of the players gets three of his/her marks in a row (vertically, horizontally, or diagonally) i.e. that player wins the game.

b. If no one can create a straight line with their own mark and all the positions on the board are occupied, then the game ends in a tie.

Got it! Let's adjust the README accordingly:

# AI Tic Tac Toe

This is a simple Tic Tac Toe game implemented in C, featuring three difficulty modes: Easy, Medium, and Hard, each with its own unique gameplay experience.

## AI Functionality
This is a simple Tic Tac Toe game implemented in C, featuring three difficulty modes: Easy, Medium, and Hard, each with its own unique gameplay experience.

### Easy Mode
In Easy mode, the AI generates random moves, making it a simple opponent for players to practice against.

### Medium Mode
Medium mode allows players to block the AI from winning or force the AI to block their winning moves. If neither player is close to winning, the AI reverts to Easy mode.

### Hard Mode
Hard mode employs an advanced minimax algorithm to determine the best possible move for the AI, making it a formidable opponent even for experienced players.

## How to Play
1. Clone the repository to your local machine.
2. Navigate to the directory where the repository was cloned.
3. Compile the `main.c` file using a C compiler (e.g., gcc).
4. Run the compiled executable.
5. Select the desired difficulty mode when prompted.
6. Follow the on-screen instructions to play the game.

## Example Usage
```
git clone https://github.com/Ahsan-Ra2a/Tic-Tac-Toe_AI.git
gcc tic-tac-toe main.c -o tic-tac-toe.c
./tic-tac-toe
```
