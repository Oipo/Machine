import bacon

# start up the bugger
bacon.StartEngine()

# initialize some new components for entities to use
Pickupable = bacon.Entity.ComponentNew()
CanShoot = bacon.Entity.ComponentNew()
IsPlayerControlled = bacon.Entity.ComponentNew()

# initialize some new entities for use in the game
# the engine will know about them the moment they are created

# are these *instances* of entities, or prototypes?
# this instances all the prototypes into real entities

Coin = bacon.Entity.CreateNew(CoinPrototype)
Crate = bacon.Entity.CreateNew()
Barrel = bacon.Entity.CreateNew()
Shotgun = bacon.Entity.CreateNew()
EvilDude = bacon.Entity.CreateNew()

# run the game loop until someone kills the game
bacon.Run()