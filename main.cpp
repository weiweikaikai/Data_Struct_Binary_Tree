#include "tree.h"


int main()
{
	BinTree<char> mytree('#');
	char*VLR="ABCDEFGH";
	char*LVR="CBEDFAGH";
	char*LRV="CEFDBHGA";
	char* str="ABC##DE##F##G#H##";
//	char *str="123##45##6##7#8##";
	char*str1="ABC##DE##F##G#H##";
	BinTree<char> mytree1('#');
	mytree1.CreatBinTree(str1);
	BinTree<char> mytree2('#');
	int select =1;
	while(select)
	{
          cout<<"*****************************************************************\n";
		  cout<<"* [1]CreatBinTree  [2]CreateBinTree_ret    [3]CreatBInTree_str   \n";
		  cout<<"* [4]preOrder_rec  [5]InOrder_rec          [6]postOrder_rec      \n";
		  cout<<"* [7]Size          [8]Height               [9]GetRoot               \n";
		  cout<<"* [10]search_val   [11]search_Adrr         [12]Find_Parent_Val   \n";
		  cout<<"* [13]Find_Pa_Adrr [14]LevelOrder          [15]Equal             \n";
		  cout<<"* [16]Copy         [17] PreOrder_norec     [18]PreOrder_norec2   \n";
		  cout<<"* [19]InOrder_norec [20]Destory            [21]postOrder_norec   \n";
          cout<<"* [22]Print_Leaves  [23]Recover_Tree_pre_in[24]Recover_Tree_in_post\n";
		  cout<<"*****************************************************************\n";
		  cout<<"Please input select:> ";
		  cin>>select;

		  switch(select)
		  {
		  case 1:
			  cout<<"Please input :\n";
			  mytree.CreateBinTree();
			  break;
		  case 2:
			  cout<<"Please input :\n";
			  	mytree.CreateBinTree_ret();
			  break;
		  case 3:
			  mytree.CreatBinTree(str);
			  break;
		  case 4:
			  mytree.preOrder();
			  cout<<endl;
			  break;
		  case 5:
			  	mytree.InOrder();
				 cout<<endl;
			  break;
		  case 6:
			  mytree.postOrder();
			   cout<<endl;
			  break;
		  case 7:
			  cout<<"共有"<<mytree.Size()<<"个节点"<<endl;
			  break;
		  case 8:
			  cout<<"共有"<<mytree.Height()<<"层"<<endl;
			  break;
		  case 9:
			  mytree.Root();
			  break;
		  case 10:
			  cout<<mytree.Search('H')->GetVal()<<endl;
			  break;
		  case 11:
			 cout<<mytree.Search(mytree.Search('H'))->GetVal()<<endl;
			  break;
		  case 12:
				  cout<<mytree.Parent('B')->GetVal()<<endl;
				  break;
		  case 13:
			  cout<<mytree.Parent(mytree.Search('B'))->GetVal()<<endl;
				  break;
		  case 14:
			  mytree.LevelOrder();
			  cout<<endl;
			  break;
		  case 15:
			cout<<mytree.Equal(mytree1)<<endl;
			  break;
		  case 16:
               mytree2.Copy(mytree1);
			   mytree2.preOrder();
			   cout<<endl;
			  break;
			  case 17:
				  mytree.PreOrder_norec();
				  cout<<endl;
				  break;
			  case 18:
				  mytree.PreOrder_norec2();
				  cout<<endl;
				  break;
			  case 19:
				  mytree.InOrder();
				  cout<<endl;
				  break;
		  case 20:
			  mytree.Destroy();
			  break;
		  case 21:
			  mytree.postOrder_norec2();
			  cout<<endl;
			  break;
		  case 22:
			  cout<<"叶子节点有: ";
			  mytree.Print_Leaves();
			  cout<<endl;
			  break;
		  case 23:
			  mytree.Recover_Tree_pre_in(VLR,LVR);
			  break;
		  case 24:
			 mytree.Recover_Tree_in_post(LVR,LRV);
			  break;
		  default:
			  cout<<"thanks using\n";
			  break;
		  }
	}

	return 0;
}