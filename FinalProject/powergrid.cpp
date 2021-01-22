/*******************************************************************************
 * Name        : powergrid.cpp
 * Author      : Ayomide Omokanwaye
 * Version     : 1.0
 * Date        : December 18, 2020
 * Description : A program that reads the graph representation from a file and computes the minimum set of roads on which to install power lines.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <limits>
#include <fstream>
#include <map>
#include <climits>
#include <iterator>
#include <string>
#include <queue>
#include <set>

using namespace std;

int matrix[1000][1000] = {-1};
string matrix2[1000][1000];
//int matrix3[1000][1000];
//int arr[2];

//long **matrix;
/*
 * powergrid.cpp
 *
 *  Created on: Dec 13, 2020
 *      Author: user
 */

//std::set<int> VT;
std::priority_queue<string, vector<string>, greater<string>> Q;
//std::set<int>::iterator it;
//std::pair<std::set<int>::iterator,bool> ret;
vector<int> VT;
//vector<int> sum;
std::priority_queue<string, vector<string>, greater<string>> str;
//std::priority_queue<int> Qweight;

//int barnacle = 18446744073709551610;
int dvectors [1000];

//void delete_matrix() {
	//Frees up memory allocated to the matrices
	//for (int x = 0; x < 1000; ++x) {
		//delete[] matrix[x];
		//delete[] matrix2[x];
		//delete[] dvectors[x];
	//}
	//delete[] matrix;
	//delete[] matrix2;
	//delete[] dvectors;
//}


int main(int argc, const char *argv[]) {
	int count = 0;
	int commas = 0;
	int num = 0;
	string str1 = "";
	int count2 = 0;
	int base = 0;
	string b = "";
	int row = 0;
	int column = 0;
	string Queue = "";
	string tempy = "";
	//long checker = -1;
  // check the argument count to see if it is equal to 2
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <input file>" << "\n";
    return 1;
  }

  // make an ifstream to read txt
  ifstream input_file(argv[1]);

  // if there is no input file throw an error
  if (!input_file) {
    cerr << "Error: Cannot open file '" << argv[1] << "'." << "\n";
    return 1;
  }

  //ifstream  myfile2(argv[1]);
    	//string line2 ;

  //myfile2.getline( myfile, line2);

  ifstream  myfile(argv[1]);
  	string line ;
  	//myfile.getline(line, 30);
  	bool found = false;
  	//int count = 0;
  	while( std::getline( myfile, line ) && !found) {
  		count2+=1;
  		if ((stoi(line)<1 || stoi(line) > 1000) && count2 == 1) {
  			cerr << "Error: Invalid number of vertices '" << line << "' on line 1.";
  		    return 1;
  		}

  		if (stoi(line)>=1 && stoi(line) <= 1000 && count2 ==1) {
  			num = stoi(line);
  		}

  		commas = 0;
  		int iter = line.find(",");
  		string oline = line;
  		int iter2 = line.substr(iter+1).find(",");
  		while (iter != -1 && count2 > 1){

  			try {

  			if ((stoi(line.substr(0, iter)) < 1 || stoi(line.substr(0, iter))> num) && commas < 2) {

  				if (commas==0){
  					//cerr << "Error: " << "Starting vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  					str1 = "Starting vertex";
  					if (iter2 == -1) {
  						cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  					  	return 1;
  					}
  				}

  				if (commas == 1){
  					//cerr << "Error: " << "Ending vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  					str1 = "Ending vertex";
  					if (iter2 == -1) {
  						cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  					  	return 1;
  					}
  				}
  			  	//cerr << "No Solution.";

  				//cout << line << endl;
  				cerr << "Error: " << str1 << " '" << line.substr(0, iter) << "' on line " << count2 << " is not among valid values 1-" << num <<".";
  			  	return 1;
  			}


  			if (commas == 2 && stoi(line.substr(0, iter))<1){
  				//base = stoi(line.substr(0, iter));
  				//b = case2(line.substr(iter +1));

  				//cerr << "Error: " << "Ending vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  				if (stoi(line.substr(0, iter))<1) {
  			  		cerr << "Error: Invalid edge weight '" << line.substr(0, iter) << "' on line " << count2 << ".";
  			  		return 1;
  			  	}
  			  	if (iter2 == -1) {
  			  		cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  			  		return 1;
  			  	}
  			//if (commas == 2){
  				//base = stoi(line.substr(0, iter));
  			//}

  			}

  			}
  			catch(std::invalid_argument &e) {
  				if (commas==0){
  					//cerr << "Error: " << "Starting vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  					str1 = "Starting vertex";
  					if (iter2 == -1) {
  						cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  						return 1;
  					}
  				 }

  				if (commas == 1){
  					//cerr << "Error: " << "Ending vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  				  	str1 = "Ending vertex";
  				  if (iter2 == -1) {
  					  cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  					  return 1;
  				  }
  				}

  				if (commas == 2){

  					if (iter2 == -1) {
  						cerr << "Error: Invalid edge data '" << oline << "' on line " << count2 << ".";
  						return 1;
  					}
  					//cerr << "Error: " << "Ending vertex" << " on line " << count2 << " is not among valid values 1-" << num;
  				  	cerr << "Error: Invalid edge weight '" << line.substr(0, iter) << "' on line " << count2 << ".";
  				  	return 1;
  				}
  				//cerr << "No Solution.";

  				//cout << line << endl;
  				cerr << "Error: " << str1 << " '" << line.substr(0, iter) << "' on line " << count2 << " is not among valid values 1-" << num <<".";
  				return 1;
  			}

  			//YYYYYYYYYYYYYYY

  			try {
  				if (commas == 0){
  					column = stoi(line.substr(0, iter))-1;
  			  	}
  				if (commas == 1){
  					row = stoi(line.substr(0, iter))-1;
  				}
  				if (commas == 2){
  					matrix[column][row] = stoi(line.substr(0, iter));
  					matrix[row][column] = stoi(line.substr(0, iter));
  					matrix2[column][row] = line.substr(iter+1) + " [" + line.substr(0, iter) + "]";
  					matrix2[row][column] = line.substr(iter+1)+ " [" + line.substr(0, iter) + "]";
  				}
  			}
  			catch(std::invalid_argument &f){
  				continue;
  			}

  			line = line.substr(iter+1);
  			commas += 1;
  			if (commas == 3){
  				b = line;
  			}
  			//cout << line << " "<< commas << endl;
  			iter = line.find(",");
  			if (iter != -1){
  				iter2 = line.substr(iter+1).find(",");
  			}

  			try {
  			if (commas == 2){
  				base = stoi(line.substr(0, iter));
  			}
  			}
  			catch(std::invalid_argument &f){
  				continue;
  			}
  		}


  		if (commas != 3 && count2 !=1) {
  			cerr << "Error: Invalid edge data '" << line << "' on line " << count2;
  			return 1;
  		}
  		count+=1;
  		//Error:Invalidedgedata'2,240,MainSt.'online4.
  	//cout << line << endl;
  	//myfile.clear();
  	//found = true;

  	}
  	if(num == 1){
  		//cout << "Total wire length (meters): 0" << endl;
  		cerr << "No solution.";
  		return 0;
  	}

  	if (num == 2 && count2-1 != 1){
  		cerr << "No solution.";
  		return 1;
  	}

  	if ((count2-1 < num || count2-1 > (num * (num -1))/2) && num >2) {
  		cerr << "No solution.";
  		return 1;
  	}



  	if(num == 2){
  		//cout << base;
  		cout << "Total wire length (meters): " << base << "\n" << b << " [" << base << "]" << endl;
  		return 0;
  	}

  	//Dijkstra’s algorithm for single-source shortest paths
  	//Input: A weighted connected graph G = V,E with nonnegative weights
  	// and its vertex s
  	//Output: The length dv of a shortest path from s to v
  	// and its penultimate vertex pv for every vertex v in V
  	//Initialize(Q) //initialize priority queue to empty

	myfile.close();
	int max = 1000000000;
	for(int v = 1; v <=num; v++){
		int dv = max;
		//int pv = 0;
		//Insert(Q, v, dv) //initialize vertex priority in the priority queue
		Queue = to_string(dv) + " " + to_string(v);

		//cout << Queue << "\n";
		Q.push(Queue);
		dvectors[v-1] = dv;
	}
	//ds ← 0; Decrease(Q, s, ds) //update priority of s with ds
	//int ds = 0;
	//cout << Q.top();
	tempy = Q.top();
	Q.pop();
	int space = tempy.find(" ");
	tempy = "0000000000" + tempy.substr(space);
	Q.push(tempy);

	//VT ← ∅
	//for i ← 0 to |V | − 1 do
	int ustar = 0;
	int dustar = 0;
	int du;
	int sum = 0;
	for(int i =1; i <=num; i++) {
		//u∗ ← DeleteMin(Q) //delete the minimum priority element
		space = Q.top().find(" ");
		ustar = stoi(Q.top().substr(space + 1));
		dustar = stoi(Q.top().substr(0,space));
		Q.pop();
		//VT ← VT ∪ {u∗}
		//ret = VT.insert(ustar);
		VT.push_back(ustar);
		//cout << VT;
		//for every vertex u in V − VT that is adjacent to u∗ do
		for (int u = 1; u <=num; u++){

			if(!(std::find(VT.begin(), VT.end(), u) != VT.end()) && matrix[u-1][ustar-1] != -1){
				//if du∗ + w(u∗, u) < du
				du = dvectors[u-1];
				if (dustar + matrix[ustar-1][u-1] < du) {
					du = dustar + matrix[ustar-1][u-1];
					dvectors[u-1] = du;
					sum+=matrix[ustar-1][u-1];
					str.push(matrix2[ustar-1][u-1]);
					//du ← du∗ + w(u∗, u); pu ← u∗
					//Decrease(Q, u, du)
					tempy = Q.top();
					Q.pop();
					int space = tempy.find(" ");
					//adding leading zeros
					int zeros = 10-to_string(du).length();
					tempy = to_string(du) + tempy.substr(space);
					while(zeros!=0){
						tempy = "0"+tempy;
						zeros-=1;
					}
					Q.push(tempy);



				}
			}

		}
	}


	cout << "Total wire length (meters): " << sum << "\n";
	while (!str.empty()) {
		std::cout << str.top() << "\n";
		str.pop();
	}
	while (!Q.empty()) {
			Q.pop();
	}



	//for(int f; f<1000; f++){
		//if(dvectors[f]){
			//delete dvectors[f];
		//}
		//delete[] matrix[f];
		//delete[] matrix;
		//delete[] matrix2[f];
		//delete[] matrix2;
		//delete[] dvectors;
	//}
	//delete_matrix();
	VT.clear();
	//delete[] dvectors;
  return 0;
}




