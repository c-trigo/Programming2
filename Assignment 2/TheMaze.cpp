/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <ctime>
#include <iostream>
#include <array>
#include <tuple>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <string>


using namespace std;

// When passing a 2D array to a function, you need to declare the size of columns. 
void print_maze(string b[][12]) { 
     // Initializing the counters for the loops
     int i, j; 
     int size = 12; 
     // Go through whole 2D array printing elmeent by element.
     for(i=0; i<size; i++)
        {
                for(j=0; j<size; j++)
                {
                        cout<<" "<<b[i][j]<<" ";
                }
                cout<<"\n";
        };
    return ;
};

void find_pos(string b[][12], int *row, int *col) { 
     // Initializing the counters for the loops
     int i, j; 
     int size = 12; 
     struct range
        {				// Declare a local structure 
            int row, col;
         };
     // Go through whole 2D array printing elmeent by element.
     for(i=0; i<size; i++)
        {
                for(j=0; j<size; j++)
                {       
                    if (b[i][j] == "x") {
                        // Prints i+1 and j+1 to make the count as a human would 
                        cout<<"\nInitial position: Row "<<i+1<<" Column "<<j+1<<endl;
                    };
                };
        };
        *row=i; 
        *col=j; 
     return ;
};

int main() {
    
    // Initialization of maze as shown in the reader. 
	string maze[12][12]= {
            { "#","#","#","#","#","#","#","#","#","#","#","#" },
            { "#",".",".",".","#",".",".",".",".",".",".","#" },
            { ".",".","#",".","#",".","#","#","#","#",".","#"  },
            { "#","#","#",".","#",".",".",".",".","#",".","#" },
            { "#",".",".",".",".","#","#","#","#","#",".","x" },
            { "#","#","#","#",".","#","#","#","#","#",".","#"  },
            { "#",".",".","#",".","#","#","#","#","#",".","#" },
            { "#","#",".","#",".","#","#","#","#","#",".","#" },
            { "#",".",".","#",".","#","#","#","#","#",".","#"  },
            { "#","#","#","#","#","#",".","#","#","#",".","#" },
            { "#",".",".",".",".",".",".",".",".",".",".","#" },
            { "#","#","#","#","#","#","#","#","#","#","#","#"  },
            };
    // Calling the function to print the maze
    print_maze(maze);
    
    int row, col; 
    find_pos(maze, &row, &col);
    return 0; 
    
};
