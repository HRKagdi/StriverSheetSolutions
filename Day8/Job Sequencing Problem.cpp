https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comparator(Job a, Job b){
        return (a.profit>b.profit);

    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparator);
        int nd, pro; nd=pro=0;
        vector<bool>deadline(n,false);
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(!deadline[j]){
                    pro+=arr[i].profit;
                    nd++;  deadline[j]=true; break;
                }
            }
        }
        vector<int>v(2); v[0]=nd; v[1]=pro;
        return v;
    } 
};
