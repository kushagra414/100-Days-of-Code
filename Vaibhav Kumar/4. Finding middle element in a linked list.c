int Findmiddle(Node *root)
{
   
	struct Node *p = root;
	if(root)
	{
		if(root->next == NULL)
			{
				return root->data;
			}
		else
		{
			while(root&& root->next)
			{
				p = p->next;
				root = root->next->next;
			}
			
			return  p->data;			
			
		}
	}
}