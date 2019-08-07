class UF{
private:
    int count;
    int* id;
    int* sz;
public:
    UF(int n){
        count=n;
        id=new int[n];
        sz=new int[n];
        for(int i=0;i<n;i++)id[i]=i;
        for(int i=0;i<n;i++)sz[i]=1;
    }
    ~UF(){
        delete []id;
    }
    int size(){
        return count;
    }
    bool isConnect(int a,int b){
        return find(a)==find(b);
    }
    int find(int a){
        while(id[a]!=a)a=id[a];
        return a;
    }
    void Union(int a,int b){
        int af=find(a),bf=find(b);
        if(af==bf)return;
        if(sz[af]<sz[bf]){
            id[af]=bf;sz[bf]+=sz[af];
        }else {
            id[bf]=af;sz[af]+=sz[bf];
        }
        count--;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UF uf(N);
        for (int i=0; i<N; ++i)
            for (int j=i; j<N; ++j){
                if (M[i][j])
                    uf.Union(i, j);
            }
        return uf.size();
    }
};
