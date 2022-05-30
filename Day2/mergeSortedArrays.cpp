//https://www.codingninjas.com/codestudio/problems/1214628?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int j=0;
    for(int i=m;i<m+n;i++){
        arr1[i]=arr2[j++];    
    }
    sort(arr1.begin(),arr1.end());
    return arr1;    
}
