//Includes
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include<math.h>

using namespace std;


//Functions
int solve(list<int>);





int main() {
    int minutes = 0;
    int numTestCases = 0;
    int initNonEmpty = 0;
    char tempChar;
    int tempInt;
    list<int> people;

    //Import Data
    //Get number of Test cases
    ifstream infile;
    infile.clear();
    infile.open("B-small.in");

    //get NumTestCases
    infile >> numTestCases;
    int solution[numTestCases];

    //Solve it
    for(int i=0; i<numTestCases; i++){
        //Reset vars
        initNonEmpty=0;
        infile >> initNonEmpty;
        people.clear();

        //Input data
        for(int j=0; j<initNonEmpty; j++){
            infile >> tempInt;
//cout << tempInt;
        people.push_back(tempInt);
        }
//cout << endl;

        //Solve the set
        people.sort();
        people.reverse();
        tempInt = solve(people);
//cout << "Solve returns: " << tempInt << endl << endl;
        solution[i] = tempInt;      
    }

    //Output
    ofstream outfile;
    outfile.open("RealCase6.out");
    for (int i=0; i < numTestCases; i++){
        //cout << "Case #" << i+1 << ": " << solution[i] << endl;
        outfile << "Case #" << i+1 << ": " << solution[i] << endl;
    }

}


int solve( list<int> data){
//cout << "Starting Solve functions." << endl;
    int tempMax;
    int max =data.front();
    int test=0;

//cout << "Max: " << max << endl;

    //Test if base case
    if(max<=3){
//cout << "Reached base case." << endl;
        return max;
    }
    else if (max % 2 == 0 ){
//cout << "Max is even" << endl;
        tempMax = max/2;
        data.pop_front();
        data.push_back(tempMax);
        data.push_back(tempMax);
        data.sort();
        data.reverse();
        test=solve(data);
        test=test+1;
//cout << "test is:" << test << endl;
//cout << "max is:" << max << endl;
        if( test<=max){
            return test;
        } else {
            return max;
        }
    }
    else {
//cout << "Max is odd" << endl;
		int ii;
		float ff;
		ii=sqrt(max);
		ff=sqrt(max);
		if(ii==ff){
			cout<<"Inside SQRT:"<<max<<"\n";
			tempMax=max/ii;
			int dummy_max=max;
		while(dummy_max!=ii){	
		data.pop_front();
		data.push_back(tempMax);
		data.push_back(dummy_max-tempMax);
		data.sort();
		data.reverse();
		dummy_max=dummy_max-ii;
		test++;
		}
		data.sort();
        data.reverse();
		test=solve(data);
        test=test+1;
		}
		else{
        tempMax = max/2;
        data.pop_front();
        data.push_back(tempMax);
        data.push_back(tempMax+1);
        data.sort();
        data.reverse();
        test=solve(data);
        test=test+1;
////cout << "test is:" << test << endl;
////cout << "max is:" << max << endl;
		}
        if(test<=max){
            return test;
        } else {
            return max;
        }
    }

}
