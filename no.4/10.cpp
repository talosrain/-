#include<algorithm>
#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;

int m, s1, s2;      // m是总结点个数，s1,s2用于筛选出最小和第二小的两个数

typedef struct{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;      //动态分配数组存储哈夫曼树

typedef char* HuffmanCode;   //动态分配数组存储哈夫曼编码表

//选出weight最小的两个结点,s1保存最小的，s2保存第二小的
void SelectMin(HuffmanTree HT, int nNode)
{
    int i, j;
    for(i = 1; i <= nNode; i++)
        if(!HT[i].parent)
        {
            s1 = i;
            break;
        }
    for(j = i+1; j <= nNode; j++)
        if(!HT[j].parent)
        {
            s2 = j;
            break;
        }

    for(i = 1; i <= nNode; i++)
        if((HT[i].weight < HT[s1].weight) && (!HT[i].parent) && (s2 != i))
            s1 = i;
    for(j = 1; j <= nNode; j++)
        if((HT[j].weight < HT[s2].weight) && (!HT[j].parent) && (s1 != j))
            s2 = j;
    // 以上只筛选出最小的两个，这里保证s1的weight比s2的小
    if(HT[s1].weight > HT[s2].weight)
    {
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
}

// w[]存放nNode个字符的权值（均大于0），构造哈夫曼树HT，
// 并求出nNode个字符的哈夫曼编码HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode *&HC, int *w, int nNode)
{
    int i, j;
    char *hfcode;
    int p;
    int cdlen;
    if(nNode < 1)
        return;
    m = 2*nNode-1;   //哈夫曼树的结点数，定理公式

    /////////////////////////////以下是求Huffman树的初始化/////////////////////////////
    HT = (HTNode*) malloc ((m+1) *sizeof(HTNode));  //0号单元未用
    for(i = 1; i <= nNode; i++)    //初始化
    {
        HT[i].weight = w[i-1];
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(i = nNode+1; i <= m; i++)
    {
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    /////////////////////////////以下是Huffman树的构建/////////////////////////////
    for(i = nNode+1; i <= m; i++)
    {
        // 建立哈夫曼树
        // 在HT[1..i-1]中选择parent为0且weight最小的两个节点
        // 其序号分别是s1和s2,并且小的是左孩子
        SelectMin(HT, i-1);
        HT[s1].parent = i;
        HT[s2].parent = i;
        //cout << "S1 && S2: " << HT[s1].weight << " " << HT[s2].weight << endl;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }


    /////////////////////////////以下是求Huffman树的编码/////////////////////////////
    /*该方法是从每个叶结点开始上溯，以从后向前的方式生成huffman编码*/
    hfcode = (char *) malloc ( (nNode + 1) * sizeof( char ) );
    hfcode[nNode] = '\0';   //编码以‘\0’结尾
    int start;
    int c;   //c:当前处理节点，p是c的父结点
    for(int i=1; i<=nNode; i++)
    {
        start = nNode;
        for(c=i, p=HT[c].parent; p!=0; c=p,p=HT[p].parent)
        {
            if(c==HT[p].lchild)
                hfcode[--start]='0';
            else if(c==HT[p].rchild)
                hfcode[--start]='1';
        }
        //申请足够存放该节点编码就行，不浪费;
        HC[i] = (char *) malloc ((nNode-start+1) * sizeof(char));
        strcpy(HC[i], &hfcode[start]);
    }
    free(hfcode);}
/*Huffman解码函数
 *HT:Huffman树，w[]:权值数组(从下标0开始)，code[]:要解码的串
 */
void HuffmanDecode(HuffmanTree HT, int w[], char code[])
{
    char *ch = code;
    int i;
    while( *ch != '\0' ){
        //解码一个结点每次都从树根m开始
        for(i=m; HT[i].lchild !=0 && HT[i].rchild != 0; ){
            if( *ch == '0' )
                i = HT[i].lchild;
            else if( *ch == '1' )
                i = HT[i].rchild;
            ++ch;
        }
        //cout<<w[i-1]<<" ";
    }
}

void ru(char ml[],int ok)
{
    for(int i=0;i<ok;i++)
    {cout<<ml[i]<<" ";}
}

int main()
{
    HuffmanTree HT = NULL;   // 哈夫曼树
    HuffmanCode *HC;    // 保存哈夫曼编码
    int *w, nNode, i , i1,ok=0,yy=0;//yy是节点树;   // w记录权值
    double a=0,b=0,c=0,d=0,e=0;
    double aa,bb,cc,dd,ee;
    char ml[100];
    char CodeStr[20]= {0};  //存放编码后的串
    cout<<"输入字符串（a,b,c,d,e组成） "<<endl;

    for(i1=0;;i1++,ok++)
    {
        scanf("%c",&ml[i1]);
        if(ml[i1]=='#')break;if(ml[i1]=='a')a++;if(ml[i1]=='b')b++;if(ml[i1]=='c')c++;if(ml[i1]=='d')d++;if(ml[i1]=='e')e++;
    }
    if(a!=0){yy++;}if(b!=0){yy++;}if(c!=0){yy++;}if(d!=0){yy++;}if(e!=0){yy++;}
    aa=(a/ok)*100; bb=(b/ok)*100; cc=(c/ok)*100; dd=(d/ok)*100; ee=(e/ok)*100;
    nNode=yy;
    HC = (HuffmanCode *) malloc (nNode* sizeof(HuffmanCode));
    w = (int *) malloc (nNode * sizeof(int));

    i=0;if(a!=0){w[i]=aa;i++;}if(b!=0){w[i]=bb;i++;}if(c!=0){w[i]=cc;i++;}if(d!=0){w[i]=dd;i++;}if(e!=0){w[i]=ee;i++;}

    HuffmanCoding(HT, HC, w, nNode);
    cout<<"\n各结点的哈夫曼编码:"<<endl;
    for(i = 1; i <= nNode; i++){
        printf("%2d(%d):%s\n", i, w[i-1], HC[i]);
        strcat(CodeStr, HC[nNode-i+1]); //简单生成一个huffman码串
    }

    cout<<"对哈夫曼编码\""<<CodeStr<<"\"的解码如下:"<<endl;
    HuffmanDecode(HT, w, CodeStr);ru(ml,ok);

    return 0;
}
