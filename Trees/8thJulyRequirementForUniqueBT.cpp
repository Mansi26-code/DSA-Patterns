class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here
            return !(a==b ||(a==1&&b==3)||(a==3 && b==1));
		}
};
//here  1 stands for preorder , 2 for inorder, 3 for postorder
//kabhi bhi pre aur post unique tree nhi de skte

//TC and SC=O(1)