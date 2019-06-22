void tree::insert(int num)
{
   treeNode *node, *help ;
   help = root;
   node = new treeNode;
   node -> left = node -> right = NULL;
   node -> key = num;
   if(root == NULL)
      root = node;
    else
    {
      while (help != NULL)
      {
	if(node -> key > help ->key)
	{
	  if (help -> right != NULL)
		help = help -> right ;
	  else {
	      help -> right=node ;
	      break ;
	  }//end of else
	} //end of if
	else  {
	    if (help -> left != NULL )
		   help = help -> left ;
	    else  {
		 help -> left=node ;
		 break ;
	    } //end of else
	}  //end of else
      }//end of while
   }//end else
}
