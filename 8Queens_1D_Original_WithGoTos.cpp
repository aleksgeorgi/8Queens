#include <iostream>
#include <cmath>
using namespace std;

int main (){

  int q[8], c = 0, counter = 0;
  q[0] = 0;

NC:
  c++;
  if (c == 8)
    goto print;
  q[c] = -1;

NR:
  q[c]++;
  if (q[c] == 8)
    goto backtrack;
  //all tests in one 
  for (int i = 0; i < c; i++)
    {
      if (q[i] == q[c] || (c - i) == abs (q[c] - q[i]))
	goto NR;
    }

  goto NC;

backtrack:
  c--;
  if (c == -1)
    return 0;
  goto NR;

print:
  counter++;
  cout << "The values in the q array are: ";
  for (int i = 0; i < 8; i++)
    {
      cout << q[i] << " ";
    }
  cout << endl;
  cout << "Solution number " << counter << ": \n";
  
  
  for (int j = 0; j < 8; j++){
      for (int i = 0; i < 8; i++){
	  if (q[i] == j){
	      cout << "1";
	    }
	  else
	    cout << "0";
	}
      cout << endl;
    }
  cout << endl;
  
  //--------------//

  goto backtrack;

}


