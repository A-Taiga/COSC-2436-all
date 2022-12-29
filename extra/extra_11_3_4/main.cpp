#include <iostream>
#include "graph.h"
using namespace std;


int main() {


    string states[] = 
                { 
                    "Alabama","Arkansas",
                    "Arizona","California","Colorado","Connecticut",
                    "Delaware","Florida","Georgia",
                    "Iowa","Idaho","Illinois","Indiana","Kansas",
                    "Kentucky","Louisiana","Massachusetts","Maryland","Maine",
                    "Michigan","Minnesota","Missouri","Mississippi","Montana",
                    "North Carolina","North Dakota","Nebraska","New Hampshire",
                    "New Jersey","New Mexico","Nevada","New York","Ohio","Oklahoma",
                    "Oregon","Pennsylvania","Rhode Island","South Carolina",
                    "South Dakota","Tennessee","Texas","Utah","Virginia",
                    "Vermont","Washington","Wisconsin","West Virginia","Wyoming"
                };
    string abb[]= { 
                "AL", "AR", "AZ", "CA", "CO", "CT", "DE", "FL", "GA", 
                "IA", "ID", "IL", "IN", "KS", "KY", "LA", "MA", "MD", "ME", "MI", "MN", "MO", 
                "MS", "MT", "NC", "ND", "NE", "NH", "NJ", "NM", "NV", "NY", "OH", "OK", "OR", "PA", 
                "RI", "SC", "SD", "TN", "TX", "UT", "VA", "VT", "WA", "WI", "WV", "WY"
                };

    graph g(sizeof(states)/sizeof(states[0]));

    for(int i = 0 ;i < sizeof(states)/sizeof(states[0]); i++)
        g.add(states[i],abb[i]);

    g.link("Texas","Louisiana",1);
    g.link("Texas","Oklahoma",1);
    g.link("Texas","New Mexico",1);
    g.link("Texas","Arkansas",1);

    g.link("California","Oregon",1);
    g.link("California","Nevada",1);
    g.link("California","Arizona",1);

    g.link("Washington","Idaho",1);


    g.link("Oregon", "Idaho",1);
    g.link("Oregon", "Washington",1);
    g.link("Oregon", "Nevada",1);

    g.link("Nevada","Idaho",1);
    g.link("Nevada","Utah",1);
    g.link("Nevada","Arizona",1);

    g.link("Arizona","Utah",1);
    g.link("Arizona","Colorado",1);
    g.link("Arizona","New Mexico",1);

    g.link("Utah","Colorado",1);
    g.link("Utah","Wyoming",1);
    g.link("Utah","Idaho",1);

    g.link("Idaho","Wyoming",1);
    g.link("Idaho","Montana",1);

    g.link("Montana","North Dakota",1);
    g.link("Montana","South Dakota",1);
    g.link("Montana","Wyoming",1);

    g.link("Wyoming","South Dakota",1);
    g.link("Wyoming","Colorado",1);
    g.link("Wyoming","Nebraska",1);

    g.link("Colorado","New Mexico",1);
    g.link("Colorado","Nebraska",1);
    g.link("Colorado","Oklahoma",1);
    g.link("Colorado","Kansas",1);

    g.link("New Mexico","Oklahoma",1);

    g.link("Oklahoma","Arkansas",1);
    g.link("Oklahoma","Kansas",1);
    g.link("Oklahoma","Missouri",1);

    g.link("Kansas","Missouri",1);
    g.link("Kansas","Nebraska",1);
    g.link("Kansas","Missouri",1);

    g.link("Nebraska","South Dakota",1);
    g.link("Nebraska","Iowa",1);
    g.link("Nebraska","Missouri",1);

    g.link("South Dakota","Iowa",1);
    g.link("South Dakota","North Dakota",1);
    g.link("South Dakota","Minnesota",1);

    g.link("North Dakota","Minnesota",1);

    g.link("Minnesota","Wisconsin",1);
    g.link("Minnesota","Iowa",1);

    g.link("Iowa","Illinois",1);
    g.link("Iowa","Wisconsin",1);
    g.link("Iowa","Missouri",1);

    g.link("Missouri","Arkansas",1);
    g.link("Missouri","Illinois",1);
    g.link("Missouri","Kentucky",1);
    g.link("Missouri","Tennessee",1);

    g.link("Arkansas","Mississippi",1);
    g.link("Arkansas","Louisiana",1);
    g.link("Arkansas","Tennessee",1);

    g.link("Louisiana","Mississippi",1);

    g.link("Mississippi","Alabama",1);
    g.link("Mississippi","Tennessee",1);
    g.link("Mississippi","Alabama",1);

    g.link("Alabama","Georgia",1);
    g.link("Alabama","Florida",1);
    g.link("Alabama","Tennessee",1);

    g.link("Tennessee","Kentucky",1);
    g.link("Tennessee","Virginia",1);
    g.link("Tennessee","North Carolina",1);
    g.link("Tennessee","Georgia",1);

    g.link("Kentucky","Indiana",1);
    g.link("Kentucky","Ohio",1);
    g.link("Kentucky","West Virginia",1);
    g.link("Kentucky","Virginia",1);
    g.link("Kentucky","Illinois",1);

    g.link("Illinois","Wisconsin",1);
    g.link("Illinois","Indiana",1);

    g.link("Wisconsin","Michigan",1);

    g.link("Michigan","Ohio",1);
    g.link("Michigan","Indiana",1);

    g.link("Indiana","Ohio",1);

    g.link("Ohio","West Virginia",1);
    g.link("Ohio","Pennsylvania",1);

    g.link("West Virginia","Pennsylvania",1);
    g.link("West Virginia","Virginia",1);
    g.link("West Virginia","Maryland",1);


    g.link("Pennsylvania","Maryland",1);
    g.link("Pennsylvania","New York",1);
    g.link("Pennsylvania","New Jersey",1);
    g.link("Pennsylvania","Delaware",1);

    g.link("Maryland","Virginia",1);
    g.link("Maryland","Delaware",1);

    g.link("Delaware","New Jersey",1);

    g.link("Virginia","North Carolina",1);


    g.link("Georgia","South Carolina",1);
    g.link("Georgia","North Carolina",1);
    g.link("Georgia","Florida",1);

    g.link("South Carolina","North Carolina",1);

    g.link("New York","Massachusetts",1);
    g.link("New York","Vermont",1);
    g.link("New York","Connecticut",1);

    g.link("Vermont","New Hampshire",1);
    g.link("Vermont","Massachusetts",1);

    g.link("New Hampshire","Maine",1);
    g.link("New Hampshire","Massachusetts",1);

    g.link("Rhode Island","Massachusetts",1);
    g.link("Rhode Island","Connecticut",1);





    g.print();


    return 0;
}