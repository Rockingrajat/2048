#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int board[4][4];
void initialize(){
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            board[j][k]=0;
        }}
}
bool occupied(int i,int j){
    if(board[i][j]==0) return false;
    else return true;
}
void popnumber(){
    int q=rand()%4;
     int p=rand()%4;
    if(occupied(p,q)) popnumber();
    else board[p][q]=2;
}
void printboard(){
      for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if(board[j][k]==0) cout<<".    ";
            else cout<<board[j][k]<<" ";
        }
        cout<<"\n";
        }
}
void newgame(){
    initialize();
    popnumber();popnumber();
    printboard();
}
void moveblocksleft(){
        for(int i=0;i<4;i++){
            if(board[i][0]==0){
                if(board[i][1]!=0){
                    swap(board[i][0],board[i][1]);
                    if(board[i][2]!=0){
                    swap(board[i][2],board[i][1]);
                    if(board[i][3]!=0)swap(board[i][2],board[i][3]);
                    }
                    else swap(board[i][3],board[i][1]);
                }
                else{
                    if(board[i][2]==0){swap(board[i][3],board[i][0]);}
                    else{
                        swap(board[i][2],board[i][0]);
                        swap(board[i][3],board[i][1]);
                    }
                }
            }
            else if(board[i][1]==0){
                if(board[i][2]==0){swap(board[i][3],board[i][1]);}
                else{
                        swap(board[i][2],board[i][1]);
                        swap(board[i][3],board[i][2]);
                    }
            }
            else if(board[i][2]==0)swap(board[i][3],board[i][2]);


        }

}

void combineleft(){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=0 && board[i][j]==board[i][j+1]) {board[i][j]=2*board[i][j];board[i][j+1]=0;}

            }
    }
}
void moveblocksright(){
        for(int i=0;i<4;i++){
            if(board[i][3]==0){
                if(board[i][2]!=0){
                    swap(board[i][3],board[i][2]);
                    if(board[i][1]!=0){
                    swap(board[i][2],board[i][1]);
                    if(board[i][0]!=0)swap(board[i][0],board[i][1]);
                    }
                    else swap(board[i][0],board[i][2]);
                }
                else{
                    if(board[i][1]==0){swap(board[i][0],board[i][3]);}
                    else{
                        swap(board[i][1],board[i][3]);
                        swap(board[i][0],board[i][2]);
                    }
                }
            }
            else if(board[i][2]==0){
                if(board[i][1]==0){swap(board[i][0],board[i][2]);}
                else{
                        swap(board[i][1],board[i][2]);
                        swap(board[i][0],board[i][1]);
                    }
            }
            else if(board[i][1]==0)swap(board[i][0],board[i][1]);


        }

}
void combineright(){
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(board[i][j]!=0 && board[i][j]==board[i][j-1]) {board[i][j]=2*board[i][j];board[i][j-1]=0;}

            }
    }
}

void moveblocksdown(){
     for(int i=0;i<4;i++){
            if(board[3][i]==0){
                if(board[2][i]!=0){
                    swap(board[3][i],board[2][i]);
                    if(board[1][i]!=0){
                    swap(board[2][i],board[1][i]);
                    if(board[0][i]!=0)swap(board[0][i],board[1][i]);
                    }
                    else swap(board[0][i],board[2][i]);
                }
                else{
                    if(board[1][i]==0){swap(board[0][i],board[3][i]);}
                    else{
                        swap(board[1][i],board[3][i]);
                        swap(board[0][i],board[2][i]);
                    }
                }
            }
            else if(board[2][i]==0){
                if(board[1][i]==0){swap(board[0][i],board[2][i]);}
                else{
                        swap(board[1][i],board[2][i]);
                        swap(board[0][i],board[1][i]);
                    }
            }
            else if(board[1][i]==0)swap(board[0][i],board[1][i]);


        }

}
void moveblocksup(){
     for(int i=0;i<4;i++){
            if(board[0][i]==0){
                if(board[1][i]!=0){
                    swap(board[0][i],board[1][i]);
                    if(board[2][i]!=0){
                    swap(board[2][i],board[1][i]);
                    if(board[3][i]!=0)swap(board[2][i],board[3][i]);
                    }
                    else swap(board[3][i],board[1][i]);
                }
                else{
                    if(board[2][i]==0){swap(board[3][i],board[0][i]);}
                    else{
                        swap(board[2][i],board[0][i]);
                        swap(board[3][i],board[1][i]);
                    }
                }
            }
            else if(board[1][i]==0){
                if(board[2][i]==0){swap(board[3][i],board[1][i]);}
                else{
                        swap(board[2][i],board[1][i]);
                        swap(board[3][i],board[2][i]);
                    }
            }
            else if(board[2][i]==0)swap(board[3][i],board[2][i]);


        }


}
void combineup(){
     for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            if(board[i][j]!=0 && board[i][j]==board[i+1][j]) {board[i][j]=2*board[i][j];board[i+1][j]=0;}

            }
    }
}
void combinedown(){
for(int j=0;j<4;j++){
        for(int i=3;i>0;i--){
            if(board[i][j]!=0 && board[i][j]==board[i-1][j]) {board[i][j]=2*board[i][j];board[i-1][j]=0;}

            }
    }

}
bool win(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==2048) return true;
        }
    }
    return false;
}
bool lost(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0) return false;
        }
    }
    return true;
    }
void instructions(){
    cout<<"n:new game, q:quit, w:up, a:left, s:down, d:right"<<"\n";
}
int main(){
    srand(time(0));
    instructions();newgame();char command;
    while(true){
        cin>>command;
        if(command=='n') newgame();
        else if(command=='q') break;
        else if(command=='a'){ moveblocksleft(); combineleft();moveblocksleft();popnumber();printboard(); }
        else if(command =='s'){moveblocksdown(); combinedown();moveblocksdown();popnumber();printboard(); }
        else if(command =='d'){moveblocksright(); combineright();moveblocksright();popnumber();printboard();}
        else if(command =='w'){moveblocksup(); combineup();moveblocksup();popnumber();printboard();}

        if(win()){cout<<"You won!"<<"\n"<<"Press q to quit or n to start a new game";}
        else if(lost()) {cout<<"No more moves left"<<"\n"<<"Press q to quit or n to start a new game";}
    }

}
