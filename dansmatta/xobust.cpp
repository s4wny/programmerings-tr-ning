#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct state
{
    state()
    {
        s1 = ' ';
        s2 = ' ';
    }
    
    void operator=(const state & a)
    {
        
        if(a.s1 != ' ')
            this->s1 = a.s1;
        if(a.s2 != ' ')
            this->s2 = a.s2;
        
    }
    
    int len()
    {
        if(s2 != ' ')
            return 2;
        
        return 1;
    }
    
    char s1;
    char s2;
};

vector<state> takter;

unsigned int cmp(state & a, state &b)
{
    unsigned int i=0;
    
    if (b.s1 != a.s1 && b.s1 != a.s2) {
        i++;
    }
    
	if(b.len() == 2 && a.len() == 2)
    {
        if (b.s2 != a.s2 && b.s2 != a.s1) {
            i++;
        }
    }
    
    
    
    return i;
}


int rec(state & st)
{
    unsigned int n = 0;
    
    for (int j = 0; j<takter.size(); j++)
    {
        if(takter[j].len() == 1 && cmp(st, takter[j]) == 1 || takter[j].len() == 2 && cmp(st, takter[j]) == 0)
        {
			if(j > 0 && cmp(takter[j],takter[j-1])==0)
			{

			}
			else
			{
				n++;
			}
        }else if(cmp(st, takter[j]) == 2)
        {
            n+=2;
            st = takter[j];
        }else if((takter[j].len() == 2 && cmp(st, takter[j]) == 1) || ( takter[j].len() == 1 && cmp(st, takter[j]) == 0))
        {
           if(j>0)
		   {
			   if(takter[j].len() == 2)
			   {
				   n+= cmp(takter[j-1],takter[j]);
					st = takter[j];

					if(st.s1 == ' ')
						st.s1 = takter[j-1].s1;
					else if(st.s2 == ' ')
						st.s2 = takter[j-1].s1;
			   }else
			   {
				   st.s1 = takter[j].s1;
				   if(takter[j-1].s1 != takter[j].s1)
					   st.s2 = takter[j-1].s1;
				   else
					   st.s2 = takter[j-1].s2;
			   }
		   }else
		   {
			   if(takter[j].len() == 2)
			   {
				   n+= cmp(st,takter[j]);
					st = takter[j];

					if(st.s1 == ' ')
						st.s1 = st.s1;
					else if(st.s2 == ' ')
						st.s2 = st.s1;
			   }else
			   {
				   st.s1 = takter[j].s1;
				   if(st.s1 != takter[j].s1)
					   st.s2 = st.s1;
				   else
					   st.s2 = st.s2;
			   }
		   }
        }

		cout << n<<"\n";
    }
    
    
    
    return n;
}



string nam="HVUN    ";

void unittest()
{

	unsigned int Num;
    cin>>Num;
    
    state cstate;
    
    cstate.s1 = 'V';
    cstate.s2 = 'H';
    
    
	for(int i = 0; i<Num; i++)
	{
        string s;
        state st;
		s = nam[rand()%4];
		s += nam[rand()%7];
		
        std::sort(s.begin(), s.end());

		cout<<s << "\n";
        
        st.s1 = s[0];
        if(s.length() >1)
        {
            st.s2 = s[1];
        }
        
        if(takter.size() == 0 && !cmp(st,cstate) )
		{
        
		}else if( takter.size() == 0  || cmp(st,takter[takter.size()-1]) )
		{
			takter.push_back(st);
		}
        
	}
	int e;
    
    cin>> e;
    
    int moves = rec(cstate);

	cout<<moves;
   

}

int main()
{
	srand(time_t());
	//unittest();

    unsigned int Num;
    cin>>Num;
    
    state cstate;
    
    cstate.s1 = 'V';
    cstate.s2 = 'H';
    
    
	for(int i = 0; i<Num; i++)
	{
        string s;
        state st;
		cin>>s;
		
        std::sort(s.begin(), s.end());
        
        st.s1 = s[0];
        if(s.length() >1 && s[1] != s[0])
        {
            st.s2 = s[1];
        }
        


		takter.push_back(st);
        
	}
	
    
    
    
    int moves = rec(cstate);
    
	cout<<moves;
   
    cin >> moves;
	return 0;
}


