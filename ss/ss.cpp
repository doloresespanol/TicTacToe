#include <iostream>

using namespace std;

int spot, playerd,wygrana=0,draw,draw_fr=0;
string t[9];
string player = "X";

void create_board() {
    for (int i = 0; i < 9; i++) {
        t[i] = "_";
    }
}

void board() {
    cout << "------" << endl;
    for (int i = 0; i < 9; i++) {
        if ((i + 1) % 3 == 0) {
            cout << t[i] << "|" << endl << "------" << endl;
        }
        else {
            cout << t[i] << "|";
        }
    }
    cout << endl;

}

void player_move() {
    cout << endl << "Player " << player << " turn:" << endl;
    cin >> spot;
    if (t[spot - 1] == "X" || t[spot - 1] == "O") {
        cout << "Invalid move" << endl;
    }
    else {
        switch (spot) {
        case 1:
            t[0] = player;
            break;
        case 2:
            t[1] = player;
            break;
        case 3:
            t[2] = player;
            break;
        case 4:
            t[3] = player;
            break;
        case 5:
            t[4] = player;
            break;
        case 6:
            t[5] = player;
            break;
        case 7:
            t[6] = player;
            break;
        case 8:
            t[7] = player;
            break;
        case 9:
            t[8] = player;
            break;

        default: "Invalid move";
        }
        if (t[0] != "_" && t[0] == t[3] && t[0] == t[6] || t[1] != "_" && t[1] == t[4] && t[1] == t[7] || t[2] != "_" && t[2] == t[5] && t[2] == t[8]) {
            cout << endl << "Player " << player << " Wins!" << endl << endl;
            wygrana = 1;
        }
        else if (t[0] != "_" && t[0] == t[4] && t[0] == t[8] || t[2] != "_" && t[2] == t[4] && t[2] == t[6]) {
            cout << endl << "Player " << player << " Wins!" << endl << endl;
            wygrana = 1;
        }
        else if (t[0] != "_" && t[0] == t[1] && t[0] == t[2] || t[3] != "_" && t[3] == t[4] && t[3] == t[5] || t[6] != "_" && t[6] == t[7] && t[6] == t[8]) {
            cout << endl << "Player " << player << " Wins!" << endl << endl;
            wygrana = 1;
        }
        for (int i = 0;i < 9; i++) {
            if (t[i] == "_") {
                draw++;
            }
        }
        if (draw != 0) {
            draw = 0;
        }
        else {
            cout << "It's a Draw!" << endl << endl;
            wygrana = 1;
        }
        if (player == "X") {
            player = "O";
        }
        else {
            player = "X";
        }
    }
}
int main()
{
    cout << "Tic Tac Toe" << endl;
    create_board();
    while (wygrana==0 ) {
        board();
        player_move();
    }
    board();
    return 0;
}
