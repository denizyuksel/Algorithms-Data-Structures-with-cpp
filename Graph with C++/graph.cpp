/** @file Graph.cpp
 * An adjacency list representation of an undirected graph.
*/

/*
* Title : Hash Tables, Graphs
* Author : Deniz Yüksel
* ID : 21600880
* Section : 1
* Assignment : 4
* Description : This file includes the implementation of graph.h file,
* except the findPlayerNumber method.
*/

#include "graph.h"

/*Do not add new libraries or files*/

Graph::Graph() {

}  // end constructor

    map<string, list<node>> adjList;

void Graph::addPerformer(string performerName) {   /*YOUR IMPLEMENTATION*/
    list<node> linkedList;
    adjList.insert(pair<string, list<node>>(performerName, linkedList));
}  // end addPerformer

void Graph::addEdge(string movieTitle, string performer1, string performer2, string director) {   /*YOUR IMPLEMENTATION*/

    map<string, list<node>>::iterator it = adjList.find(performer1);
    node newValue;
    newValue.name = performer2;
    newValue.director = director;
    newValue.movie = movieTitle;
    it->second.push_back(newValue);

    map<string, list<node>>::iterator it2 = adjList.find(performer2);
    node newValuePerf2;
    newValuePerf2.name = performer1;
    newValuePerf2.director = director;
    newValuePerf2.movie = movieTitle;
    it2->second.push_back(newValuePerf2);

    //find performer 1 first, then performer 2, add to their lists accordingly.


    /*
    for( map<string, list<node>>::iterator it = adjList.begin();
                            it != adjList.end(); it++){
        if( it->first == performer1){
            node newValue;
            newValue.name = performer2;
            newValue.director = director;
            newValue.movie = movieTitle;
            it->second.push_back(newValue);
        }
    }


    for( map<string, list<node>>::iterator it = adjList.begin();
         it != adjList.end(); it++){
        if( it->first == performer2){
            node newValue;
            newValue.name = performer1;
            newValue.director = director;
            newValue.movie = movieTitle;
            it->second.push_back(newValue);
        }
    }

     */
}  // end addEdge

list<string> Graph::getMovies(string performerName) {   /*YOUR IMPLEMENTATION*/
    list<string> performedMovies;

    map<string, list<node>>::iterator itNames = adjList.find(performerName);

    list<node> nodes = itNames->second;
    for (list<node>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        performedMovies.push_back(it->movie);
    }
    return performedMovies;

    /*
     for( int i = 0; i < it->second.size(); i++){
        string movieName = it->second
    }
    */

}  // end getMovies

list<string> Graph::deletePerformers() {   /*YOUR IMPLEMENTATION*/
    //deletes all performers who directed their own movies, basically. If I got it right.

    list<string> directorOfOwnMovies;

    for (map<string, list<node>>::iterator itNames = adjList.begin();
         itNames != adjList.end(); itNames++) {
        list<node> nodes = itNames->second;
        for (list<node>::iterator it = nodes.begin(); it != nodes.end();
             ++it) {
            if (itNames->first == it->director) {
               //for( list<string>::iterator checker = directorOfOwnMovies.begin();
                 //    checker != directorOfOwnMovies.end(); checker++){
                 directorOfOwnMovies.push_back(itNames->first);
                 adjList.erase(itNames->first);
                }
            }
        }

        int count = 0;
        map<string, int> translator;
        for( list<string>::iterator checker = directorOfOwnMovies.begin();
        checker != directorOfOwnMovies.end(); checker++){
            translator.insert(pair<string, int> (*checker, count));
            count++;
        }
        list<string> pureList;
        for( map<string, int>::iterator iter = translator.begin();
            iter != translator.end(); iter++){
            pureList.push_back(iter->first);
        }

    return pureList;

    /*
    for( map<string, list<node>>::iterator itNames = adjList.begin();
         itNames != adjList.end(); itNames++){
        list<node> nameList = itNames->second;
        for( list<node>::iterator itList = nameList.begin();
            itList != nameList.end(); itList++){
            if( itNames->first == itList->director){
                directorOfOwnMovies.push_back(itList ->director);

            }
        }
    }
     */

}  // end deletePerformers

map<string, int> Graph::getMostActivePerformers() {   /*YOUR IMPLEMENTATION*/
    map<string, int> activePerformers;
    int maxPerformed = 0;

    /* Find the number of max performances */
    for (map<string, list<node>>::iterator it = adjList.begin();
         it != adjList.end(); it++) {
        if (it->second.size() > maxPerformed) {
            maxPerformed = it->second.size();
        }
    }

    /* Find actors with that number of performances... */
    /* insertion template...
     * adjList.insert(pair<string, list<node>> ( performerName, linkedList));*/
    for (map<string, list<node>>::iterator it = adjList.begin();
         it != adjList.end(); it++) {
        if (maxPerformed == it->second.size()) {
            string actorName = it->first;
            activePerformers.insert(pair<string, int>(actorName, maxPerformed));
        }
    }
    return activePerformers;
}  // end getMostActivePerformers

map<string, int> Graph::getPerformerNumber(string performerName) {

    

    /*
     list<string> directorOfOwnMovies;

for (map<string, list<node>>::iterator itNames = adjList.begin();
     itNames != adjList.end(); itNames++) {
    list<node> nodes = itNames->second;
    for (list<node>::iterator it = nodes.begin(); it != nodes.end();
         ++it) {
        if (itNames->first == it->director) {
            directorOfOwnMovies.push_back(itNames->first);
            adjList.erase(itNames->first);
        }
    }
}

    map<string, int> performerNumber;
    map<string, bool> unvisited;
    for( map<string, list<node>>::iterator unvisitedMarker = adjList.begin();
         unvisitedMarker != adjList.end(); unvisitedMarker++){
        // set every vertices' visited as false.
        unvisited.insert(pair<string, bool> (unvisitedMarker->first, false));
    }

    queue <string> q;

    map<string, bool>::iterator visitMarker = unvisited.find(performerName);
    visitMarker->second = true;
    unvisited.find(performerName)->second = true;

    q.push(performerName);
    while( !q.empty()){
        string processed = q.front();
        q.pop();
        map<string, list<node>>::iterator vertexProcessor = adjList.find(processed);


        list<node> nodes = vertexProcessor->second;
        for( list<node>::iterator adjacents = nodes.begin(); adjacents != nodes.end(); ++adjacents){
            string actorName = adjacents->name;
            visitMarker = unvisited.find(actorName);
            if( visitMarker->second == false){
                visitMarker->second = true;
                q.push(actorName);
            }
        }


    }

*/
}  // end getPerformerNumber

map<string, int> Graph::getFrequentPartner(string performerName) {   /*YOUR IMPLEMENTATION*/
    map<string, int> allPartners;
    //map<string, bool>::iterator visitMarker = unvisited.find(performerName);
    map<string, list<node>>::iterator playerIterator = adjList.find(performerName);
    /*
     * list<node> nodes = vertexProcessor->second;
        for( list<node>::iterator adjacents = nodes.begin(); adjacents != nodes.end(); ++adjacents)
     */
    list<node> playerNodes = playerIterator->second;

    //insert all the performers with corresponding frequencies.
    for( list<node>::iterator runningIt = playerNodes.begin(); runningIt != playerNodes.end(); ++runningIt){
        int frequency = findFrequency(performerName, runningIt->name);
        allPartners.insert(pair<string, int> (runningIt->name, frequency));
    }
    //allPartners.findHighestFrequencies();
    int highestFreq = findHighestFrequency(allPartners);

    //now, make another map with highestFrequency.
    map<string, int> highFreqMap;
    for( map<string, int>::iterator it = allPartners.begin(); it != allPartners.end(); it++){
        if( it->second == highestFreq){
            highFreqMap.insert(pair<string, int>(it->first, it->second));
        }
    }
    return highFreqMap;

}  // end getFrequentPartner

map<string, int> Graph::getFrequentDirector(string performerName) {
    /*YOUR IMPLEMENTATION*/
    map<string, int> allDirectors;
    //map<string, bool>::iterator visitMarker = unvisited.find(performerName);
    map<string, list<node>>::iterator playerIterator = adjList.find(performerName);
    /*
     * list<node> nodes = vertexProcessor->second;
        for( list<node>::iterator adjacents = nodes.begin(); adjacents != nodes.end(); ++adjacents)
     */
    list<node> playerNodes = playerIterator->second;

    //insert all the performers with corresponding frequencies.
    for( list<node>::iterator runningIt = playerNodes.begin(); runningIt != playerNodes.end(); ++runningIt){
        int frequency = findFrequency(performerName, runningIt->director);
        allDirectors.insert(pair<string, int> (runningIt->director, frequency));
    }
    //allPartners.findHighestFrequencies();
    int highestFreq = findHighestFrequency(allDirectors);

    //now, make another map with highestFrequency.
    map<string, int> highFreqMap;
    for( map<string, int>::iterator it = allDirectors.begin(); it != allDirectors.end(); it++){
        if( it->second == highestFreq){
            highFreqMap.insert(pair<string, int>(it->first, it->second));
        }
    }
    return highFreqMap;


}  // end getFrequentDirector

int Graph:: findFrequency(string performer1, string performerOrDirector){
    map<string, list<node>>::iterator players = adjList.find(performer1);
    list<node> movies = players->second;

    int frequency = 0;
    for( list<node>::iterator it = movies.begin(); it != movies.end(); it++){
        if( it->name == performerOrDirector || it->director == performerOrDirector){
            frequency++;
        }
    }
    return frequency;
}

int Graph:: findHighestFrequency( map<string, int> partnershipMap){
    int maxOccurrence = 0;

    for( map<string, int>::iterator it = partnershipMap.begin(); it != partnershipMap.end(); it++){
        if( it->second > maxOccurrence){
            maxOccurrence = it->second;
        }
    }
    return maxOccurrence;
}
