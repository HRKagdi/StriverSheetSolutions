//https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


int findMinimumCoins(int amount) 
{

        vector<int> v={1,2,5,10,20,50,100,500,1000};
        int i=v.size()-1; int ans=0;
        while(i>=0 && amount>0){
            if(amount>=v[i]) {ans++; amount-=v[i];}
            else i--;
        }
        return ans;
  
}
