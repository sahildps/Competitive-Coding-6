/*
TC : O(n!)
SC : O(H)
LC : 526 : https://leetcode.com/problems/beautiful-arrangement/description/
*/
class Solution
{
public:
    int count = 0;
    int countArrangement(int n)
    {
        // visited indices
        vector<bool> visited(n + 1, false);

        computeSub(n, 1, visited);
        return count;
    }

    void computeSub(int n, int index, vector<bool> visited)
    {
        // base case
        if (index > n)
        {
            count++;
            return;
        }

        // logic
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && (i % index == 0 || index % i == 0))
            {
                visited[i] = true;                 // action
                computeSub(n, index + 1, visited); // recurse
                visited[i] = false;                // backtrack
            }
        }
    }
};