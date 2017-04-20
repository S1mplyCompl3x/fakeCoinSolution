//
//  main.cpp
//  algorithmsFinal
//
//  Created by IMI  on 4/20/17.
//  Copyright © 2017 s1mplycompl3x. All rights reserved.
//

/* ---------------------------- TO DO ---------------------------------
 
    1. Implement search
    2. Figure how the iteration through the loop should be
    3. Implement a way to find how long each operation took
*/

/*  how to split vector into 2 
 std::vector<int> lines;
 // fill
 std::size_t const half_size = lines.size() / 2;
 std::vector<int> split_lo(lines.begin(), lines.begin() + half_size);
 std::vector<int> split_hi(lines.begin() + half_size, lines.end());
 */

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

//Declarations
void insertFakeCoin(vector<int> &v, int index);




//Main Program

int main(){
    srand (time(NULL)); //get the time to be hella random
    int num; //
    for (num = 1000;num<=30000;num+=1000){
        vector<int> initialVector(num,0);
        insertFakeCoin(initialVector, num);
        for (vector<int>::iterator it = initialVector.begin() ; it != initialVector.end(); ++it){
            cout <<*it<<" ";
        }
        cout <<"\n-----------------------------------------------"<<endl;
    }
    
    return 0;
    
}

//Definition

void insertFakeCoin(vector<int> &v, int index){
    int r = rand() % index;
    v[r] = 1;
}
