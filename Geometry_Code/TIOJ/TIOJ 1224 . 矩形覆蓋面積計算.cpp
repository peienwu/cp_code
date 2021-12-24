#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0);
#define N 100005
#define M 1000001
#define lld long long
using namespace std;
int n;

struct Node{    //每一個矩陣分成上下兩條邊
    int x1;     //矩形左界x1
    int x2;     //矩形右界x2
    int y;      //矩形y座標（分上下兩邊）
    int val;    //val = ±1(進入代表1、離開代表-1)
    
}arr[2*N];

//seg[i]表示i的左右兩子樹的區間非0的個數
struct node{    //建立線段樹
    int val;    //維護非0個數
    int tag;    //使用tag紀錄區間被覆蓋次數
    
}seg[4*M];

bool cmp(Node a, Node b){
    return a.y<b.y;
}

//對區間[ql,qr)進行加值val
void modify(int cur,int l,int r,int ql,int qr,int val){
    if(r <= l || ql >= r || qr <= l)return;
    if(ql <= l && qr >= r){
        seg[cur].tag += val;
        return;
    }
    int mid = (l+r)/2;
    modify(2*cur,l,mid,ql,qr,val);
    modify(2*cur+1,mid,r,ql,qr,val);
    
    //左右節點如有tag表示被完全覆蓋，直接加上區間大小，否則加上seg[左右子樹]
    seg[cur].val = (seg[2*cur].tag?mid-l:seg[2*cur].val)
                  +(seg[2*cur+1].tag?r-mid:seg[2*cur+1].val);
}

int main(){
    ios;
    memset(arr,0,sizeof(arr));
    memset(seg,0,sizeof(seg));
    
    cin>>n;                                   //依序輸入左右下上：x1,x2,y1,y2
    for(int i=0;i<(n<<1);i+=2){
        int x1,x2,y1,y2;cin>>x1>>x2>>y1>>y2;
        arr[i] = (Node){x1,x2,y1,1};          //插入矩形下邊，帶入val = 1
        arr[i+1] = (Node){x1,x2,y2,-1};       //上邊要val = -1
    }
    stable_sort(arr,arr+(n<<1),cmp);          //依照y座標由小到大排序
    
    int y0 = 0,val = 0;                       //有下而上的枚舉所有水平邊
    lld ans = 0LL;                            //上一條y的座標，計算高，val為矩形結合起來的寬
    for(int i=0;i<(n<<1);i++){                //枚舉2n條y的邊
        ans += (lld)(arr[i].y-y0)*val;        //計算面積（寬*高）
        modify(1,0,M,arr[i].x1,arr[i].x2,arr[i].val);
        y0 = arr[i].y;
        val = seg[1].val;                     //修改後（下一輪）的矩陣寬度
    }
    cout<<ans<<'\n';
}