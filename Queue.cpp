#include "Queue.h"

Queue::Queue()
{
    head=NULL;
    tail=NULL;
}

Queue::~Queue()
{

    while(head!=NULL)
    {
        Node* temp=head;
        head= head->next;
        if (head!=NULL)
        {
            head->prev=NULL;
        }
        //std::cout<<"Deallocating value: "<<temp->unit<<std::endl;
        delete temp;
        temp=NULL;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if (head==NULL)
    {
        head = new Node;
        head->unit=unit;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        Node* temp=new Node;
        tail->next=temp;
        temp->prev=tail;
        tail=tail->next;
        tail->next=NULL;
        tail->unit=unit;
    }
}

void Queue::Update(long int& frame, SDL_Renderer* gRenderer, Unit* target, LTexture* image, LTexture* missileimage, Mix_Chunk* gunsound, Mix_Chunk* missile)
{
    Unit* gun=NULL;
    if(head != NULL)
    {
        Node* temp = head;
        while (temp!=NULL)   //looping foe the queue
        {

            if (temp->unit->GetAlive()==false)    //until the alive is false
            {
                if (temp==head)
                {
                    head=head->next;    //shift to next head
                    if (head!=NULL)
                    {
                        head->prev=NULL;
                    }
                    delete temp;
                    temp=head;
                }
                else if (temp==tail)
                {
                    tail=tail->prev;    //shift to previous tail
                    tail->next = NULL;
                    delete temp;
                    temp=tail;

                }
                else          //if node is in the middle
                {
                    temp->next->prev=temp->prev;
                    temp->prev->next=temp->next;
                    delete temp;
                    temp=temp->prev;
                }
                break;
            }
            temp->unit->Render(frame, gRenderer);
            if (temp->unit->GetType()==5)
            {
                temp->unit->Move(frame);
            }
            else
            {
                temp->unit->Move();
            }
            if (temp->unit->Attack()==1)
            {
                Point departure=temp->unit->GetPosition();
                Point destination=target->GetPosition();
                if (temp->unit->GetType()==4 || temp->unit->GetType()==5)
                {
                    gun = new Missiles(missileimage, departure, target);
                    Mix_PlayChannel(-1,missile,0);
                }
                else
                {
                    gun = new EBullet(image, departure, destination);
                    Mix_PlayChannel(-1,gunsound,0);
                }
                Enqueue(gun);
                temp->unit->Setfire(-1);
            }
            temp=temp->next;    //shift to next node

        }
    }
}

void Queue::Save(FILE* filewriter)
{
    char buff[32];
    if (head!=NULL)
    {
        Node* temp=head;
        while (temp!=NULL) //Run for loop times the number of drivers
        {
            fputs("[Unit]\n", (FILE*)filewriter); //Reading the name of the driver directly
            Point position=temp->unit->GetPosition();
            fputs(itoa(position.x, buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
            fputs(itoa(position.y, buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
            fputs(itoa(temp->unit->GetState(), buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
            fputs(itoa(temp->unit->GetType(), buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
            temp=temp->next;
        }
    }

}

void Queue::Collision(LTexture* explosionimage, LTexture* powerupimage, LTexture* bossexplode, Unit* target, Mix_Chunk* explodes, Mix_Chunk* bonus, int* score)
{
    Unit* generator= NULL;
    Node* temp=head;
    Node* temp2=NULL;

    while(temp != NULL)
    {
        if (temp->unit->GetType() == 100 || temp->unit->GetType() == 1 || temp->unit->GetType() == 2 ||
            temp->unit->GetType() == 13 || temp->unit->GetType() == 14 || temp->unit->GetType()==3 ||
            temp->unit->GetType()==4 || temp->unit->GetType() == 50 || temp->unit->GetType() == 51 || temp->unit->GetType()==5)
        {
            temp2 = head;
            while(temp2 != NULL)
            {
                if (temp2->unit->GetType() == 11 || temp2->unit->GetType() == 12)
                {
                    if ((temp2->unit->left()<=temp->unit->right()) && (temp2->unit->right()>=temp->unit->left()))
                    {
                        if (temp2->unit->bottom()>=temp->unit->top())
                        {
                            if (temp->unit->GetType() == 1 || temp->unit->GetType()==100)
                            {
                                temp->unit->Move();
                            }
                            if (temp2->unit->top()<=temp->unit->bottom() && temp->unit->GetState()!=DIE)
                            {
                                temp->unit->SetHealth(-1);
                                *score=*score+5;
                                if (!(temp->unit->GetType()==50 || temp->unit->GetType()==51))
                                {
                                    temp2->unit->SetAlive(false);
                                }
                                if (!(temp->unit->GetType()==13 || temp->unit->GetType()==14))
                                {
                                    if (temp->unit->GetHealth()==0)
                                    {
                                        int random = rand()%10;
                                        if (random<2)
                                        {
                                            Point powerup=temp->unit->GetPosition();
                                            generator=new Powerups(powerupimage, powerup, random);
                                            Enqueue(generator);
                                        }
                                        if (temp->unit->GetType()==3 || temp->unit->GetType()==4)
                                        {
                                            Point explode=temp->unit->GetPosition();
                                            generator=new Explosion(explosionimage, explode, ENEMY);
                                            Enqueue(generator);
                                            Mix_PlayChannel(-1,explodes,0);
                                        }
                                        else if (temp->unit->GetType()==5)
                                        {
                                            Point explode=temp->unit->GetPosition();
                                            generator=new Explosion(explosionimage, explode, BOSS);
                                            Enqueue(generator);
                                            Mix_PlayChannel(-1,explodes,0);
                                        }
                                    }
                                }


                                temp2=NULL;

                            }

                        }

                    }


                    if (temp2 != NULL)
                    {
                       temp2 = temp2->next;
                    }

                }

                else if ( (temp2->unit->left()<=target->right()) && (temp2->unit->right()>=target->left()) &&
                    (temp2->unit->bottom()>=target->top()) && (temp2->unit->top()<=target->bottom()) &&
                    (target->GetState()!=DIE) && (target->GetAlive()) &&
                    (temp2->unit->GetType()==13 || temp2->unit->GetType()==14 || temp2->unit->GetType()==50 ||
                     temp2->unit->GetType()==51 || temp2->unit->GetType()==5) )
                {
                    if (temp2->unit->GetType()==5)
                    {
                        target->SetHealth(-2);
                    }
                    else if (temp2->unit->GetType()==50)
                    {
                        if (target->GetHealth()<=8)
                        {
                            target->SetHealth(2);
                            Mix_PlayChannel(-1,bonus,0);
                        }
                    }
                    else if (temp2->unit->GetType()==51)
                    {
                        *score=*score+100;
                        Mix_PlayChannel(-1,bonus,0);
                    }
                    else
                    {
                        target->SetHealth(-1);
                    }

                    if (temp2->unit->GetType()!=5)
                    {
                        temp2->unit->SetAlive(false);
                        temp2=NULL;
                        return;
                    }

                }

                else
                {
                    temp2 = temp2->next;
                }
            }
            temp=temp->next;
        }

        else
        {
            temp=temp->next;
        }
    }

}
