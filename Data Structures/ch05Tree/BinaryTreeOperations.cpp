#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void storeleft(TreeNode *t, vector<int> &v)
{
    if (t == NULL || t->left == NULL)
        return;
    storeall(t->left, v);
}

void storeall(TreeNode *t, vector<int> &v)
{
    if (t == NULL)
        return;
    storeall(t->left, v);
    v.push_back(t->val);
    storeall(t->right, v);
}

int maxleaf(TreeNode *t)
{
    if (t == NULL)
        return -999999;
    if ((t->left == NULL) && (t->right == NULL))
        return t->val;
    int leftmax = maxleaf(t->left);
    int rightmax = maxleaf(t->right);
    if (leftmax >= rightmax)
        return leftmax;
    else
        return rightmax;
}

int kth(TreeNode *root, int &k)
{
    if (root == nullptr || k == 0)
        return 0;
    int leftSum = kth(root->left, k);

    if (k > 0)
    {
        leftSum += root->val;
        k--;
    }
    int rightSum = kth(root->right, k);
    return leftSum + rightSum;
}

int distance(TreeNode *t, int val1, int val2)
{
    int d = 0;
    TreeNode *tmp = t, *tmp2 = t;
    if (t == NULL)
        return 0;
    while (tmp != NULL)
    {
        tmp = tmp->left;
        d++;
        if (tmp->val == val1)
            break;
        else if (val1 < tmp->val)
        {
            tmp = tmp->left;
            d++;
        }
        else
        {
            tmp = tmp->right;
            d++;
        }
    }
    while (tmp2 != NULL)
    {
        tmp2 = tmp2->right;
        d++;
        if (tmp2->val == val2)
            break;
        else if (val1 < tmp2->val)
        {
            tmp2 = tmp2->left;
            d++;
        }
        else
        {
            tmp2 = tmp2->right;
            d++;
        }
    }
    return d;
}

int main()
{
    int k = 4;
    vector<int> leftValues;
    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(35);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->left->left = new TreeNode(20);
    root->left->right->left = new TreeNode(38);
    root->left->right->right = new TreeNode(45);
    root->right->right = new TreeNode(70);

    storeleft(root, leftValues);
    cout << "Left-side values: ";
    for (int val : leftValues)
        cout << val << " ";
    cout << endl;
    cout << maxleaf(root) << endl;
    cout << kth(root, k) << endl;
    return 0;
}