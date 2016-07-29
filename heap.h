#ifndef __HEAP_H__
#define __HEAP_H__

      
class TreeNode 
{
    public:
        int value;
        int key;
        TreeNode* leftChild;
        TreeNode* rightChild;
        TreeNode * parent;    
        TreeNode(int key, int value) 
        {
            this->key = key;
            this->value = value;
            leftChild = NULL;
            rightChild = NULL;
        }
        bool operator < (const TreeNode& anotherNode);
        bool operator > (const TreeNode& anotherNode);
        bool operator == (const TreeNode& anotherNode);
        bool isLeaf();   
        void swapNodes(TreeNode * e);
};
class BinaryHeap 
{
    private:
        bool isMaxHeap;
        int heapSize;
    public:        
        TreeNode * root;
        BinaryHeap(bool isMaxHeap);
        void heapify(int size, TreeNode * nodes);
        bool insert(TreeNode * node);
        TreeNode * extract();
        int size();
        TreeNode * peek();
        void printTree(TreeNode * e);
        void upheap(TreeNode * e);
        int maxHeight(int n);
        void addLevel(TreeNode * e, TreeNode * from);
        char * bitString(int num);
        void downheap();
};
#endif
