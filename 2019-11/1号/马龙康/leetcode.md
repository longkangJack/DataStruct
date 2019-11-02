# leetcode

给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal

```c
int size(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return size(root->left)+size(root->right)+1;
}
void  _preorderTraversal(struct TreeNode *root,int *result,int *i)
{
    if(root!=NULL)
    {
        result[*i] = root->val;
        (*i)++;
         _preorderTraversal(root->left,result,i);
         _preorderTraversal(root->right,result,i);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int n = size(root);
    int *result = (int*)malloc(sizeof(int)*n);
    *returnSize = n;
    int i = 0;
    _preorderTraversal(root,result,&i); 
    return result;
}
```

