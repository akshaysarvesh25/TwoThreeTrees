#include <iostream>
#include <math.h>
#include <string.h>
#include<tuple>
#include <algorithm>
#include <vector>


using namespace std;

#define DEBUG_MODE_ON_PROCESSROOT 1
#define DEBUG_MODE_ON_ADDLEAF 1
#define DEBUG_MODE_ON_INSERT 1


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

     /***************************************************************
     *
     *
     ***************************************************************/
    bool CheckAndProcessRoot(T val1)
    {
      /* If the root contains only left element */
      if(root->LData && !root->MData && !root->RData)
      {
        if(root->LData <= val1)
        {
          root->MData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Adding MData"<<endl;
          #endif
          return true;
        }
        else
        {
          root->MData = root->LData;
          root->LData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Replacing LData"<<endl;
          #endif
          return true;
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
          return true;
        }
        /* If the middle element is larger than the right element */
        else if((root->LData <= val1) &&(root->MData > val1))
        {
          root->RData = root->MData;
          root->MData = val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"If middle element is large, adding right element"<<endl;
          #endif
          return true;
        }
        else
        {
          root->RData =val1;
          #if DEBUG_MODE_ON_PROCESSROOT
          cout<<"Adding Right element"<<endl;
          #endif
          return true;
        }
      }

      else
      {
        return false;
      }
    }

    /***************************************************************
     *
     *
     ***************************************************************/
    std::vector<T> Order4InstancesData(T val1, T val2, T val3,T val4)
    {
      vector<T> vec;

      vec.push_back(val1);
      vec.push_back(val2);
      vec.push_back(val3);
      vec.push_back(val4);

      sort( vec.begin(), vec.end() );

      return vec;
    }

    /***************************************************************
     *
     *
     ***************************************************************/
    void AddLeaf(TwoThreeTree_Node<T> *r1, T val1,TwoThreeTree_Node<T> *r2)
    {

      #if DEBUG_MODE_ON_ADDLEAF
      cout<<"Starting AddLeaf"<<endl;
      #endif

      r2 = NULL;

      /* If r1 is a parent of leaves */
      if((r1->LChild->LChild == NULL) && (r1->MChild->LChild == NULL) && (r1->RChild->LChild == NULL))
      {
        /* If r1 has only two children i.e only Left and Right children exist */
        if((r1->LChild)&&(r1->MChild)&&!(r1->RChild))
        {
          r1->RChild = new TwoThreeTree_Node<T>(val1);
        }

        else
        {
            std::vector<T> SortedData = Order4InstancesData(val1,r1->LData,r1->MData,r1->RData);

            r1->LData = SortedData[0];
            r1->MData = SortedData[1];
            r2->LData = SortedData[2];
            r2->MData = SortedData[3];

        }
        return;
      }

      TwoThreeTree_Node<T> *v,*v2=NULL;

      if((r1->LData)>=val1)
      {

        v = r1->LChild;
      }

      else if((r1->MData>=val1) || !(r1->RChild) )
      {
        v = r1->MChild;
      }

      else
      {
        v = r1->RChild;
      }

      AddLeaf(v,val1,v2);

      if(v2 == NULL)
      {
        return;
      }

      if((v2!=NULL)&&(r1->LChild)&&(r1->MChild))
      {
        r1->RChild = v2;
      }
      else
      {
        std::vector<T> SortedData1 = Order4InstancesData(v2->LData,r1->LData,r1->MData,r1->RData);

        r1->LData = SortedData1[0];
        r1->MData = SortedData1[1];
        r2->LData = SortedData1[2];
        r2->MData = SortedData1[3];

        return;
      }


      //return *r_;
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


      void Insert(T val1)
      {
         /* If root exists */
         if (root)
         {
             /* Check if Root exists */
             bool bRetVal = CheckAndProcessRoot(val1);
             #if DEBUG_MODE_ON_INSERT
             cout<<"bRetVal is : "<<bRetVal<<endl;
             #endif

             if(bRetVal == true)
             {
               return;
             }

             /* Dummy Node variable */
             TwoThreeTree_Node<T> *r1;

             /* Add elements to the tree */
             AddLeaf(root,val1,r1);






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
    TwoThree_Tree1->Insert(96);

    return 0;
  }
