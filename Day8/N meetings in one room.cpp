//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]=make_pair(end[i],start[i]);
        }
        sort(v.begin(),v.end());
        int s=v[0].second; int e=v[0].first;
        int ans=1;
        for(int i=1;i<n;i++){
            if(v[i].second>e){
                ans++;
                s=v[i].second; e=v[i].first;
            }
        }
        return ans;
    }
};
