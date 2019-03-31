#include <iostream>
#include <math.h>
#include <string.h>
#include<tuple>

using namespace std;

#define DEBUG_MODE_ON_PROCESSROOT 1


template <class T>
struct TwoThreeTree_Node {
    T LData,RData,MData;
    TwoThreeTree_Node *LChild;
    TwoThreeTree_Node *RChild;
    TwoThreeTree_Node *MChild;

    TwoThreeTree_Node(T valL) {
        this->LData = valL;

    }

    TwoThreeTree_Node(T valL,T valR, T valM) {
        this->LData = valL;
        this->RData = valR;
        this->MData = valM;

    }

    TwoThreeTree_Node(T valL,T valR,T valM, TwoThreeTree_Node<T> left, TwoThreeTree_Node<T> right, TwoThreeTree_Node<T> middle) {
        this->LData = valL;
        this->RData = valR;
        this->MData = valM;
        this->LChild = left;
        this->RChild = right;
        this->MChild = middle;
    }
};

template <class T>
class TwoThree_Tree {

    private:
    TwoThreeTree_Node<T> *root;

    void CheckAndProcessRoot(T val1)
    {
      if(root->LData && !root->MData && !root->RData) //If the root contains only left element
      {
        if(root->LData <= val1)
        {
          root->MData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Adding MData"<<endl;
          #endif
        }
        else
        {
          root->MData = root->LData;
          root->LData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Replacing LData"<<endl;
          #endif
        }
      }

      /* If the root contains only left and right elements */
      else if(root->LData && root->MData && !root->RData)
      {
        /* If both left and middle elements are large, add the right element */
        if(root->LData > val1 && root->MData > val1)
        {
          root->RData = root->MData;
          root->MData = root->LData;
          root->LData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"If both left and middle elements are large, adding right element"<<endl;
          #endif
        }
        /* If the middle element is larger than the right element */
        else if((root->LData <= val1) &&(root->MData > val1))
        {
          root->RData = root->MData;
          root->MData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"If middle element is large, adding right element"<<endl;
          #endif
        }
        else
        {
          root->RData =val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Adding Right element"<<endl;
          #endif
        }
      }
    }


      public:
        void CreateTree(T val)
        {
          if(root)
          {
            cout<<"Invalid operation, use Insert()"<<endl;
          }
          else
          {
            cout<<"Adding new root"<<endl;
            root = new TwoThreeTree_Node<T>(val);
          }
        }


      void Insert(T val1)//,T valR, T valM) {
      {
         /* If root exists */
         if (root)
         {
             /* Check if Root exists */
             CheckAndProcessRoot(val1);







         }
         else
         {
             root = new TwoThreeTree_Node<T>(val1);
             cout<<"New root Receieved"<<endl;
         }
       }

};


int main() {
    TwoThree_Tree<int> *TwoThree_Tree1 = new TwoThree_Tree<int>();
    TwoThree_Tree1->CreateTree(11);
    TwoThree_Tree1->CreateTree(11);
    TwoThree_Tree1->Insert(10);
    TwoThree_Tree1->Insert(9);

    return 0;
  }
