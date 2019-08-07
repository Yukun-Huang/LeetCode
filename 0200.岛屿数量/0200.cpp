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
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        UF uf(nr*nc);
        int zero_cnt = 0;
        for (int r = 0; r < nr; ++r)
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    if (r - 1 >= 0 && grid[r-1][c] == '1')
                        uf.Union(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1')
                        uf.Union(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1')
                        uf.Union(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1')
                        uf.Union(r * nc + c, r * nc + c + 1);
                }
                else
                    zero_cnt++;
            }
        return uf.size() - zero_cnt;
    }
};
