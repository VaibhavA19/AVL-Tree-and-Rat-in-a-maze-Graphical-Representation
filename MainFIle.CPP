#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#define RADIUS 15
#define BX 639
#define BY 100
/// RAT MAZE DEFINE //////////////////
#define ROWS 4
#define COLS 4
#define EDGE 50
#define XX getmaxx()/3
#define YY getmaxy()/5
/// RAT MAZE DEFINE END//////////////////
/// RAT MAZE FUNCTIONS//////////////////
int array[ROWS][COLS] = {{1,1,0,0},
                         {0,1,1,1},
                         {0,0,1,0},
                         {0,0,1,1}};
void disp_message (int row ,int  col )
{
	char message[20];
    if(row!= - 1)
    {
        char message[30];
        sprintf(message ,"YYOU ARE AT %d , %d",row,col);
        outtextxy(5,getmaxy()-90,message );
        setcolor(BLACK);
        delay(500);
        outtextxy(5,getmaxy()-90,message );
        setcolor(WHITE);
    }
    else
    {
        outtextxy(5,getmaxy()-90,"MOVE NOT POSSIBLE" );
        setcolor(BLACK);
        delay(500);
        outtextxy(5,getmaxy()-90,"MOVE NOT POSSIBLE" );
        setcolor(WHITE);
    }
}
void back_at(int row , int col)
{
        char message[30];
        sprintf(message ,"YOU ARE BACK   AT %d , %d",row,col);
        outtextxy(5,getmaxy()-90,message );
        setcolor(BLACK);
        delay(500);
        outtextxy(5,getmaxy()-90,message );
        setcolor(WHITE);
}
void blink(int row ,int col)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        setfillstyle(SOLID_FILL,RED);
        floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
        delay(200);
        setfillstyle(SOLID_FILL,8);
        floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
        delay(200);
    }
    if(array[row][col] == 1 || array[row][col] == 2)
    {
        setfillstyle(SOLID_FILL,0);
        floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
    }
}
int game(int row , int col )
{
	char message[20];
    setfillstyle(SOLID_FILL,10);
	floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
	disp_message(row,col);
    int rflag = 0 , lflag = 0 , uflag = 0 , dflag = 0 ;
    char choice ;
    array[row][col] = 2 ;
    /////
        cout<<row<<" "<<col<<" = 2"<<endl ;
        ////
    if( row == ROWS - 1 && col == COLS - 1 )
	return 1 ;
    input:
    if(rflag == 1 && dflag == 1 && lflag == 1 && uflag == 1)
    {
        array[row][col] = 1 ;
        sprintf(message,"you cannot go any further from here");
        outtextxy(5,getmaxy()-90,message);
        setcolor(BLACK);
        delay(500);
        outtextxy(5,getmaxy()-90,message );
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,8);
        floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
        return 0 ;
    }
	sprintf(message,"enter choice ");
        outtextxy(5,getmaxy()-90,message );
        setcolor(BLACK);
        delay(500);
        outtextxy(5,getmaxy()-90,message );
        setcolor(WHITE);
	fflush(stdin);
    choice = getch();
    fflush(stdin);
    ///RIGHT
    if(choice == 'd' && rflag == 0)
    {
	rflag = 1 ;
	if( col != (COLS - 1)  )
	{
	    if( array[row][col+1] != 0 && array[row][col+1] != 2 )
	    {
		setfillstyle(SOLID_FILL,0);
		floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		if( game( row , col+1 ) )
		{
		    return 1 ;
		}
		else
		{
		    setfillstyle(SOLID_FILL,10);
		    floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		    back_at(row,col);
		    goto input;
		}
	     }
	    else
	    {
		blink(row,col+1);
		disp_message(-1,-1);
		goto input;
	    }
	    }
	else
	{
	    disp_message(-1,-1);
	    goto input;
	}
    }
    ///DOWN
    if(choice == 's' && dflag == 0)
	{
	    dflag = 1 ;
	    if( row != ROWS -1  )
	{
	    if( array[row+1][col] != 0 && array[row+1][col] != 2 )
	    {
		setfillstyle(SOLID_FILL,0);
		floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		if(game( row +1 , col ) )
		{
		    return 1;
		}
		else
		{
		    setfillstyle(SOLID_FILL,10);
		    floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		    back_at(row,col);
		    goto input;
		}
	    }
	    else
	    {
		blink(row+1,col);
		disp_message(-1,-1);
		goto input;
	    }
	}
	else
	{
	    disp_message(-1,-1);
	    goto input;
	}
	}
	    ///LEFT
    if(choice == 'a' && lflag == 0 )
	{
	    lflag = 1 ;
	    if( col != 0  )
	    {
	    if( array[row][col-1] != 0 && array[row][col-1] != 2 )
	    {
		setfillstyle(SOLID_FILL,0);
		floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		if(game( row , col - 1 ) )
		{
		    return 1 ;
		}
		else
		{
		    setfillstyle(SOLID_FILL,10);
		    floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		    back_at(row,col);
		    goto input;
		}
	    }
	    else
	    {
		blink(row,col-1);
		disp_message(-1,-1);
		goto input;
	    }
	}
	else
	{
	    disp_message(-1,-1);
	    goto input;
	}
	}
    ///UP
    if(choice == 'w' && uflag == 0)
	{
	uflag = 1 ;
	    if( row != 0  )
	    {
	    if( array[row-1][col] != 0 && array[row-1][col] != 2 )
	    {
		setfillstyle(SOLID_FILL,0);
		floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		if(game( row - 1 , col ) )
		{
		    return 1 ;
		}
		else
		{
		    setfillstyle(SOLID_FILL,10);
		    floodfill(XX+(col*EDGE)+(EDGE/2) , YY+(row*EDGE)+(EDGE/2) ,WHITE);
		    back_at(row,col);
		    goto input;
		}
	    }
	    else
	    {
		blink(row-1,col);
		disp_message(-1,-1);
		goto input;
	    }
	}
	    else
	{
	    disp_message(-1,-1);
	    goto input;
	}
	}
	if(lflag ==0 || rflag == 0 || uflag == 0 || dflag == 0 )
	{
	sprintf(message,"you already tried this");
	outtextxy(5,getmaxy()-90,message );
	setcolor(BLACK);
	delay(500);
	outtextxy(5,getmaxy()-90,message );
	setcolor(WHITE);
	goto input ;
	}
	///
	cout<<"some moves tried after"<<endl ;///
    array[row][col] = 1 ;
	return 0 ;
}
void set_maze()
{
    for(int i = 0 ; i < ROWS ; i++)
	for(int j = 0 ; j < COLS ; j++)
	{
	    cout << '('<< i << j << ')' <<endl ;
	    cin>> array[i][j] ;
	}
}
void sol()
{
    for(int i = 0 ; i < ROWS ; i++ )
    {
        cout<<endl ;
        for(int j = 0 ; j < COLS ; j++ )
        {
            cout.width(5);
            if(array[i][j]==2)
                cout << 1 ;
            else
            cout << 0 ;
        }
    }
}
void initial_display()
{
    int  k = 1  ;
    for(int i = 0 ; i  < (ROWS-1)*EDGE +1 ; i+=EDGE)
	for(int j = 0 ; j < (ROWS-1)*EDGE +1 ; j+=EDGE)
	{
	    rectangle(XX+j , YY+i , XX+j+EDGE , YY+i+EDGE );
	    setfillstyle(SOLID_FILL,k++);
	    floodfill(XX+j+25 , YY+i+25 ,WHITE);
	    if(k==15)
            k=1 ;
		if(k  == 8)
	    k = 9 ;
        if(k==10)
            k=11 ;
	}
}
/// RAT MAZE FUNCTIONS END //////////////////
class node
{
public:
    int height ,X , Y , data ;
    node *left , *right ;
    node()
    {
	left = right = NULL ;
    }
};
class avl
{
    public:
    node *root ;
    avl()
    {
        root = NULL ;
    }
    int x_center(int x  )
    {
        return BX/2 + x  ;
    }
    int y_center(int y )
    {
        return BY/4 + y  ;
    }
    void Circle(int x , int y , int color)
    {
		circle(x,y,RADIUS);
		setfillstyle(SOLID_FILL,color);
		floodfill(x - 5 ,y - 5 ,WHITE);
    }
    void highlight(node * b , int color)
    {
        Circle(b->X,b->Y,color);
        delay(500);
        Circle(b->X,b->Y,BLUE);
    }
    int height(node *rt , int level  = 0 )
    {
        if(rt==NULL)
            return -1 ;
        int l = 0 , r = 0 ;
        if(rt->left)
            l = height(rt->left, level+1);
        if(rt->right)
            r = height(rt->right , level+1);
        if(rt->left == NULL && rt->right == NULL)
            return 1 + level ;
        if(l>r)
            return l ;
        else
            return r ;
    }
    void color_loop(node *x)
    {
	for(int i = 1 ; i < 15 ; i++)
        {
            Circle(x->X,x->Y,i);
            delay(400);
        }
    }
    void left_down(int src_x,int src_y , int des_x , int des_y)
    {
	for(int i = src_x  ; i >= des_x ; i-=20 )
        {
            Circle(i,src_y,GREEN);
            delay(100);
            Circle(i,src_y,YELLOW);
        }
        for(i = src_x  ; i <= des_x ; i+=20 )
        {
            Circle(i,src_y,GREEN);
            delay(100);
            Circle(i,src_y,YELLOW);
        }
	i = des_x ;
        for(int j = src_y ; j <= des_y+15 ; j+=20)
        {
            Circle(i,j,GREEN);
            delay(100);
            Circle(i,j,YELLOW);
        }
        Circle(des_x ,des_y+4,GREEN);
    }
    void down_left(int src_x,int src_y , int des_x , int des_y)
    {
        int i = src_x ;
	for(int j = src_y ; j <= des_y+15 ; j+=20)
        {
            Circle(i,j,GREEN);
            delay(100);
            Circle(i,j,YELLOW);
        }
        for(i = src_x  ; i >= des_x ; i-=20 )
        {
	    Circle(i,des_y,GREEN);
            delay(100);
            Circle(i,des_y,YELLOW);
        }
        Circle(des_x+4 ,des_y,GREEN);
    }
    void down_right(int src_x,int src_y , int des_x , int des_y)
    {
	int i = src_x ;
	for(int j = src_y ; j <= des_y+15 ; j+=20)
        {
            Circle(i,j,GREEN);
            delay(100);
            Circle(i,j,YELLOW);
        }
        for(i = src_x  ; i <= des_x ; i+=20 )
        {
            Circle(i,des_y,GREEN);
	    delay(100);
            Circle(i,des_y,YELLOW);
	}
        Circle(des_x+4 ,des_y,GREEN);
    }
    void Display(node *rt , int cc )
    {
	if(rt==NULL && cc == 1 )
        {
            clearviewport();
            settextstyle(5,HORIZ_DIR,5);
            outtextxy(0,getmaxy()/2,"TREE IS EMPTY" );
            outtextxy(0,getmaxy()/2+30,"Press any key to continue");
            getch();
            settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
            clearviewport();
            return ;
	}
	else if(root == NULL)
	return ;
        int a = 40 ;
	char out[5] ;
        if(rt==root)
            a= 120 ;
        if(rt->left)
        {
            line(rt->X  - RADIUS , rt->Y  ,rt->X - a, rt->Y -RADIUS + 40);
            Display(rt->left ,cc);
        }
        circle(rt->X , rt->Y  , RADIUS);
        highlight(rt,GREEN);
	Circle(rt->X , rt->Y  , BLUE);
        sprintf(out,"%d",rt->data);
	outtextxy(rt->X - 3 , rt->Y-3  , out );
        if(rt->right)
        {
            line(rt->X + RADIUS , rt->Y  ,rt->X + a, rt->Y -RADIUS + 40);
            Display(rt->right,cc);
        }
    }
    void update_xy(node *r , int x , int y)
    {
        int a = 40 ;
        if(r == root)
            a = 120 ;
        r->X = x ;
        r->Y = y ;
        if(r->right)
            update_xy(r->right , x+a,y+40);
        if(r->left)
	    update_xy(r->left , x-a , y+40);
    }
    void Insert()
    {
        node *neww = new node ;
	    settextstyle(3,HORIZ_DIR,3);
        outtextxy(5,getmaxy()-90,"ENTER DATA" );
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        cin>>neww->data ;
        Display(root,0);
        if(root!=NULL)
        delay(500);
        settextstyle(5,HORIZ_DIR,5);
        outtextxy(0,getmaxy()/2+30,"Inserting ");
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        insert(&root,neww,0,0);
        settextstyle(5,HORIZ_DIR,5);
        setcolor(BLACK);
        outtextxy(0,getmaxy()/2+30,"Inserting ");
        setcolor(WHITE);
        outtextxy(0,getmaxy()/2+30,"Inserted Successfully ");
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        delay(300);
    }
    void insert(node **rt , node * neww , int x , int y )
    {
        highlight((*rt),MAGENTA);
        delay(500);
        int a = 40   ;
        if((*rt)==NULL || (*rt)==root)
	    a = 120 ;
        neww->X = x_center(x);
        neww->Y = y_center(y);
        if((*rt)==NULL)
	{
            char out[5];
            (*rt)=neww ;
            (*rt)->height = height((*rt));
            circle((*rt)->X , (*rt)->Y  , RADIUS);
            highlight((*rt),MAGENTA);
            Circle((*rt)->X , (*rt)->Y  , BLUE);
            sprintf(out,"%d",(*rt)->data);
            outtextxy((*rt)->X - 3 , (*rt)->Y-3  , out );
            return ;
        }
        if((*rt)->data > neww->data )
        {
            if((*rt)->left)
            {
		insert(&((*rt)->left), neww, x - a , y +40);
            }
            else
            {
                char out[5];
		neww->X = x_center(x-a);
                neww->Y = y_center(y+40);
                (*rt)->left = neww ;
                neww->height = height(neww);
                (*rt)->height = height((*rt));
                line((*rt)->X  - RADIUS , (*rt)->Y  ,  (*rt)->X - a, (*rt)->Y -RADIUS + 40);
                circle(neww->X , neww->Y  , RADIUS);
		highlight(neww,MAGENTA);
		Circle(neww->X , neww->Y  , BLUE);
                sprintf(out,"%d",neww->data);
                outtextxy(neww->X - 3 , neww->Y-3  , out );
                return ;
            }
            if(ht((*rt)->left) - ht((*rt)->right) > 1 )
	    {
                if((*rt)->left->data > neww->data)
                {
                    blink((*rt),(*rt)->left,(*rt)->left->left);
                    down_left((*rt)->X , (*rt)->Y ,(*rt)->left->X +40 , (*rt)->left->Y + 40  )  ;
                    (*rt)->left->X = (*rt)->X ;
		    (*rt)->left->Y = (*rt)->Y ;
                    (*rt)=LL((*rt));
                    update_xy((*rt),(*rt)->X , (*rt)->Y);
                }
                else
                {
                    blink((*rt),(*rt)->left,(*rt)->left->right);
		    down_right((*rt)->left->X, (*rt)->left->Y,(*rt)->left->right->X - 40 , (*rt)->left->right->Y+40);
		    delay(400);
                    down_right((*rt)->X, (*rt)->Y,(*rt)->left->right->X + 40 , (*rt)->left->right->Y+40);
                    (*rt)->left->right->X = (*rt)->X ;
                    (*rt)->left->right->Y = (*rt)->Y ;
                    (*rt)=LR((*rt));
		    update_xy((*rt), (*rt)->X , (*rt)->Y);
                }
            }
	}
        else if((*rt)->data < neww->data )
        {
            if((*rt)->right)
	    {
                insert(&((*rt)->right),neww, x+a , y +40);
            }
            else
            {
                char out[5] ;
                neww->X = x_center(x+a);
                neww->Y = y_center(y+40);
		(*rt)->right = neww ;
                neww->height = height(neww);
                (*rt)->height = height((*rt));
                line((*rt)->X + RADIUS , (*rt)->Y  ,(*rt)->X + a, (*rt)->Y -RADIUS + 40);
		circle(neww->X , neww->Y  , RADIUS);
                highlight(neww,MAGENTA);
		Circle(neww->X , neww->Y  , BLUE);
                sprintf(out,"%d",neww->data);
		outtextxy(neww->X - 3 , neww->Y-3  , out );
                return ;
            }
            if(ht((*rt)->right) - ht((*rt)->left) > 1)
	    {
                if((*rt)->right->data < neww->data)
                {
                    blink((*rt),(*rt)->right,(*rt)->right->right);
                    down_right((*rt)->X, (*rt)->Y,(*rt)->right->X - 40 , (*rt)->right->Y+40);
                    (*rt)->right->X = (*rt)->X ;
                    (*rt)->right->Y = (*rt)->Y ;
		    (*rt)= RR((*rt));
		    update_xy((*rt),(*rt)->X , (*rt)->Y);
                }
                else
		{
                    blink((*rt),(*rt)->right,(*rt)->right->left);
                    down_left((*rt)->right->X , (*rt)->right->Y , (*rt)->right->left->X  + 40 , (*rt)->right->left->Y +40 );
                    delay(400);
                    left_down((*rt)->X, (*rt)->Y , (*rt)->right->left->X - 40 , (*rt)->right->left->Y +40);
                    (*rt)->right->left->X = (*rt)->X ;
                    (*rt)->right->left->Y = (*rt)->Y ;
                    (*rt)=RL((*rt));
                    update_xy((*rt),(*rt)->X , (*rt)->Y);
		}
            }
        }
        else{}
        (*rt)->height = height((*rt));
    }
    int ht(node * n)
    {
	if(n==NULL)
            return 0 ;
	else
            return n->height ;
    }
    node * LL(node *x )
    {
        node *temp = x->left ;
        x->left = temp->right ;
        temp->right  = x ;
        temp->height = height(temp);
        x->height = height(x);
	return temp ;
    }
    node * RR(node *x)
    {
        node * temp = x->right ;
        x->right = temp->left ;
        temp->left = x ;
	temp->height = height(temp);
	x->height = height(x);
	return temp ;
    }
    node * LR(node * x)
    {
        x->left = RR(x->left);
        return LL(x);
    }
    node * RL(node * x)
    {
        x->right = LL(x->right);
        return RR(x);
    }
    ///DELETE///////////////////////////////////
    void Delete()
    {
        Display(root,1);
        if(root==NULL)
            return ;
        int cd ;
        cout<<"enter value to be deleted"<<endl ;
        cin>>cd ;
        cout<<"deleting"<<endl ;
        Delete(cd,&root);
        cout<<"deleted succesfully"<<endl ;
    }
       void Delete(int e,node **r)
    {
	if((*r)==NULL)
        return;
	if(e < (*r)->data)
		Delete(e,&((*r)->left));
	else if(e > (*r)->data)
		Delete(e,&((*r)->right));
	else if((*r)->left !=NULL && (*r)->right != NULL)
	{
		//(*r)->data = findMin((*r)->right);
		Delete((*r)->data,&((*r)->right));
	}
    else
        {
		node *old  = (*r);
		(*r) = ((*r)->left!=NULL)?(*r)->left:(*r)->right;
		delete old;
		cout<<1;
		if((*r)!=NULL)
		inorderCheck(r);
		cout<<endl<<"Element "<<e<<"is Removed"<<endl;
	}
}
void inorderCheck(node **r)
{
	if((*r) != NULL)
        {
            if((*r)->left!=NULL)
            inorderCheck(&((*r)->left));
            if(ht((*r)->left)-ht((*r)->right) > 1)
            {
                if((*r)->left->left->data < (*r)->left->data)
                    (*r) =LL((*r));
                else
                    (*r) = LR((*r));
            }
        if((*r)->right!=NULL)
		inorderCheck(&((*r)->right));
		if(ht((*r)->right)-ht((*r)->left) > 1)
		{
		    if((*r)->right->right->data > (*r)->right->data)
                (*r) = RR((*r));
            else
                (*r) = RL((*r));
		}
	}
	(*r)->height = height((*r));
}
    ///DELETE ENDS///////////////////////////////////////////////////
    void display(node *rt)
    {
        if(rt->left)
            display(rt->left);
        cout <<rt->data <<'\t'<<rt->height<<endl;
        if(rt->right)
	    display(rt->right);
    }
    void blink(node * b , node * c , node * d)
    {
	for(int i = 0 ; i < 4 ; i++)
        {
        Circle(b->X,b->Y,BLUE);
        Circle(c->X,c->Y,BLUE);
        Circle(d->X,d->Y,BLUE);
        delay(300);
        Circle(b->X,b->Y,RED);
        Circle(c->X,c->Y,RED);
        Circle(d->X,d->Y,RED);
	delay(300);
        }
    }
    void Search()
    {
        int k ;
        settextstyle(3,HORIZ_DIR,3);
        outtextxy(5,getmaxy()-90,"ENTER KEY" );
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        cin>>k;
        clrscr();
        clearviewport();
        Display(root,1);
        search(root,k);
    }
    void search(node *rt , int x)
    {

        if(rt==NULL)
        {
        clearviewport();
        settextstyle(5,HORIZ_DIR,5);
        outtextxy(0,getmaxy()/2,"TREE IS EMPTY" );
        outtextxy(0,getmaxy()/2+30,"Press any key to continue");
        getch();
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        clearviewport();
	    return ;
        }
	highlight(rt,LIGHTBLUE);
	delay(350);
	if(rt->data == x)
	{
	    color_loop(rt);
	    settextstyle(3,HORIZ_DIR,3);
        outtextxy(5,getmaxy()-90,"ELEMENT FOUND" );
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	    return ;
	}
	if(rt->data > x )
	{
	    if(rt->left)
		search(rt->left,x);
	    else
	    {
	    settextstyle(3,HORIZ_DIR,3);
        outtextxy(5,getmaxy()-90,"ELEMENT  NOT FOUND" );
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		return ;
	    }
	}
	else if(rt->data < x )
	{
	    if(rt->right)
		search(rt->right,x);
	    else
	    {
	    settextstyle(3,HORIZ_DIR,3);
        outtextxy(5,getmaxy()-90,"ELEMENT NOT FOUND" );
        settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
                return ;
        }
        }
    }
    void find_min()
    {
        if(root == NULL)
        {
            clearviewport();
            settextstyle(5,HORIZ_DIR,5);
            outtextxy(0,getmaxy()/2,"TREE IS EMPTY" );
            outtextxy(0,getmaxy()/2+30,"Press any key to continue");
            getch();
            settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
            clearviewport();
            return;
        }
        Display(root,1);
        node * temp  = root ;
	while(temp->left != NULL)
	    {
                highlight(temp,10);
                delay(300);
                temp = temp->left ;
	    }
        color_loop(temp);
    }
    /////////////////menu
    void rect_high(int y)
    {
	rectangle(5,y , 200 , y+30);
    }
    void rem_rect(int y)
    {
	setcolor(8);
	rectangle(5,y , 200 , y+30);
	setcolor(WHITE);
    }
    int menu()
{
    int c , y = 10 ;
    rect_high(y);
    c = getch();
    while(1)
    {
        if(c==13)
        return (y-10)/6 ;
        if(y == 190 && c == 115)
        {
            rem_rect(y);
            y = 10 ;
            rect_high(y);
        }
        else if(y==10 && c== 119)
        {
            rem_rect(y);
            y = 190 ;
            rect_high(y);
        }
        else if(c==115)
        {
            rem_rect( y );
	    y+=30 ;
            rect_high( y); //y+30+35) ;
        }
        else if(c==119)
        {
            rem_rect( y );
            y-=30;
            rect_high(y); //y+30+35) ;
	}
	c = getch();
    }
    y-=10 ;
    return y/6 ;
}
    /////////////
};
avl A;
//////////////////////////////////////////////////////
int main()
{
    clrscr();
    int gdriver=DETECT , gmode;
    initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
    ///INTRO PAGE ////////////////////////////////////////////////////////////////////////////////////////
    int count=0 , i = 0 , x = 160 ;
    setbkcolor(BLACK);
    while(1)
    {
	setcolor(i);
	settextstyle(3,HORIZ_DIR,5);
	outtextxy(210,120,"AVL Tree");
	outtextxy(260,180,"and");
	outtextxy(205,240,"Rat maze");
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(360,348,"Made By:-");
	settextstyle(3,HORIZ_DIR,3);
	i++;
	if(i==14)
	    i=0;
	line(x,295,x,315);
	delay(10);
	count++;
	x++;
	if(x==450)
	    break;
    }
	clearviewport();
	i = 0 ;
	count = 0 ;
	x = 160 ;
	while(1)
    {
	setcolor(i);
	settextstyle(3,HORIZ_DIR,10);
	outtextxy(80,120,"AVL Tree");
	i++;
	if(i==14)
	    i=0;
	line(x,295,x,315);
	delay(10);
	count++;
	x++;
	if(x==450)
	    break;
    }
    clearviewport();
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    ///INTRO PAGE END /////////////////////////////////////////////////////////////////////////////////////
    int choice  ;
    do
    {
	clearviewport();
	settextstyle(3,HORIZ_DIR,4);
	setfillstyle(SOLID_FILL , 8);
	floodfill(100,20,WHITE);
	setcolor(10);
	outtextxy(10,3,"1.Insert");
	outtextxy(10,33,"2.Search");
	outtextxy(10,63,"3.Delete" );
	outtextxy(10,93,"4.Find min");
	outtextxy(10,123,"5.Display ");
	outtextxy(10,153,"6.Rat Maze");
	outtextxy(10,183,"7.Exit");
	setcolor(15);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	choice = A.menu() ;
	delay(100);
	clrscr();
	clearviewport();
	switch(choice)
	{
	case 0:
	    A.Insert();
	    break ;
	case 5:
	    A.Search();
	    break ;
	case 10:
	    A.Delete();
	    break ;
	case 15:
	    A.find_min();
	    break ;
	case 20:
	    A.Display(A.root,1);
	    break ;
	case 30:
	    break ;
    case 25:
        /// RAT MAZE OPTION///////////////////////////////////////////////////////
        int i = 0 ;
	int count = 0 ;
	int x = 160 ;
	while(1)
    {
	setcolor(i);
	settextstyle(3,HORIZ_DIR,10);
	outtextxy(70,120,"RAT MAZE");
	i++;
	if(i==14)
	    i=0;
	line(x,295,x,315);
	delay(10);
	count++;
	x++;
	if(x==450)
	    break;
    }
    clearviewport();
    setcolor(WHITE);

        int j;
        settextstyle(3,HORIZ_DIR,5);
	for(i=0;i<=360;++i)
	{
	    circle(300,200,80);
	    pieslice(300,200,0,i,80);
	    outtextxy(215,320,"Loading,Please Wait!");
	    delay(5);
	}
	clearviewport();
        settextstyle(3,HORIZ_DIR,3);
    initial_display();
    if(game(0,0))
    {
        clearviewport();
	int i = 0 ;
	int count = 0 ;
	int x = 160 ;
	while(1)
    {
	setcolor(i);
	settextstyle(3,HORIZ_DIR,10);
	outtextxy(80,120,"TARGET");
	i++;
	if(i==14)
	    i=0;
	line(x,295,x,315);
	delay(10);
	count++;
	x++;
	if(x==450)
	    break;
    }
    clearviewport();
    setcolor(WHITE);
	}
    else
	cout<<"no solution" << endl;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
        /// RAT MAZE OPTION ENDS///////////////////////////////////////////////////////
        break ;
	default:
	    cout<<"enter valid choice"<<endl;
	    break;
	}
	settextstyle(5,HORIZ_DIR,5);
	  outtextxy(5,getmaxy()-90,"press any key too continue");
	  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	getch();
	clrscr();
	clearviewport();
    }while(choice != 30);
    return 0 ;
}
