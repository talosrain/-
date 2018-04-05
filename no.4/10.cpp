#include<algorithm>
#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;

int m, s1, s2;      // m���ܽ�������s1,s2����ɸѡ����С�͵ڶ�С��������

typedef struct{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;      //��̬��������洢��������

typedef char* HuffmanCode;   //��̬��������洢�����������

//ѡ��weight��С���������,s1������С�ģ�s2����ڶ�С��
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
    // ����ֻɸѡ����С�����������ﱣ֤s1��weight��s2��С
    if(HT[s1].weight > HT[s2].weight)
    {
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
}

// w[]���nNode���ַ���Ȩֵ��������0���������������HT��
// �����nNode���ַ��Ĺ���������HC
void HuffmanCoding(HuffmanTree &HT, HuffmanCode *&HC, int *w, int nNode)
{
    int i, j;
    char *hfcode;
    int p;
    int cdlen;
    if(nNode < 1)
        return;
    m = 2*nNode-1;   //���������Ľ����������ʽ

    /////////////////////////////��������Huffman���ĳ�ʼ��/////////////////////////////
    HT = (HTNode*) malloc ((m+1) *sizeof(HTNode));  //0�ŵ�Ԫδ��
    for(i = 1; i <= nNode; i++)    //��ʼ��
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

    /////////////////////////////������Huffman���Ĺ���/////////////////////////////
    for(i = nNode+1; i <= m; i++)
    {
        // ������������
        // ��HT[1..i-1]��ѡ��parentΪ0��weight��С�������ڵ�
        // ����ŷֱ���s1��s2,����С��������
        SelectMin(HT, i-1);
        HT[s1].parent = i;
        HT[s2].parent = i;
        //cout << "S1 && S2: " << HT[s1].weight << " " << HT[s2].weight << endl;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }


    /////////////////////////////��������Huffman���ı���/////////////////////////////
    /*�÷����Ǵ�ÿ��Ҷ��㿪ʼ���ݣ��ԴӺ���ǰ�ķ�ʽ����huffman����*/
    hfcode = (char *) malloc ( (nNode + 1) * sizeof( char ) );
    hfcode[nNode] = '\0';   //�����ԡ�\0����β
    int start;
    int c;   //c:��ǰ����ڵ㣬p��c�ĸ����
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
        //�����㹻��Ÿýڵ������У����˷�;
        HC[i] = (char *) malloc ((nNode-start+1) * sizeof(char));
        strcpy(HC[i], &hfcode[start]);
    }
    free(hfcode);}
/*Huffman���뺯��
 *HT:Huffman����w[]:Ȩֵ����(���±�0��ʼ)��code[]:Ҫ����Ĵ�
 */
void HuffmanDecode(HuffmanTree HT, int w[], char code[])
{
    char *ch = code;
    int i;
    while( *ch != '\0' ){
        //����һ�����ÿ�ζ�������m��ʼ
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
    HuffmanTree HT = NULL;   // ��������
    HuffmanCode *HC;    // �������������
    int *w, nNode, i , i1,ok=0,yy=0;//yy�ǽڵ���;   // w��¼Ȩֵ
    double a=0,b=0,c=0,d=0,e=0;
    double aa,bb,cc,dd,ee;
    char ml[100];
    char CodeStr[20]= {0};  //��ű����Ĵ�
    cout<<"�����ַ�����a,b,c,d,e��ɣ� "<<endl;

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
    cout<<"\n�����Ĺ���������:"<<endl;
    for(i = 1; i <= nNode; i++){
        printf("%2d(%d):%s\n", i, w[i-1], HC[i]);
        strcat(CodeStr, HC[nNode-i+1]); //������һ��huffman�봮
    }

    cout<<"�Թ���������\""<<CodeStr<<"\"�Ľ�������:"<<endl;
    HuffmanDecode(HT, w, CodeStr);ru(ml,ok);

    return 0;
}
