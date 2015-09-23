#pragma once
#include <iostream>
#include<stack>
#include<queue>
using namespace std;

static bool flag=0;
template<class T>
class BinTree;

template<class T>
class BinTreeNode
{
	friend class BinTree<T>;
	public:
	BinTreeNode(T item = T(),BinTreeNode<T>* l=NULL,BinTreeNode<T>* r=NULL):data(item),lc(l),rc(r)
   {

   }
   ~BinTreeNode()
	{

	}
   T GetVal()const
   {
	   return data;
   }
   private:
	   T data;
	   BinTreeNode<T>* lc;
	   BinTreeNode<T>* rc;
};
template<class T>
class BinTree
{
	public:
		struct stknode
		{
			BinTreeNode<T>*ptr;
			bool tag;
		};
typedef struct stknode stknode; 
	
	BinTree():root(NULL)
		{
            
		}
        BinTree(T refer):reference(refer),root(NULL)
		{
            
		}
		void CreateBinTree()
		{
            CreateBinTree(root);
		}
		void CreateBinTree_ret()
		{
			CreateBinTree_ret();
		}
	   void CreatBinTree(const char*str)
		{
			CreatBinTree(root,str);
		}
	   void PreOrder_norec()const//版本一
	   {
		   PreOrder_norec(root);
	   }
	   void PreOrder_norec2()const//版本2
	   {
		   PreOrder_norec2(root);
	   }
	   void InOrder_norec()const
	   {
		   InOrder_norec(root);
	   }

	   void postOrder_norec()
	   {
		   postOrder_norec(root);
	   }
	   void postOrder_norec2()
	   {
		   postOrder_norec2(root);
	   }
		void preOrder()const
		{
            preOrder(root);
		}
		void InOrder()const
		{
            InOrder(root);
		}
		void postOrder()const
		{
            postOrder(root);
		}
		size_t Size()const
		{
           return size(root);  
		}
		size_t Height()const
		{
	        return Height(root);
		}
		BinTreeNode<T> Root()const
		{
             return *root;
		}
		BinTreeNode<T>* LeftChild(BinTreeNode<T> *p)const
		{
               if(p==NULL)
			   {
				   return NULL;
			   }
			   else
			   {
				   return p->lc;
			   }
		}
		BinTreeNode<T>* RightChild(BinTreeNode<T> *p)const
		{
            if(p==NULL)
			{
				return NULL;
			}
			else
			{
				return p->rc;
			}
		}
		BinTreeNode<T>* Search(const T &key)
		{
           return Search(root,key);
		}
		BinTreeNode<T>* Search(BinTreeNode<T>*p)
		{
          return Search(root,p);
		}
		BinTreeNode<T>* Parent(const T &key)
		{
			return Parent(root,key);
		}
		BinTreeNode<T>* Parent(BinTreeNode<T> *p)
		{
			return Parent(root,p);
		}
		void LevelOrder()const
		{
            LevelOrder(root);
		}
		void Print_Leaves()const
		{
            Print_Leaves(root);
		}
		bool Empty()const
		{
			return root==NULL;
		}
		bool Equal(BinTree<T> &bt)
		{
             return Equal(root ,bt.root);
		}
		void Copy(BinTree<T> &bt)
		{
            DestroyBinTree(root);
            root=Copy(bt.root);
		}
	~BinTree()
	{
		if(!flag)
		{
		DestroyBinTree(root);
		}
	}
	void Destroy()
	{
	   	DestroyBinTree(root);
		root=NULL;
		flag=1;
	}
	void Recover_Tree_pre_in(char* VLR,char*LVR)
	{
        Recover_Tree_pre_in(root,VLR,LVR,strlen(VLR));
	}
	void Recover_Tree_in_post(char*LVR,char*LRV)
	{
		int n=strlen(LVR);
       Recover_Tree_in_post(root,LVR,LRV,n);
	}
	protected:
		void postOrder_norec3(BinTreeNode<T>*r)const
		{
			stack<stknode*>st;
			BinTreeNode<T> *p=r;
			stknode*tmp=NULL;
			while(p!=NULL || !st.empty())
			{
				while(p!=NULL)
				{
					stknode*ptmp=new stknode[sizeof(stknode)];
					ptmp->ptr=p;
					ptmp->tag=true;
					st.push(ptmp);
					p=p->lc;
				}
				if(!st.empty())
				{
					tmp=st.top();
					st.pop();
					if(tmp->tag==true)
					{
						tmp->tag=false;
						st.push(tmp);
						p=tmp->ptr->rc;
					}
					else
					{
						cout<<tmp->ptr->data<<" ";
						p=NULL;
					}
				}
			}
		}
		void postOrder_norec2(BinTreeNode<T>*root)  // 后序遍历的非递归     双栈法    
		{      
			stack<BinTreeNode<T>*> s1,s2;    
			BinTreeNode<T>* curr ;           // 指向当前要检查的节点    
			s1.push(root);    
			while(!s1.empty())  // 栈空时结束      
			{    
				curr = s1.top();    
				s1.pop();    
				s2.push(curr);    
				if(curr->lc)    
					s1.push(curr->lc);    
				if(curr->rc)    
					s1.push(curr->rc);    
			}    
			while(!s2.empty())    
			{    
				cout<< s2.top()->data<<" ";    
				s2.pop();    
			}    
}   
		 void Recover_Tree_pre_in(BinTreeNode<T>*&root,char *VLR,char* LVR,size_t n)
		 {
           if(n==0)
		   {
			   return;
		   }
		   else
		   {   int k=0;
			   while(VLR[0] != LVR[k])
			   {
				   ++k;
			   }
			   root= new BinTreeNode<T>(LVR[k]);
			   Recover_Tree_pre_in(root->lc,VLR+1,LVR,k);
			   Recover_Tree_pre_in(root->rc,VLR+k+1,LVR+k+1,n-k-1);
   
		   }
		 }
		 
		 
		void Recover_Tree_in_post(BinTreeNode<T>*&root,char*LVR,char*LRV,size_t n)
		{
            if(n==0)
				return;
			else
			{
				int k=0;
					while(LRV[n-1] != LVR[k])
					{
                       ++k;
					}
			   root=new BinTreeNode<T>(LVR[k]);
			   Recover_Tree_in_post(root->lc,LVR,LRV,k);
               Recover_Tree_in_post(root->rc,LVR+k+1,LRV+k,n-k-1);
			}
		}
		
		void Print_Leaves(BinTreeNode<T>*r)const
		{
			if(r != NULL)
			{
				if(r->lc ==NULL && r->rc == NULL)
				{
					cout<<r->data<<" ";
				}
				Print_Leaves(r->lc);
				Print_Leaves(r->rc);
			}
		}
		void postOrder_norec(BinTreeNode<T>*root)  //非递归后序遍历
		{
			stack<BinTreeNode<T>*> s;
			BinTreeNode<T> *cur;          //当前结点 
			BinTreeNode<T> *pre=NULL;      //前一次访问的结点 
			s.push(root);
			while(!s.empty())
			{
				cur=s.top();
				if( (cur->lc==NULL && cur->rc==NULL)||
					(pre!=NULL && (pre==cur->lc||pre==cur->rc)))
				{
					cout<<cur->data<<" ";//如果当前结点没有孩子结点或者孩子节点都已被访问过 
					s.pop();
					pre=cur;
				}
				else
				{
					if(cur->rc!=NULL)
						s.push(cur->rc);
					if(cur->lc!=NULL)    
						s.push(cur->lc);
				}
			}    
}
		void InOrder_norec(BinTreeNode<T> *r)const
		{
			stack<BinTreeNode<T>*> st;
			BinTreeNode<T>* p=r;
			while(p != NULL || !st.empty())
			{
				if(p != NULL)
				{
					st.push(p);
					p=p->lc;
				}
				else
				{
					p=st.top();
					cout<<p->data<<" ";
					st.pop();
					p=p->rc;
				}
			  }
		}
		void PreOrder_norec2(BinTreeNode<T>*r)const
		{ 
		      stack<BinTreeNode<T>*> st;
			  BinTreeNode<T>* p=r;
			  while(p != NULL || !st.empty())
			  {
				  if(p != NULL)
				  {
                    cout<<p->data<<" ";
					st.push(p);//为了返回时候找到这个节点所以进行压栈
					p=p->lc;
				  }
				  else
				  {
                      p=st.top();
					  st.pop();
					  p=p->rc;
				  }
			  }

		}
		void PreOrder_norec(BinTreeNode<T>*r)const
		{
           stack<BinTreeNode<T>*> st;
		   BinTreeNode<T>* p=NULL;
		   st.push(r);

		   while(!st.empty())
		   {
			   p=st.top();
			   st.pop();
			   cout<<p->data<<" ";
			   if(p->rc != NULL)
			   {
				   st.push(p->rc);
			   }
			   if(p->lc != NULL)
			   {
				   st.push(p->lc);
			   }
		   }

		}
		  BinTreeNode<T>* Copy(BinTreeNode<T>*r)
		  {
                 if(r== NULL)
					 return NULL;
				 else
				 {
                 BinTreeNode<T> *t=new BinTreeNode<T>(r->data);
				 t->lc = Copy(r->lc);
			     t->rc=Copy(r->rc);
				 return t;
				 }
		  }

	    bool Equal(BinTreeNode<T>*r1,BinTreeNode<T>*r2)
		{
			if(r1 == NULL && r2 == NULL)
			{
				return true;
			}
			return (r1 != NULL && r2 != NULL && r1->data==r2->data 
				&& Equal(r1->lc,r2->lc)
				&&Equal(r1->rc,r2->rc));	
		}
		void DestroyBinTree(BinTreeNode<T>*r)
		{
           if(r != NULL)
		   {
            DestroyBinTree(r->lc);
			DestroyBinTree(r->rc);
			delete r;
			r=NULL;
		   }

		}
	  BinTreeNode<T>* Parent(BinTreeNode<T>*r,BinTreeNode<T>*p)
	{
            if((r == NULL) || (p==NULL))
			{
				return NULL;
			}
			if((r->lc == p) || (r->rc ==p))
			{
               return r;
			}

			BinTreeNode<T>*ptmp;
			if((ptmp=Parent(r->lc,p)) != NULL)
			{
              return ptmp;
			}
            else
			{
              return Parent(r->rc,p);
			}
	}
		BinTreeNode<T>* Parent(BinTreeNode<T>*r,const T &key)
		{
			if(r==NULL || r->data ==key)
			{
                return NULL;
			}
			if((r->lc != NULL && r->lc->data == key) || (r->rc!=NULL && r->rc->data == key))
			{
				return r;
			}
			BinTreeNode<T>* ptmp;
			if((ptmp = Parent(r->lc,key)) != NULL)
			{
				return ptmp;
			}
			else
			{
				return Parent(r->rc,key);
			}
			
		}
		BinTreeNode<T>* Search( BinTreeNode<T>*r,const BinTreeNode<T>*p)
		{
			if(r==NULL || p==NULL)
			{
				return NULL;
			}
			if(r == p)
			{
				return r;
			}
			BinTreeNode<T>*ptmp;
			if((ptmp = Search(r->lc,p) )!= NULL)
			{
				return ptmp;
			}
			else
			{
				return Search(r->rc,p);
		   }
		}
		BinTreeNode<T>* Search( BinTreeNode<T>*r,const T &key)
		{
           if(r==NULL)
		   {
			   return NULL;
		   }
		   if(r->data== key)
		   {
			   return r;
		   }
		   BinTreeNode<T>*ptmp;
		   if((ptmp = Search(r->lc,key)) != NULL)
		   {
			   return ptmp;
		   }
		   else
		   {
			   return Search(r->rc,key);
		   }
		}
		size_t Height(const BinTreeNode<T> *t)const
		{
			if(t== NULL)
			{
				return 0;
			}
			else
			{
				size_t lcount,rcount;
				lcount = Height(t->lc);
				rcount = Height(t->rc);
				return 1+(lcount > rcount ? lcount :rcount);
				
			}
		
		}
	size_t size(const BinTreeNode<T>*t)const
		{
			if(t==NULL)
			{
				return 0;
			}
			else
			{
				return 1+ size(t->lc)+size(t->rc);
			}
		}
       void CreateBinTree(BinTreeNode<T>*&t)
	   {
            T item=T();
		    cin>>item;
			if(item == reference)
			{
				t=NULL;
			}
			else
			{
				t= new BinTreeNode<T>(item);
				CreateBinTree(t->lc);
				CreateBinTree(t->rc);
			}
	   }
	 void CreatBinTree(BinTreeNode<T> *&t, const char *&str)
	   {
		 // static const char* Str =str;
		   if(*str == '#' || *str == '\0')
		   {
			   t=NULL;
		   }
		   else
		   {
			   t= new BinTreeNode<T>(*str);
			   CreatBinTree(t->lc,++str);
			   CreatBinTree(t->rc,++str);
		   }
 }

	 BinTreeNode<T>* CreatBinTree_ret()
	 {
		 BinTreeNode<T> *t;
		 T item;
		 cin>>item;
		 if(item == reference)
		 {
			 t==NULL;
		 }
		 else
		 {
			 t= new BinTreeNode<T>(item);
			 t->lc=CreatBinTree_ret();
			 t->rc=CreatBinTree_ret();
			 return t;
		 }
	 }
      void LevelOrder(BinTreeNode<T>*r)const
		{
             if(r == NULL)
				 return;
			 queue<BinTreeNode<T>*> Q;
			 BinTreeNode<T> *p;
			 Q.push(r);
			 while(!Q.empty())
			 {
				   p=Q.front();
                   Q.pop();
				   cout<<p->data<<" ";
				   if(p->lc != NULL)
				   {
					   Q.push(p->lc);
				   }
				   if(p->rc != NULL)
				   {
					   Q.push(p->rc);
				   }
				   
			 }
		}
	   void preOrder(const BinTreeNode<T>*t)const
	   {
            if(t!=NULL)
			{
            cout<<t->data<<" ";
            preOrder(t->lc);
			preOrder(t->rc);
			}
	   }
	   void InOrder(const BinTreeNode<T>*t)const
	   {
		   if(t!=NULL)
		   {
			   InOrder(t->lc);
			   cout<<t->data<<" ";
			   InOrder(t->rc);
			}
       
	   }
	   void postOrder(const BinTreeNode<T>*t)const
	   {
		   if(t!=NULL)
		   {
			   postOrder(t->lc);
			   postOrder(t->rc);
			   cout<<t->data<<" ";
			}
	   }
	private:
		BinTreeNode<T>* root;
		T reference;
};
