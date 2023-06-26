# Edit Distance Algorithm
By *Andrew Ocegueda* <br>
CS 141 Intermediate Data Structure's and Algorithms
## Requirements

An IDE that supports C++ programs

## How to run the code

Copy the source code to a C++ compatible IDE, then run the code. The program does not need any inputs, but changes can be made so that different words can be used or you can manually insert two words into the program rather than hard code it. (See Possible Altercation Section).
r
## What does this program do?

The program compares two strings and calculates the amount of edits needed to make the changes. E.g. we have two strings denote "X" and "Y", we want to edit the string from X to Y with the shortest amount of edits possible. The algorithm utilizes dynamic programming to find the minimal amount of edits needed to make the edit from X to Y. Once the user runs the program, the program tells the user which letters from X to keep (These "Keep" actions do not contribute to the edit distance cost) and which letters to insert from Y, delete in X or replace a letter in X from Y. <br><br>
The program will print out the 2d array that shows the optimal amount of edits at each position from the words X and Y. Once the edit distance is complete, the algorithm then starts where the optimal edit distnace, which is located at the botoom right most corner of the array. From there the program backtracks from the optimal answer to ```array[1][1]``` to find out which edits are the most optimal to change the word from X to Y in the fewest amount of steps needed. 
## Limitation

The program works best if all the characters in both strings are lowercase. As of now, the program differentiates uppercase and lowercase letters despite being the same letter. So when inserting two words into the program, insert lowercase letters for every character in the string. 

## Example output
The following is an example of one of the many input that can be given to the ```EditDistnace()``` function and the following outputs. <br>
<br>
### Example 1
Inputs: "football" and "basketball"
```C++
int distance = EditDistance("football", "basketball");
```
Output:
```
The shortest edit distnance from the word "football" to "basketball":

The 2d array of the optimal amount of edits needed at each position
0   1   2   3   4   5   6   7   8   9   10
1   1   2   3   4   5   6   7   8   9   10
2   2   2   3   4   5   6   7   8   9   10
3   3   3   3   4   5   6   7   8   9   10
4   4   4   4   4   5   5   6   7   8   9
5   4   5   5   5   5   6   5   6   7   8
6   5   4   5   6   6   6   6   5   6   7
7   6   5   5   6   7   7   7   6   5   6
8   7   6   6   6   7   8   8   7   6   5

Steps needed to make the edit:
Replace f with b
Replace o with a
Replace o with s
Insert k
Insert e
Keep t
Keep b
Keep a
Keep l
Keep l
The amount of edits needed are 5

Process finished with exit code 0
```
### Example 2
Inputs: "batman" and "superman"
```C++
int distance = EditDistance("batman", "superman");
```
Output:
```
The shortest edit distnance from the word "batman" to "superman":

The 2d array of the optimal amount of edits needed at each position
0   1   2   3   4   5   6   7   8   
1   1   2   3   4   5   6   7   8   
2   2   2   3   4   5   6   6   7   
3   3   3   3   4   5   6   7   7   
4   4   4   4   4   5   5   6   7
5   5   5   5   5   5   6   5   6
6   6   6   6   6   6   6   6   5

Steps needed to make the edit:
Replace b with s
Replace a with u
Replace t with p
Insert e
Insert r
Keep m
Keep a
Keep n
```
### Example 3
Inputs: "goblin" and "golden"
```C++
int distance = EditDistance("goblin", "golden");
```
Output:
```
The shortest edit distnance from the word "goblin" to "golden":

The 2d array of the optimal amount of edits needed at each position
0   1   2   3   4   5   6
1   0   1   2   3   4   5
2   1   0   1   2   3   4
3   2   1   1   2   3   4
4   3   2   1   2   3   4
5   4   3   2   2   3   4
6   5   4   3   3   3   3
Steps needed to make the edit:
Keep g
Keep o
Delete b
Keep l
Replace i with d
Insert e
Keep n
The amount of edits needed are 3
```

## Possible Alterations to the Code

If you want input the strings while the program is running rather than hardcode the words into the source code, you can alter the following block of code in the ```main int()``` section of the source code. <br>

Change this block of code
```C++
int main(){
int distance = EditDistance("football", "basketball");
cout << "The amount of edits needed are " << distance << endl;
return 0;
}
```
To the following
```C++
int main(){
string word1, word2;
cout << "Enter the first word: \n";
cin >> word1;
cout << "Enter the second word: \n";
cin >> word2;
int distance = EditDistance(word1, word2);
cout << "The amount of edits needed are " << distance << endl;
return 0;
}
```
This altercation will allow the program to let you enter two strings when the program runs rather than hard coding the words into the program.
