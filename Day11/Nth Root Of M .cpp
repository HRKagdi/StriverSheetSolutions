//https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



double mult(double x,int p){
    double ans=1.0;
    for(int i=1;i<=p;i++){
        ans=ans*x;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
        double low=1.0; double high=m; double eps=1e-6;
        while((high-low)>eps){
            int mid=(low+high)/2;
            if(mult(mid,n)<m) low=mid;
            else high=mid;
        }
    return high;
}
