/**
 * CS 202 - HW 4
 * A main file
 * Please make sure that your code compiles and runs with this main file
 */

/*
* Title : Hash Tables, Graphs
* Author : Deniz Yüksel
* ID : 21600880
* Section : 1
* Assignment : 4
* Description : main file. Processing the txt file is done here.
* Please don't forget to read readme.txt and scribe your own path of
* movieDataset.txt.
*/

#include "graph.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

/*You can add additional libraries here to read and process the dataset*/

using namespace std;

void printList(list<node> aList) {
    while (!aList.empty()) {

        node listNode = aList.front();
        aList.pop_front();

        cout << left << setw(10) << "Movie Name: " << listNode.movie;
        cout << right << setw(10) << "Performer 2: " << listNode.name;
        cout << right << setw(10) << "Director: " << listNode.director << endl;
    }
}

void printElements(list<string> aList){
    while (!aList.empty()) {

        string element = aList.front();
        aList.pop_front();

        cout << left << setw(10) << element << endl;
    }
}

void printPlayers( map<string, int> players){
    cout << "Player name" << "\t\t" << "Number of Movies" << endl;
    for( map<string, int>::iterator it = players.begin();
    it != players.end(); it++){
        cout << it->first << "\t\t" << it->second << endl;
    }
}

int main() {
    /*YOUR IMPLEMENTATION*/

    Graph myGraph;

    std::ifstream file("/home/deniz/Courses/CS/Cs-202/homework/hw4/movieDataset.txt");
    std::string str;
    std::string file_contents;

    //movieTitle;performer1;performer2;director

    string movie;
    string performer1;
    string performer2;
    string director;


    // reading file and adding vertices and edges...
    int counter = 0;

    while (std::getline(file, str))
    {
        string thisLine = str;
        int position = thisLine.find(";"); // beklenenden bir az dönüyor.

        movie = thisLine.substr(0, position);
        thisLine = thisLine.substr(position + 1);

        position = thisLine.find(";");
        performer1 = thisLine.substr(0, position);
        thisLine = thisLine.substr(position + 1);

        position = thisLine.find(";");
        performer2 = thisLine.substr(0, position);
        thisLine = thisLine.substr(position + 1);

        position = thisLine.find(";");
        director = thisLine.substr(0, position);

        myGraph.addPerformer(performer1);
        myGraph.addPerformer(performer2);

        myGraph.addEdge(movie, performer1, performer2, director);
        /*
        cout << movie << endl;
        cout << performer1 << endl;
        cout << performer2 << endl;
        cout << director << endl;
        break;
         //tester...
         */

    }

    int selection = 0;

    do{
        cout << "\nWelcome to Movie Dataset" <<
         "\nSelect an option :" <<
         "\n1 - See movies of a performer" <<
         "\n2 - Delete performers who directed their own movies" <<
         "\n3 - Find performer(s) who played in highest number of movies" <<
         "\n4 - Find performer number of performers based on a given performer" <<
         "\n5 - Find performer(s) who played in highest number of movies with a given performer" <<
         "\n6 - Find director(s) who directed highest number of movies of a given performer" <<
         "\n7 - Exit" << "\nSelection: ";
    cin >> selection;


        if( selection == 1){
            cin.ignore();
            cout << "Enter performer name: " << endl;
            string performerName;
            getline(cin, performerName);
            list<string> movies;
            movies = myGraph.getMovies(performerName);
            printElements(movies);
        }

        else if( selection == 2){
            cout << "Deleting and displaying directors who performed in their movies..." << endl;
            list<string> deletedPerformers = myGraph.deletePerformers();
            printElements(deletedPerformers);
        }

        else if( selection == 3){
            map<string, int> actives = myGraph.getMostActivePerformers();
            printPlayers(actives);
        }

        else if( selection == 4){


        }

        else if( selection == 5){
            cin.ignore();
            cout << "Enter performer name: " << endl;
            string performerName;
            getline(cin, performerName);
            map<string, int> frequentPlayers = myGraph.getFrequentPartner(performerName);
            printPlayers(frequentPlayers);
        }

        else if( selection == 6){
            cin.ignore();
            cout << "Enter performer name: " << endl;
            string performerName;
            getline(cin, performerName);
            map<string, int> frequentPlayers = myGraph.getFrequentDirector(performerName);
            printPlayers(frequentPlayers);
        }

        else if( selection == 7){
            cout << "System will now exit..." << endl;
        }

        else{
            cout << "Please enter a proper selection..." << endl;
            cin >> selection;
        }
    }
    while( selection != 7);






    return 0;
}
// End of main file
