#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;
map<string, vector<string>> Neighbors;
map<string, int> dists;

typedef pair<int, string> State;
vector<State> eccs;

void bfs(string source){
  queue<string> Q;
  dists[source] = 0;
  Q.push(source);
  while (!Q.empty()) {
    string to_visit = Q.front();
    Q.pop();
//    for (int i=0; i<V.size(); i++)
    for (auto &n : Neighbors[to_visit]) {
      if (dists.count(n) == 0) {   // is nbr unvisited so far...?
        Q.push(n);
        dists[n] = dists[to_visit] + 1;
      }
    }
  }
}
int main(){

  ifstream input;
  string start, finish;
  input.open("usa_48_state_graph.txt");
  if (!input.is_open()) {cout << "not open";}
  while(input >> start >> finish){

    Neighbors[start].push_back(finish);
    Neighbors[finish].push_back(start);
    // dists[start] = 0;
    // dists[finish] = 0;
  }
//  cout << dists.size() << endl;
//  cout << Neighbors.size() << endl;
  int best = 0;
  for (auto &i : Neighbors){
    bfs(i.first);
    for (auto &j : dists){
      // cout << i.first << " ";
      // cout << i.second << endl;
      if (best < j.second) {best = j.second;}
    }
    eccs.push_back(State(best, i.first));
//    cout << i.first << " " << best << endl;
    best = 0;
    dists.clear();
  }
  sort(eccs.begin(), eccs.end());
  for (auto &k : eccs) {cout << k.second << " " << k.first << endl;}
  //sort()
return 0;
}
