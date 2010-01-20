import bacon
import prototypes

# start up the bugger
bacon.StartEngine()
prototypes.registerPrototypes()

# initialize some new components for entities to use
# i have no idea if we want the engine to know about this
Pickupable = bacon.Entity.ComponentNew()
CanShoot = bacon.Entity.ComponentNew()
IsPlayerControlled = bacon.Entity.ComponentNew()

# initialize some new entities for use in the game
# the engine will know about them the moment they are created
Coin = bacon.Spawn("coin",0,0)
Crate = bacon.Spawn("crate",0,100)
Barrel = bacon.Spawn("barrel",100,0)
Shotgun = bacon.Spawn("shotgun",30,0);
Enemy = bacon.Spawn("enemy",200,200);

# run the game loop until someone kills the game
bacon.Run()