#include "iostream"
using namespace std;

class Leaf{
public:
    string msg;
    Leaf(string msg){
        this->msg=msg;
    }
};

class Node{
public:
    int value;
    Node *left;
    Node *right;
    Leaf *leftL;
    Leaf *rightL;
    Node(int val){
        value=val;
        left=NULL;
        right=NULL;
        leftL=NULL;
        rightL=NULL;
    }

};

int main(){
    Node *root = new Node(80);
    Node *left54 = new Node(54);
    Node *right140 = new Node(140);
    root->right = right140;
    root->left = left54;
    Node *left49 = new Node(49);
    left54->left = left49;
    Node *right60 = new Node(60);
    left54->right = right60;
    Node *left104 = new Node(104);
    right140->left = left104;

    Leaf *leafN = new Leaf("Net");
    right140->rightL = leafN;
    Leaf *leafV = new Leaf("Victory");
    left49->leftL = leafV;
    Leaf *leafH = new Leaf("Happy");
    left49->rightL = leafH;
    Leaf *leafF = new Leaf("Flower");
    right60->rightL = leafF;
    Leaf *leafP = new Leaf("Power");
    left104->leftL = leafP;
    Leaf *leafVi = new Leaf("Vision");
    left104->rightL = leafVi;
    Leaf *leaf55 = new Leaf("55");
    right60->leftL = leaf55;

    int val;
    cin >> val;
    val++;
    Node *temp = root;
    while(1){
        if(temp->value == val){
            cout << val;
            break;
        }
        else if(temp->rightL || temp->leftL) {
            if (temp->value == val)cout << val;
            else {
                if (val > temp->value) cout << temp->rightL->msg;
                else cout << temp->leftL->msg;
            }
            break;
        }else{
            if(val < temp->value) temp = temp->left;
            else if(val > temp->value) temp = temp->right;
            }
    }

}
