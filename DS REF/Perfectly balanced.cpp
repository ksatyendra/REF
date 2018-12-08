# include <iostream.h>

struct Tree
{
  Tree * left;
  Tree * right;
  int element;
  int height;
};

int i=0;
class avl
{
      Tree* root;


      public:

      avl()
      {
           root=NULL;
      }

     int height(Tree *t)
     {
      if (t == NULL)
        return -1;
      else
        return t->height;
     }

     Tree *find(int elem, Tree *t)
     {
      if (t == NULL)
        return NULL;

      if (elem < t->element)
        return find(elem, t->left);
      else if (elem > t->element)
        return find(elem, t->right);
      else
        return t;
     }

     Tree *find_min(Tree *t)
     {
       if (t == NULL)
         return NULL;
       else if (t->left == NULL)
         return t;
       else
         return find_min(t->left);
     }


     Tree *find_max(Tree *t)
     {
       if (t == NULL)
         return NULL;
       else if (t->right == NULL)
         return t;
       else
         return find_max(t->right);
     }


     void insert(int value)
    {
     root=insert(value,root);
     i++;
    }

    Tree* insert(int value, Tree * &t)
    {
       Tree * p;
       if (t == NULL)
       {
          p= new Tree;
         if (p == NULL)
	        return t;

         p->element = value;
         p->height = 0;
         p->left = p->right = NULL;
         return p;
       }
        else if (value < t->element)
       {
         t->left = insert(value, t->left);
         if((i%2)!=0)
         {if (height(t->left) - height(t->right) == 2)
         {
           if (value < t->left->element)
             t = single_rotation_with_left(t);
           else
             t = double_rotation_with_left(t);
          }
        }
        }
        else if (value > t->element)
        {
          t->right = insert(value, t->right);
          if((i%2)!=0)
          {
          if (height(t->right) - height(t->left) == 2)
          {
             if (value > t->right->element)
               t = single_rotation_with_right(t);
             else
                t = double_rotation_with_right(t);
           }
         }
         }
         t->height = MAX(height(t->left), height(t->right)) + 1;
            return t;
       }

       int MAX(int x, int y)
      {
         if(x>y)
           return x;
         else
           return y;
       }


       void remove(int value)
       {
          remove(value,root);
        }

        Tree * remove(int value, Tree * t)
        {

           Tree * x;
           Tree *p;

           if (t==NULL) return NULL;

           if (value < t->element)
           {
              t->left = remove(value, t->left);

              if (height(t->right) - height(t->left) >= 2)
              {
                 if (t->left && (value < t->left->element))
                       t = double_rotation_with_right(t);
                 else
                      t = single_rotation_with_right(t);

              }
            }
            else if (value > t->element)
            {
               t->right = remove(value, t->right);

               if (height(t->left) - height(t->right) >= 2)
               {
                  if (t->right && (value > t->right->element))
                       t = double_rotation_with_left(t);
                  else
                       t = single_rotation_with_left(t);
                }

              }
             else if (t->left && t->right)
             {
                 p= find_min(t->right);
                 t->element = p->element;
                 t->right = remove(t->element, t->right);
             }
             else
             {
                p = t;
                if (t->left == NULL)
                   t = t->right;
                else if (t->right == NULL)
                   t = t->left;
                delete(p);
                p= NULL;
              }

             return t;
       }


      Tree *single_rotation_with_left(Tree *k2)
     {
         Tree *k1;

         k1 = k2->left;
         k2->left = k1->right;
         k1->right = k2;

         k2->height = MAX(height(k2->left), height(k2->right)) + 1;
         k1->height = MAX(height(k1->left), height(k2->right)) + 1;

         return k1;
      }


      Tree *single_rotation_with_right(Tree *k2)
      {
         Tree *k1;

         k1 = k2->right;
         k2->right = k1->left;
         k1->left = k2;

         k2->height = MAX(height(k2->left), height(k2->right)) + 1;
         k1->height = MAX(height(k1->right), height(k2->left)) + 1;
         return k1;
      }


      Tree *double_rotation_with_left(Tree *k3)
      {
          k3->left = single_rotation_with_right(k3->left);
          return single_rotation_with_left(k3);
      }


      Tree *double_rotation_with_right(Tree *k3)
      {
          k3->left = single_rotation_with_left(k3->right);
          return single_rotation_with_right(k3);
      }


      void display(Tree* &t)
      {
          if(t!=NULL)
          {
              display(t->left);
              cout<<t->element;
              display(t->right);
          }
      }


      void display()
      {
              display(root);
      }

     void preorder()
     {
      priorder(root);
     }

     void priorder(Tree *&node)
     {
     if(node!=NULL)
      {
      cout<<node->element;
      priorder(node->left);
      priorder(node->right);
      }
     else return;
     }

};


int main()
{
 int val;
 int x;
 avl a;
 char c;
 do
{
cout<<"\nEnter: "<<endl;
cout<<"      1 Insert"<<endl;
cout<<"      2 Inorder traversal"<<endl;
cout<<"      3 Preorder traversal"<<endl;
cout<<"      4 Deletion"<<endl;
cin>>x;
switch(x)
{
 case 1: cout<<"Enter value to insert: ";
         cin>>val;
         a.insert(val);
         break;
 case 2: a.display();
         break;
 case 3: a.preorder();
         break;
 case 4: cout<<"Enter value to remove: ";
         cin>>val;
         a.remove(val);
         break;
 default: cout<<"Wrong Choice"<<endl;
}
cout<<"Do you wish to continue: ";
cin>>c;
}
while(c=='y');
}
