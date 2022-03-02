#include <iostream>
#include <cmath>
using namespace std;

bool OKFunction(int q[8], int c){
    //row and diagonal tests
    for(int i=0; i<c; i++){
        if((q[i]==q[c]) || ((c-i) == abs(q[c]-q[i]))){
            return false; //false it does not pass test
        }
    }
    return true; //true it passes test
}



void print(int q[8], int &counter){
  counter++;
  cout << "The values in the q array are: ";
  for (int i = 0; i < 8; i++){
      cout << q[i] << " ";
    }
    
  cout << endl;
  
  cout << "Solution number " << counter << ": \n";
  for (int j = 0; j < 8; j++){
      for (int i = 0; i < 8; i++){
    	  if (q[i] == j){
    	      cout << "1";
    	  }
    	  else{
    	    cout << "0";
    	  }
	  }
      cout << endl;
  }
  cout << endl;
  
}



int main() {
    int board[8]={0}, c = 0, counter = 0; 
    
    //put the queen in the upper left square
    board[0] = 0; 

    while(c>=0){// if we backtrack beyond the first col, we are done
        
        // if we have moved beyond the last column
        if(c==8){
            // print the board
            print(board, counter);
            
            // BACKTRACK to find more solutions
            c--;
            board[c]++;
        }
        
        // If we have moved beyond the last row 
        else if(board[c]==8){
            // reset queen
            board[c] = 0;
            
            // BACKTRACK
            c--;
            if (c == -1){
                return 0;
            }
            board[c]++; 


        }

        // Check if the placed queen is ok.
        else if(OKFunction(board, c)){
            // move to next column if ok
            c++;
        } 
        
        else{
            // move to next row if not ok
            board[c]++;
        }

    }
    
    return 0;
}
