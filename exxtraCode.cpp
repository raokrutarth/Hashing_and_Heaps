/*
cout << "inserting " << node->key << endl;
        node->parent = NULL;
        TreeNode **e =  &from;//&root;
        while (*e)
        {
            node->parent = *e;
            if (node->key < (*e)->key ) //|| !((*e)->leftChild) )
                e = &( (*e)->leftChild );
            else if ( !(node->key == (*e)->key) ) // || !((*e)->rightChild)  ) ///if the keys are the same, new entry is ignored.
                e = &( (*e)->rightChild );
            else
                return true; //method returns true because the key already exists
        }
        if(node->parent == NULL)
            root = node;
        else if(node->key < node->parent->key)
            node->parent->leftChild = node;
        else
            node->parent->rightChild = node;
        // *e = node;
        heapSize++;
        upheap(root->parent);
        return true;
*/



/*
//cout << "inserting " << node->key << endl;
        //TreeNode **e =  &from;
        if( !from)
        {
            root = node;
            cout << node->key << " at level " << level << endl;
            heapSize++;
            return true;
        }            
        if( !from->leftChild)
        {
            from->leftChild = node;
            cout << node->key << " at level " << level << endl;
            heapSize++;
            node->parent = from;
            return true;
        }            
        else if ( !from->rightChild)
        {
            from->rightChild = node;
            cout << node->key << " at level " << level << endl;
            heapSize++;
            node->parent = from;
            return true;
        }            
        else if( level < maxHeight(heapSize) )
        {
            if( !(insert(node, from->leftChild, level+1) ) )
                if( !(insert(node, from->rightChild, level+1)) ) 
                    addLevel(node, from); 
            return true;
        }
        else
            return false;
*/