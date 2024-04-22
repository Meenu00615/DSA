class Solution {
public:
    unordered_set<string> deadendsSet;
    string start;
    string target;
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
      
        for (const auto& d : deadends) deadendsSet.insert(d);
        if (deadendsSet.count("0000")) return -1; 
      
        this->start = "0000";
        this->target = target;
      
        // Perform a bidirectional BFS to find the shortest path.
        return bidirectionalBFS();
    }

    int bidirectionalBFS() {
        unordered_map<string, int> m1; 
        unordered_map<string, int> m2; 
        m1[start] = 0; // Initialize start
        m2[target] = 0; // Initialize target
      
        queue<string> q1{{start}};
        queue<string> q2{{target}};
      
        while (!q1.empty() && !q2.empty()) {
            int t = (q1.size() <= q2.size()) ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) return t; // If a connection is found, return the number of steps.
        }
        return -1; 
    }

    int extend(unordered_map<string, int>& visitedFromOneSide, 
               unordered_map<string, int>& visitedFromOtherSide,
               queue<string>& queueToExtend) {
        for (int n = queueToExtend.size(); n > 0; --n) {
            string currentPosition = queueToExtend.front();
            int step = visitedFromOneSide[currentPosition];
            queueToExtend.pop();
          
            for (const string& nextPosition : getNextPositions(currentPosition)) {
                if (deadendsSet.count(nextPosition) || visitedFromOneSide.count(nextPosition)) continue;
                if (visitedFromOtherSide.count(nextPosition)) {
                    return step + 1 + visitedFromOtherSide[nextPosition];
                }
              
                visitedFromOneSide[nextPosition] = step + 1; 
                queueToExtend.push(nextPosition);
            }
        }
        return -1;
    }
    vector<string> getNextPositions(string& currentPosition) {
        vector<string> possibleNextPositions;
        for (int i = 0; i < 4; ++i) {
            char originalChar = currentPosition[i];

            currentPosition[i] = originalChar == '0' ? '9' : (char) (originalChar - 1);
            possibleNextPositions.push_back(currentPosition);
            currentPosition[i] = originalChar == '9' ? '0' : (char) (originalChar + 1);
            possibleNextPositions.push_back(currentPosition);

            currentPosition[i] = originalChar;
        }
        return possibleNextPositions;
    }
};