//ע�⣡vector����ͨ�����һ����Ҫ������Ϊ��������ʱ����ͨ���鰴���������ݼ�����ַ���ݣ� ��vector �������������൱�ڰ�ֵ���ݣ�
//�������ϣ���������ڶ�vector���޸��ں���ִ���������Ч�� ��vector�谴 ���� ���� ��ַ ���ݣ� �β����ͷֱ�Ϊ vector<T> & �� vector<T> *
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
 
typedef struct BinNode{
    int data;
    BinNode * lc;
    BinNode * rc;
    BinNode(int d, BinNode *l = NULL, BinNode *r = NULL):
        data(d), lc(l), rc(r){}
}BinNode, * BST;
 
void Init_Array(int *, int);
BST Init_BST(int *, int);
bool Compare_BST(BST, BST);
void preorder(BST, std::vector<int>&);//ǰ��ɼ�������data���δ���vector��
void inorder(BST, std::vector<int>&);//����ɼ�������data���δ���vector��
bool comp_vector(vector<int>, vector<int>);//�Ƚ�����vector�ĸ�Ԫ���Ƿ�˳����ȣ�ȫ��ȷ���true�����򷵻�false
 
int main()
{
    int N, L;
    vector<bool> YorN;
    while(true){
        cin >> N;
        if(N == 0)
            break;
        cin >> L;
 
        int a[N];
        Init_Array(a, N);
        int b[L][N];
        for(int j = 0; j < L; ++j){
            Init_Array(b[j],N);
            //���ڶ�ά����b[row][column], b[row]�������൱��һά�����������
        }
 
        BST bst_tree = Init_BST(a, N);//��ʼ����һ��BST
        BST bst_comp[L];//����L�����ڱȽϵ�BST
        for(int j = 0; j < L; ++j){
            bst_comp[j] = Init_BST(b[j], N);
            if(Compare_BST(bst_tree, bst_comp[j]))//�ж��������Ƿ����
                YorN.push_back(true);
            else
                YorN.push_back(false);
        }
    }
    vector<bool>::iterator it;
    for(it = YorN.begin(); it != YorN.end(); it++){
        if((*it) == true)
            cout << "Yes";
        else
            cout << "No";
        if(it+1 != YorN.end())
            cout << endl;
    }
    return 0;
}
 
void Init_Array(int *arr, int n)
{
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}
 
BST Init_BST(int *a, int n)
{
    BST T = new BinNode(a[0]);
    BinNode * p = T;//p���ڶ�λ������λ��
    int e;//�µ�data
    for(int k = 1; k < n; ++k){
        e = a[k];
 
        while(true){
            if(p->data > e){
                if(p->lc)
                    p = p->lc;
                else{
                    p->lc = new BinNode(e);
                    break;
                }
            }
            else if(p->data < e){
                if(p->rc)
                    p = p->rc;
                else{
                    p->rc = new BinNode(e);
                    break;
                }
            }
            else{//ÿ��data���죬�����������else��Զ���ᱻִ��
                cout << "p->data == e\n";
                getchar();
            }
        }
        p = T;
    }
    return T;
}
 
bool Compare_BST(BST T1, BST T2)
{
    vector<int> v1_pre;
    vector<int> v2_pre;
    vector<int> v1_in;
    vector<int> v2_in;
    preorder(T1, v1_pre);
    preorder(T2, v2_pre);
    inorder(T1, v1_in);
    inorder(T2, v2_in);
    if(comp_vector(v1_pre, v2_pre) && comp_vector(v1_in, v2_in))
    //ǰ�������ȷ��Ψһһ����
        return true;
    else
        return false;
}
void preorder(BST bst,  vector<int> &vec_pre)
{
    if(bst){
        vec_pre.push_back(bst->data);
        preorder(bst->lc, vec_pre);
        preorder(bst->rc, vec_pre);
    }
}
void inorder(BST bst,  vector<int> &vec_in)
{
    if(bst){
        inorder(bst->lc, vec_in);
        vec_in.push_back(bst->data);
        inorder(bst->rc, vec_in);
    }
}
bool comp_vector(vector<int> v1, vector<int> v2)
{
    if(v1.size() != v2.size())
        return false;
    for(unsigned int i = 0; i < v1.size(); ++i)
        if(v1[i] != v2[i])
            return false;
    return true;
}