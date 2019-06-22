void tree::deleteNode(int item)
{
  int found;
  treeNode *x, *parent, *xSucc, *subtree;
  search2(item, &found, &x, &parent);
  if(!found)
  {
      cout << "item not found in BST.";
      return;
  }
  if(x -> left != NULL && x -> right != NULL)
  {    //node has two children
       //Find x's successor and its parent
       xSucc = x -> right;
       parent = x;
       while(xSucc -> left != 0)  //descend left
       {
	  parent = xSucc;
	  xSucc = xSucc -> left;
       }
       //Move contents of xSucc to x and change x
       //to point to successor, wich will be deleted.
       x -> key = xSucc -> key;
       x = xSucc;
  }//end of if
  //Now proceed with case where node has 0 or 1 child
  subtree = x -> left;   //point to a subtree of x
  if(subtree == NULL)
     subtree = x -> right;
  if(parent == NULL)     //root being deleted
      root = subtree;
  else if(parent -> left == x) //left child of parent
      parent -> left = subtree;
  else           //right child of parent
      parent -> right = subtree;
  delete x;
} //end of deleteNode()
//********************
void tree::search2(int item, int *found,
	     treeNode **locptr, treeNode **parent)
{
   *locptr = root;
   *parent = NULL;
   *found = 0;
   for(;;)
   {
       if((*found) || *locptr == NULL)
	  return;
       if(item < (*locptr) -> key)    //descend left
       {
	  *parent = *locptr;
	  *locptr = (*locptr) -> left;
       }
       else if(item > (*locptr) -> key) //descend right
       {
	  *parent = *locptr;
	  *locptr = (*locptr) -> right;
       }
       else
	  (*found) = 1;
   }
}
