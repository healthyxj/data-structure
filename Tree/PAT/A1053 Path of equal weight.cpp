#include<stdio.h>
#include<vector>
#include<algorithm>
#define MaxSize 105
using namespace std;

/*
题意：第一行给出总的结点数N，非叶子结点数M，要满足的权重S；
第二行给出了N个结点的权重，最后要按照路径的大小进行输出从根结点到叶结点的路径。
*/

//考虑到最后要输出要按照权值输出，可以在读入的时候就进行排序
struct node{
    int Weight; //表示权重
    vector<int> Child;  //表示指针域
}Node[MaxSize];

bool cmp(int a, int b){
    return Node[a].Weight > Node[b].Weight; //按结点的权重从小到大排序
}

int N, M, S;    //表示总的结点数、非叶结点数和要满足的权重
int path[MaxSize];  //存放递归过程中产生的路径上的结点编号

void DFS(int index, int numNode, int sum){
    //index表示开始访问的结点，numNode表示当前path上的结点数，sum表示path上结点的和
    
    if(sum > S) return ;
    
    if(sum == S){
        if(Node[index].Child.size() != 0) return ;  //没到叶结点，不符合条件
        
        for(int i = 0; i < numNode; i++){
            printf("%d", Node[path[i]].Weight); //用path创造一条路径
            if(i < numNode - 1) printf(" ");
            else printf("\n");
        }
        
        return ;
    }
    
    for(int i = 0; i < Node[index].Child.size(); i++){  //对所有子结点检索
        int child = Node[index].Child[i];   //当前访问结点的第i个孩子结点
        path[numNode] = child;  //将结点child加入到path末尾
        DFS(child, numNode + 1, sum + Node[child].Weight);
    }
    
}

int main(){
    scanf("%d%d%d", &N, &M, &S);
    
    for(int i = 0; i < N; i++){
        scanf("%d", &Node[i].Weight);
    }
    
    int id, k, child;
    for(int i = 0; i < M; i++){
        scanf("%d%d", &id, &k); //读入结点编号、孩子结点的个数
        
        for(int j = 0; j < k; j++){
            scanf("%d", &child);
            Node[id].Child.push_back(child);    //将读入的孩子结点放到后面
        }
        
        sort(Node[id].Child.begin(), Node[id].Child.end(), cmp);    //排序
    }
    
    path[0] = 0;
    
    DFS(0, 1, Node[0].Weight);
    
    return 0;
}
