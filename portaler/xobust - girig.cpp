
#include <iostream>
#include <unordered_map>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

/*
 
  () -Cykel
  /\ -Grenar
 /\/\
 
 
 */


//största antalet protaler
#define maxsize 50001

//första tillgängliga grupp
int first_group;

struct Group
{
    
    Group()
    {
        id = first_group++;
        type = 0;
        high = 0;
        low = 0;
        add = 0;
    }
    
    //Om gruppen är av green typen så sparar denhär mapen avståndet till andra grenar
    //eller cykeln den är ansluten till, den första inten är vilken grupp den är andsluten till
    //Det andra paret av nummer är var någonstans på grenen denhär vägen kommer att leda dig till och hur långt det är dit.
    unordered_map<int, pair<int, int>> merge;
    
    int id;
    int type; //1 = cykel, 2=gren
    long high; //Högsta numret i gruppen
    long low; //Lägsta numeret i gruppen
    long add;
    
};


class Portal
{
    
public:
    long new_index; //Nya indexen som noden får
    long exit; //Vart portalen leder enligt det gamla index systmet
    Group * group; //Vilken grupp noden tillhör
    
    Portal()
    {
        new_index = 0;
        exit = 0;
        group = new Group();
        
    }
    
    //Returnerar den nya indexen + förskjutning
    long i() const
    {
        return new_index + group->add;
    }
    
    bool in(const Group * g)const
    {
        return i() <= g->high && i() >= g->low;
    }
    
    //Avtånd mellan två portaler
    long dist(Portal &p) const;
    
};


//Array som inehåller alla portaler
Portal portals[maxsize];



long Portal::dist(Portal &p) const
{
    //Om de är i samma grupp
    if (p.group->id == this->group->id)
    {
        //Om du ska hitta avtåndet i en cykel
        if (group->type == 1)
        {
            if (p.i() < i())
                return group->high - i() + 1 + p.i() - group->low;
            else
                return p.i() - i();
        }
        
        //Avståndet i en gren
        if (group->type == 2)
        {
            if (p.in(group) && p.i() > i())
                return p.i() - i();
            else
                return -1;
        }
        
        
    }
    else
    {
        
        //Om det finns en väg mellan de två nodernas grupper
        if (group->merge.find(p.group->id) != group->merge.end())
        {
            //Om noden har en index högre än där grenen ansluter till dens grupp
            if (portals[group->merge[p.group->id].first].i() <= p.i())
            {
                return group->high - i() + 1 + group->merge[p.group->id].second + p.i() - portals[group->merge[p.group->id].first].i();
            }
            else if (p.group->type == 1)
            {
                return group->high - i() + 1 + group->merge[p.group->id].second + p.group->high - portals[group->merge[p.group->id].first].i() + p.i() - p.group->low + 1;
            }
            
        }
        else
            return -1;
        
    }
    
    
    return -1;
}


//Första index för det nya index systemet
long first;

//Skapa den nya datastrukturen med grupper
//Varje nod besöks 1 gång O(N)
//a = noden som skall besökas, low = lägsta noden (ny index) som besökts (början på en gren)
inline Group * rec(long a, const long & low)
{
    Portal * p = &portals[a];
    
    //Om noden inte har fått en ny index
    if (p->i() == 0) {
        //Ge en ny index
        p->new_index = first++;
        
        Group * g = rec(p->exit, low);
        
        //Om vi ansluter till en cykel
        if (g->type == 1)
        {
            //Om den nuvarande noden finns i cykeln
            if (p->in(g))
            {
                //sätt nodens grupp till cykelns
                return p->group = g;
                
            }
            else
            {
                //Annars skapa en gren
                p->group->type = 2;
                p->group->merge[portals[p->exit].group->id] = make_pair(p->exit, 0);
                p->group->low = low;
                p->group->high = p->new_index;
                
                return p->group;
            }
            
            
        }
        else
        {
            //Om numret inte finns i den nuvarande grenen
            if (!p->in(g)) {
                //_(Optimering)_
                //Om du ansluter en nod i början av grenen
                if (portals[p->exit].i() == g->low)
                {
                    //Flytta upp noderna i grenens index så att de nu är över den nuvarande nodens index
                    g->add += (p->i() - g->low) + 1;
                    g->high += (p->i() - g->low) + 1;
                    
                    first = g->high + 1;
                    p->new_index -= g->add;
                    g->low = low;
                }else
                {
                    //Om den nya noden ansluter mitt på grenen skapa en ny gren.
                    p->group->type = 2;
                    //Hämta avtånde och anslutningsinformation från överliggadne gren
                    for (auto item : g->merge)
                        p->group->merge[item.first] = make_pair(item.second.first, item.second.second + g->high - portals[p->exit].i() + 1);
                    
                    p->group->merge[g->id] = make_pair(p->exit, 0);
                    p->group->low = low;
                    p->group->high = p->new_index;
                    
                    return p->group;
                }
            }
            else
            {
                //Om noden finns på grenen justera dens index
                p->new_index -= g->add;
            }
            
            return p->group = g;
            
        }
        
    }
    else
    {
        //Om noden är besökt men inte har en grupp
        if (p->group->type == 0)
        {
            //Skapa en cykel
            p->group->type = 1;
            p->group->low = p->i();
            p->group->high = first - 1;
            
            return p->group;
            
        }
        else
        {
            return p->group;
        }
    }
    
}



int main() {
    int N, Q;
    
    first = 1;
    first_group = 0;
    
    //Bost my io 2014 anversery edition 100% tested & Clean
    std::ios_base::sync_with_stdio(false);
    
    cin >> N;
    
    long dir;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> dir;
        portals[i].exit = dir;
    }
    
    //Besök alla noder
    for (int i = 1; i <= N; i++)
    {
        long f = first;
        rec(i, f);
    }
    
    
    cin >> Q;
    
    int a=0, b;
    
    for (int i = 0; i<Q; i++)
    {
        cin >> a >> b;
        cout << portals[a].dist(portals[b]) << "\n";
        
    }
    
    
    return 0;
}