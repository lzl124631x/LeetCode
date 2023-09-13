// OJ: https://leetcode.com/problems/robot-room-cleaner/
// Author: github.com/lzl124631x
// Time: O(MN) where M and N are the width and height of the room.
// Space: O(MN)
class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_map<int, unordered_set<int>> seen;
    void dfs(Robot& robot, int x, int y, int dir) {
        for (int i = 0; i < 4; ++i, robot.turnRight(), dir = (dir + 1) % 4) {
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];
            if (seen[nx].find(ny) != seen[nx].end()) continue;
            seen[nx].insert(ny);
            bool movable = robot.move();
            if (!movable) continue;
            robot.clean();
            dfs(robot, nx, ny, dir);
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
public:
    void cleanRoom(Robot& robot) {
        robot.clean();
        seen[0].insert(0);
        dfs(robot, 0, 0, 0);
    }
};