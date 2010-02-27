import bacon
import appstates
import prototypes

engine = bacon.bacon()
# start up the bugger
engine.StartEngine()
prototypes.registerPrototypes(engine)

# initialize some new components for entities to use
# i have no idea if we want the engine to know about this
#Pickupable = bacon.Entity.ComponentNew()
#CanShoot = bacon.Entity.ComponentNew()
#IsPlayerControlled = bacon.Entity.ComponentNew()

# initialize some new entities for use in the game
# the engine will know about them the moment they are created
Coin = engine.Spawn("coin",0,0)
Crate = engine.Spawn("crate",0,100)
Barrel = engine.Spawn("barrel",100,0)
Shotgun = engine.Spawn("shotgun",30,0);
Enemy = engine.Spawn("enemy",200,200);

# run the game loop until someone kills the game
engine.Run()
