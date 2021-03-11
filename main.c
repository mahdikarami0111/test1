#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
//
//
//typedef struct temp2{
//    int x;
//    int y;
//}point;
//
//
//typedef struct temp{
//    struct temp* next;
//    int l;
//    point points[5];
//    int des;
//    int side;
//}ship;
//
//
//typedef struct temp3{
//    char name[25];
//    int score;
//    struct temp3* next;
//} player;
//
//
//typedef struct{
//    char name[25];
//    int turn;
//    int board1[10][10];
//    int board2[10][10];
//    int cnt_ship1;
//    ship ship1[10];
//    int cnt_ship2;
//    ship ship2[10];
//    int bot_dif;
//    char player1_name[25];
//    char player2_name[25];
//}save_data;
//
//
//player* player1;
//player* player2;
//int board1[10][10];
//int board2[10][10];
//int cnt_players;
//int bot_dif = 0;
//player* head_usersg;
//
//
//
//void help(void);
//void menu (player* head_users,ship** ship1,ship** ship2);
////user functions
//void get_players(player** head_users);
//player* add(player* head_users);
//player* set_player(player* head_users,int n);
//void print_users(player* head_users);
//void update_users(player* head_users);
////general ship functions
//void print_ships(ship* ships);
//ship* create_ship(point s,point e);
//int ship_check(int x,int y,ship* temp);
//int is_placeable(ship* temp,int board[10][10]);
//void add_ship(ship** head_ships,ship* new_ship,int board[10][10]);
//void put_ships(ship** head_ships,int board[10][10]);
//void draw(int t);
//int game_over(void );
////multiplayer specific functions
//void destroy_1(int x,int y,ship** head_ships);
//void destroy_2(int x,int y,ship** head_ships);
//void play_turn_1(ship** head_ships,ship** head_shipsave);
//void play_turn_2(ship** head_ships,ship** head_shipsave);
//void game_loop_multi_player(ship** head_ship1, ship** head_ship2);
////bot specific functions
//void bot_difficulty(void);
//void put_ships_bot(ship** head_ships,int board[10][10]);
//void bot_turn(ship** head_ships);
//void game_loop_bot(ship** head_ship1,ship** head_ship2);
//void destroy_2_bot(int x,int y,ship** head_ships);
////save functions
//void save(int turn,ship* head_ship1,ship* head_ship2);
//int get_ship_count(ship* head_ships);
//save_data* print_saves(void);
//void load_data(ship** head_ship1,ship** head_ship2,save_data* load);
//void get_players_via_save(player* head_users,save_data* load);
//void add_ships_load(ship** head_ships,ship new_ship);
//
//
//
//
//void help (void){
//    printf("Hello and Welcome to Battleship\n"
//           "Here you will be asked to set up your deck of ships.\n"
//           "According to the length of the wanted ship enter the sarting point\n"
//           "and ending point of the ship in form of --> x y x y\n"
//           "if the length of the ship is 1 only enter the point that you want to place the ship \n"
//           "ships can not be placed within one point of another ship\n"
//           "during placement the status of your ships will be shown to you\n"
//           "in order to help you have better understanding of allowed placements\n");
//    printf("now if you are ready press Enter to continue\n");
//    fflush(stdin);
//    getchar();
//}
//
//
//void print_ships(ship* ships){
//    while (ships != NULL){
//        printf("\nside = %d\n L = %d\n des = %d\n",ships->side,ships->l,ships->des);
//        int i = 0;
//        for(i=0;i<5;i++){
//            printf("(%d,%d) ",ships->points[i].x,ships->points[i].y);
//        }
//        ships = ships->next;
//    }
//}
//
//
//ship* create_ship(point s,point e){
//    ship* temp = NULL;
//    ship* p =NULL;
//    temp = (ship*)malloc(sizeof(ship));
//    point pp;
//    int i = 0;
//    if (s.x == e.x){
//        temp->side = 1;
//        temp->l =abs(e.y - s.y) + 1;
//        temp->des = 0;
//        temp->next = NULL;
//        if (e.y < s.y){
//            pp = s;
//            s = e;
//            e = pp;
//        }
//        for(i=0;i<5;i++){
//            if (i>= temp->l){
//                temp->points[i].x = -1;
//                temp->points[i].y = -1;
//            }
//            else {
//                temp->points[i] = s;
//                s.y ++;
//            }
//        }
//    }
//    else if (s.y == e.y){
//        temp->side = 0;
//        temp->l = abs(s.x - e.x) + 1;
//        temp->des = 0;
//        temp->next = NULL;
//        if (e.x < s.x){
//            pp = s;
//            s = e;
//            e = pp;
//        }
//        for(i=0;i<5;i++){
//            if (i>= temp->l){
//                temp->points[i].x = -1;
//                temp->points[i].y = -1;
//            } else{
//                temp->points[i] = s;
//                s.x++;
//            }
//        }
//    }
//    return temp;
//}
//
//
//int ship_check(int x,int y,ship* temp){
//    int i =0,flag = 0;
//    for(i=0;i<temp->l;i++){
//        if(x == temp->points[i].x && y == temp->points[i].y){
//            flag = 1;
//        }
//    }
//    return flag;
//}
//
//
//int is_placeable(ship* temp,int board[10][10]){
//    int x,y,i,j;
//    point p;
//    x = temp->points[0].x - 1;
//    y = temp->points[0].y - 1;
//    for(i=0;i<temp->l;i++){
//        p = temp->points[i];
//        if (p.x<0 || p.x>9 || p.y<0 || p.y>9){
//            return 1;
//        }
//        if(board[p.y][p.x] == 1){
//            return 1;
//        }
//    }
//
//    if (temp->side == 1){
//        for(i=x;i<x+3;i++){
//            for(j=y;j<y+temp->l+2;j++){
//                if (i<0 || i>9 || j<0 || j>9){
//                    continue;
//                }
//                if(board[j][i] == 1 && ship_check(i,j,temp) == 0){
//                    return 1;
//                }
//            }
//        }
//    }
//    else if (temp->side == 0){
//        for(i=x;i<x+temp->l+2;i++){
//            for(j=y;j<y+3;j++){
//                if (i<0 || i>9 || j<0 || j>9){
//                    continue;
//                }
//                if(board[j][i] == 1 && ship_check(i,j,temp) == 0){
//                    return 1;
//                }
//            }
//        }
//    }
//    return 0;
//}
//
//
//void add_ship(ship** head_ships,ship* new_ship,int board[10][10]){
//    ship* p = NULL;
//    if (*head_ships == NULL){
//        *head_ships = new_ship;
//    } else{
//        p = *head_ships;
//        while (p->next != NULL){
//            p = p->next;
//        }
//        p->next = new_ship;
//    }
//    int i =0,x,y;
//    for(i=0;i<new_ship->l;i++){
//        x = new_ship->points[i].x;
//        y = new_ship->points[i].y;
//        board[y][x] =1;
//    }
//    int k =0,j = 0;
//    printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//    for(k=0;k<10;k++){
//        printf("%d",k);
//        for(j=0;j<10;j++){
//            if(board[k][j] == 0) {
//                printf(" -");
//            }
//            else{
//                printf(" S");
//            }
//        }
//        printf("% d\n",k);
//    }
//    printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//    printf("Your board so far\n");
//}
//
//
//void put_ships(ship** head_ships,int board[10][10]){
//    point s,e;
//    int flag = 0,i = 0;
//    ship* temp;
//    printf("\nEnter the ship with length of 5:\n");
//    while (flag ==0){
//        flag = 1;
//        scanf("%d %d %d %d",&s.x,&s.y,&e.x,&e.y);
//        temp = create_ship(s,e);
//        if (is_placeable(temp,board) == 1 || temp->l != 5){
//            printf("Invalid placement or ship length try again :\n");
//            flag = 0;
//        }
//    }
//    add_ship(head_ships,temp,board);
//
//
//    for(i=0;i<2;i++){
//        flag = 0;
//        printf("\nEnter the ship with length of 3:\n");
//        while (flag ==0){
//            flag = 1;
//            scanf("%d %d %d %d",&s.x,&s.y,&e.x,&e.y);
//            temp = create_ship(s,e);
//            if (is_placeable(temp,board) == 1 || temp->l != 3){
//                printf("Invalid placement or ship length try again :\n");
//                flag = 0;
//            }
//        }
//        add_ship(head_ships,temp,board);
//    }
//
//
//    for(i=0;i<3;i++){
//        flag = 0;
//        printf("\nEnter the ship with length of 2:\n");
//        while (flag ==0){
//            flag = 1;
//            scanf("%d %d %d %d",&s.x,&s.y,&e.x,&e.y);
//            temp = create_ship(s,e);
//            if (is_placeable(temp,board) == 1 || temp->l != 2){
//                printf("Invalid placement or ship length try again :\n");
//                flag = 0;
//            }
//        }
//        add_ship(head_ships,temp,board);
//    }
//
//
//    for(i=0;i<4;i++){
//        flag = 0;
//        printf("\nEnter the ship with length of 1:\n");
//        while (flag ==0){
//            flag = 1;
//            scanf("%d %d",&s.x,&s.y);
//            e = s;
//            temp = create_ship(s,e);
//            if (is_placeable(temp,board) == 1 || temp->l != 1){
//                printf("Invalid placement or ship length try again :\n");
//                flag = 0;
//            }
//        }
//        add_ship(head_ships,temp,board);
//    }
//}
//
//void bot_difficulty(void){
//    int i;
//    printf("please adjust bot diffculty:\n"
//           "1.Expert\n"
//           "2.Hard\n"
//           "3.Normal\n"
//           "4.Easy\n");
//    scanf("%d",&i);
//    bot_dif = i+1;
//}
//
//
//void put_ships_bot(ship** head_ships,int board[10][10]){
//    FILE* fp;
//    fp = fopen("bot_map.txt","r");
//    point s,e;
//    ship* temp;
//    int  i =0,j = 0;
//    for(i=0;i<6;i++){
//        fscanf(fp,"%d %d",&s.x,&s.y);
//        fscanf(fp,"%d %d",&e.x,&e.y);
//        temp = create_ship(s,e);
//        add_ship(head_ships,temp,board);
//    }
//    for(i=0;i<4;i++){
//        fscanf(fp,"%d %d",&s.x,&s.y);
//        e = s;
//        temp = create_ship(s,e);
//        add_ship(head_ships,temp,board);
//    }
//    player2 =(player*)malloc(sizeof(player));
//    fscanf(fp,"%s",(*player2).name);
//    fscanf(fp,"%d",&(*player2).score);
//    fclose(fp);
//}
//
//
//
//
////user and player functions
//void get_players(player** head_users){
//    *head_users = NULL;
//    player* p = NULL;
//    player* temp = NULL;
//    FILE* fp;
//    int score,i = 0;
//    char name[25];
//    fp = fopen("users.txt","r");
//    fscanf(fp,"%d",&cnt_players);
//    for(i=0;i<cnt_players;i++){
//        temp = (player*)malloc(sizeof(player));
//        fscanf(fp,"%s",temp->name);
//        fscanf(fp,"%d",&temp->score);
//        temp->next = NULL;
//        if (*head_users == NULL){
//            *head_users = temp;
//        }
//        else {
//            p = *head_users;
//            while(p->next != NULL){
//                p = p->next;
//            }
//            p->next = temp;
//        }
//    }
//    fclose(fp);
//}
//
//
//player* add(player* head_users){
//    cnt_players += 1;
//    player* temp;
//    temp = (player*)malloc(sizeof(player));
//    fflush(stdin);
//    gets(temp->name);
//    temp->score = 0;
//    temp->next = NULL;
//    while (head_users->next != NULL){
//        head_users = head_users->next;
//    }
//    head_users->next = temp;
//    return temp;
//}
//
//
//void print_users(player* head_users){
//    int  i = 0;
//    while (head_users != NULL){
//        printf("%d.%s %d\n",i+1,head_users->name,head_users->score);
//        head_users = head_users->next;
//        i++;
//    }
//}
//
//
//player* set_player(player* head_users,int n){
//    int i =0;
//    player* temp = head_users;
//    for(i=0;i<n-1;i++){
//        temp = temp->next;
//    }
//    return temp;
//}
//
//
//void update_users(player* head_users){
//    FILE* fp = fopen("users.txt","w");
//    fprintf(fp,"%d",cnt_players);
//    player* temp = head_users;
//    while (temp != NULL){
//        fprintf(fp,"%s",temp->name);
//        fprintf(fp," %d",temp->score);
//        temp = temp->next;
//    }
//    fclose(fp);
//}
//
////end of user and player functions
//
//
//
//
//
//
////gameplay functions
//void draw(int t){
//    int i = 0, j = 0;
//    if (t == 2){
//        printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//        for(i=0;i<10;i++){
//            printf("%d ",i);
//            for(j=0;j<10;j++){
//                if(board1[i][j] == 0 || board1[i][j] == 1){
//                    printf("- ");
//                }
//                else if (board1[i][j] == 2){
//                    printf("w ");
//                }
//                else if (board1[i][j] == -1){
//                    printf("E ");
//                }
//                else if (board1[i][j] == -2){
//                    printf("C ");
//                }
//            }
//            printf("%d\n",i);
//        }
//        printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//    }
//    else if (t == 1){
//        printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//        for(i=0;i<10;i++){
//            printf("%d ",i);
//            for(j=0;j<10;j++){
//                if(board2[i][j] == 0 || board2[i][j] == 1){
//                    printf("- ");
//                }
//                else if (board2[i][j] == 2){
//                    printf("w ");
//                }
//                else if (board2[i][j] == -1){
//                    printf("E ");
//                }
//                else if (board2[i][j] == -2){
//                    printf("C ");
//                }
//            }
//            printf("%d\n",i);
//        }
//        printf(". 0 1 2 3 4 5 6 7 8 9 .\n");
//    }
//
//}
//
//
//void destroy_1(int x,int y,ship** head_ships){
//    int  i =0;
//    point p;
//    if (board2[y][x] == 1){
//        board2[y][x] = -1;
//    }
//    else if (board2[y][x] == 0){
//        board2[y][x] = 2;
//        return;
//    }
//    ship* temp2;
//    ship* temp = *head_ships;
//    if (ship_check(x,y,*head_ships) == 1){
//        (*head_ships)->des += 1;
//        if ((*head_ships)->des == (*head_ships)->l){
//            for(i=0;i<(*head_ships)->l;i++){
//                p = (*head_ships)->points[i];
//                board2[p.y][p.x] = -2;
//            }
//            player1->score += 25/(*head_ships)->l;
//            (*head_ships) = (*head_ships)->next;
//        }
//    }
//    else{
//        while (ship_check(x,y,temp->next) == 0){
//            temp = temp->next;
//        }
//        temp2 = temp->next;
//        temp2->des +=1;
//        if(temp2->des == temp2->l){
//            for(i=0;i<temp2->l;i++){
//                p = temp2->points[i];
//                board2[p.y][p.x] = -2;
//            }
//            player1->score += 25/temp2->l;
//            temp->next = temp->next->next;
//        }
//    }
//}
//
//
//void destroy_2(int x,int y,ship** head_ships){
//    int i =0;
//    point p;
//    if (board1[y][x] == 1){
//        board1[y][x] = -1;
//    }
//    else if (board1[y][x] == 0){
//        board1[y][x] = 2;
//        return;
//    }
//    ship* temp2;
//    ship* temp = *head_ships;
//    if (ship_check(x,y,*head_ships) == 1){
//        (*head_ships)->des += 1;
//        if ((*head_ships)->des == (*head_ships)->l){
//            for(i=0;i<(*head_ships)->l;i++){
//                p = (*head_ships)->points[i];
//                board1[p.y][p.x] = -2;
//            }
//            player2->score += 25/(*head_ships)->l;
//            (*head_ships) = (*head_ships)->next;
//        }
//    }
//    else{
//        while (ship_check(x,y,temp->next) == 0){
//            temp = temp->next;
//        }
//        temp2 = temp->next;
//        temp2->des +=1;
//        if(temp2->des == temp2->l){
//            for(i=0;i<temp2->l;i++){
//                p = temp2->points[i];
//                board1[p.y][p.x] = -2;
//            }
//            player2->score += 25/temp2->l;
//            temp->next = temp->next->next;
//        }
//    }
//
//}
//
//
//void destroy_2_bot(int x,int y,ship** head_ships){
//    int i =0;
//    point p;
//    if (board1[y][x] == 1){
//        board1[y][x] = -1;
//    }
//    else if (board1[y][x] == 0){
//        board1[y][x] = 2;
//        return;
//    }
//    ship* temp2;
//    ship* temp = *head_ships;
//    if (ship_check(x,y,*head_ships) == 1){
//        (*head_ships)->des += 1;
//        if ((*head_ships)->des == (*head_ships)->l){
//            for(i=0;i<(*head_ships)->l;i++){
//                p = (*head_ships)->points[i];
//                board1[p.y][p.x] = -2;
//            }
//            (*head_ships) = (*head_ships)->next;
//        }
//    }
//    else{
//        while (ship_check(x,y,temp->next) == 0){
//            temp = temp->next;
//        }
//        temp2 = temp->next;
//        temp2->des +=1;
//        if(temp2->des == temp2->l){
//            for(i=0;i<temp2->l;i++){
//                p = temp2->points[i];
//                board1[p.y][p.x] = -2;
//            }
//            temp->next = temp->next->next;
//        }
//    }
//}
//
//
//int game_over(void ){
//    int i =0,j = 0,player_1 = 0,player_2 = 0;
//    for(i=0;i<9;i++){
//        for(j=0;j<9;j++){
//            if (board1[i][j] == 1){
//                player_1 = 1;
//            }
//            if (board2[i][j] == 1){
//                player_2 = 1;
//            }
//        }
//    }
//    if (player_1 == 0 ){
//        return 2;
//    }
//    if (player_2 == 0){
//        return 1;
//    }
//    else {
//        return 0;
//    }
//
//}
//
//
//void play_turn_1(ship** head_ships,ship** head_shipsave){
//    printf("%s's board\n",player2->name);
//    draw(1);
//    int x,y,prize = 0;
//    printf("%s's turn\n",player1->name);
//    printf("enter a point:\n");
//    scanf("%d",&x);
//    if (x == -1){
//        save(1,*head_shipsave,*head_ships);
//        printf("enter a point:\n");
//        scanf("%d",&x);
//    }
//    scanf("%d",&y);
//    while (board2[y][x] == -2 || board2[y][x] == -1 || board2[y][x] == 2){
//        printf("Wrong point try again :\n");
//        scanf("%d",&x);
//        scanf("%d",&y);
//    }
//    if (board2[y][x] == 1){
//        prize = 1;
//    }
//    destroy_1(x,y,head_ships);
//    printf("%s's board\n",player2->name);
//    draw(1);
//    if (prize == 1){
//        printf("you got a prize ! your turn again\n");
//    }
//    printf("press Enter to continue \n");
//    fflush(stdin);
//    getchar();
//    if (game_over() != 0){
//        return;
//    }
//    if (prize == 1){
//        play_turn_1(head_ships,head_shipsave);
//    }
//}
//
//
//void play_turn_2(ship** head_ships,ship** head_shipsave){
//    printf("%s's board:\n",player1->name);
//    draw(2);
//    int x,y,prize = 0;
//    printf("%s's turn\n",player2->name);
//    printf("enter a point:\n");
//    scanf("%d",&x);
//    if (x == -1){
//        save(2,*head_ships,*head_shipsave);
//        printf("enter a point:\n");
//        scanf("%d",&x);
//    }
//    scanf("%d",&y);
//    while (board1[y][x] == -2 || board1[y][x] == -1 || board1[y][x] == 2){
//        printf("Wrong point try again :\n");
//        scanf("%d",&x);
//        scanf("%d",&y);
//    }
//    if (board1[y][x] == 1){
//        prize = 1;
//    }
//    destroy_2(x,y,head_ships);
//    printf("%s's board:\n",player1->name);
//    draw(2);
//    if (prize == 1){
//        printf("you got a prize ! your turn again\n");
//    }
//    printf("press Enter to continue\n");
//    fflush(stdin);
//    getchar();
//    if (game_over() != 0){
//        return;
//    }
//    if (prize == 1){
//        play_turn_2(head_ships,head_shipsave);
//    }
//}
//
//
//void bot_turn(ship** head_ships){
//    int i = 0,j = 0,k=0,index,prize = 0,z = 0,flag;
//    point valid_points[100];
//    point ship_points[25];
//    point p;
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            if (board1[i][j] == 1 || board1[i][j] == 0){
//                p.x = j;
//                p.y = i;
//                valid_points[k] = p;
//                k++;
//            }
//            if (board1[i][j] == 1){
//                ship_points[z] = p;
//                z++;
//            }
//        }
//    }
//    srand(time(NULL));
//    flag = rand() % bot_dif;
//    if (flag == 0){
//        printf("yes\n");
//        index = rand()%(z);
//        p = ship_points[index];
//    }
//    else{
//        index = rand()%(k);
//        p = valid_points[index];
//    }
//    if (board1[p.y][p.x] == 1){
//        prize = 1;
//    }
//    printf("%s hit point (%d,%d)\n",player2->name,p.x,p.y);
//    destroy_2_bot(p.x,p.y,head_ships);
//    printf("your board\n");
//    draw(2);
//
//    if (prize == 1 && game_over() == 0){
//        printf("%s gets a prize!\n",player2->name);
//    }
//    printf("press Enter to continue\n");
//    fflush(stdin);
//    getchar();
//    if (game_over() != 0){
//        return;
//    }
//    if (prize == 1){
//        bot_turn(head_ships);
//    }
//}
//
//
//void game_loop_bot(ship** head_ship1,ship** head_ship2){
//    while (game_over() == 0){
//        play_turn_1(head_ship2,head_ship1);
//        if (game_over() != 0){
//            break;
//        }
//        bot_turn(head_ship1);
//    }
//    printf("congratz game is over the winner is:\n");
//    if (game_over() == 1){
//        printf("%s",player1->name);
//    }
//    else{
//        printf("%s",player2->name);
//    }
//}
//
//
//void game_loop_multi_player(ship** head_ship1, ship** head_ship2){
//    while (game_over() == 0){
//        play_turn_1(head_ship2,head_ship1);
//        if (game_over() != 0){
//            break;
//        }
//        play_turn_2(head_ship1,head_ship2);
//    }
//    printf("congratz game is over and the winner is:\n");
//    if (game_over() == 1){
//        printf("%s",player1->name);
//    }
//    else{
//        printf("%s",player2->name);
//    }
//}
//
//
//void add_ships_load(ship** head_ships,ship new_ship){
//    ship* temp;
//    ship* p;
//    temp = (ship*)malloc(sizeof(ship));
//    *temp = new_ship;
//    temp->next = NULL;
//    if (*head_ships == NULL){
//        *head_ships = temp;
//    }
//    else{
//        p = *head_ships;
//        while (p->next != NULL){
//            p =p->next;
//        }
//        p->next = temp;
//    }
//}
//
//
//int get_ship_count(ship* head_ships){
//    int i =0;
//    while (head_ships != NULL){
//        i++;
//        head_ships = head_ships->next;
//    }
//    return i;
//}
//
//
//void save(int turn,ship* head_ship1,ship* head_ship2){
//    save_data info;
//    printf("please enter a name for your save: \n");
//    fflush(stdin);
//    gets(info.name);
//    info.turn = turn;
//    int i = 0;
//    int j = 0;
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            info.board1[i][j] = board1[i][j];
//        }
//    }
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            info.board2[i][j] = board2[i][j];
//        }
//    }
//    info.cnt_ship1 = get_ship_count(head_ship1);
//    for(i = 0;i<info.cnt_ship1;i++){
//        info.ship1[i] = *head_ship1;
//        head_ship1 = head_ship1->next;
//    }
//    info.cnt_ship2 = get_ship_count(head_ship2);
//    for(i=0;i<info.cnt_ship2;i++){
//        info.ship2[i] = *head_ship2;
//        head_ship2 = head_ship2->next;
//    }
//    info.bot_dif = bot_dif;
//    strcpy(info.player1_name,player1->name);
//    strcpy(info.player2_name,player2->name);
//    FILE* fp;
//    fp = fopen("saves.bin","ab");
//    fwrite(&info,sizeof(save_data),1,fp);
//    fclose(fp);
//    printf("Game saved\n");
//    update_users(head_usersg);
//    int cmd = 0;
//    printf("Do you want to continue? if yes press 1 else press 0\n");
//    scanf("%d",&cmd);
//    if (cmd == 0){
//        exit(0);
//    }
//}
//
//
//save_data* print_saves(void){
//    int i = 0,j = 0;
//    FILE* fp;
//    fp = fopen("saves.bin","rb");
//    save_data temp_save;
//    while (feof(fp) == 0){
//        fread(&temp_save,sizeof(save_data),1,fp);
//        i++;
//    }
//    fseek(fp,0,SEEK_SET);
//    for(j=0;j<i-1;j++){
//        fread(&temp_save,sizeof(save_data),1,fp);
//        printf("%d.%s : (%s)vs(%s)\n",j+1,temp_save.name,temp_save.player1_name,temp_save.player2_name);
//    }
//    scanf("%d",&j);
//    fseek(fp,0,SEEK_SET);
//    for(i=0;i<j;i++){
//        fread(&temp_save,sizeof(save_data),1,fp);
//    }
//    save_data* load;
//    load = (save_data*)malloc(sizeof(save_data));
//    *load = temp_save;
//    return load;
//}
//
//
//void get_players_via_save(player* head_users,save_data* load){
//    player* temp;
//    temp = (player*)malloc(sizeof(player));
//    temp = head_users;
//    while (strcmp(temp->name,load->player1_name) != 0){
//        temp = temp->next;
//    }
//    player1 = temp;
//    temp = head_users;
//    if (load->bot_dif != 0){
//        player2 =(player*)malloc(sizeof(player));
//        strcpy(player2->name,"Henry(bot)\0");
//        player2->score = 0;
//        return;
//    }
//    while (strcmp(temp->name,load->player2_name) != 0){
//        temp = temp->next;
//    }
//    player2 = temp;
//}
//
//
//void load_data(ship** head_ship1,ship** head_ship2,save_data* load){
//    int i =0,j = 0;
//    int junk[10][10];
//    for(i=0;i<load->cnt_ship1;i++){
//        add_ships_load(head_ship1,load->ship1[i]);
//    }
//    for(i=0;i<load->cnt_ship2;i++){
//        add_ships_load(head_ship2,load->ship2[i]);
//    }
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            board1[i][j] = load->board1[i][j];
//        }
//    }
//    for(i=0;i<10;i++){
//        for(j=0;j<10;j++){
//            board2[i][j] = load->board2[i][j];
//        }
//    }
//    bot_dif = load->bot_dif;
//}
//
//
//void score_board(player* head_users){
//    player* temp;
//    int i = 0,j = 0;
//    temp = (player*)malloc(sizeof(player));
//    player users[cnt_players];
//    for(i=0;i<cnt_players;i++){
//        users[i] = *head_users;
//        head_users = head_users->next;
//    }
//    player* max = &users[0];
//    for(i=0;i<cnt_players;i++){
//        max = &users[0];
//        for(j = 0;j<cnt_players;j++){
//            if(users[j].score >= max->score){
//                max = &users[j];
//            }
//        }
//        printf("%d %s  score: %d\n",i+1,max->name,max->score);
//        max->score = -1;
//    }
//}
//
//
//void menu (player* head_users,ship** ship1,ship** ship2){
//    int command;
//    printf("Menu\n"
//           "1.Play with a friend\n"
//           "2.Play with  bot\n"
//           "3.Load game\n"
//           "4.Score board\n"
//           "5.Exit\n");
//    scanf("%d",&command);
//    if (command ==1){
//        printf("First player\n"
//               "1.Choose from available users\n"
//               "2.New user\n");
//        scanf("%d",&command);
//
//        if (command == 1){
//            print_users(head_users);
//            scanf("%d",&command);
//            player1 = set_player(head_users,command);
//        }
//        else if (command == 2){
//            player1 = add(head_users);
//        }
//        help();
//        put_ships(ship1,board1);
//        printf("\nit's player 2 turn now press any key to continue\n");
//        fflush(stdin);
//        getchar();
//        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//        printf("Second player\n"
//               "1.Choose from available users\n"
//               "2.New user\n");
//        scanf("%d",&command);
//
//        if (command == 1){
//            print_users(head_users);
//            scanf("%d",&command);
//            player2 = set_player(head_users,command);
//        }
//        else if (command == 2){
//            player2 = add(head_users);
//        }
//        help();
//        put_ships(ship2,board2);
//        printf("\nthe game is about to begin press any key to continue\n");
//        fflush(stdin);
//        getchar();
//        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//        game_loop_multi_player(ship1, ship2);
//    }
//
//
//    else if (command == 2){
//        printf("Player\n"
//               "1.Choose from available users\n"
//               "2.New user\n");
//        scanf("%d",&command);
//        if (command == 1){
//            print_users(head_users);
//            scanf("%d",&command);
//            player1 = set_player(head_users,command);
//        }
//        else if (command == 2){
//            player1 = add(head_users);
//        }
//        bot_difficulty();
//        help();
//        put_ships(ship1,board1);
//        printf("the game is about to begin press Enter to continue\n");
//        fflush(stdin);
//        getchar();
//        put_ships_bot(ship2,board2);
//        game_loop_bot(ship1,ship2);
//    }
//
//
//
//    else if (command == 3){
//        save_data* load;
//        load = print_saves();
//        load_data(ship1,ship2,load);
//        get_players_via_save(head_users,load);
//        if (bot_dif == 0){
//            if(load->turn == 2){
//                play_turn_2(ship1,ship2);
//                game_loop_multi_player(ship1,ship2);
//            }
//            else if (load->turn == 1){
//                game_loop_multi_player(ship1,ship2);
//            }
//        }
//        else if (bot_dif != 0){
//            if(load->turn == 1){
//                game_loop_bot(ship1,ship2);
//            }
//            else if(load->turn == 2){
//                bot_turn(ship1);
//                game_loop_bot(ship1,ship2);
//            }
//        }
//    }
//    else if(command == 4){
//        score_board(head_users);
//    }
//    else if (command == 5){
//        exit(0);
//    }
//    update_users(head_users);
//    printf("\n\n");
//    menu(head_users,ship1,ship2);
//}
//
//
//int main (void){
//    FILE* fp;
//    fp = fopen("saves.bin","wb");
//    player* head_users = NULL;
//    get_players(&head_users);
//    head_usersg = head_users;
//    ship* ship1 = NULL;
//    ship* ship2 = NULL;
//    menu(head_users,&ship1,&ship2);
//    update_users(head_users);
//}





int main (void){

}