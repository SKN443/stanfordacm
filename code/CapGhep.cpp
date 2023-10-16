#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5;
const int NoMatch = -1;

int nx, ny, m; //So X_dinh, so Y_dinh va so canh
int match[maxN]; //match[y] = chi so X_dinh ghep voi y ? Y, = NoMatch neu y chua ghep
int visited, lab[maxN]; //danh dau: lab[y] khac visited <-> y chua thawm
bool found; //Cowf bao tim ra duong tang
vector<int> adj[maxN]; //adj[x]: Danh sach chi so cac Y_dinh ke voi x
vector<int> S; //Danh sach cac X_dinh chua ghep

void Enter() //Nhap du lieu
{
    cin >> nx >> ny >> m;
    while (m-- > 0)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void Init() //Khoi tao bo ghep rong
{
    fill(match, match + ny, NoMatch); //moi Y_dinh chua ghep
    S.reserve(nx);
    for (int x = 0; x < nx; ++x) S.push_back(x); //S chuwsa cac X_dinh chua ghep
}

void DFS(int x) //Thuat toan DFS tu x
{
    for (int y: adj[x]) //Xet cac Y_dinh ke x
        if (lab[y] != visited) //y chua thawm
        {
            lab[y] = visited; //Danh dau thawm y
            if (match[y] == NoMatch) //y chua ghep
                found = true; //tim ra duong tang
            else
                DFS(match[y]); //DFS tiep
            if (found) //Da~ tim ra duong tawng
            {
                match[y] = x; //Cho x ghep voi y
                return; //Thoat day chuyen de quy
            }
        }
}

void Solve()
{
    vector<int>::size_type oldsize;
    fill(lab, lab + ny, 0);
    visited = 0;
    do
    { //Mot pha xu ly
        ++visited; //Cac Y_dinh deu chua thawm, visited khac lab[0...ny)
        oldsize = S.size(); //Luu lai so luong X_dinh chua ghep
        for (int i = S.size() - 1; i >= 0; --i) //Duyet nguoc vector S
        {
            found = false; //Dat cowf bao chua tim ra duong tang
            DFS(S[i]); //Thu tim duong tang xuat phat tu S[i] va tang cap
            if (found) //Neu tim thay, loai S[i] khoi S
            {
                S[i] = S.back();
                S.pop_back();
            }
        }
    }
    while (oldsize != S.size());
}
void Print() //In ket qua
{
    for (int y = 0; y < ny; ++y)
        if (match[y] != NoMatch)
            cout << "x[" << match[y] << "] - y[" << y << "]\n";
}
int main()
{
    Enter();
    Init();
    Solve();
    Print();
}
