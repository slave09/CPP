class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    
    queue<int>queue;
    vector<int>visited_rooms(rooms.size(), 0);
    visited_rooms[0] = 1;
    int number_of_rooms = 1;
    
    for(auto firstRoom : rooms[0])
      queue.push(firstRoom);
    
    while(!queue.empty()){
      int key = queue.front();
      queue.pop();
      if(visited_rooms[key] > 0) continue;
      visited_rooms[key]++;
      for(auto key : rooms[key])
        queue.push(key);
      number_of_rooms++;
    }
    
    return rooms.size() == number_of_rooms;
  }
};