#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

struct idd
{
    char id[7];
};

typedef struct _Student
{
    char name[51];          // 姓名
    char id[7];             // 学号，可以以0开头，定长6位
    int score;              // 成绩，[0,100]之间
    struct _Student *left;  // 左子树
    struct _Student *right; // 右子树
} STUDENT;

int compare(STUDENT *a, STUDENT *b)
{
    // 比较函数，a>b则返回正数，a==b返回0，a<b返回负数
    return strcmp(a->id, b->id); // 题目保证不同的学生会有不同的id
}

void insert(STUDENT *root, STUDENT *new_one) // 插入新的节点
{
    STUDENT *p = root;
    while (true)
    {
        if (compare(p, new_one) < 0)
        {
            if (p->right != nullptr)
            {
                p = p->right;
            }
            else
            {
                p->right = new_one;
                break;
            }
        }
        else
        {
            if (p->left != nullptr)
            {
                p = p->left;
            }
            else
            {
                p->left = new_one;
                break;
            }
        }
    }
}

void print_stu(STUDENT *x) //输出节点信息
{
    cout << x->name << " " << x->id << " " << x->score << endl;
}

void print_tree(STUDENT *root) //先序遍历，输出全树
{
    if (root->left != nullptr)
    {
        print_tree(root->left);
    }
    print_stu(root);
    if (root->right != nullptr)
    {
        print_tree(root->right);
    }
}

tuple<STUDENT *, int> search(idd id, STUDENT *root) //返回tuple的第一个为要找的节点，找不到就是nullptr。第二个int类型的是找了几次
{
    STUDENT *res = root;
    int cnt{1};
    while (res != nullptr)
    {
        if (strcmp(id.id, res->id) < 0)
        {
            res = res->left;
            cnt++;
        }
        else if (strcmp(id.id, res->id) == 0)
        {
            return tuple<STUDENT *, int>(res, cnt);
        }
        else
        {
            res = res->right;
            cnt++;
        }
    }
    cnt--; //最后一次不算，因此减去1
    return tuple<STUDENT *, int>(nullptr, cnt);
}

int main()
{
    int n, m;
    cin >> n >> m;
    STUDENT *root;
    STUDENT *new_one;
    root = new STUDENT;
    root->left = root->right = nullptr;
    cin >> root->name >> root->id >> root->score;
    for (int i = 2; i <= n; ++i)//插入后续节点
    {
        new_one = new STUDENT;
        new_one->left = new_one->right = nullptr;
        cin >> new_one->name >> new_one->id >> new_one->score;
        insert(root, new_one);
    }
    print_tree(root);
    idd id;
    tuple<STUDENT *, int> found;
    for (int i = 1; i <= m; ++i)
    {
        cin >> id.id;
        found = search(id, root);
        cout << id.id;
        cout << " " << get<1>(found) << " ";
        if (get<0>(found) == nullptr)
        {
            cout << "NOT FOUND";
        }
        else
        {
            cout << (get<0>(found))->score;
        }
        cout << endl;
    }
}