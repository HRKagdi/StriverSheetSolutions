class MinHeap{
     int capacity; int heapSize;
     int* heap;
    public:
    MinHeap(int capacity)
{
    // Initialize the object parameters.
    capacity = capacity;
    heapSize = 0;
    heap = new int[capacity];
}
      int parent(int i){
          return (i-1)/2;
      }
      int leftChild(int p){
        return 2*p+1;
      }
      int rightChild(int p){
         return 2*p+2;
      }
     void heapify(int i){
         int left=leftChild(i);
         int right=rightChild(i);
         int smallest=i;
         if(left<heapSize && heap[left]<heap[smallest]) smallest=left;
         if(right<heapSize && heap[right]<heap[smallest]) smallest=right;
         if(smallest!=i){
             int temp=heap[smallest]; heap[smallest]=heap[i];
             heap[i]=temp;
             heapify(smallest);
         }
     }
     void insert(int x){
         heap[heapSize]=x; heapSize++; heapify(0);
     }
    int pop(){
        int temp=heap[0];
        heap[0]=heap[heapSize-1];
           heapSize--;
        heapify(0);
        return temp;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    MinHeap *pq=new MinHeap(100000);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i][0]==0){
            pq->insert(q[i][1]);
        }
        else{
            ans.push_back(pq->pop());
        }
    }
    return ans;
}
