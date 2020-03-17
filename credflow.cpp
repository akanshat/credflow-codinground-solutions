#include <bits/stdc++.h>
using namespace std;

struct animal {
  string type;
  int room;
  int times = 0;
  animal(string _type, int _room) : type(_type), room(_room) {};
  void reset() {
    times = 0;
  }

  void walk() { times++; };
  int count() {  return times; };
};

list<animal> out, goat, cow;
  
void takeout (int cows, int goats) {
  int reqgoats = (goats + 2) / 3;
  while (reqgoats-- > 0) {
    if (goat.back().count() == 0) {
      out.push_back(goat.back());  
      out.back().walk();
      goat.pop_back();
    } else 
      break;
  }

  int reqcows = (cows + 2) / 3;
  while (reqcows-- > 0) {
    if (cow.back().count() == 0) {
      out.push_back(cow.back());  
      out.back().walk();
      cow.pop_back();
    } else 
      break;
  }

  while (out.size()) {
    if (out.front().type == "goat") {
      goat.push_back(out.front());
      goat.back().reset();
      out.pop_front();
    } else {
      cow.push_back(out.front());
      cow.back().reset();
      out.pop_front();
    }
  }
}

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int budget = 1e6, cows = 0, goats = 0, maxprofit = 0, blocks = 80;
  int gprofit = 2, cprofit = 6, ccost = 400, gcost = 100, gblock = 5, cblock = 2;
  // i = number of goats
  // j = number of cows
  for (int i = 0; i <= gblock * blocks; ++i) {
    for (int j = 0; j <= cblock * blocks; ++j) {
      int cost = gcost * i + ccost * j;
      int profit = gprofit * i + cprofit * j;

      int requiredblocks = (i+gblock-1)/gblock + (j+cblock-1)/cblock;
      if (profit > maxprofit && cost <= budget && requiredblocks <= blocks)
        cows = j, goats = i, maxprofit = profit;
    }
  }

  int totalgblocks = (goats + gblock - 1) / gblock;
  int totalcblocks = (cows + cblock - 1) / cblock;

  for (int i = 0; i < goats; ++i) {
    goat.emplace_back("goat", i % totalgblocks + 1);
  } 

  for (int i = 0; i < cows; ++i) {
    cow.emplace_back("cows", i % totalcblocks + 1 + gblock);
  }  

  for (int i = 0; i < 5; ++i) 
    takeout(cows, goats);

  cout<<"maxprofit = "<<maxprofit <<endl;
  cout <<"No. of cows = "<<cows << "\t No. of goats = " << goats << endl;
}