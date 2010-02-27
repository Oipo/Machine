import bacon

# ALL you're allowed to do here is register prototypes.
# this code runs in editor context as well as your game!

class CoinPrototype(object):
	img = "coin"

class CratePrototype(object):
	img = "crate"

class BarrelPrototype(object):
	img = "barrel"

class ShotgunPrototype(object):
	img = "shotgun"

class EnemyPrototype(object):
	img = "enemy"

def registerPrototypes:
	bacon.RegisterPrototype("coin", CoinPrototype)
	bacon.RegisterPrototype("crate", CratePrototype)
	bacon.RegisterPrototype("barrel", BarrelPrototype)
	bacon.RegisterPrototype("shotgun", ShotgunPrototype)
	bacon.RegisterPrototype("enemy", EnemyPrototype)
