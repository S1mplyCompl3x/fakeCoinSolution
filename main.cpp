//
//  main.cpp
//  algorithmsFinal
//
//  Created by IMI  on 4/18/17.
//  Copyright © 2017 s1mplycompl3x. All rights reserved.
//



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>


using namespace std;

//Declarations
int insertFakeCoin(vector<int> &v, int index);
void findFakeCoinDividenConquer(vector<int> &v, int index);
void findFakeCoinBruteForce(vector<int> v, int index);




//Main Program

int main(){
    srand (time(NULL)); //get the time to be truly random
    int num;
    long long averageBruteForce=0;
    long long averageDividenConquer=0;
    for (num = 10000;num<=30000;num+=1000){
        for (int i=1;i<=10;i++){
        vector<int> initialVector(num,0);
        int index = insertFakeCoin(initialVector, num);
        vector<int> initialVectorCopy = initialVector;

        auto start = std::chrono::high_resolution_clock::now();
        findFakeCoinDividenConquer(initialVector, index);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        averageDividenConquer += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();


        auto start1 = std::chrono::high_resolution_clock::now();
        findFakeCoinBruteForce(initialVector, num);
        auto elapsed1 = std::chrono::high_resolution_clock::now() - start1;
        averageBruteForce += std::chrono::duration_cast<std::chrono::microseconds>(elapsed1).count();
        }
        cout<<"Divide and Conquer Average for "<<num<<" is "<<averageDividenConquer/10<<" microseconds"<<endl;
        cout<<"BruteForce Average for "<<num<<" is "<<averageBruteForce/10<<" microseconds"<<endl;

    }
    
    return 0;
    
}

//Definition

int insertFakeCoin(vector<int> &v, int index){

    int r = rand() % index;
    v[r] = 1;
    return r;
}

void findFakeCoinDividenConquer(vector<int> &v, int index){

	size_t half = v.size() / 2;
    vector<int> lo_temp, hi_temp, temp1, temp2;
    int remainder = v.size() % 2;
    int rem = remainder;
    int remPosition = (v.size() / 2);
    /* Split the vector based on if remainder exists */
    if (remainder == 0){
	vector<int> temp1(v.begin(), v.begin()+half);
        lo_temp = temp1;
	vector<int> temp2(half + v.begin(), v.end());
        hi_temp = temp2;
    }
    else if (remainder == 1){
        vector<int> temp1(v.begin(), v.begin()+half);
        lo_temp = temp1;
        vector<int> temp2((remPosition+1) + v.begin(), v.end());
        hi_temp = temp2;
        remainder = v[remPosition];
    }
    /*---------Conditions---------*/

    if (half == 1){
        if (lo_temp[0] == 1){
            return;}
        else if (hi_temp[0] == 1){
            return;}
    }
    if (remainder == 1){
        return;
    }
    else if(index<half && remainder == 0){
        v = lo_temp;
        findFakeCoinDividenConquer(v, index);
    }
    else if(index>=half && remainder == 0){
        v = hi_temp;
        if (index > half){
            index = (index) - (half +rem) ;
            findFakeCoinDividenConquer(v, index);}
        
    }
    
}


void findFakeCoinBruteForce(vector<int> v, int index){
    for (int i=0;i<index;i++){
        if (v[i] == 1){
            i = index;
        }
    }
    
        
}


