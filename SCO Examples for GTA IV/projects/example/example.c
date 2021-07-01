/*	---------------------------------------------------------------
     This source contains GTAIV/EFLC PC script functioning codes.

     This file is a part of SC-CL Project (C)

*    AUTHORS :
*		Rocko Tompkins
*		Nathan James

     Created Some Natives using Existing Game Natives for Convenience.

     Edited by SG a.k.a. Gaming With SG (In YouTube)
    ---------------------------------------------------------------  */


#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"
#include "example.h"


//Asking VEHICLE From Game Process
void LoadModel(uint lVEHICLE)
{
    REQUEST_MODEL(lVEHICLE);
    while (!HAS_MODEL_LOADED(lVEHICLE))
    {
        WAIT(100);
    }
}

void main(void)
{
    WAIT(1000);
    while (TRUE)
    {
        //Cops Only
        uint grd = PED_M_Y_PRISONGUARD, cop = PED_M_Y_COP, cop2 = PED_M_Y_COP_TRAFFIC, cop3 = PED_M_Y_STROOPER;
        uint fcop = PED_M_M_FATCOP_01;
        //FIB CIA Only
        uint fib = PED_M_M_FBI, cia = PED_M_Y_CIADLC_01, cia2 = PED_M_Y_CIADLC_02;
        //NOoSE Only
        uint nose = PED_M_Y_SWAT, nose2 = PED_M_Y_NHELIPILOT;
        //Police Vehicles
        uint pcar = VEHICLE_POLICE, pcar2 = VEHICLE_POLICE2, pcar3 = VEHICLE_POLICE3, pcar4 = VEHICLE_POLICE4, pbik = VEHICLE_POLICEB;
        //NOoSE Vehicles
        uint nstock = VEHICLE_NSTOCKADE, noocar = VEHICLE_NOOSE, polpat = VEHICLE_POLPATRIOT, pstock = VEHICLE_PSTOCKADE;
        uint apc = VEHICLE_APC, avan = VEHICLE_AVAN, pbus = VEHICLE_PBUS;
        //FIB CIA Vehicles
        uint fbicar = VEHICLE_FBI;
        //Rifles
        //M4
        uint rifle = WEAPON_M4;
        //AK47
        uint rifle2 = WEAPON_AK47;
        //M249
        uint  rifle3 = WEAPON_EPISODIC_14;
        //Sub-Machine Guns
        //MP5
        uint smg = WEAPON_MP5,
            //UZI
            smg2 = WEAPON_MICRO_UZI,
            //P90
            smg3 = WEAPON_EPISODIC_12;
        //Shotguns
        //Pumpshot
        uint sg = WEAPON_SHOTGUN;
        //Beretta
        uint sg2 = WEAPON_BARETTA;
        //AA-12
        uint sg3 = WEAPON_EPISODIC_11;
        //Pistols/Handguns
        //Glock
        uint hg = WEAPON_PISTOL;
        //Desert Eagle
        uint hg2 = WEAPON_DEAGLE;
        //.44 Amag
        uint hg3 = WEAPON_EPISODIC_9;
        //RPGs Grenades
        uint rpg = WEAPON_RLAUNCHER, grnde = WEAPON_GRENADE;

        //getting episode ID
        uint ep = GET_CURRENT_EPISODE();

        //Requesting All the Models from game to spawn them in world
        //peds
       LoadModel(grd);
        LoadModel(cop);
        LoadModel(cop2);
        LoadModel(cop3);
        LoadModel(fcop);
        LoadModel(fib);
        LoadModel(nose);
        LoadModel(nose2);
       
            LoadModel(cia);
            LoadModel(cia2);
        
        //vehicles
        
            LoadModel(apc);
            LoadModel(avan);
        
        LoadModel(pcar);
        LoadModel(pcar2);
        LoadModel(pcar3);
        LoadModel(pstock);
        LoadModel(polpat);
        LoadModel(noocar);
        LoadModel(pcar4);
        LoadModel(pbik);
        LoadModel(fbicar);
        LoadModel(nstock);
        LoadModel(pbus);

        
        
        uint wl;//to store wanted level
        STORE_WANTED_LEVEL(GetPlayerIndex(), &wl); //get player's wanted level

       
        //Stuff for normal Traffic in LC.
        if ((wl == 0) || (wl == 1) || (wl == 2))
        {
            int a; //for randomisation
            a++; //increment of +1 in every interval tick
            if (a == 11)//here the cases
                a = 1;
            if (a == 1)
            {
                if (ep == 2)SPAWN_POLICE_BIKE(cop, pbik, 100);//police bike
                else SPAWN_COP_CAR(cop, cop2, pcar2, sg, hg, 100);//merit
            }
            if (a == 2) SPAWN_COP_CAR(cop2, cop3, pcar, sg2, hg, 100);//stainer
            if (a == 3)
            {
                if (ep == 2)SPAWN_COP_CAR(cop3, cop, pcar, sg2, hg2, 100);//buffalo
                else SPAWN_COP_CAR(cop, cop2, pcar, sg, hg, 100);//stainer
            }
            if (a == 4) SPAWN_COP_CAR(cop2, cop2, pcar2, sg, hg2, 100);//merit
            if (a == 5) {
                if (ep == 2)SPAWN_POLICE_BIKE(cop2, pbik,100);//bike
                else SPAWN_COP_CAR(cop, cop2, pcar, sg, hg, 100);//stainer
            }
            if (a == 6) SPAWN_COP_CAR(cop, cop2, pcar, sg, hg2, 100);//stainer
            if (a == 7)
            {
                if (ep == 2)SPAWN_COP_CAR(cop3, cop2, pcar4, sg, hg, 100);//stinger
                else SPAWN_COP_CAR(cop3, cop2, pcar2, sg2, hg2, 100);//merit
            }
            if (a == 8) SPAWN_COP_CAR(cop3, cop3, pcar, sg, hg, 100);//stainer
            if (a == 9) SPAWN_COP_CAR(cop, cop2, pcar2, sg2, hg2, 100);//merit
            if (a == 10)
            {
                if (ep == 2)SPAWN_POLICE_BIKE(cop2, pbik,100);//bike
                else SPAWN_COP_CAR(cop, cop, pcar, sg, hg2, 100);//stainer
            }

        }

        //Stuff only for wanted star 3.
        if (wl == 3)
        {
            int b; //for randomisation
            b++; //increment of +1 in every interval tick
            //GENERATE_RANDOM_INT_IN_RANGE(0, 10);
            if (b == 11)//here the cases
                b = 1;
            {
                if (b == 1) SPAWN_COP_CAR(cop, cop2, pcar2, sg, hg2, 100);//lcpd
                if (b == 2) SPAWN_COP_CAR(cop2, cop3, pcar, sg2, hg, 100);//traffic
                if (b == 3)
                {
                    if (ep == 2)SPAWN_POLICE_BIKE(cop3, pbik, 100);//bike asp
                    else SPAWN_COP_CAR(cop, cop2, pcar2, sg, hg, 100);//asp
                }
                if (b == 4) SPAWN_COP_CAR(cop2, cop2, pcar, sg, hg2, 100);//asp
                if (b == 5) SPAWN_COP_CAR(cop3, cop2, pcar2, sg2, hg, 100);//traffic
                if (b == 6) SPAWN_COP_CAR(cop, cop2, pcar, sg, hg2, 100);//lcpd
                if (b == 7)
                {
                    if (ep == 2)SPAWN_COP_CAR(cop3, cop2, pcar3, sg, hg, 100);//buffalo lcpd
                    else SPAWN_COP_CAR(cop3, cop2, pcar, sg2, hg2, 100);//asp
                }
                if (b == 8) SPAWN_COP_CAR(cop3, cop3, pcar, sg, hg, 100);//asp
                if (b == 9) SPAWN_COP_CAR(cop, cop2, pcar2, sg2, hg2, 100);//cop
                if (b == 0)
                {
                    if (ep == 1)SPAWN_COP_CAR(cop3, cop, pcar, sg2, hg, 100);//lcpd 
                    else SPAWN_COP_CAR(cia, cia, VEHICLE_INFERNUS, sg, hg2, 100);//ciA
                }

            }
        }
        //Stuff only for Wanted Star 4.
        if (wl == 4)
        {
            int c; //for randomisation
            c++; //increment of +1 in every interval tick
            if (c == 11)//here the cases
                c = 1;
            if (c == 1)
            {
                if (ep == 1)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(grd, grd, grd, grd, pcar, sg2, hg2, 100, 1);
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop, cop2, cop2, cop,  pstock, sg, hg, 100, 1);
            }
            if (c == 2) SPAWN_COP_CAR(cop2, cop3, pcar, sg2, hg, 100);
            if (c == 3)
            {
                if (ep == 1)SPAWN_COP_CAR(grd, grd, pcar, sg2, hg2, 100);
                else SPAWN_COP_CAR(cop, cop2, pcar2, sg, hg, 100);
            }
            if (c == 4) SPAWN_COP_CAR(cop2, cop2, pcar, sg, hg2, 100);
            if (c == 5) {
                if (ep == 1)SPAWN_COP_CAR(grd, grd, pcar, sg2, hg2, 100);
                else SPAWN_COP_CAR(cop, cop2, pcar2, sg, hg, 100);
            }
            if (c == 6) SPAWN_COP_CAR(cop, cop2, pcar, sg, hg2, 100);
            if (c == 7)
            {
                if (ep == 2)SPAWN_COP_CAR(cop3, cop2, pcar3, sg, hg, 100);
                else SPAWN_COP_CAR(cop3, cop2, pcar, sg2, hg2, 100);
            }
            if (c == 8) SPAWN_COP_CAR(cop3, cop3, pcar, sg, hg, 100);
            if (c == 9) SPAWN_COP_CAR(cop, cop2, pcar2, sg2, hg2, 100);
            if (c == 10)
            {
                if (ep == 0)SPAWN_COP_CAR(cop3, cop, pcar, sg2, hg, 100);
                else SPAWN_COP_CAR(cia, cia, VEHICLE_INFERNUS, sg, hg2, 100);
            }
        }

        //Stuff for star wanted 5.
        //From here Cops start Wearing armours (visible).
        if (wl == 5)
        {
            int d; //for randomisation
            d++; //increment of +1 in every interval tick
            if (d == 11)//here the cases
                d = 1;
            if (d == 1)
            {
                if (ep == 1)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(grd, grd, grd, grd, pbus, rifle, hg2, 100, 1);//pbus
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop3, cop3, cop3, cop3, pcar2, sg2, hg, 100, 1);//asp
            }
            if (d == 2) SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(fib, fib, fib, fib, fbicar, 100, rifle, smg, sg2, hg2, 100);//fib
            if (d == 3)
            {
                if (ep == 2)SPAWN_TACTICAL_CAR_WITH_TWO_PASSENGER_WITH_GUNS(nose, nose2, rifle, smg, sg2, hg, avan, 100, 100);//avan
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop,cop2, cop, cop2, pcar2, sg, hg, 100, 1);//lcpdmix
            }
            if (d == 4) SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(nose, nose2, nose2, nose, noocar, 100, rifle, smg2, sg, hg, 100);//noose
            if (d == 5) {
                if (ep == 2)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop, cop2, cop3, cia, pcar3, rifle, hg2, 100, 1);//buffalo
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop2, cop2, cop2, cop2, pstock, sg, hg, 100, 1);//pstickade with traffic
            }
            if (d == 6) SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop2, cop2, cop2, cop2, pcar, sg, hg2, 100, 1);//traffic
            if (d == 7)
            {
                if (ep == 2)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop3, cop, cia, cia, pcar3, smg3, hg3, 100, 1);//stinger
                else SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(fib, fib, fib, fib, fbicar, 100, rifle2, smg2, sg2, hg2, 100);//fbi
            }
            if (d == 8) SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(nose, nose2, nose2, nose, noocar, 100, rifle, smg, sg2, hg, 100);//noose car
            if (d == 9) SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(nose, nose, cop2, cop3, polpat, sg2, hg2, 100, 1);//patriot car
            if (d == 10)
            {
                if (ep == 2)SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(cia, cia2, cia, cia2, fbicar, 100, rifle2, smg3, sg3, hg3, 100);//fbicia
                else SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(nose, nose, nose, nose2, pstock, 100, rifle2, smg2, sg2, hg2, 100);//pstockade
            }
        }
        //Here also cops wear armours.
        //Stuff for wanted star 6.
        if (wl == 6)
        {
            int e; //for randomisation
            e++; //increment of +1 in every interval tick
            if (e == 11)//here the cases
                e = 1;
            if (e == 1)
            {
                if (ep == 1)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(grd, grd, grd, grd, pbus, rifle2, hg3, 100, 1);//prisonguards
                else SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(fib, fib, fib, fib, fbicar, 100, rifle, smg2, sg, hg, 100);//fib  both
            }
            if (e == 2) SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop, cop, cop, cop, pstock, sg2, hg, 100, 1);//lcpd cops
            if (e == 3)
            {
                if (ep == 2)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop2, cop2, cop2, cop2, pcar3, smg3, hg3, 100, 1);//stinger with traffic cops
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop3, cop3, cop3, cop3, pstock, sg2, hg, 100, 1);//asp cops with pstockade
            }
            if (e == 4) SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(nose2, nose2, nose2, nose, nstock, 100, rifle, smg2, sg2, hg2, 100);//noose stockade with noose
            if (e == 5) 
            {
                if (ep == 2)SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop, cop, cop, cop, pcar3, sg3, hg3, 100, 1);// buffalo with lcpd
                else SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(cop2, cop2, cop2, cop2, pstock, rifle, hg2, 100, 1);//pstockade with lcpd traffic
            }
            if (e == 6) SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(nose, nose2, nose, nose2, noocar, rifle, hg2, 100, 1);//noose crusier with noose
            if (e == 7)
            {
                if (ep == 2) SPAWN_TACTICAL_CAR_WITH_TWO_PASSENGER_AND_HEAVY_WEAPON(nose, nose2, grnde, smg3, sg3, hg3, apc, 100, 100);//apc with noose grenade
                else SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(nose, nose2, nose, nose2, nstock, 100, rifle, smg2, sg2, hg2, 100);//noose truck
            }
            if (e == 8) 
            {
                if (ep == 2)SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(cia, cia, cia2, cia2, fbicar, 100, rifle2, smg3, sg2, hg3, 100);//fbi
                else SPAWN_TACTICAL_POLICE_WITH_CAR_AND_GUNS(fib, fib, fib, fib, fbicar, 100, rifle2, smg2, sg2, hg2, 100);//fbi but cia
            }
            if (e == 9) SPAWN_COP_CAR_WITH_FOUR_PASSENGERS(nose, nose2, nose2, cop, polpat, rifle, hg2, 100, 1);//polpatriot noose
            if (e == 10)
            {
                if (ep == 2)SPAWN_TACTICAL_CAR_WITH_TWO_PASSENGER_AND_HEAVY_WEAPON(nose, nose2, rpg, smg3, sg3, hg3, avan, 100, 100);//brickade with noose rpg 
                else SPAWN_COP_CAR(cop, cop2, pcar2, smg2, hg2, 100);//lcpd
            }
        }
        WAIT(17500);//EVERY 17.5 Seconds (for testing 5 sec)
    }
}