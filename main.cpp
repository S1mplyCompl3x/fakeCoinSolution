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
#include <stdlib.h>

using namespace std;

//Declarations
void insertFakeCoin(vector<int> &v, int index);
void findFakeCoin(vector<int> &v, int index);




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

void findFakeCoin(vector<int> &v, int index){
	size_t half = v.size() / 2;
	vector<int> lo_temp(v.begin(), v.begin()+half);
	vector<int> hi_temp(half + v.begin(), v.end());
	bool found = false;
	while (found == false){
	//If found change found to true and change &v to that array
	for (vector<int>::iterator it = lo_temp.begin() ; it != lo_temp.end(); ++it){
			if (*it == 1){
				found = true;
				v = lo_temp;
			}
		}
	for (vector<int>::iterator it = hi_temp.begin() ; it != hi_temp.end(); ++it){
		if (*it == 1){
				found = true;
				v = hi_temp;
			}
		}
	}	
	
}

