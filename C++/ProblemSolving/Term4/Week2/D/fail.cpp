#include<bits/stdc++.h>
using namespace std;
#define maxn 505
int N, M;
bool is_trans = 0;
struct point{
    int x, y;
};
struct range{
    point bottom, top;
};
point UP = {0, 1}, DOWN = {0, -1}, LEFT = {-1, 0}, RIGHT = {1, 0};
point start;
bool mark[maxn][maxn];
void pt_print(point P, bool trans);
void rec_move(point st, point ed, point dir, range R);
bool try_move(point st, point dir, range R);
void step_move(point &st, point dir);
bool is_arrive(point p1, point p2);
point pt_add(point p1, point p2);
void turn_move(point &st, point ed, point &dir, point target_dir, range R);
void Solve();
bool is_margin(point p);
range get_range(point p, int wh);
enum{LD, LU, RD, RU};

int main(){
    cin >> N >> M;
    cin >> start.x >> start.y;
    assert(start.x <= M - 1 && start.y <= N - 1);
    Solve();
}

void Solve(){
    point S1, S2, S3, S4;
    point E1, E2, E3, E4;
    
    if (N % 2 != 0){
        is_trans = 1;
        swap(start.x, start.y);
        swap(N, M);
    }
    if (!is_margin(start)){
        if (start.y & 1){
            S1 = start;             E1 = {S1.x, 0};
            S2 = pt_add(E1, RIGHT); E2 = {S2.x, S1.y};
            S3 = pt_add(E2, UP);    E3 = {S2.x, N - 1};
            S4 = pt_add(E3, LEFT);  E4 = {S4.x, S3.y};

            assert(is_arrive(pt_add(E4, DOWN), S1));
            rec_move(S1, E1, LEFT,  get_range(S1, LD));
            rec_move(S2, E2, RIGHT, get_range(E2, RD));
            rec_move(S3, E3, RIGHT, get_range(S3, RU));
            rec_move(S4, E4, LEFT,  get_range(E4, LU));
        }
        else {
            S1 = start;             E1 = {S1.x, N - 1};
            S2 = pt_add(E1, RIGHT); E2 = {S2.x, S1.y};
            S3 = pt_add(E2, DOWN);  E3 = {S3.x, 0};
            S4 = pt_add(E3, LEFT);  E4 = {S4.x, S3.y};

            assert(is_arrive(pt_add(E4, UP), S1));
            rec_move(S1, E1, LEFT,  get_range(S1, LU));
            rec_move(S2, E2, RIGHT, get_range(E2, RU));
            rec_move(S3, E3, RIGHT, get_range(S3, RD));
            rec_move(S4, E4, LEFT,  get_range(E4, LD));
        }
    }

}

range get_range(point p, int wh){
    if (wh == LD){
        return {{0, 0}, p};
    }
    else if (wh == RU){
        return {p, {M - 1, N - 1}};
    }
    else if (wh == LU){
        return {{0, p.y}, {p.x, N -1}};
    }
    else if (wh == RD){
        return {{p.x, 0}, {M - 1, p.y}};
    }
    assert(0);
    return {};
}
bool is_margin(point p){
    return p.x == 0 || p.y == 0 || p.x == M - 1 || p.y == N - 1;
}
point pt_add(point p1, point p2){
    point ans = {p1.x + p2.x, p1.y + p2.y};
    return ans;
}
bool is_arrive(point p1, point p2){
    return p1.x == p2.x && p1.y == p2.y;
}
void step_move(point &st, point dir){
    st.x += dir.x;
    st.y += dir.y;
    mark[st.x][st.y] = 1;
    pt_print(st, is_trans);
}

bool try_move(point st, point dir, range R){
    point nt = {st.x + dir.x, st.y + dir.y};
    return nt.x >= R.bottom.x && nt.y >= R.bottom.y && nt.y <= R.top.y && nt.x <= R.top.x;
}

void pt_print(point P, bool trans){
    if (trans == 0){
        cout << P.x << " " << P.y << endl;
    }
    else
        cout << P.y << " " << P.x << endl;
}

void turn_move(point &st, point ed, point &dir, point target_dir, range R){
    point old_dir = dir;
    if (is_arrive(dir, LEFT) || is_arrive(dir, RIGHT)){
        dir = target_dir;
        step_move(st, dir);
        dir = is_arrive(old_dir, LEFT) ? RIGHT : LEFT;
    }
    else{
        assert(0);
    }

}

void rec_move(point st, point ed, point dir, range R){
    point t_dir;
    if (ed.y > st.y) t_dir = UP;
    else t_dir = DOWN;
    pt_print(st, is_trans);
    while (!is_arrive(st, ed)){
        // pt_print(st, is_trans);
        if (try_move(st, dir, R)){
            step_move(st, dir);
        }
        else{
            turn_move(st, ed, dir, t_dir, R);
        }
    }
    // pt_print(ed, is_trans);
}