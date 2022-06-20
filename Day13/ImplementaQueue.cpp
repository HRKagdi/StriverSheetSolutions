//https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website



class Queue {
public:
    vector<int> q;
    int l; int r; int size;
    Queue() {
        l=0; r=0; size=0; 
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return (size==0);
    }

    void enqueue(int data) {
        q.push_back(data); size++; r++;
    }

    int dequeue() {
        if(size==0) return -1;
        int temp=q[l]; 
        l++; size--;
        return temp;
    }

    int front() {
        if(size==0) return -1;
        return q[l];
    }
};
