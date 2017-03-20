The code here is not a demo for any particular game. It's a demo of a less obvious but imo better way to code falling block games.

Many people have a tendency to use x,y and nested loops everywhere when coding falling block games. This can make the code unnessecarily complicated and difficult to understand.   
I think there is a nicer way to do this which involves storing the matrix in a 1d array and using offsets to represent the tetrominos.
This project is intended to serve as a code demo of that approach. 

The demo was written by me but the concepts used for manipulating the playing pieces inside the playing field and detecting line clears is the brainchild of https://github.com/myndzi  
Chili framework was used for detecting user input and drawing stuff to the screen. https://github.com/planetchili/chili_framework
