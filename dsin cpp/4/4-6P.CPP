#include <iostream.h>
#include <stdio.h>
#include <conio.h>
class node {
    friend class linkedList;
    friend queue;
  private:
    int time;
    int duration;
    int type;
    node *next;
};
class linkedList {
    public:
      linkedList();
      void  place(node *);
      void  popEvent(node *auxinfo);
      void  arrive(int atime, int dur);
      void  aux(node auxinfo, int qindex, int dtime, float &count, float &tottime);
      void  depart(int atime, int dur, float &count, float &tottime);
      node  *getEvList(){return evlist;}
    private:
      node *evlist;
};
linkedList list;
//*******************
void linkedList::aux(node auxinfo, int qindex, int dtime, float &count, float &tottime)
{
   int atime, dur;
   cout << "Enter time and duration:";
   cin >> auxinfo.time >> auxinfo.duration;
   auxinfo.type = -1; /* an arrival*/
   auxinfo.next = NULL;
   list.place(&auxinfo);
   /* run the simulation as long as */
   /* the event list is not empty   */
   while(list.getEvList() != NULL)
   {
      list.popEvent(&auxinfo);
      /* check if the next event     */
      /* is an arriveal or departure */
      if(auxinfo.type == -1)
      {
	 atime = auxinfo.time;
	 dur = auxinfo.duration;
	 list.arrive(atime, dur);
      }
      else {
	 /* a departure   */
	 qindex = auxinfo.type;
	 dtime = auxinfo.time;
	 list.depart(qindex, dtime, count, tottime);
     }//end of else
   }//end of while
}
//******************
class queue {
  public:
    void  insert(node *);
    void  qremove(node *);
    node  *getFront() { return front;}
    void  setFront(node *value) {front = value;}
    node  *getRear()  { return rear;}
    void  setRear(node *value) { rear = value;}
    int   getNum() { return num;}
    void  setNum(int value) { num = value;}
  private:
    node *front;
    node *rear;
    int num;
};
//****************
queue q[4];
//****************
linkedList::linkedList()
{
  evlist = NULL;
}
//*************************
void linkedList::popEvent(node *auxinfo)
{
    auxinfo -> time = evlist -> time;
    auxinfo -> type = evlist -> type;
    auxinfo -> duration = evlist -> duration;
    evlist = evlist -> next;
}
//******************
void linkedList::place(node *auxinfo)
{
   node *h, *p, *help;
   help = new node;
   *help = *auxinfo;
   if(evlist == NULL)
      evlist = help;
   else
   {
       p = h = evlist;
       while(h != NULL)
       {
	     if(help -> time > h ->time )
	     {
		p = h;
		h = h -> next;
	     }
	     else
		break;
       }//end of while
       help -> next = h;
       if(h == evlist)
	  evlist = help;
       else
	  p -> next = help;
   }//end of else
}
//******************
void linkedList::arrive(int atime, int dur)
{
  node auxinfo;
  int i, j, small;
  // find the shortest queue
  j = 0;
  small = q[0].getNum();
  for(i = 1; i < 4; i ++)
     if(q[i].getNum() < small)
     {
	small = q[i].getNum();
	j = i;
     }//end of if and for
  //queue j is the shorthest
  //Insert a new customer node.
  auxinfo.time = atime;
  auxinfo.duration = dur;
  auxinfo.type = j;
  auxinfo.next = NULL;
  q[j].insert(&auxinfo);
  //check if this is the only node on the queue.
  //if it is, the customer's departure node must
  // be placed on the event list
  if(q[j].getNum() == 1)
  {
     auxinfo.time = atime + dur;
     place(&auxinfo);
  }
  //if any input remains, read the next data pair
  // and place an arrival on the event list.
  cout << "Enter time:";
  if(cin >> auxinfo.time)
  {
     cout << "Enter duration:";
     cin >> auxinfo.duration;
     auxinfo.type = -1;
     auxinfo.next = NULL;
     place(&auxinfo);
  }//enf if
}
//*****************
void linkedList::depart(int qindex, int dtime, float &count, float &tottime)
{
  node *p, auxinfo;
  q[qindex].qremove(&auxinfo);
  tottime = tottime +(dtime - auxinfo.time);
  count++;
  //if there are any more customers on the queue
  //place the departure of the next customer onto
  //the event list after computing its departure time
  if(q[qindex].getNum() > 0)
  {
    p = q[qindex].getFront();
    auxinfo.time = dtime + p -> duration;
    auxinfo.type = qindex;
    auxinfo.next = NULL;
    place(&auxinfo);
  }
}
//****************
void queue::qremove(node *auxinfo)
{
    node *p;
    if(front != NULL)
    {
       p = front;
       num--;
       auxinfo -> time = front -> time;
       auxinfo -> type = front -> type;
       auxinfo -> duration = front -> duration;
       front =  front -> next;
       p -> next = NULL;
       delete p;
    }
}
//***************
void queue::insert(node *auxinfo)
{
  node *help;
  help = new node;
  *help = *auxinfo;
  num++;
  if(front == NULL)
      front = rear = help;
  else
     {
	rear -> next = help;
	rear = rear -> next /*auxinfo*/;
     }
}
//***********************
int main()
{
   int atime, dtime, dur, qindex;
   float count, tottime;
   node auxinfo;
   count = tottime = 0;
   for(qindex = 0; qindex < 4; qindex++)
   {
     q[qindex].setNum(0);
     q[qindex].setFront(NULL);
     q[qindex].setRear(NULL);
   }//end of for
   clrscr();
   list.aux(auxinfo, qindex, dtime, count, tottime);
   cout << "Average time is :" << tottime/count;
   getch();
   return 0;
}








