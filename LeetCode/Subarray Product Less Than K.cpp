//Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size(), i = 0 , j = 0 ,total_count = 0 ; 
        int prev_j = 0 ;
        long long int prod = 1;
        while(i < len && j < len)
        {
            prod *= nums[j];
            if(prod >= k)
            {
                int n = j-i;
                int duplicates = prev_j - i ;
                int dup = (duplicates*(duplicates+1)/2);
                
                total_count += (((n*(n+1)/2))-dup);
                //cout<<i << " "<<j<<" "<<prev_j<<" "<<prod<<" "<<total_count<<"\n";
                while(prod >= k && i <= j)
                {
                    prod /= nums[i];
                    i++;
                }
                prev_j = j;
            }
            j++;
        }
        if(i < len)
        {
            int n = j-i;
            int duplicates = prev_j - i ;
            int dup = (duplicates*(duplicates+1)/2);
            total_count += (((n*(n+1)/2))-dup);
        }
        return total_count;
    }
};