#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;


template <class T>
struct TwoThreeTree_Node {
    T LData,RData,MData;
    TwoThreeTree_Node *LChild;
    TwoThreeTree_Node *RChild;
    TwoThreeTree_Node *MChild;


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


      public:
      void add(T valL,T valR, T valM) {
         if (root) {
             cout<<"Adding new elements"<<endl;
         } else {
             root = new TwoThreeTree_Node<T>(valL,valR,valM);
             cout<<"New root Receieved"<<endl;
         }
      }

};


int main() {
    TwoThree_Tree<int> *TwoThree_Tree1 = new TwoThree_Tree<int>();
    TwoThree_Tree1->add(11,12,13);
    TwoThree_Tree1->add(11,12,13);
    TwoThree_Tree1->add(11,12,13);
    TwoThree_Tree1->add(11,12,13);

    return 0;
  }
