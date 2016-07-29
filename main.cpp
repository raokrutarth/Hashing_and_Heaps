#include <iostream>
#include <cstdlib>
#include <cstring>
#include "heap.h"
#include "cchash.h"

using namespace std;

void CuckooHashing() 
{
    int tl;
    int ml;
    cin >> tl >> ml;
    CCHash * cch = new CCHash(tl, ml);
    char command;
    int num;
    while(cin >> command >> num)
    {
        if (command=='i')
            cch->insert(num, cch->get_t1(), cch->get_t2() );
        else if (command == 'r')
            cch->remove(num);  //cout << "remove sucess = " <<  << endl;
        else if (command == 'l')
            cch->lookup(num);
    }    
}

void Binary_Heap() 
{
    int n;
    cin >> n;
    char c;
    int x, y;
    BinaryHeap *bh;
    while(n--)
    {
        cin >> c;
        if(c =='c')
        {
            cin >> x;
            if( x == 1)
                bh = new BinaryHeap(true);
            else if( x == 2)
                bh = new BinaryHeap(false);            
        }
        else if ( c == 'i')
        {
            cin >> x >> y;
            bh->insert(new TreeNode(x, y) );
        }
        else if(c == 'p')
        {
            TreeNode * tn = bh->peek();
            if(tn)
                cout << tn->key << " " << tn->value << endl;
            else
                cout << "empty" << endl;
        }
        else if ( c == 'e')
        {
            TreeNode * tn = bh->extract();
            if(tn)
                cout << tn->key << " " << tn->value << endl;
            else
                cout << "empty" << endl;
        }
        else if( c == 'h')
        {
            cin >> x;
            while(x--)
            {
                cin >> y;
                bh->insert(new TreeNode(y,0));
            }
        }
        else if( c == 's')
            cout << bh->size() << std::endl;
    }
	//cout << endl;
}
void HeapSort() 
{
    int order, n;
    cin >> order;
    BinaryHeap * bh;
    if(order == 1)
        bh = new BinaryHeap(false);
    else if(order == 2)
        bh = new BinaryHeap(true);
    cin >> n;
    int a, b;
    for(int i =0; i < n; i++)
    {
        cin >> a >> b;
        bh->insert(new TreeNode(a, b));
    }
    char c;
    cin >> c;
    TreeNode * tn;
    if( c == 'q')
    {        
        while(n--)
        {
            tn = bh->extract();
            cout << tn->key << " " << tn->value << std::endl; 
        }
    }
	//cout << endl;
}


/* Main function */
int main(int argc, char** argv) {

    /* Read the option */
    int option;
    std::cin >> option;

    /* Call the respective function */
    switch(option) {

        /* Cuckoo Hashing */
        case 1:
            CuckooHashing();
        break;

        /* Binary Heap */
        case 2:
            Binary_Heap();
        break;
        
        case 3:
            HeapSort();
        break;

        /* Wrong option */
        default:
            std::cout << "Wrong option" << std::endl;

    }
    /* Close the program */
	return 0;
}

