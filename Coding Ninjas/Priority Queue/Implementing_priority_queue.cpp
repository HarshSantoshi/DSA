#include <iostream>
using namespace std;
#include <vector>

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getsize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    int removeMin() {
		if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;

	}
};
#include <vector>
#include <string>
#include<limits.h>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/
    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }

    void insert(int element) {
        // Implement the insert() function here
        if(isEmpty()){
            return;
        }
        pq.push_back(element);
        int childIndex = pq.size()-1;
        while(childIndex>0){

        int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
        
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){

        return INT_MAX;}
        return pq[pq.size()-1];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(isEmpty()){
            return INT_MAX;
        }
        int ans = pq[pq.size()-1];
        pq[pq.size()-2]= pq[pq.size()-1];
        pq.pop_back();
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }
// void insert(int data)
//     {
//         int parent = 0;

//          pq.push_back(data);
//         current =  pq.size() - 1;
//         parent = (current - 1) / 2;

//         if ( pq.size() > 1)
//         {
//             while ( pq.at(parent) <  pq.at(current))
//             {
//                 if ( pq.at(current) >  pq.at(parent))
//                 {
//                     std::swap( pq.at(parent),  pq.at(current));
//                     current = parent;
//                     parent = (parent - 1) / 2;
//                 }
//             }
//         }
//         // for(int i = 0; i < heap.size(); i++)
//         //      {
//         //          std::cout << heap.at(i) << std::endl;
//         //      }
//         //  std::cout << std::endl;
//     }

//     int removeMax()
//     {
//         if (! pq.empty())
//         {
//             if ( pq.size() == 1)
//             {
//                  pq.pop_back();
//                 return ;
//             }
//             std::swap( pq.at(0),  pq.at( pq.size() - 1));
//              pq.pop_back();
//             int parent =  pq.at(0);
//             int lchild = (parent * 2) + 1;
//             int rchild = (parent * 2) + 2;

//             // while(lchild < heap.size() && rchild < heap.size())
//             //  {
//             //      if(heap.at(lchild) < heap.at(rchild))
//             //      {
//             //          std::swap(heap.at(parent), heap.at(rchild));
//             //          parent = rchild;
//             //      }
//             //      else
//             //      {
//             //          std::swap(heap.at(parent), heap.at(lchild));
//             //          parent = rchild;
//             //      }

//             //      lchild = (lchild * 2) + 1;
//             //      rchild = (rchild * 2) + 2;
//             //  }

//             if (lchild < rchild)
//             {
//                 while (parent > lchild)
//                 {
//                     std::swap( pq.at(parent),  pq.at(lchild));
//                     lchild = (lchild * 2) + 1;
//                     parent = (rchild - 1) / 2;
//                 }
//             }
//             else
//             {
//                 while (parent > rchild)
//                 {
//                     std::swap( pq.at(parent),  pq.at(rchild));
//                     rchild = (rchild * 2) + 2;
//                     parent = (rchild - 1) / 2;
//                 }
//             }
//         }
//         // for(int i = 0; i < heap.size(); i++)
//         //  {
//         //      std::cout << heap.at(i) << std::endl;
//         //  }
//         // std::cout << std::endl;
//         return ;
//     }

//     int getMax()
//     {
//         return  pq.size();
//     }

//     bool isEmpty()
//     {
//         return  pq.size()==0;
//     }

    
};