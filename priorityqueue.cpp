#include<iostream>
#define SIZE 5
int order;
using namespace std;
class Data
{
        public:
                  char job[20];
                  int priority;
                  int incoming_order;
};
class Queue: public Data
{
          private:
                        Data Q[SIZE];
                        int frontt,rear;
         public:
                      Queue();
                      void init();
                      void Insert(Data obj);
                      Data Delete();
                      int isFull();
                     int isEmpty();
                     void display();
};
void Queue :: init()
{
         frontt=-1;
         rear=-1;
         order=0;
}
Queue :: Queue()
{
         init();
}
void Queue :: Insert(Data data)
{
       if(isFull())
       {
            cout<<"\n\t Stack overflow occures";
       }
       else
       {
            if(rear==-1)
            {
                    frontt=0;
                    rear=0;
            }
            else
            {
                   rear=rear+1;
            }
            Q[rear]=data;
            cout<<"\n\t "<<data.job<<"inserted succesfully";

            Data temp;
            for(int i=frontt; i<rear; i++)
            {
                    for(int j=i+1; j<=rear; j++)
                    {
                           if(Q[i].priority<Q [j].priority)
                           {
                                    temp=Q[i];
                                    Q[i]=Q[j];
                                    Q[j]=temp;
                           }
                           else
                           {
                                     if(Q[i].priority == Q[j].priority)
                                     {
                                             if(Q[i].incoming_order > Q[j].incoming_order)
                                             {
                                                    temp=Q[i];
                                                    Q[i]=Q[j];
                                                    Q[j]=temp;
                                             }
                                     }
                           }
                    }
            }
       }
}
Data Queue :: Delete()
{
        Data data;
        if(isEmpty())
        {
                cout<<"\n\t Stack overflow occures";
        }
        else
        {
                data=Q[frontt];
                if(rear==frontt)
                {
                        frontt=-1;
                        rear=-1;
                }
                else
                {
                        frontt=frontt+1;
                }
        }
        return data;
}
int Queue :: isFull()
{
       if(rear==SIZE)
       {
              return 1;
       }
       return 0;
}
int Queue :: isEmpty()
{
       if(frontt==-1)
       {
              return 1;
       }
       return 0;
}
void Queue :: display()
{
        if(isEmpty())
        {
            cout<<"\n\t Queue is empty";
        }
        else
        {
                 for(int i=frontt; i<=rear;i++)
                 {
                        cout<<" "<<Q[i].job;
                 }
        }
}
int main()
{
         Queue obj;
         Data obj1;
         int ch;
         char c;
         do
         {
                   cout<<"\n\t Menu";
                   cout<<"\n\t 1. Initialize";
                   cout<<"\n\t 2.Insert";
                   cout<<"\n\t 3.Delete";
                   cout<<"\n\t 4.isFull()";
                   cout<<"\n\t 5.isEmpty()";
                   cout<<"\n\t 6.Display";
                   cout<<"\n\t 7.Exit";

                   cout<<"\n\t Enter your choice(1-7): ";
                   cin>>ch;

                   switch(ch)
                   {
                          case 1:
                                     break;
                          case 2:
                                       cout<<"\n\t Enter the job name: ";
                                       cin>>obj1.job;
                                       cout<<"\n\t Enter the priority of job: ";
                                       cin>>obj1.priority;
                                       obj.incoming_order=order++;
                                       obj.Insert(obj1);
                                      break;
                          case 3:
                                      obj1=obj.Delete();
                                     break;
                          case 4:
                                      if(obj.isFull()==1)
                                      {
                                            cout<<"\n\t Queue is full";
                                      }
                                      else
                                      {
                                            cout<<"\n\t Queue is not full";
                                      }
                                      break;
                          case 5 :
                                      if(obj.isEmpty()==1)
                                      {
                                            cout<<"\n\t Queue is empty";
                                      }
                                      else
                                      {
                                            cout<<"\n\t Queue is not empty";
                                      }
                                     break;
                          case 6:obj.display();
                                      break;
                          case 7:
                                       //exit(0);
                                      break;
                          default:
                                        cout<<"\n\t Invalid choice";
                   }
                   cout<<"\n\t Do you want to continue(y/n): ";
                   cin>>c;
         }while(c=='Y'|| c=='y');
}
