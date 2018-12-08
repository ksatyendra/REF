#include<iostream>
#include<cstdlib>
using namespace std;
class btree
{ public:
  struct node
  {
    int count;
    int key[2d];
    node  *ptrs[2*d+1];
    
  }*root;
  btree(int order)
  {
    d=order;
    root=NULL;
  }
  int d;
  void insert(int val);
  int setval( int val, node *n, int *p, node **c ) ;
  static node * search ( int val, node *root, int *pos ) ;
	static int searchnode ( int val, node *n, int *pos ) ;
	void fillnode ( int val, node *c, node *n, int k ) ;
	void split ( int val, node *c, node *n,
				int k, int *y, node **newnode ) ;
  static void display ( btnode *root ) ;
};
  
 void btree::insert(int val)
 {
  int i ;
	btnode *c, *n ;
	int flag ;

	flag = setval ( val, root, &i, &c ) ;
	if ( flag )
	{
		n = new btnode ;
		n -> count = 1 ;
		n -> value[1] = i ;
		n -> child[0] = root ;
		n -> child[1] = c ;
		root = n ;
	}
}
