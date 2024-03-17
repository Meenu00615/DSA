class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        List<int[]> result = new ArrayList();
        boolean intervalInserted = false;

        for(int i = 0; i < n; i++) {
            if(intervals[i][1] < newInterval[0]) {
                result.add(intervals[i]);
            } else if(intervals[i][0] > newInterval[1]) {
                if(!intervalInserted) {
                    result.add(newInterval);
                    intervalInserted = true;
                }
                result.add(intervals[i]);
            } else {
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            }
        }
        if(!intervalInserted) {
            result.add(newInterval);
        }
        return result.toArray(new int[0][]);
    }
}