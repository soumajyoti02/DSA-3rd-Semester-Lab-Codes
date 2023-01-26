Question :  Using recursions solve the problem of Tower Of Hanoi;
===========================================================================
  
Algorithm :

---> Initialize the number of disks and the names of the rods (in this case, A, B and C) in the main function.
  
---> Define the towerOfHanoi function, which takes in the number of disks, and the names of the source rod, auxiliary rod and destination rod as parameters.
  
---> Inside the function, check if theres only one disk, in that case, print the instruction to move that disk from source rod to destination rod.
  
---> If theres more than one disk, first move the top n-1 disks from source rod to auxiliary rod using the destination rod, by calling the towerOfHanoi
     function recursively.
  
---> Once the top n-1 disks are moved, move the remaining disk from source rod to destination rod and print the instruction.
  
---> Finally, move the n-1 disks from auxiliary rod to destination rod using the source rod, by calling the towerOfHanoi function recursively.
  
---> In every recursive call, it reduces the number of disk by 1 and changes the rods according to the rules of Tower of Hanoi problem. As it reduces the number
    of disk in every call, it will eventually reach the base case where there is only one disk, then it will start returning the calls and prints the instruction;



Code Below :::
-------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
  
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // If only one disk, move it from the source peg to the destination peg
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    // Move top n-1 disks from source peg to aux peg using destination peg
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    // Move remaining disk from source peg to destination peg
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    // Move n-1 disks from aux peg to destination peg using source peg
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}






